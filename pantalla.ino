/**
 * Este es un programa que muestra en pantalla la información
 * de la humedad, humedad de la tierra y temperatura
 */
 
#include <DHT.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensor = 2;
int temp, humedad;
int boton = 3;
const int nivel = 9;
const int humedadSuelo = A0;

DHT dht(sensor, DHT11);
int botonest = 0;

void setup() {
 Serial.begin(9600);
 dht.begin();

 pinMode(humedadSuelo, INPUT);
 pinMode(bomba, OUTPUT);
 pinMode(nivel, INPUT);
 pinMode(boton, INPUT);

 lcd.init();
 lcd.backlight();
 lcd.clear();
 lcd.setCursor(0,0);
}

void loop() {
 
  int SensorNivel = digitalRead(nivel);
  int botonest = digitalRead(boton);

  temp = dht.readTemperature();

  void temperatura(){
     Serial.print("Temperatura: ");
     Serial.print(temp);
  }

  void humedad(){
    Serial.print("ºC Humedad: ");
    Serial.print(humedad);
    Serial.println("%");
  }

  void humedadSuelo(){
    int SensorValue = analogRead(humedadSuelo);
    Serial.print("Humedad del suelo: ");
    Serial.print(SensorValue);
    Serial.println("%");
  }
  delay(500);
}