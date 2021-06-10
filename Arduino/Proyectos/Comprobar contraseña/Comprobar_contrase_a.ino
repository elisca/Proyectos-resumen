#include <Keypad.h>//Libreria para teclados matriciales
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //

//Constantes para definir dimensiones del teclado
const byte FILAS = 4;
const byte COLUMNAS = 4;
String cont_ingreso=""; // Contraseña ingresada
byte posIngreso=0; // Contador de caracteres ingresados (permitido hasta 8)

//Juego de caracteres personalizado
char CARACTERES[FILAS][COLUMNAS] = {
  {'1','4','7','*'},
  {'2','5','8','0'},
  {'3','6','9','#'},
  {'A','B','C','D'}
};

//Pines de matrices del teclado
byte pinesFilas[FILAS] = {5,4,3,2};
byte pinesColumnas[COLUMNAS] = {9,8,7,6};

//Instanciar juego de caracteres personalizado
Keypad customKeypad = Keypad(makeKeymap(CARACTERES), pinesFilas, pinesColumnas, FILAS, COLUMNAS);

void setup() {
  //Inicializa consola
  Serial.begin(9600);
  CancelarIngreso();

  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  MostrarPantalla("",1);
}

//Reinicia el ingreso de caracteres
void CancelarIngreso(){
   posIngreso=0;
   cont_ingreso="";
}

//Reinicia la pantalla y muestra el string del parametro
void MostrarPantalla(String texto, int fila){
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("   Contrasena   ");
  lcd.setCursor(fila, 1);
  lcd.print(texto);
}

void loop() {
  char customKey = customKeypad.getKey();//Revisa si fue presionada una tecla

  //Si fue presionada una tecla la muestra
  if(customKey){
    switch(customKey){//Segun la tecla acciona
        case '#'://Comprobar una contraseña
          if(cont_ingreso.compareTo("10AD")==0){
            MostrarPantalla("  Clave OK!!!   ",1);
            Serial.println("Contraseña correcta.");
          }
          else{
            MostrarPantalla("  Clave mal!!!  ",1);
            Serial.println("Contraseña incorrecta.");
          }
          posIngreso=0;
          CancelarIngreso();
          break;
        case '*'://Cancelar un ingreso
          CancelarIngreso();
          MostrarPantalla("Ing. cancelado",1);
          Serial.println("Ingreso cancelado.");
          break;
        default://Ingresar un caracter
          if(posIngreso<8){
            cont_ingreso.concat(customKey);
            posIngreso++;
            MostrarPantalla(cont_ingreso,1);
            Serial.println(cont_ingreso);
          }
          else{//Excedido de los 8 caracteres permitidos
            MostrarPantalla("No mas de 8 car.",1);
            Serial.println("No se admiten mas de 8 caracteres. Continuar con *-cancelar o #-aceptar.");
          }
          break;
    }
  }
}
