/*Samuel Alonso*/
int buzzer=7;
/*Cristian López*/
long distancia;
long tiempo;
int sensorINC = 8;  //declarar pin del sensor

/*Abel García*/
int bombaAgua = 2;

/*Abel García*/
void riega(int segundos) {
    digitalWrite(pinBombaAgua, HIGH);
    delay(segundos * 1000);
    digitalWrite(pinBombaAgua, LOW);
}

/*Cristian López*/
static boolean estaCaida(){
  boolean caida = false;
  if(digitalRead(sensorINC) == 0){  //significa que mi sensor esta cerrado
    return caida = true;
  }
  return caida;
  }
  static void sonar(){
    if(digitalRead(sensorINC) == 0){  //significa que mi sensor esta cerrado
      tone(buzzer, 440);
      delay(1000);
      noTone(buzzer);
      delay(2000);
      }
    else{
      noTone(buzzer);
      }
    }

/*Yariana*/
#include <DHT.h>
#include <LiquidCrystal.h>
int SENSOR = 2;
DHT dht(SENSOR, DHT11);
LiquidCrystal lcd(4,5,6,7,8,9);


/*Yari López*/
float mostrarHumedad(float humedad) {
  lcd.print("Humedad: ");
  lcd.print(humedad);
  lcd.println("%");
}

float mostrarTemperatura(float temp) {
  
  lcd.print("Temperatura: ");
  lcd.print(temp);
  lcd.println("ºC"); 
  }

float mostrarHumedadSuelo(float humedadSuelo) {
  lcd.print("Humedad del suelo: ");
  lcd.print(humedadSuelo);
  lcd.println("%");
  }



/*Raposo*/
float getHumedadSuelo(){
  int humedadSuelo = analogRead(sensorPin);
  return humedadSuelo;
  }

  

/*Samuel Alonso Gil*/
float controlHumedad{
  if(getHumedadTierra() < humedadSuelo){
    digitalWrite(buzzer,HIGH);
    delay(2000);
    digitalWrite(buzzer,LOW); 
    delay(100);
    }
  }


/*Christian Fernandez Bielsa*/
float temperatura(){
return dht.readTemperature();
}

float humedad(){
return dht.readHumidity();
}
 



void setup() {
  /*Samuel Alonso*/
  pinMode(buzzer, OUTPUT);

  /*Yariana Lopez*/
    dht.begin();
    lcd.begin(16, 2);
    analogWrite(V0, 50)
    pinMode(humedadSuelo, INPUT);
   lcd.init();
   lcd.backlight();
   lcd.clear();
   lcd.setCursor(0,0);


  /*Christian Fernandez Bielsa*/
  Serial.begin(9600);
  dht.begin();

  /*Cristian López*/
  Serial.begin(9600);
  pinMode(sensorINC, INPUT); //declarar el sensor de inclinacion como entrada
  pinMode(buzzer, OUTPUT); //declarar el buzzer como salida

  /*Abel García*/
  pinMode(bombaAgua, OUTPUT);
    riega(2, bombaAgua);
  }

void loop() {
  
  lcd.clear();
 
  float humedadSuelo=getHumedadSuelo();
  mostrarHumedadSuelo(humedadSuelo);

  float humedad=humedad();
  mostrarHumedad(humedad);

  float temperatura=temperatura();
  mostrarTemperatura(temperatura);
  delay(500);

  riega(10000);
  
  }
