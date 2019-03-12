//Sparkfun sound detector

#define SOUND_SENSOR 38
#define PROMEDIO 10

void sound_setup(){
  pinMode(MQ135_PIN, INPUT);
}

unsigned int sound_get_value(){
  unsigned int medida=0;
  for (int i=0; i<PROMEDIO; i++){
    medida += analogRead(SOUND_SENSOR);
    delay(10);
  }
  return medida / PROMEDIO;
}


