const byte PIN_CORRIENTE = A0;
const byte PIN_RELAY = 2;
const float LIMIT_CORRIENTE = 0.3; 
//const float SENSIBILITY = 0.185;   // Modelo 5A
//const float SENSIBILITY = 0.100; // Modelo 20A
const float SENSIBILITY = 0.066; // Modelo 30A
const byte CANT_MUESTRAS = 100;
const int RETARDO = 1000;
float valCorriente = 0;

void setup() {
  pinMode(PIN_CORRIENTE, INPUT);
  pinMode(PIN_RELAY, OUTPUT);
  digitalWrite(PIN_RELAY, HIGH);
  delay(RETARDO);
  Serial.begin(9600);
}

void loop() {
   digitalWrite(PIN_RELAY, HIGH);
   /*
   valCorriente = getCorriente(CANT_MUESTRAS);
   Serial.println(valCorriente);
   if(valCorriente<LIMIT_CORRIENTE){
    digitalWrite(PIN_RELAY, HIGH);
   }
   else{
    digitalWrite(PIN_RELAY, LOW);
   }
   */
   delay(RETARDO);
}

float getCorriente(int samplesNumber)
{
   float voltage;
   float corrienteSum = 0;
   for (int i = 0; i < samplesNumber; i++)
   {
      voltage = analogRead(A0) * 5.0 / 1023.0;
      corrienteSum += (voltage - 2.5) / SENSIBILITY;
   }
   return(corrienteSum / samplesNumber);
}
