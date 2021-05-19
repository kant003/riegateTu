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

static boolean estaCaida(){

  boolean caida = false;
  
  if(digitalRead(sensorINC) == 0){  //significa que mi sensor esta cerrado
    return caida = true;
  }
  
  return caida;
  }

static void sonar(){

    if(digitalRead(sensorINC) == 0){  //significa que mi sensor esta cerrado
      
    tone(buzzerPin, 440);
    delay(1000);
    noTone(buzzerPin);
    delay(2000);
  }
  
  else{
    noTone(buzzerPin);
  }
 
}

void loop()


{
  Serial.println(estaCaida());
  sonar();
}
