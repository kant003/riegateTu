int bombaAgua = 2;
void setup() {
    pinMode(bombaAgua, OUTPUT);
    riega(2, bombaAgua);
}

void loop() {
}

void riega(int segundos, int pinBombaAgua) {
    digitalWrite(pinBombaAgua, HIGH);
    delay(segundos * 1000);
    digitalWrite(pinBombaAgua, LOW);
}