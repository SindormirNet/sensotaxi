#define MQ135_PIN 36
#define MQ132_PIN 37
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


void mq132_setup(){
  pinMode(MQ132_PIN, INPUT);
}

unsigned int mq132_get_value(){
  unsigned int medida=0;
  for (int i=0; i<PROMEDIO; i++){
    medida += analogRead(MQ132_PIN);
    Serial.println(analogRead(MQ132_PIN));
    delay(10);
  }
  return medida / PROMEDIO;
}

