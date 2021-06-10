const byte PIN_SALIDA = 2;
const int INTERVALO = 3000;


void setup() {
  pinMode(PIN_SALIDA, OUTPUT);
}

void loop() {
  digitalWrite(PIN_SALIDA, HIGH);
  delay(INTERVALO);
  digitalWrite(PIN_SALIDA, LOW);
  delay(INTERVALO);
}
