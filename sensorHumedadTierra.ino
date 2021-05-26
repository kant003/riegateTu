const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
   

}
int getHumedadSuelo(){
   
  int humedadSuelo = analogRead(sensorPin);
  return humedadSuelo;

}
