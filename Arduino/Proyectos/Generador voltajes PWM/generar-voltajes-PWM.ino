const byte PIN_SALIDA=10;
const float VOLTAJE_SALIDA=5; //0 A 5V

void setup() {
  Serial.begin(9600);
  pinMode(PIN_SALIDA,OUTPUT);
  analogWrite(PIN_SALIDA,CalcularPWM(VOLTAJE_SALIDA));
  Serial.println("Voltaje salida activado");
}

void loop() {
}

byte CalcularPWM(float voltaje){
  byte retorno;
  if(voltaje>5){
    retorno=0;
    Serial.println("Voltaje de salida no válido. No ingresar valores mayores a 5v.");
  }
  else{
    retorno=voltaje*256/5;
  }
  return retorno;
}

