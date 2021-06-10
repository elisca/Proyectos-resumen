#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED

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

/** \brief Calcula el promedio en un array de numeros long.
 *
 * \param longArray long* Array de numeros long.
 * \param qtyArrayElem int Cantidad de elementos del array.
 * \param promElem float* Promedio.
 * \return int -1 Error, 0 OK.
 *
 */
int promLongArrayElements(long* longArray,int qtyArrayElem,float* promElem);

/** \brief Calcula el promedio en un array de numeros flotantes.
 *
 * \param floatArray float* Array de numeros flotantes.
 * \param qtyArrayElem int Cantidad de elementos del array.
 * \param promElem float* Promedio.
 * \return int -1 Error,0 OK.
 *
 */
int promFloatArrayElements(float* floatArray,int qtyArrayElem,float* promElem);

/** \brief Acumula el total en un array de numeros enteros.
 *
 * \param intArray int* Array de numeros enteros.
 * \param qtyArrayElem int Cantidad de elementos del array.
 * \param totalElem int* Acumulacion, total.
 * \return int -1 Error,0 OK.
 *
 */
int totalIntArrayElements(int* intArray,int qtyArrayElem,int* totalElem);

/** \brief Acumula el total en un array de numeros long.
 *
 * \param longArray long* Array de numeros long.
 * \param qtyArrayElem int Cantidad de elementos del array.
 * \param totalElem long* Acumulacion, total.
 * \return int -1 Error,0 OK.
 *
 */
int totalLongArrayElements(long* longArray,int qtyArrayElem,long* totalElem);

/** \brief Acumula el total en un array de numeros float.
 *
 * \param floatArray float* Array de numeros float.
 * \param qtyArrayElem int Cantidad de elementos del array.
 * \param totalElem float* Acumulacion, total.
 * \return int -1 Error,0 OK.
 *
 */
int totalFloatArrayElements(float* floatArray,int qtyArrayElem,float* totalElem);
#endif // CALCULOS_H_INCLUDED
