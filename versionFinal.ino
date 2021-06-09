/** Declaracion de Pines y variables **/
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

int buzzer = 2;
int sensorHumedadSueloPin = 35;
int sensorINC = 13;
int pinBombaAgua = 5;
int sensorDHT = 4;
DHT dht(sensorDHT, DHT11);
LiquidCrystal_I2C lcd(0x3F, 16, 2);

/*Simbolo º */
byte grado[] = {
    B01110,
    B01010,
    B01110,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000};

/*Simbolo % */
byte porcentaje[] = {
    B11000,
    B11000,
    B00001,
    B00010,
    B00100,
    B01000,
    B10011,
    B00011};

/** FIN de declaracion de variables **/

/** Declaracion de funciones **/

/*Abel García*/
void riega(int segundos)
{
    digitalWrite(pinBombaAgua, HIGH);
    delay(segundos * 1000);
    digitalWrite(pinBombaAgua, LOW);
}
void regar()
{
    digitalWrite(pinBombaAgua, HIGH);
}
void noRegar()
{
    digitalWrite(pinBombaAgua, LOW);
}

/*Cristian López*/
boolean estaCaida()
{
    return !digitalRead(sensorINC);
}

/*Christian Fernandez Bielsa*/
int getTemperatura()
{
    return dht.readTemperature();
}

int getHumedad()
{
    return dht.readHumidity();
}
/*Raposo*/
int getHumedadSuelo()
{
    int humedadSuelo = analogRead(sensorHumedadSueloPin);
    return humedadSuelo;
}

/*Yariana*/
void mostrarHumedad(int humedad)
{
    lcd.print("Hum: ");
    lcd.print(humedad);
    lcd.write(1);
}
void mostrarTemperatura(int temp)
{
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.write(0);
    lcd.print("C");
}
void mostrarHumedadSuelo(int humedadSuelo)
{
    lcd.print("Suelo: ");
    lcd.print(humedadSuelo);
}

/*Samuel Alonso Gil*/
void controlHumedad()
{
    if (getHumedadSuelo() > 1500)
    {
        regar();
    }
    else
    {
        noRegar();
    }

    if (getHumedadSuelo() > 3000)
    {
        sonar();
    }
    else
    {
        noSonar();
    }
}

void sonar()
{
    digitalWrite(buzzer, HIGH);
}
void noSonar()
{
    digitalWrite(buzzer, LOW);
}
/** FIN de declaracion de funciones**/

void setup()
{
    Serial.begin(9600);

    pinMode(buzzer, OUTPUT);
    pinMode(sensorHumedadSueloPin, INPUT);
    pinMode(sensorINC, INPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(pinBombaAgua, OUTPUT);

    dht.begin();
    lcd.init();
    lcd.backlight();
    lcd.createChar(0, grado);
    lcd.createChar(1, porcentaje);
}

void loop()
{
    Serial.println(getHumedadSuelo());
    Serial.println(estaCaida());
    lcd.setCursor(0, 0);
    mostrarTemperatura(getTemperatura());
    lcd.setCursor(0, 1);
    mostrarHumedad(getHumedad());
    lcd.setCursor(11, 1);
    mostrarHumedadSuelo(getHumedadSuelo());
    lcd.scrollDisplayLeft();
    delay(300);

    if (!estaCaida())
    {
        sonar();
    }
    else
    {
        noSonar();
    }

    controlHumedad();
}