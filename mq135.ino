#define MQ135_PIN 36
#define PROMEDIO 10

void mq135_setup(){
  pinMode(MQ135_PIN, INPUT);
}

unsigned int mq135_get_value(){
  unsigned int medida=0;
  for (int i=0; i<PROMEDIO; i++){
    medida += analogRead(MQ135_PIN);
    delay(10);
  }
  return medida / PROMEDIO;
}

