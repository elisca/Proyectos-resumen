#include <Keypad.h>//Libreria para teclados matriciales

//Constantes para definir dimensiones del teclado
const byte FILAS = 4;
const byte COLUMNAS = 4;

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
}

void loop() {
  char customKey = customKeypad.getKey();//Revisa si fue presionada una tecla

  //Si fue presionada una tecla la muestra
  if(customKey){
    Serial.println(customKey);//Muestra la tecla

    switch(customKey){//Segun la tecla acciona
        case 'A':
          Serial.println("Presionaste tecla A");
          break;
        default:
          Serial.println("Presionaste otra tecla");
    }
  }
}
