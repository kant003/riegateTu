long distancia;
long tiempo;

int buzzerPin = 10;

void setup()

{

Serial.begin(9600);

pinMode(9, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/

pinMode(8, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/

pinMode(10, OUTPUT);

}

void loop()

{

digitalWrite(9,LOW); /* Por cuestión de estabilización del sensor*/

delayMicroseconds(5);

digitalWrite(9, HIGH); /* envío del pulso ultrasónico*/

delayMicroseconds(10);

tiempo=pulseIn(8, HIGH); /* recibe el pulso ultrasónico y calcula la duración de ida y vuelta del pulso*/

distancia= int(0.017*tiempo); /*fórmula para calcular la distancia, se genera de la velocidad del pulso ultrasónico en el aire, 0,034 cm/microseg*/

Serial.println("Distancia ");

Serial.println(distancia); //

Serial.println(" cm");

delay(1000);

/*El siguiente código utiliza el valor de distancia para activar el sonido del buzzer*/

if (distancia < 20)

{

tone(buzzerPin, 440);

delay(900);

noTone(buzzerPin); } // cierro if distancia

else

{

digitalWrite(buzzerPin, LOW);

delay(900);

}// cierra else }
}
