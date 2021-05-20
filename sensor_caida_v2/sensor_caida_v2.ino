long distancia;
long tiempo;

int buzzerPin = 10; //declarar pin del buzzer
int sensorINC = 8;  //declarar pin del sensor

void setup()

{

Serial.begin(9600);

pinMode(sensorINC, INPUT); //declarar el sensor de inclinacion como entrada

pinMode(buzzerPin, OUTPUT); //declarar el buzzer como salida

}

void loop()

{
  
  noTone(buzzerPin);
  if(digitalRead(sensorINC) == 0){  //sigifica que mi sensor esta cerrado
    
    Serial.println("sensor INCLINADO");
    tone(buzzerPin,440);
    delay(1000);
    noTone(buzzerPin);
    delay(2000);
  }
  else{
    Serial.println("sensor DERECHO");
    noTone(buzzerPin);
  }
  
}
