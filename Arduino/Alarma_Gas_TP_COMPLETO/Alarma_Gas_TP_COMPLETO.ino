//Librerias para contorl de LCD 16x2 con modulo I2C
//Limite de temperatura, hacer un delta para corte.
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  //Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
                                   //Pines modulo I2C: Alimentacion: Fuente SDA A4 SCL A5
                                   //EP LCD 0x3F

//Pines analogicos
const int MQ_APIN = A0; //Pin analogico deteccion valores gas
const int TMP_APIN = A1; //Pin analogico deteccion temperatura ambiente

//Pines digitales
const int MQ_DPIN = 5; //Pin digital deteccion gas
const int SW0_DPIN = 3; //Pin digital pulsador corte manual
const int SW1_DPIN = 4; //Pin digital pulsador reset corte gas
const int REL_DPIN=6; //Pin digital relay valvula solenoide gas
const int RLEDDPIN=7; //Pin digital, LED rojo alerta
const int GLEDDPIN=8; //Pin digital, LED verde normal

//Otras configuraciones
const int MQ_DELAY = 50; //Retardo para actualizar si se detecta gas
const short int maxTemp=70; //Entero corto, temperatura maxima antes de habilitar corte de gas

//Datos variables del programa
bool corteSW=0; //Booleano, guarda si el corte manual esta activado
float tempAmb; //Flotante, temperatura ambiente

void setup()
{
  lcd.init(); //lcd.init();
  lcd.backlight(); //Encender la luz de fondo.
  lcd.home();

  lcd.print("  Cargando...   ");
  
  Serial.begin(9600); //Inicializa puerto serie para monitorear datos sensor

  Serial.println("  Cargando...   ");
  
  //Define entradas y salidas del Arduino
  //ANALOGICOS
  pinMode(MQ_APIN,INPUT); //ENTRADA, Señal analogica sensor de gas
  pinMode(TMP_APIN,INPUT); //ENTRADA, Señal analogica sensor de temperatura
  //DIGITALES
  pinMode(SW0_DPIN,INPUT); //ENTRADA, Señal digital switch corte de gas
  pinMode(SW1_DPIN,INPUT); //ENTRADA, Señal digital switch reset del corte de gas  
  pinMode(MQ_DPIN,INPUT); //ENTRADA, Señal digital sensor de gas
  pinMode(REL_DPIN,OUTPUT); //SALIDA, Rele de valvula solenoide de gas
  pinMode(RLEDDPIN,OUTPUT); //SALIDA, LED Rojo
  pinMode(GLEDDPIN,OUTPUT); //SALIDA, LED Verde



}

void loop()
{
  //Lecturas - entradas
  bool dGas= digitalRead(MQ_DPIN); //Booleano, detecta gas o no. Lectura digital MQ_DPIN
  int aGas= analogRead(MQ_APIN); //Entero, detecta valores de gas devueltos por el sensor MQ_APIN
  bool dSW0= digitalRead(SW0_DPIN); //Booleano, detecta si el pulsador de corte manual fue activado
  bool dSW1= digitalRead(SW1_DPIN); //Booleano, detecta si el pulsador de reset de corte manual fue activado
  int aTmp= analogRead(TMP_APIN); //Entero, detecta señal del sensor de temperatura ambiente
  
  bool excTemp; //Booleano, indica si alcanzamos exceso de temperatura

  //Activa corte de gas manual en caso de presionar el switch
  if(dSW0==1)
  {
    corteSW=1;
  }
  
  //Resetea el corte de gas manual en caso de presionar el switch
  if(dSW1==1)
  {
    corteSW=0;
  }
   
  
  tempAmb=convertTemp(aTmp); //Temperatura ambiente en Celsius

  if(tempAmb>=maxTemp){
    excTemp=1;
  }
    
  else{
   excTemp=0;
  }

  interfaceGas(corteSW,dSW1,!dGas,excTemp);
  
  delay(MQ_DELAY);//Retardo aplicado para actualizar informacion
}

//Calcula la temperatura ambiente en base a la señal del sensor recibida
float convertTemp(int ADC_Snsr)
{
  float millivolts = (ADC_Snsr / 1023.0) * 5000;
  float celsius = millivolts / 10; 
  
  return celsius;
}

//Interface en donde el sistema decide que decisiones tomar en base a las entradas por usuario y sensores
void interfaceGas(bool SW0, bool SW1, bool SG0, bool ST0)
{
  lcd.clear(); //Borra el contenido de la pantalla LCD
  lcd.home(); //Situamos cursor en posicion (0,0).
  
  //Estado normal
  if(SW0==0 && SG0==0 && ST0==0)
  {
    lcd.print(" STATUS: NORMAL ");
    lcd.setCursor(0,1); //Situa el cursor en el primer caracter de la fila inferior de la pantalla
    lcd.print(" T. Amb.: ");
    lcd.print(tempAmb);
    lcd.print("C");
                
    Serial.println(" STATUS: NORMAL ");
    Serial.print(" T. Amb.: ");
    Serial.print(tempAmb);
    Serial.println("C");

    digitalWrite(GLEDDPIN,HIGH); //LED Verde encendido
    digitalWrite(RLEDDPIN,LOW); //LED Rojo apagado

    digitalWrite(REL_DPIN,HIGH); //Activa el gas
  }
  //Si presiona el usuario ambas teclas error.
  else if(SW0==1 && SW1==1)
  {
    lcd.print("    ERROR!!!    ");
    lcd.setCursor(0,1); //Situa el cursor en el primer caracter de la fila inferior de la pantalla
    lcd.print(" Pres. un Switch");

    Serial.println("    ERROR!!!    ");
    Serial.println(" Pres. un Switch");

    digitalWrite(GLEDDPIN,LOW); //LED Verde apagado
    digitalWrite(RLEDDPIN,HIGH); //LED Rojo encendido

  }
  //En caso de un motivo de corte de gas, muestra cual es el problema
  else
  {
    lcd.print("   PELIGRO!!!   ");
    lcd.setCursor(0,1); //Situa el cursor en el primer caracter de la fila inferior de la pantalla
    lcd.print("Sw: ");
    lcd.print(SW0);
    lcd.print(" Ga: ");
    lcd.print(SG0);
    lcd.print(" T: ");
    lcd.print(ST0);

    Serial.println("   PELIGRO!!!   ");
    Serial.print("Sw: ");
    Serial.print(SW0);
    Serial.print(" Ga: ");
    Serial.print(SG0);
    Serial.print(" T: ");
    Serial.print(ST0);

    digitalWrite(GLEDDPIN,LOW); //LED Verde apagado
    digitalWrite(RLEDDPIN,HIGH); //LED Rojo encendido
    
    digitalWrite(REL_DPIN,LOW); //Desactiva el gas

    if(ST0==1) //En caso de corte de gas por exceso de temperatura ambiente, espera 10 segundos antes de tomar otra lectura. Evita comando inestable en la valvula con el valor limite.
      delay(10000);
  }
}
