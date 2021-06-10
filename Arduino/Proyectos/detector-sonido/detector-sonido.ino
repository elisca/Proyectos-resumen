const byte ENTRADA_SONIDO = A0;
const byte RETARDO = 500;
const int SENSIBILIDAD_ANALOG = 30;
int analogSonido = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ENTRADA_SONIDO, INPUT);
}

void loop() {
  analogSonido = analogRead(ENTRADA_SONIDO);
  Serial.println(analogSonido);
  if(analogSonido>=SENSIBILIDAD_ANALOG){
    Serial.println("SONIDO DETECTADO");
  }
  else{
    Serial.println("NO SE DETECTA SONIDO");
  }
  delay(RETARDO);
}
