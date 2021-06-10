#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

/** \brief Muestra un array de numeros enteros, con posibilidad de debug y pausar cada cierta cantidad de elementos mostrados.
 *
 * \param array int* Array de numeros enteros.
 * \param cantidad int Cantidad de elementos del array.
 * \param debug int 0 Sin Debug,1 Con Debug.
 * \param conPausa int 0 Sin Pausa,1 Con Pausa.
 * \param pausaCantLineas int Cantidad de lineas a mostrar antes de pausar.
 * \return int -1 Error,0 OK.
 *
 */
int mostrarArrayEPublicacion(int* array,int cantidad,int debug,int conPausa,int pausaCantLineas);

/** \brief Carga secuencialmente un array de numeros enteros.
 *
 * \param intArray int* Array de numeros tipo entero.
 * \param qtyArrayElem int Cantidad de elementos del array.
 * \param numMin int Numero minimo permitido.
 * \param numMax int Numero maximo permitido.
 * \return int -1 Error,0 OK.
 *
 */
int loadIntArrayElements(int* intArray,int qtyArrayElem,int numMin,int numMax);

/** \brief Carga secuencialmente un array de numeros flotantes.
 *
 * \param floatArray float* Array de numeros flotantes.
 * \param qtyArrayElem int Cantidad de elementos del array.
 * \param numMin float Numero minimo permitido.
 * \param numMax float Numero maximo permitido.
 * \return int -1 Error,0 OK.
 *
 */
int loadFloatArrayElements(float* floatArray,int qtyArrayElem,float numMin,float numMax);

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

/** \brief Calcula el promedio de un array de numeros flotantes.
 *
 * \param floatArray float* Array de numeros flotantes.
 * \param qtyArrayElem int Cantidad de elementos del array.
 * \param promElem float* Devuelve el promedio calculado.
 * \return int -1 Error,0 OK.
 *
 */
int promFloatArrayElements(float* floatArray,int qtyArrayElem,float* promElem);

/** \brief Muestra en consola los valores de los elementos de un array de numeros enteros.
 *
 * \param array int* Array de numeros enteros a mostrar.
 * \param cantidad int Cantidad de elementos del array.
 * \return int 0-Predeterminado y unico valor.
 *
 * MODIFICAR: La funcion deberia comprobar errores.
 */
int mostrarArrayInt(int * array,int cantidad);

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
int buscarPrimeraOcurrencia(int array[],int cantElementos,int valor);
#endif // ARRAYS_H_INCLUDED
