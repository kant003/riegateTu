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

  lcd.print("Humedad: ");
  lcd.print(humedad);
  lcd.println("%");

  delay(500);
}

float mostrarTemperatura{
  lcd.clear();

  temp = dht.readTemperature();

  lcd.print("Temperatura: ");
  lcd.print(temp);
  lcd.println("ºC"); 

  delay(500);
}

float mostrarHumedadSuelo{
  lcd.clear();
  int SensorValue = analogRead(humedadSuelo);

  lcd.print("Humedad del suelo: ");
  lcd.print(SensorValue);
  lcd.println("%");
  delay(500);
}
