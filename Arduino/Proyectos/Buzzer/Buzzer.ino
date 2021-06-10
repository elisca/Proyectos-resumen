const int pinBuzzer = 9;
 
const int tonos[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
const int countTonos = 10;
   
void setup()
{ 
}

void loop()
{
  for (int iTono = 0; iTono < countTonos; iTono++)
  {
   tone(pinBuzzer, tonos[iTono]);//Genera un tono con la frecuencia especificada en determinado pin
   delay(1000);
  }
  noTone(pinBuzzer);//Detiene el tono generado en determinado pin
}
