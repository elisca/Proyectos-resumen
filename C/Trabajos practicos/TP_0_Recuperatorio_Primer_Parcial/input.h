#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

/** \brief Menu de opciones.
 *
 * \param listaOpciones char* Mensaje a ser mostrado para informar las opciones del menu disponible.
 * \param opcionSeleccionada int* Opcion seleccionada por el usuario.
 * \param opcMin int Valor minimo permitido de la opcion seleccionada.
 * \param opcMax int Valor maximo permitido de la opcion seleccionada.
 * \return int -1 Error,0 OK.
 *
 */
int input_menuOpciones(char* listaOpciones,int* opcionSeleccionada,int opcMin,int opcMax);

/** \brief Muestra un mensaje en pantalla y solicita responder por Si o No.
 *
 * \param textoConsulta char* Mensaje a ser mostrado.
 * \param respSi char Letra para indicar respuesta afirmativa.
 * \param respNo char Letra para indicar respuesta negativa.
 * \return 0 Responde NO,1 Responde SI.
 *
 */
int input_opcionSiNo(char* textoConsulta,char respSi,char respNo);

/** \brief Solicita al usuario una cadena de caracteres y la devuelve.
 *
 * \param mensaje[] char Mensaje a ser mostrado al solicitar la cadena de caracteres.
 * \param input[] char Devolucion de la cadena ingresada.
 * \return void
 *
 */
void input_getStringLetEsp(char mensaje[],char input[]);

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
int input_getInt(char*,char*,int,long,long,int*);

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
int input_getFloat(char* msg,char* msgE,int cIntentos,float numMin,float numMax,float* result);

/** \brief Solicita un caracter al usuario y lo devuelve.
 *
 * \param mensaje[] char Mensaje a ser mostrado cuando se solicita un caracter.
 * \return char Caracter ingresado.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=ybuFMs9qlJY&index=4&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV
 */
char input_getChar(char mensaje[]);

/** \brief Genera un numero aleatorio.
 *
 * \param desde int Numero aleatorio minimo.
 * \param hasta int Numero aleatorio maximo.
 * \param iniciar int Indica si se trata del primer numero solicitado. 1- Indica que SI.
 * \return char Retorna el numero aleatorio generado.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=ybuFMs9qlJY&index=4&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV
 */
char input_getNumeroAleatorio(int desde,int hasta,int iniciar);

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
void input_getString(char mensaje[],char input[]);

/** \brief Solicita al usuario ingresar letras y/o espacios.
 *
 * \param mensaje[] char Mensaje a ser mostrado cuando se solicita el dato al usuario.
 * \param input[] char Devuelve la cadena de caracteres ingresada por el usuario si es valida.
 * \param longMin int Longitud minima de caracteres admitida.
 * \param longMax int Longitud maxima de caracteres admitida.
 * \return int -1 Error de argumentos,-2 Error de ingreso de datos por usuario,0 OK.
 *
 */
int input_getStringLetrasEspacios(char mensaje[],char input[],int longMin,int longMax);

/** \brief Solicita al usuario ingresar una cadena de caracteres unicamente compuesta por letras.
 *
 * \param mensaje[] char Mensaje a ser mostrado cuando se solicita el dato.
 * \param input[] char  Devuelve la cadena ingresada por el usuario.
 * \param longMin int Cantidad minima de caracteres permitida.
 * \param longMax int Cantidad maxima de caracteres permitida.
 * \return int 0 OK,-1 No esta compuesto solo por letras.
 *
 */
int input_getStringLetras(char mensaje[],char input[],int longMin,int longMax);

/** \brief Solicita una cadena de caracteres al usuario y analiaz si corresponde a un dato numerico.
 *
 * \param mensaje[] char Mensaje que se mostrara al solicitar la cadena de caracteres.
 * \param input[] char Devuelve la cadena de caracteres ingresada.
 * \param minNum int Numero minimo admitido.
 * \param maxNum int Numero maximo admitido.
 * \return int 0-No corresponde a un dato numerico,1-Si corresponde.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=x4-l7zR5BEs&index=7&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV
 * AVISO: Funcion modificada.
 */
int input_getStringNumeros(char mensaje[],char input[],int minNum,int maxNum);

/** \brief Solicita una cadena de caracteres al usuario y analiaz si corresponde a un dato numerico tipo Long.
 *
 * \param mensaje[] char Mensaje que se mostrara al solicitar la cadena de caracteres.
 * \param input[] char Devuelve la cadena de caracteres ingresada.
 * \param minNum long Numero minimo admitido.
 * \param maxNum long Numero maximo admitido.
 * \return int 0-No corresponde a un dato numerico,1-Si corresponde.
 *
 */
int input_getStringNumerosLong(char mensaje[],char input[],long minNum,long maxNum);

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
int input_getInt(char*,char*,int,long,long,int*);

/** \brief Solicita una cadena de caracteres al usuario y analiaz si corresponde a un dato numerico flotante.
 *
 * \param mensaje[] char Mensaje que se mostrara al solicitar la cadena de caracteres.
 * \param input[] char Devuelve la cadena de caracteres ingresada.
 * \return int 0-No corresponde a un dato numerico flotante,1-Si corresponde.
 *
 */
int input_getStringFloat(char mensaje[],char input[]);

/** \brief Muestra en consola los valores de los elementos de un array de numeros enteros.
 *
 * \param array int* Array de numeros enteros a mostrar.
 * \param cantidad int Cantidad de elementos del array.
 * \param conPausa int <!=0> Pausa cada 20 elementos mostrados,0 Sin pausa.
 * \return int 0-Predeterminado y unico valor.
 *
 * MODIFICAR: La funcion deberia comprobar errores.
 */
int input_mostrarArrayInt(int * array,int cantidad,int conPausa);

/** \brief Inicializa con un determinado valor, un array de elementos enteros.
 *
 * \param array[] int Array de elementos entero.
 * \param cantElementos int Cantidad de elementos del array.
 * \param valor int Valor a asignar a los elementos.
 * \return void
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=x4-l7zR5BEs&index=7&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV
 */
void input_inicializarArrayInt(int array[],int cantElementos,int valor);

/** \brief Carga secuencialmente un array de numeros enteros.
 *
 * \param intArray int* Array de numeros enteros.
 * \param qtyArrayElem int Cantidad de elementos del array.
 * \return int -1 Error,0 OK.
 *
 */
int input_loadIntArrayElements(int* intArray,int qtyArrayElem);

/** \brief Solicita numero de CUIT al usuario.
 *
 * \param mensaje[] char Mensaje a ser mostrado cuando solicita el dato.
 * \param input[] char Devuelve el CUIT ingresado por el usuario.
 * \param longMin int Cantidad minima de caracteres permitidos.
 * \param longMax int Cantidad maxima de caracteres permitidos.
 * \return int -1 Error,0 OK.
 *
 * NOTA: Si no se trata de un posible CUIT, no devuelve la cadena ingresada por el usuario.
 */
int input_getStringCUIT(char mensaje[],char input[],int longMin,int longMax);
#endif // INPUT_H_INCLUDED
