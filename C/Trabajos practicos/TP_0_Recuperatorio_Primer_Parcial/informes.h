#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "cliente.h"
#include "publicacion.h"

/** \brief Indica que rubros tienen la menor cantidad de publicaciones activas.
 *
 * \param arrayPublicacion EPublicacion* Array de datos tipo EPublicacion.
 * \param cantPublicacion int Cantidad de elementos del array.
 * \return int -1 Error,0 OK.
 *
 */
int informes_contarMinRubroPubliActivas(EPublicacion* arrayPublicacion,int cantPublicacion);

/** \brief Indica que rubros tienen la mayor cantidad de publicaciones activas.
 *
 * \param arrayPublicacion EPublicacion* Array de datos tipo EPublicacion.
 * \param cantPublicacion int Cantidad de elementos del array.
 * \return int -1 Error,0 OK.
 *
 */
int informes_contarMaxRubroPubliActivas(EPublicacion* arrayPublicacion,int cantPublicacion);

/** \brief Cuenta la cantidad de publicaciones activas de un rubro en especifico que solicita el usuario.
 *
 * \param arrayPublicacion EPublicacion*
 * \param cantPublicacion int
 * \return int
 *
 */
int informes_contarPubliActivasRubroEspecifico(EPublicacion* arrayPublicacion,int cantPublicacion);

/** \brief Muestra clientes que poseen la mayor cantidad de publicaciones en un estado determinado.
 *
 * \param arrayCliente ECliente*
 * \param cantCliente int
 * \param arrayPublicacion EPublicacion*
 * \param cantPublicacion int
 * \param estadoPublicacion int
 * \return int
 *
 */
int informes_mostrarMaxClienteAvisos(ECliente* arrayCliente,int cantCliente,EPublicacion* arrayPublicacion,int cantPublicacion,int estadoPublicacion);

/** \brief Muestra las publicaciones activas de todos los clientes.
 *
 * \param arrayCliente ECliente* Array de datos tipo ECliente.
 * \param cantCliente int Cantidad de elementos del array tipo ECliente.
 * \param arrayPublicacion EPublicacion* ECliente* Array de datos tipo EPublicacion.
 * \param cantPublicacion int Cantidad de elementos del array tipo EPublicacion.
 * \param conPausa int 0 Sin Pausa,1 Con Pausa.
 * \param pausaCantLineas int Cantidad de lineas a ser listadas antes de aplicar pausa.
 * \return int -1 Error,0 OK.
 *
 */
int informes_mostrarPublicacionesActivas(ECliente* arrayCliente,int cantCliente,EPublicacion* arrayPublicacion,int cantPublicacion,int conPausa,int pausaCantLineas);

/** \brief Cuenta la cantidad de avisos activos que posee cada cliente en alta.
 *
 * \param arrayCliente ECliente* Array de datos tipo ECliente.
 * \param cantCliente int Cantidad de elementos del array tipo ECliente.
 * \param arrayPublicacion EPublicacion* Array de datos tipo EPublicacion.
 * \param cantPublicacion int Cantidad de elementos del array tipo EPublicacion.
 * \return int -1 Error,0 OK.
 *
 */
int informes_contarAvisosClientes(ECliente* arrayCliente,int cantCliente,EPublicacion* arrayPublicacion,int cantPublicacion);

/** \brief Cuenta la cantidad de numeros que pertenecen a un rango determinado.
 *
 * \param arrayInt int* Array de numeros enteros a analizar.
 * \param qtyArrayInt int Cantidad de elementos del array.
 * \param valorLimite int Numero desde donde empieza o termina el rango a buscar.
 * \param buscarSuperior int -1 Cuenta unicamente al valor limite(Solo busca ese numero), 0 Cuenta todos los numeros inferiores al valor limite,1 Cuenta todos los numeros superiores al valor limite.
 * \param incluirLimite int 0 No incluye al valor limite dentro del rango a buscar,1 Incluye al valor limite dentro del rango a buscar.
 * \return int Retorna la cantidad de numeros encontrados dentro del rango especificado.
 *
 */
int informes_contadorRangosArrayInt(int* arrayInt,int qtyArrayInt,int valorLimite,int buscarSuperior,int incluirLimite);

/** \brief Cuenta la cantidad de numeros flotantes que pertenecen a un rango determinado.
 *
 * \param arrayFloat float* Array de numeros flotantes a analizar.
 * \param qtyArrayInt int Cantidad de elementos del array.
 * \param valorLimite float Numero desde donde empieza o termina el rango a buscar.
 * \param buscarSuperior int -1 Cuenta unicamente al valor limite(Solo busca ese numero), 0 Cuenta todos los numeros inferiores al valor limite,1 Cuenta todos los numeros superiores al valor limite.
 * \param incluirLimite int 0 No incluye al valor limite dentro del rango a buscar,1 Incluye al valor limite dentro del rango a buscar.
 * \return int Retorna la cantidad de numeros encontrados dentro del rango especificado.
 *
 */
int informes_contadorRangosArrayFloat(float* arrayFloat,int qtyArrayInt,float valorLimite,int buscarSuperior,int incluirLimite);

/** \brief Cuenta la cantidad de numeros long que pertenecen a un rango determinado.
 *
 * \param arrayLong long* Array de numeros long a analizar.
 * \param qtyArrayInt int Cantidad de elementos del array.
 * \param valorLimite long Numero desde donde empieza o termina el rango a buscar.
 * \param buscarSuperior int -1 Cuenta unicamente al valor limite(Solo busca ese numero), 0 Cuenta todos los numeros inferiores al valor limite,1 Cuenta todos los numeros superiores al valor limite.
 * \param incluirLimite int 0 No incluye al valor limite dentro del rango a buscar,1 Incluye al valor limite dentro del rango a buscar.
 * \return int Retorna la cantidad de numeros encontrados dentro del rango especificado.
 *
 */
int informes_contadorRangosArrayLong(long* arrayLong,int qtyArrayInt,long valorLimite,int buscarSuperior,int incluirLimite);

/** \brief Busca un minimo en un array de numeros enteros.
 *
 * \param arrayInt int* Array de numeros enteros.
 * \param qtyElem int Cantidad de elementos del array.
 * \param minVal int* Devuelve el valor minimo encontrado.
 * \param idMinVal int* Devuelve el ID del array en donde se encuentra el valor minimo.
 * \return int -1 Error,0 OK.
 *
 * NOTA: Es necesario realizar el codigo de comprobacion de errores de la funcion, siempre retorna cero.
 */
int informes_buscarMinIntArray(int* arrayInt,int qtyElem,int* minVal,int* idMinVal);

/** \brief Busca el maximo en un array de numeros enteros.
 *
 * \param arrayInt int* Array de numeros enteros.
 * \param qtyElem int Cantidad de elementos del array.
 * \param maxVal int* Devuelve el valor maximo encontrado.
 * \param idMaxVal int* Devuelve el ID del array en donde se encuentra el valor maximo encontrado.
 * \return int -1 Error,0 OK.
 *
 * NOTA: Es necesario realizar el codigo de comprobacion de errores de la funcion, siempre retorna cero.
 */
int informes_buscarMaxIntArray(int* arrayInt,int qtyElem,int* maxVal,int* idMaxVal);

/** \brief Busca el minimo en un array de numeros long.
 *
 * \param arrayLong long* Array de numeros long.
 * \param qtyElem int Cantidad de elementos del array.
 * \param minVal long* Devuelve el valor minimo encontrado.
 * \param idMinVal long* Devuelve el ID del array en donde se encuentra el valor minimo encontrado.
 * \return int -1 Error,0 OK.
 *
 * NOTA: Es necesario realizar el codigo de comprobacion de errores de la funcion, siempre retorna cero.
 */
int informes_buscarMinLongArray(long* arrayLong,int qtyElem,long* minVal,long* idMinVal);

/** \brief Busca el valor maximo en un array de numeros long.
 *
 * \param arrayLong long* Array de numeros long.
 * \param qtyElem int Cantidad de elementos del array.
 * \param maxVal long* Devuelve el valor maximo encontrado.
 * \param idMaxVal long* Devuelve el ID del array en donde se encuentra el valor maximo.
 * \return int -1 Error,0 OK.
 *
 * NOTA: Es necesario realizar el codigo de comprobacion de errores de la funcion, siempre retorna cero.
 */
int informes_buscarMaxLongArray(long* arrayLong,int qtyElem,long* maxVal,long* idMaxVal);

/** \brief Busca el valor minimo encontrado en un array de numeros flotantes.
 *
 * \param arrayFloat float* Array de numeros flotantes.
 * \param qtyElem int Cantidad de elementos del array.
 * \param minVal float* Devuelve el valor minimo encontrado.
 * \param idMinVal float* Devuelve el ID del array en donde se encuentra el valor minimo encontrado.
 * \return int -1 Error,0 OK.
 *
 * NOTA: Es necesario realizar el codigo de comprobacion de errores de la funcion, siempre retorna cero.
 */
int informes_buscarMinFloatArray(float* arrayFloat,int qtyElem,float* minVal,float* idMinVal);

/** \brief Busca el valor maximo en un array de numeros flotantes.
 *
 * \param arrayFloat float* Array de numeros flotantes.
 * \param qtyElem int Cantidad de elementos del array.
 * \param maxVal float* Devuelve el valor maximo encontrado.
 * \param idMaxVal float* Devuelve la ubicacion en el array del valor maximo encontrado.
 * \return int -1 Error,0 OK.
 *
 * NOTA: Es necesario realizar el codigo de comprobacion de errores de la funcion, siempre retorna cero.
 */
int informes_buscarMaxFloatArray(float* arrayFloat,int qtyElem,float* maxVal,float* idMaxVal);
#endif // INFORMES_H_INCLUDED
