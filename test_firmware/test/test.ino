const int TRANSMITPERIOD = 1000;
const int CHANGEPERIOD   = 5000;
bool flag = false;
long lastChangePeriod = 0;
long lastPeriod = 0;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  lastPeriod = millis();
  lastChangePeriod = millis();
}

void loop() {
  if (millis() - lastPeriod > TRANSMITPERIOD) {
    sendMessage();
    
    lastPeriod = millis();
  }
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
     Serial.read(); 
    }
    blink(5);
  }
}

void sendMessage() {
  if (millis() - lastChangePeriod > CHANGEPERIOD) {
    flag = !flag;
    lastChangePeriod = millis();
  }
  if (flag) {
   Serial.println("^DID=1;LAT=11.111111;LON=22.222222;STA=1;JOB=1;&DID=2;LAT=33.333333;LON=44.444444;STA=2;JOB=2;");
  } else {
    Serial.println("^DID=1;LAT=99.888888;LON=88.888888;STA=9;JOB=9;&DID=2;LAT=77.777777;LON=66.666666;STA=8;JOB=8;");
  }
    
}

void blink(int ms) {
  digitalWrite(13, HIGH);
  delay(ms);
  digitalWrite(13, LOW);
}
