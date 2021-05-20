
int buzzer=7;

int getHumedadTierra(){
  return 1;} 

int controlHumedad{
  if(getHumedadTierra() < 2){
    digitalWrite(buzzer,HIGH);
    delay(2000);
    digitalWrite(buzzer,LOW); 
    delay(100);
    }
  }

void setup() {
  pinMode(buzzer, OUTPUT);
  
  }

void loop() {}
