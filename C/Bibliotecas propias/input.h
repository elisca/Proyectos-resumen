#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

/** \brief Solicita al usuario ingresar letras y/o espacios.
 *
 * \param mensaje[] char Mensaje a ser mostrado cuando se solicita el dato al usuario.
 * \param input[] char Devuelve la cadena de caracteres ingresada por el usuario si es valida.
 * \param longMin int Longitud minima de caracteres admitida.
 * \param longMax int Longitud maxima de caracteres admitida.
 * \return int -1 Error de argumentos,-2 Error de ingreso de datos por usuario,0 OK.
 *
 */
//int getStringLetrasEspacios(char mensaje[],char input[],int longMin,int longMax);

/** \brief Muestra un mensaje por pantalla y pide cargar un numero entero.
 *
 * \param char* Mensaje predeterminado a mostrar al pedir un numero.
 * \param char* Mensaje de error.
 * \param int Cantidad maxima de intentos de ingreso admitidos.
 * \param long Numero minimo admitido.
 * \param long Numero maximo admitido.
 * \param int* Puntero a entero de la variable en la que se desea guardar el entero ingresado por el usuario.
 * \return int 0-No hay errores, -1-Hay errores.
 *
 */
int getInt(char*,char*,int,long,long,int*);

/** \brief Solicita un numero flotante al usuario y lo devuelve.
 *
 * \param msg char* Mensaje a ser mostrado al solicitar el numero.
 * \param msgE char* Mensaje de error a ser mostrado en caso de recibir un valor no valido.
 * \param cIntentos int Cantidad maxima de intentos de ingreso erroneos admitida.
 * \param numMin float Numero minimo permitido al usuario.
 * \param numMax float Numero maximo permitido al usuario.
 * \param result float* Devuelve el numero flotante ingresado por el usuario.
 * \return int -1 Error,0 OK.
 *
 */
int getFloat(char* msg,char* msgE,int cIntentos,float numMin,float numMax,float* result);

/** \brief Solicita un caracter al usuario y lo devuelve.
 *
 * \param mensaje[] char Mensaje a ser mostrado cuando se solicita un caracter.
 * \return char Caracter ingresado.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=ybuFMs9qlJY&index=4&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV
 */
char getChar(char mensaje[]);

/** \brief Genera un numero aleatorio.
 *
 * \param desde int Numero aleatorio minimo.
 * \param hasta int Numero aleatorio maximo.
 * \param iniciar int Indica si se trata del primer numero solicitado. 1- Indica que SI.
 * \return char Retorna el numero aleatorio generado.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=ybuFMs9qlJY&index=4&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV
 */
char getNumeroAleatorio(int desde,int hasta,int iniciar);

/** \brief Toma una cadena de caracteres plano(sin espacios) y la devuelve.
 *
 * \param mensaje[] char Mensaje a mostrar cuando solicita ingresar una cadena de caracteres.
 * \param input[] char Devuelve la cadena de caracteres.
 * \return void
 *
 * AVISO: Se agrega limpieza del buffer de entrada.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=x4-l7zR5BEs&index=7&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV
 */
void getString(char mensaje[],char input[]);

/** \brief Solicita una cadena de caracteres compuesta unicamente por letras y la devuelve.
 *
 * \param mensaje[] char Mensaje a ser mostrado cuando se solicita una cadena de caracteres.
 * \param input[] char Devuelve la cadena de caracteres ingresada.
 * \return int 0-No es una cadena de caracteres unicamente compuesta por letra,1-Lo es.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=x4-l7zR5BEs&index=7&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV
 */
int getStringLetras(char mensaje[],char input[]);

/** \brief Solicita una cadena de caracteres al usuario y analiaz si corresponde a un dato numerico.
 *
 * \param mensaje[] char Mensaje que se mostrara al solicitar la cadena de caracteres.
 * \param input[] char Devuelve la cadena de caracteres ingresada.
 * \return int 0-No corresponde a un dato numerico,1-Si corresponde.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=x4-l7zR5BEs&index=7&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV
 */
int getStringNumeros(char mensaje[],char input[]);

/** \brief Solicita una cadena de caracteres al usuario y analiaz si corresponde a un dato numerico flotante.
 *
 * \param mensaje[] char Mensaje que se mostrara al solicitar la cadena de caracteres.
 * \param input[] char Devuelve la cadena de caracteres ingresada.
 * \return int 0-No corresponde a un dato numerico flotante,1-Si corresponde.
 *
 */
int getStringFloat(char mensaje[],char input[]);
#endif // INPUT_H_INCLUDED
