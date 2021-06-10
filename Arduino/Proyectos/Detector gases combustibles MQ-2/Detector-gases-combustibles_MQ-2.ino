#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //

int pin_d_mq = 2;
int pin_a_mq = A0;

void setup() { 
  Serial.begin(9600);
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
  // Escribimos el Mensaje en el LCD.
  lcd.print("Iniciando...");
  
  pinMode(pin_d_mq, INPUT);
}


void loop() {
  boolean mq_estado = digitalRead(pin_d_mq);//Leemos el sensor
  int mq_a_valor = analogRead(pin_a_mq);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Val. Analog: ");
  lcd.print(mq_a_valor);
  
  // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
  lcd.setCursor(0, 1);

  Serial.print("Valor analógico: ");
  Serial.print(mq_a_valor);
  if(mq_estado) //si la salida del sensor es 1
  {
    Serial.println("-Sin presencia de gases combustibles");
    lcd.print("Combustible: NO");
  }
  else //si la salida del sensor es 0
  {
    Serial.println("-Con presencia de gases combustibles");
    lcd.print("Combustible: SI");
  }
  delay(500); 
}

