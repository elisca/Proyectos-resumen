#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //

int pin_a_pot=A1;
int val_pot;

void setup() {
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
}

void loop() {
  val_pot=analogRead(pin_a_pot)/4; 
   // Escribimos el número de segundos trascurridos
  lcd.clear();
  lcd.print("Val. Analog.: ");
  lcd.print(val_pot);
  delay(500);
}

