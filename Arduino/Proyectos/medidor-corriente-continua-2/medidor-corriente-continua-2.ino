/*
  amp_acs712.pde
http://www.leandroruiz.com/blog/amperimetro-con-arduino/ 
He modificado la formula de modo que ahora
 Funciona muy bien.

FUENTE: https://www.diarioelectronicohoy.com/blog/sensor-de-corriente-acs712
*/

//Librerias para pantalla LCD con modulo I2C
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //

const float OFFSET = -0.26; //Desplazamiento del cero como correccion de errores
const int CANT_MUESTRAS = 500; //Cantidad de muestreos para calcular consumo promedio
const int ZERO = 512; //Valor analogico como cero absoluto de intensidad
const int ENTRADAINTE = A0; //Intensidad medida
const int SALIDARELE = 2; //Señal de salida rele
const float LIM_INT = 0.10; //Limite de consumo
const float MS_DELAY = 0.12; //Minutos de espera para habilitar carga apagada por proteccion
const int MS_CHECK = 200; //Milisegundos de espera para medir

long Sensor = 0; //Variable de lectura analogica del sensor

void setup() {
  Serial.begin(9600); 
  pinMode(ENTRADAINTE, INPUT); 
  pinMode(SALIDARELE, OUTPUT);
  digitalWrite(ENTRADAINTE, LOW); //Inhabilita la carga hasta inicializar
  Serial.println("------------------");
  Serial.println(" AMPERIMETRO DC");
  Serial.println("Max. Corriente: 30A");  
  lcd.init(); // Inicializar el LCD
  lcd.backlight(); //Encender la luz de fondo.
  lcd.setCursor(0, 0);
  lcd.print("CONSUMO PROMEDIO");  
  delay(2000);
  digitalWrite(ENTRADAINTE, HIGH); //Habilita la carga
}

void loop() {
  // Realizamos la medida
  // long Sensor = 0;
  for(int i = 0; i < CANT_MUESTRAS; i++){ 
   Sensor += analogRead(ENTRADAINTE);
  }
  Sensor /= CANT_MUESTRAS; // promedio
  float Intensidad = (5.0*(float)(Sensor-ZERO)/1024.0)*CANT_MUESTRAS/66; // la condición es
  // que el valor de Zero sea el que lee el sensor.
  Intensidad += OFFSET; //A la intensidad promedio se le agrega el offset

  if(Intensidad>LIM_INT)
  {
    digitalWrite(SALIDARELE,LOW);
    
    Serial.println("CONSUMO LIMITE EXCEDIDO!"); 
 
    lcd.setCursor(0, 1);
    lcd.print("LIMITE EXCEDIDO!");
    lcd.print("APAGADA CARGA");

    delay(MS_DELAY*1000*60);
  }
  else
  {
    digitalWrite(SALIDARELE,HIGH);

    Serial.print("Intensidad: "); 
    Serial.print(Intensidad); 
    Serial.println(" A");
 
    lcd.setCursor(0, 1);
    lcd.print("     ");
    lcd.print(Intensidad);
    lcd.print(" A       ");
    
    // Esperamos un poco
    delay(MS_CHECK);
  }
}
