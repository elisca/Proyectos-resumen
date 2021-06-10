#ifndef cliente_H_INCLUDED
#define cliente_H_INCLUDED
#include "publicacion.h"

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char CUIT[33];
    int contAvisosActivos;
    int contAvisosPausados;
    int contAvisos;
    int estado;
}ECliente;

void cliente_harcodeClientes(ECliente* arrayCliente);

/** \brief Crea una nueva publicacion solicitando todos los datos necesarios previamente.
 *
 * \param arrayCliente ECliente* Array de datos tipo ECliente.
 * \param cantCliente int Cantidad de elementos del array tipo ECliente.
 * \param arrayPublicacion EPublicacion* Array de datos tipo EPublicacion.
 * \param cantPublicacion int Cantidad de elementos del array tipo EPublicacion.
 * \return int -1 Error,0 OK.
 *
 */
int cliente_nuevaPublicacion(ECliente* arrayCliente,int cantCliente,EPublicacion* arrayPublicacion,int cantPublicacion);

/** \brief Modifica los datos de un cliente (nombre,apellido y CUIT).
 *
 * \param arrayCliente ECliente* Array de datos tipo ECliente.
 * \param cantCliente int Cantidad de elementos del array.
 * \return int -1 Error,0 OK.
 *
 */
int cliente_modificarCliente(ECliente* arrayCliente,int cantCliente);

/** \brief Solicita todos los datos necesarios para dar alta a un nuevo cliente.
 *
 * \param arrayCliente ECliente* Array de datos tipo ECliente.
 * \param cantCliente int Cantidad de elementos del array.
 * \return int -1 Error,0 OK.
 *
 */
int cliente_altaCliente(ECliente* arrayCliente,int cantCliente);

/** \brief Pide ID del cliente y lo marca en estado de baja.
 *
 * \param arrayCliente ECliente* Array de datos tipo ECliente.
 * \param cantCliente int Cantidad de elementos del array tipo ECliente.
 * \param arrayPublicacion EPublicacion* Array de datos tipo EPublicacion.
 * \param cantPublicacion int Cantidad de elementos del array tipo EPublicacion.
 * \return int -1 Error,0 OK.
 *
 */
int cliente_bajaClientexID(ECliente* arrayCliente,int cantCliente,EPublicacion* arrayPublicacion,int cantPublicacion);

/** \brief Compacta un array de tipo ECliente.
 *
 * \param array ECliente* Array de datos tipo ECliente.
 * \param tamArrayNums int Cantidad de elementos del array.
 * \param ascend int 0 Libres primero,1 Ocupados primero.
 * \return int 0 OK,-1 Error en argumentos,-2 Array sin altas.
 *
 */
int cliente_compactarECliente(ECliente* array,int tamArrayNums,int ascend);

/** \brief Comprueba si un array tipo ECliente tiene al menos un alta.
 *
 * \param lista ECliente* Array de datos tipo ECliente.
 * \param cantLista int Cantidad de elementos del array.
 * \param valorAlta int Recibe que valor numerico se toma como elemento ocupado(Alta) dentro del array a analizar.
 * \return int 0 Array vacio,1 Array con altas.
 *
 */
int cliente_arrayEClienteConAltas(ECliente* lista,int cantLista,int valorAlta);

/** \brief Ordenamiento por nombre de datos tipo ECliente mediante metodo de la burbuja.
 *
 * \param array ECliente* Array de datos tipo ECliente.
 * \param tamArrayNums int Cantidad de elementos del array.
 * \param ascend int Criterio de ordenamiento: 0 Descendente,1 Ascendente.
 * \return int -1 Error,0 OK.
 *
 */
int cliente_burbujeoMejoradoEClienteXNombres(ECliente* array,int tamArrayNums,int ascend);

/** \brief Muestra registros en el array de datos tipo ECliente.
 *
 * \param array EPublicacion* Array de datos tipo ECliente.
 * \param cantidad int Cantidad de elementos del array.
 * \param debug int 0 Sin Debug,1 Con Debug.
 * \param conPausa int 0 Sin Pausa,1 Con Pausa.
 * \param pausaCantLineas int Cantidad de lineas a mostrar antes de pausar la consola.
 * \return int -1 Error,0 OK.
 *
 */
int cliente_mostrarArrayECliente(ECliente* array,int cantidad,int debug,int conPausa,int pausaCantLineas);

/** \brief Inicializa un array de tipo ECliente.
 *
 * \param lista[] ECliente Array tipo ECliente.
 * \param cantLista int Cantidad de elementos del array.
 * \return int -1 Error,0 OK.
 *
 */
int cliente_initArrayClientes(ECliente lista[],int cantLista);

/** \brief Busca un valor dentro de un array, devolviendo en que indice se encuentra.
 *
 * \param array[] int Array de elementos de tipo entero.
 * \param cantElementos int Cantidad de elementos del array.
 * \param valor int Valor a buscar.
 * \return int Retorna el elemento en el que se encuentra el valor buscado. Si retorna -1 no se encontro el valor.
 *
 */
int cliente_buscarPrimeraOcurrenciaClientes(ECliente array[],int cantElementos,int idCliente);

/** \brief Busca el primer lugar libre del array tipo ECliente.
 *
 * \param array[] ECliente Array de tipo ECliente.
 * \param cantElementos int Cantidad de elementos del array.
 * \return int -1 Error,<id> del elemento disponible del array.
 *
 */
int cliente_buscarLibreClientes(ECliente array[],int cantElementos);
#endif // cliente_H_INCLUDED
