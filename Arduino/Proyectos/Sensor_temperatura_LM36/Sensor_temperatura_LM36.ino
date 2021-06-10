const byte pinTemp=A0;
float analogTemp=0;
float temp=0;

void setup()
{
  pinMode(pinTemp, INPUT);
  Serial.begin(9600);
}

void loop()
{
  analogTemp=analogRead(pinTemp);
  Serial.println(analogTemp);
  temp=0.0048828125*analogTemp*100-50;
  Serial.println(temp);
  delay(1000);
}
