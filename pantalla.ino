/**
 * Este es un programa que muestra en pantalla la información
 * de la humedad, humedad de la tierra y temperatura
 */
 
#include <DHT.h>
#include <LiquidCrystal.h>

int SENSOR = 2;
DHT dht(SENSOR, DHT11);
LiquidCrystal lcd(4,5,6,7,8,9);

int temp;
int humedad;

void setup() {
 Serial.begin(9600);
 dht.begin();
 lcd.begin(16, 2);
 analogWrite(V0, 50)

 pinMode(humedadSuelo, INPUT);

 lcd.init();
 lcd.backlight();
 lcd.clear();
 lcd.setCursor(0,0);
}

float mostrarHumedad{
  lcd.clear();

 humedad = dht.readHumidity();

  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println("%");

  delay(500);
}

float mostrarTemperatura{
  lcd.clear();

  temp = dht.readTemperature();

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println("ºC"); 

  delay(500);
}

float mostrarHumedadSuelo{
  lcd.clear();
  int SensorValue = analogRead(humedadSuelo);

  Serial.print("Humedad del suelo: ");
  Serial.print(SensorValue);
  Serial.println("%");
  delay(500);
}
