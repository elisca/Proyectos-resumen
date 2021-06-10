const int RETARDO = 1000;

#define pinEntrada 2

bool pushDown = false;

void setup() {
  pinMode(pinEntrada, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  pushDown = digitalRead(pinEntrada);

  if(!pushDown){
    Serial.println("Boton presionado");
  }
  else{
    Serial.println("Boton sin presionar");
  }
  delay(RETARDO);
}
