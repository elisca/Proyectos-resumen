#ifndef ORDENAMIENTO_H_INCLUDED
#define ORDENAMIENTO_H_INCLUDED

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

#endif // ORDENAMIENTO_H_INCLUDED
