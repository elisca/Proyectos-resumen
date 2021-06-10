const int potPin = A0; // pin entrada para potenciómetro
const int ledPin = 13; // pin de salida para el LED
const int pinBuzzer = 2; // pin del buzzer
int entAnalog; // Calcula el valor analogico de entrada
int salBuzzer; // Frecuencia de buzzer

void setup()
{
  pinMode(ledPin, OUTPUT); // declara ledPin como SALIDA
  Serial.begin(9600); // Inicializa la consola
}
void loop()
{
  entAnalog=analogRead(potPin);
  salBuzzer=entAnalog*4;
  Serial.println(entAnalog);
  digitalWrite(ledPin, HIGH); // pone ledPin en on
  if(salBuzzer>=100){ // Si la frecuencia es de al menos 100Hz sale sonido por el buzzer
    tone(pinBuzzer, salBuzzer);//Genera un tono con la frecuencia especificada en determinado pin
  }
  delay(entAnalog); // detiene la ejecución un tiempo “potPin”
  digitalWrite(ledPin, LOW); // pone ledPin en off
  noTone(pinBuzzer);//Detiene el tono generado en determinado pin
  delay(entAnalog); // detiene la ejecución un tiempo “potPin”
} 
