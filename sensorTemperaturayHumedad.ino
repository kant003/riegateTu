
/**
 * Este es un programa para detectar la temperatura en Celsius y la humedad del ambiente.
 * Se incluyen las librerías: DHT_sensor y Adafruit unified sensor para su funcionamiento.
 * Además se declara el pin del sensor y modelo con la librería (Pin,Modelo_del_sensor)
 */
#include <DHT.h>
DHT dht(6,DHT11); 

public:
float temperatura(){
return dht.readTemperature();
}

float humedad(){
return dht.readHumidity();
}



void setup(){
    Serial.begin(9600);
    dht.begin();
    
}

void loop() {  
float TemperaturaCelius = dht.readTemperature();
float Humedad = dht.readHumidity();
}
