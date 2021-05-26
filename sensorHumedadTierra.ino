const int sensorPin = A0;
int getHumedadSuelo;
void setup() {
  Serial.begin(9600);
}

void loop() {
 
  getHumedadSuelo = analogRead(sensorPin);
  return getHumedadSuelo;
 
}
