
/**
 * Este es un programa para detectar la temperatura en Celsius y la humedad del ambiente.
 * Se incluyen las librerías: DHT_sensor y Adafruit unified sensor para su funcionamiento.
 * Además se declara el pin del sensor y modelo con la librería (Pin,Modelo_del_sensor)
 */
#include <DHT.h>
DHT dht(6,DHT11); 



void setup() {
    Serial.begin(9600);
    dht.begin();
    
}

void loop() {  
float TemperaturaCelius = dht.readTemperature();
float Humedad = dht.readHumidity();

if(isnan(TemperaturaCelius) || isnan(Humedad)){ 
  Serial.println("Error al tomar medidas, revisa las conexiones");
  
}else {
  Serial.println("Temperatura: ")+String(TemperaturaCelius,1)+"ºC";
  Serial.println("Humedad: ")+String(Humedad,1)+"%";
}
delay(5000);

}
