#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado; //Tomamos flag en 0-Libre,1-Ocupado.
    int dni;

}EPersona;

/** \brief Compacta un array de tipo EPersona.
 *
 * \param array EPersona* Array de datos tipo EPersona.
 * \param tamArrayNums int Cantidad de elementos del array.
 * \param ascend int 0 Libres primero,1 Ocupados primero.
 * \return int 0 OK,-1 Error en argumentos,-2 Array sin altas.
 *
 */
int compactarEPersona(EPersona* array,int tamArrayNums,int ascend);

/** \brief Comprueba si un array tipo EPersona tiene al menos un alta.
 *
 * \param lista EPersona* Array de datos tipo EPersona.
 * \param cantLista int Cantidad de elementos del array.
 * \param valorAlta int Recibe que valor numerico se toma como elemento ocupado(Alta) dentro del array a analizar.
 * \return int 0 Array vacio,1 Array con altas.
 *
 */
int arrayEPersonaConAltas(EPersona* lista,int cantLista,int valorAlta);

/** \brief Grafica con caracteres la cantidad de personas que existen en la base de datos por cada grupo de edades.
 *
 * \param array EPersona* Array de datos tipo EPersona.
 * \param cantArray int Cantidad de elementos del array.
 * \param caracterGrafico char Caracter con el que se grafica cada persona representada.
 * \return int -1 Error,0 OK.
 *
 */
int graficoGruposEdades(EPersona* array,int cantArray,char caracterGrafico);

/** \brief Ordenamiento por nombre de datos tipo EPersona mediante metodo de la burbuja.
 *
 * \param array EPersona* Array de datos tipo EPersona.
 * \param tamArrayNums int Cantidad de elementos del array.
 * \param ascend int Criterio de ordenamiento: 0 Descendente,1 Ascendente.
 * \return int -1 Error,0 OK.
 *
 */
int burbujeoMejoradoEPersonaXNombres(EPersona* array,int tamArrayNums,int ascend);

/** \brief Muestra un array completo de tipo de dato EPersona.
 *
 * \param array EPersona* Array de tipo EPersona.
 * \param cantidad int Cantidad de elementos del array.
 * \param debug int Debug mode. 0- Desactivado,<distinto de cero>- Muestra todas las variables del array.
 * \return int -1 Error,0 OK.
 *
 */
int mostrarArrayEPersona(EPersona* array,int cantidad,int debug);

/** \brief Inicializa un array de tipo EPersona.
 *
 * \param lista[] EPersona Array tipo EPersona.
 * \param cantLista int Cantidad de elementos del array.
 * \return int -1 Error,0 OK.
 *
 */
int initArrayPersonas(EPersona lista[],int cantLista);

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

/** \brief Muestra mensajes por pantalla solicitando numeros enteros para cargarlos en un array.
 *
 * \param intArray int* Array de enteros en el que se desea guardar los numeros ingresados por el usuario.
 * \param qtyArrayElem int Tamaño del array.
 * \return int 0-No hay errores, -1-Hay errores.
 *
 * Esta funcion tiene dependencia de "getInt", de esta misma libreria.
 */
int loadIntArrayElements(int* intArray,int qtyArrayElem);

/** \brief Calcula el promedio en un array de numeros enteros.
 *
 * \param intArray int* Array de numeros enteros.
 * \param qtyArrayElem int Cantidad de elementos del array.
 * \param promElem float* Promedio.
 * \return int 0-No hay errores, -1-Hay errores.
 *
 * Esta funcion tiene dependencia de "loadIntArrayElements", de esta misma libreria.
 */
int promIntArrayElements(int* intArray,int qtyArrayElem,float* promElem);

/** \brief Muestra en consola los valores de los elementos de un array de numeros enteros.
 *
 * \param array int* Array de numeros enteros a mostrar.
 * \param cantidad int Cantidad de elementos del array.
 * \return int 0-Predeterminado y unico valor.
 *
 * MODIFICAR: La funcion deberia comprobar errores.
 */
int mostrarArrayInt(int * array,int cantidad);

/** \brief Solicita un numero flotante al usuario y devuelve el resultado.
 *
 * \param mensaje[] char Mensaje a ser mostrado cuando se pide el numero.
 * \return float Numero ingresado por el usuario.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=ybuFMs9qlJY&index=4&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV
 */
float getFloat(char mensaje[]);

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

/** \brief Verifica si una cadena de caracteres corresponde a un numero entero.
 *
 * \param str[] char Cadena de caracteres a ser analizada.
 * \return int 0-No es entero,1-Es entero.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=OW1TqB6Xzdw&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV&index=6
 */
int esNumerico(char str[]);

/** \brief Verifica si una cadena de caracteres tiene solamente espacios y letras (mayusculas y minusculas).
 *
 * \param str[] char Cadena de caracteres a ser analizada.
 * \return int 0-No contiene unicamente espacios y letras,1-Si los contiene.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=OW1TqB6Xzdw&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV&index=6
 */
int esSoloLetras(char str[]);

/** \brief Verifica una cadena de caracteres mostrando si esta compuesta solo por letras, espacios y/o numeros.
 *
 * \param str[] char Cadena de caracteres a ser analizada.
 * \return int 0-No contiene unicamente dichos caracteres,1-Si los contiene.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=OW1TqB6Xzdw&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV&index=6
 */
int esAlfanumerico(char str[]);

/** \brief Verifica una cadena de caracteres indicando si es un numero de telefono.
 *
 * \param str[] char Cadena de caracteres a ser analizada.
 * \return int 0-No es un numero telefonico,1-Si lo es.
 *
 * AVISO: Se modifica la validacion de la cantidad de guiones. Esta funcion admite un guion o mas.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=OW1TqB6Xzdw&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV&index=6
 */
int esTelefono(char str[]);

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

/** \brief Solicita al usuario ingresar letras y/o espacios.
 *
 * \param mensaje[] char Mensaje a ser mostrado cuando se solicita el dato al usuario.
 * \param input[] char Devuelve la cadena de caracteres ingresada por el usuario si es valida.
 * \param longMin int Longitud minima de caracteres admitida.
 * \param longMax int Longitud maxima de caracteres admitida.
 * \return int -1 Error de argumentos,-2 Error de ingreso de datos por usuario,0 OK.
 *
 */
int getStringLetrasEspacios(char mensaje[],char input[],int longMin,int longMax);

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
 * \param minNum int Numero minimo admitido.
 * \param maxNum int Numero maximo admitido.
 * \return int 0-No corresponde a un dato numerico,1-Si corresponde.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=x4-l7zR5BEs&index=7&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV
 * AVISO: Funcion modificada.
 */
int getStringNumeros(char mensaje[],char input[],int minNum,int maxNum);

/** \brief Solicita una cadena de caracteres al usuario y analiaz si corresponde a un dato numerico tipo Long.
 *
 * \param mensaje[] char Mensaje que se mostrara al solicitar la cadena de caracteres.
 * \param input[] char Devuelve la cadena de caracteres ingresada.
 * \param minNum long Numero minimo admitido.
 * \param maxNum long Numero maximo admitido.
 * \return int 0-No corresponde a un dato numerico,1-Si corresponde.
 *
 */
int getStringNumerosLong(char mensaje[],char input[],long minNum,long maxNum);

/** \brief Inicializa con un determinado valor, un array de elementos enteros.
 *
 * \param array[] int Array de elementos entero.
 * \param cantElementos int Cantidad de elementos del array.
 * \param valor int Valor a asignar a los elementos.
 * \return void
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=x4-l7zR5BEs&index=7&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV
 */
void inicializarArrayInt(int array[],int cantElementos,int valor);

/** \brief Busca un valor dentro de un array, devolviendo en que indice se encuentra.
 *
 * \param array[] int Array de elementos de tipo entero.
 * \param cantElementos int Cantidad de elementos del array.
 * \param valor int Valor a buscar.
 * \return int Retorna el elemento en el que se encuentra el valor buscado. Si retorna -1 no se encontro el valor.
 *
 */
int buscarPrimeraOcurrencia(EPersona array[],int cantElementos,int dni);

/** \brief Busca el primer lugar libre del array tipo EPersona.
 *
 * \param array[] EPersona Array de tipo EPersona.
 * \param cantElementos int Cantidad de elementos del array.
 * \return int -1 Error,<id> del elemento disponible del array.
 *
 */
int buscarLibre(EPersona array[],int cantElementos);

/** \brief Calcula la suma entre dos numeros.
 *
 * \param op1 float Operando 1.
 * \param op2 float Operando 2.
 * \param resultado float* Puntero a flotante en donde se devuelve el resultado de la operacion.
 * \return int Codigo de errores: 0-OK, <distinto cero>-Error.
 *
 */
int matSuma(float op1,float op2,float* resultado);

/** \brief Calcula la resta entre dos numeros.
 *
 * \param op1 float Operando 1.
 * \param op2 float Operando 2.
 * \param resultado float* Puntero a flotante en donde se devuelve el resultado de la operacion.
 * \return int Codigo de errores: 0-OK, <distinto cero>-Error.
 *
 */
int matResta(float op1,float op2,float* resultado);

/** \brief Calcula el producto entre dos numeros.
 *
 * \param op1 float Operando 1.
 * \param op2 float Operando 2.
 * \param resultado float* Puntero a flotante en donde se devuelve el resultado de la operacion.
 * \return int Codigo de errores: 0-OK, <distinto cero>-Error.
 *
 */
int matMultipl(float op1,float op2,float* resultado);

/** \brief Calcula el cociente entre dos numeros.
 *
 * \param op1 float Operando 1.
 * \param op2 float Operando 2.
 * \param resultado float* Puntero a flotante en donde se devuelve el resultado de la operacion.
 * \return int Codigo de errores: 0-OK, -1-Error por divisor igual a cero.
 *
 */
int matDivision(float op1,float op2,float* resultado);

/** \brief Calcula el factorial de un numero.
 *
 * \param N int Numero a calcular.
 * \param resultado int* Puntero a entero en donde devuelve el resultado de la operacion.
 * \return int Codigo de error: 0-OK, -1-Error por numero menor a cero.
 *
 */
int matFactorial(int N,int* resultado);

/** \brief Ordena un array de numeros enteros, por metodo de burbujeo optimizado.
 *
 * \param nums int* Array de numeros enteros a ordenar.
 * \param tamArrayNums int Cantidad de elementos del array de enteros recibido.
 * \param ascend int 0-Ordenamiento ascendente,1-Ordenamiento descendente.
 * \return int 0-OK,-1-Error.
 *
 */
int burbujeoMejoradoInt(int* nums,int tamArrayNums,int ascend);

/** \brief Ordena un array de numeros enteros, por metodo de burbujeo.
 *
 * \param nums int* Array de numeros enteros a ordenar.
 * \param tamArrayNums int Cantidad de elementos del array de enteros recibido.
 * \param ascend int 0-Ordenamiento ascendente,1-Ordenamiento descendente.
 * \return int 0-OK,-1-Error.
 *
 */
int burbujeoInt(int* nums,int tamArrayNums,int ascend);

/** \brief Realiza intercambio entre dos numeros enteros.
 *
 * \param num1 int* Numero 1 a intercambiar.
 * \param num2 int* Numero 2 a intercambiar.
 * \return int 0-OK,-1-Error.
 *
 */
int numsSwapInt(int* num1,int* num2);

/** \brief Desplaza un segmento de elementos de un array de enteros, hacia la izquierda o hacia la derecha del mismo.
 *
 * \param numsArray int* Array de numeros enteros a modificar.
 * \param cantElementosArray int Cantidad de elementos del array.
 * \param sentido int 0-Desplazar hacia la izquierda,1-Desplazar hacia la derecha.
 * \param inicioSeg int Elemento del array en donde comienza el segmento que se desea desplazar.
 * \param finalSeg int Elemento del array en donde finaliza el segmento que se desea desplazar.
 * \return int 0-OK,-1-Error.
 *
 */
int numsDesplazaSegmentosInt(int* numsArray,int cantElementosArray,int sentido,int inicioSeg,int finalSeg);

/** \brief Ordenamiento de array de numeros enteros por metodo de insercion.
 *
 * \param array int* Array de numeros enteros a ser ordenados.
 * \param cantidad int Cantidad de elementos del array.
 * \param orden int 0-Orden descendente,1-Orden ascendente.
 * \return int 0-Predeterminado y unico valor.
 *
 * MODIFICAR: La funcion deberia comprobar errores.
 */
int ordenarArrayIntInsertion(int * array,int cantidad,int ordenAscendente);

/** \brief Comprueba si una cadena de caracteres corresponde a un numero flotante o entero.
 *
 * \param numFlot char* Cadena de caracteres que se desea analizar.
 * \return int 0-No es un numero flotante,1-Es un numero flotante.
 *
 */
int esFlotante(char* numFlot);

/** \brief Comprueba si la direccion de email que se ingresa es valida.
 *
 * \param direccionEmail char* Direccion de email a comprobar.
 * \param longMinUsuario int Longitud minima del nombre de usuario.
 * \param longMinDominio int Longitud minima del nombre de dominio (antes del primer punto en el dominio).
 * \return int 0-No corresponde a un email,1-Corresponde a un email.
 *
 */
int esEmailValido(char* direccionEmail,int longMinUsuario,int longMinDominio);

/** \brief Solicita una cadena de caracteres al usuario y analiaz si corresponde a un dato numerico flotante.
 *
 * \param mensaje[] char Mensaje que se mostrara al solicitar la cadena de caracteres.
 * \param input[] char Devuelve la cadena de caracteres ingresada.
 * \return int 0-No corresponde a un dato numerico flotante,1-Si corresponde.
 *
 */
int getStringFloat(char mensaje[],char input[]);
#endif // FUNCIONES_H_INCLUDED
