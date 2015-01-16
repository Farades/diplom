const int TRANSMITPERIOD = 1000;
long lastPeriod = 0;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  lastPeriod = millis();
}

void loop() {
  if (millis() - lastPeriod > TRANSMITPERIOD) {
    Serial.println("^DID=1;LAT=56.329821;LON=22.212142;STA=1;JOB=2;&DID=2;LAT=22.223344;LON=11.223344;STA=0;JOB=1;&DID=23;LAT=22.223344;LON=11.223344;STA=0;JOB=1;");
    lastPeriod = millis();
  }
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
     Serial.read(); 
    }
    blink(5);
  }
}


void blink(int ms) {
  digitalWrite(13, HIGH);
  delay(ms);
  digitalWrite(13, LOW);
}
