#include <RFM69.h>
#include <SPI.h>

#define NODEID_1      1
#define NODEID_2      2
#define NETWORKID     100  //the same on all nodes that talk to each other
#define FREQUENCY     RF69_433MHZ
#define ENCRYPTKEY    "sampleEncryptKey" //exactly the same 16 characters/bytes on all nodes!
#define ACK_TIME      30 // max # of ms to wait for an ack
#define SERIAL_BAUD   115200

RFM69 radio1(10, 2, false, 0);
RFM69 radio2(A3, 3, false, 1);
bool promiscuousMode = false; //set to 'true' to sniff all packets on the same network

void setup() {
  Serial.begin(SERIAL_BAUD);
  delay(10);
  if (radio1.initialize(FREQUENCY,NODEID_1,NETWORKID))
    Serial.println("OK");
 if (radio2.initialize(FREQUENCY,NODEID_2,NETWORKID))
    Serial.println("OK");
  radio1.encrypt(ENCRYPTKEY);
  radio2.encrypt(ENCRYPTKEY);
  radio1.promiscuous(promiscuousMode);
  radio2.promiscuous(promiscuousMode);
}

byte ackCount=0;
void loop() {
  //process any serial input
  if (Serial.available() > 0)
  {
    char input = Serial.read();
    if (input == 'r') //read register
    {
      Serial.println("Radio 1:");
      radio1.readAllRegs();
      Serial.println("Radio 2:");
      radio2.readAllRegs();
    }  

    if (input == 't')
    {
      byte temperature =  radio1.readTemperature(-1); // -1 = user cal factor, adjust for correct ambient
      byte fTemp = 1.8 * temperature + 32; // 9/5=1.8
      Serial.print( "Radio Temp is ");
      Serial.print(temperature);
      Serial.print("C, ");
      Serial.print(fTemp); //converting to F loses some resolution, obvious when C is on edge between 2 values (ie 26C=78F, 27C=80F)
      Serial.println('F');
    }
  }
  
  //bool test1 = radio1.receiveDone();
  //bool test2 = radio2.receiveDone();
  if (/*radio1.receiveDone()*/false)
  {
    Serial.print('[');Serial.print(radio1.SENDERID, DEC);Serial.print("] ");
    if (promiscuousMode)
    {
      Serial.print("to [");Serial.print(radio1.TARGETID, DEC);Serial.print("] ");
    }
    for (byte i = 0; i < radio1.DATALEN; i++)
      Serial.print((char)radio1.DATA[i]);
    Serial.print("   [RX_RSSI:");Serial.print(radio1.RSSI);Serial.print("]");
    
    if (radio1.ACKRequested())
    {
      byte theNodeID = radio1.SENDERID;
      radio1.sendACK();
      Serial.print(" - ACK sent.");

      // When a node requests an ACK, respond to the ACK
      // and also send a packet requesting an ACK (every 3rd one only)
      // This way both TX/RX NODE functions are tested on 1 end at the GATEWAY
      if (ackCount++%3==0)
      {
        Serial.print(" Pinging node ");
        Serial.print(theNodeID);
        Serial.print(" - ACK...");
        delay(3); //need this when sending right after reception .. ?
        if (radio1.sendWithRetry(theNodeID, "ACK TEST", 8, 0))  // 0 = only 1 attempt, no retries
          Serial.print("ok!");
        else Serial.print("nothing");
      }
    }
    Serial.println();
    Blink(9,3);
  }
  if (radio2.receiveDone())
  {
    Serial.print('[');Serial.print(radio2.SENDERID, DEC);Serial.print("] ");
    if (promiscuousMode)
    {
      Serial.print("to [");Serial.print(radio2.TARGETID, DEC);Serial.print("] ");
    }
    for (byte i = 0; i < radio2.DATALEN; i++)
      Serial.print((char)radio2.DATA[i]);
    Serial.print("   [RX_RSSI:");Serial.print(radio2.RSSI);Serial.print("]");
    
    if (radio2.ACKRequested())
    {
      byte theNodeID = radio2.SENDERID;
      radio2.sendACK();
      Serial.print(" - ACK sent.");

      // When a node requests an ACK, respond to the ACK
      // and also send a packet requesting an ACK (every 3rd one only)
      // This way both TX/RX NODE functions are tested on 1 end at the GATEWAY
      if (ackCount++%3==0)
      {
        Serial.print(" Pinging node ");
        Serial.print(theNodeID);
        Serial.print(" - ACK...");
        delay(3); //need this when sending right after reception .. ?
        if (radio2.sendWithRetry(theNodeID, "ACK TEST", 8, 0))  // 0 = only 1 attempt, no retries
          Serial.print("ok!");
        else Serial.print("nothing");
      }
    }
    Serial.println();
    Blink(A1,3);
  }
}

void Blink(byte PIN, int DELAY_MS)
{
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN,HIGH);
  delay(DELAY_MS);
  digitalWrite(PIN,LOW);
}
