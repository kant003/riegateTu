const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int getHumedadSuelo = analogRead(sensorPin);
 
}
