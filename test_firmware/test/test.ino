const int TRANSMITPERIOD = 1000;
long lastPeriod = 0;

void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(115200);
  lastPeriod = millis();
}

void loop() {
  if (millis() - lastPeriod > TRANSMITPERIOD) {
    Serial.println("^DID=1;LAT=56.329821;LON=22.212142;STA=1;JOB=2;&DID=2;LAT=22.223344;LON=11.223344;STA=0;JOB=1;");
    lastPeriod = millis();
  }
}
