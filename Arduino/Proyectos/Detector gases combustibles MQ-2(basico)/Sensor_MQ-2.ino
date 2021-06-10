int pin_d_mq = 2;
int pin_a_mq = A0;

void setup() { 
  Serial.begin(9600);
  pinMode(pin_d_mq, INPUT);
}


void loop() {
  boolean mq_estado = digitalRead(pin_d_mq);//Leemos el sensor
  int mq_a_valor = analogRead(pin_a_mq);

  Serial.print("Valor analógico: ");
  Serial.println(mq_a_valor);
  if(mq_estado) //si la salida del sensor es 1
  {
    Serial.println("-Sin presencia de gases combustibles");
  }
  else //si la salida del sensor es 0
  {
    Serial.println("-Con presencia de gases combustibles");
  }
  delay(500); 
}
