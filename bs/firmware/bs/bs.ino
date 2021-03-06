#include <RFM69.h>
#include <SPI.h>

#define NODEID      99
#define NETWORKID   100
#define FREQUENCY   RF69_433MHZ //Match this with the version of your Moteino! (others: RF69_433MHZ, RF69_868MHZ)
#define KEY         "thisIsEncryptKey" //has to be same 16 characters/bytes on all nodes, not more not less!
#define LED         9
#define SERIAL_BAUD 115200
#define ACK_TIME    30  // # of ms to wait for an ack

int TRANSMITPERIOD = 3000; //transmit a packet to gateway so often (in ms)
byte sendSize = 0;
boolean requestACK = false;
RFM69 radio;

byte nodeId = 0;
byte cmd = 0;
byte cmdValue = 0;
int prevPotValue = 0;
int potSensitivity = 5;

typedef struct {		
  byte cmd1;
  byte cmd2;
  byte cmdValue1;
  byte cmdValue2;
  float latitude1;
  float latitude2;
  float longitude1;
  float longitude2;
  byte state1;
  byte state2;
} Payload;
Payload theData;

void setup() {
  Serial.begin(SERIAL_BAUD);
  radio.initialize(FREQUENCY,NODEID,NETWORKID);
  radio.encrypt(KEY);
  //char buff[50];
  //sprintf(buff, "BS firmware by Artem Matsepura");
  //Serial.println(buff);
}

long lastPeriod = -1;
void loop() {
  //process any serial input
  if (Serial.available() > 0) {
    delay(3);
    char buffer[100];
    int i = 0;
    while (Serial.available() && i < 99) {
       buffer[i++] = Serial.read(); 
    }
    buffer[i] = '\0';
    if (i > 0) {
      Serial.print("Parse input query: ");
      Serial.println(String(buffer)); 
      parseQuery(buffer);
    }
  }

  //check for any received packets
  if (radio.receiveDone()) {
    //Serial.print('[');Serial.print(radio.SENDERID, DEC);Serial.print("] ");
    if (radio.DATALEN != sizeof(Payload))
      Serial.print("Invalid payload received, not matching Payload struct!");
    else
    {
      theData = *(Payload*)radio.DATA; //assume radio.DATA actually contains our struct and not something else
      Serial.print("^DID=");Serial.print(radio.SENDERID);Serial.print(";LAT=");Serial.print(theData.latitude1);Serial.print(";LON=");Serial.print(theData.longitude1);Serial.print(";STA=");Serial.print(theData.state1);Serial.print(";JOB=");Serial.print(theData.cmd1);Serial.print(";");
      Serial.print("&");Serial.print("DID=");Serial.print(2);Serial.print(";LAT=");Serial.print(theData.latitude2);Serial.print(";LON=");Serial.print(theData.longitude2);Serial.print(";STA=");Serial.print(theData.state2);Serial.print(";JOB=");Serial.print(theData.cmd2);Serial.print(";\n");
    }
    //Serial.print("   [RX_RSSI:");Serial.print(radio.readRSSI());Serial.print("]");

    if (radio.ACKRequested())
    {
      radio.sendACK();
      Serial.print(" - ACK sent");
      delay(10);
    }
    Blink(LED,5);
  }
  
  int currPeriod = millis()/TRANSMITPERIOD;
  if (currPeriod != lastPeriod)
  {
    theData.cmd1 = 0;
    theData.cmdValue1 = 0;
    sendMessage(255);
    
    lastPeriod=currPeriod;
  }
  
  int currentPotValue = map(analogRead(A2), 0, 1023, 0, 255);
  if ( abs(currentPotValue - prevPotValue) >  potSensitivity ) {
    prevPotValue = currentPotValue;
    theData.cmd1 = 2;
    theData.cmdValue1 = currentPotValue;
    theData.cmd2 = 0;
    theData.cmdValue2 = currentPotValue;
    sendMessage(255);
  }
}

void sendMessage(int gatewayID) {    
  //Serial.print("Sending struct (");
  //Serial.print(sizeof(theData));
  //Serial.print(" bytes) ... ");
  //if (radio.sendWithRetry(gatewayID, (const void*)(&theData), sizeof(theData)))
  //  Serial.print(" ok!");
  //else Serial.print(" nothing...");
  radio.send(gatewayID, (const void*)(&theData), sizeof(theData));
  //Serial.println();
  Blink(LED,3);
}

void parseQuery(char query[100]) {
  char GID_in[5];
  char CMD_in[5];
  char VAL_in[5];
  sscanf(query, "%*c%*c%*c%*c%[^';'];%*c%*c%*c%*c%[^';'];%*c%*c%*c%*c%s",
      &GID_in, &CMD_in, &VAL_in);
  sscanf(CMD_in, "%d", &theData.cmd1);
  sscanf(VAL_in, "%d", &theData.cmdValue1);
  int gatewayID;
  sscanf(GID_in, "%d", &gatewayID);
  sendMessage(gatewayID);
}

void Blink(byte PIN, int DELAY_MS) {
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN,HIGH);
  delay(DELAY_MS);
  digitalWrite(PIN,LOW);
}
