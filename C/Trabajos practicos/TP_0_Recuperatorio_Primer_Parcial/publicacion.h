#ifndef publicacion_H_INCLUDED
#define publicacion_H_INCLUDED
#include "cliente.h"

typedef struct
{
    int idCliente;
    int numRubro;
    char texto[65];
    int id;
    int estado;
}EPublicacion;

void publicacion_hardcodePublicaciones(EPublicacion* arrayPublicacion);

/** \brief Cambia el estado de una publicacion a ACTIVA o PAUSADA.
 *
 * \param arrayPublicacion EPublicacion* Array de datos tipo EPublicacion.
 * \param cantPublicacion int Cantidad de elementos del array.
 * \param nuevoEstado int 1 Activada,2 Pausada.
 * \return int -1 Error,0 OK.
 *
 */
int publicacion_cambiarEstadoPublicacion(EPublicacion* arrayPublicacion,int cantPublicacion,int nuevoEstado);

/** \brief Guarda en estado de baja a todos los registros de publicaciones del ID de cliente recibido.
 *
 * \param arrayPublicacion EPublicacion* Array de datos tipo EPublicacion.
 * \param cantPublicacion int Cantidad de elementos del array tipo EPublicacion.
 * \param idCliente int ID del cliente a dar baja las publicaciones relacionadas.
 * \return int -1 Error,0 OK.
 *
 */
int publicacion_bajaPublicacionesCliente(EPublicacion* arrayPublicacion,int cantPublicacion,int idCliente);

/** \brief Muestra todas las publicaciones de un cliente.
 *
 * \param array EPublicacion* Array de tipo EPublicacion.
 * \param cantidad int Cantidad de elementos del array.
 * \param idCliente int ID del cliente a mostrar sus publicaciones.
 * \param debug int 0 Sin Debug,1 Con Debug.
 * \param conPausa int 0 Sin Pausa,1 Con Pausa.
 * \param pausaCantLineas int Cantidad de registros mostrados antes de pausar la consola.
 * \return int -1 Error,0 OK.
 *
 */
int publicacion_mostrarPublicacionesCliente(EPublicacion* array,int cantidad,int idCliente,int debug,int conPausa,int pausaCantLineas);

/** \brief Compacta un array de tipo EPublicacion.
 *
 * \param array EPublicacion* Array de datos tipo EPublicacion.
 * \param tamArrayNums int Cantidad de elementos del array.
 * \param ascend int 0 Libres primero,1 Ocupados primero.
 * \return int 0 OK,-1 Error en argumentos,-2 Array sin altas.
 *
 */
int publicacion_compactarEPublicacion(EPublicacion* array,int tamArrayNums,int ascend);

/** \brief Comprueba si un array tipo EPublicacion tiene al menos un alta.
 *
 * \param lista EPublicacion* Array de datos tipo EPublicacion.
 * \param cantLista int Cantidad de elementos del array.
 * \param valorAlta int Recibe que valor numerico se toma como elemento ocupado(Alta) dentro del array a analizar.
 * \return int 0 Array vacio,1 Array con altas.
 *
 */
int publicacion_arrayEPublicacionConAltas(EPublicacion* lista,int cantLista,int valorAlta);

/** \brief Ordenamiento por texto de datos tipo EPublicacion mediante metodo de la burbuja.
 *
 * \param array EPublicacion* Array de datos tipo EPublicacion.
 * \param tamArrayNums int Cantidad de elementos del array.
 * \param ascend int Criterio de ordenamiento: 0 Descendente,1 Ascendente.
 * \return int -1 Error,0 OK.
 *
 */
int publicacion_burbujeoMejoradoEPublicacionXNombres(EPublicacion* array,int tamArrayNums,int ascend);

/** \brief Muestra un array completo de tipo de dato EPublicacion.
 *
 * \param array EPublicacion* Array de tipo EPublicacion.
 * \param cantidad int Cantidad de elementos del array.
 * \param debug int Debug mode. 0- Desactivado,<distinto de cero>- Muestra todas las variables del array.
 * \param conPausa int <!=0>- Pausa cada (pausaCantLineas) elementos en pantalla (Desde 1 en adelante).
 * \param pausaCantLineas int Pausa cuando muestra la cantidad de registros indicados en esta variable, antes de mostrar el resto de la lista.
 * \return int -1 Error,0 OK.
 *
 */
int publicacion_mostrarArrayEPublicacion(EPublicacion* array,int cantidad,int debug,int conPausa,int pausaCantLineas);

/** \brief Inicializa un array de tipo EPublicacion.
 *
 * \param lista[] EPublicacion Array tipo EPublicacion.
 * \param cantLista int Cantidad de elementos del array.
 * \return int -1 Error,0 OK.
 *
 */
int publicacion_initArrayPublicaciones(EPublicacion lista[],int cantLista);

/** \brief Busca un valor dentro de un array, devolviendo en que indice se encuentra.
 *
 * \param array[] int Array de elementos de tipo entero.
 * \param cantElementos int Cantidad de elementos del array.
 * \param valor int Valor a buscar.
 * \return int Retorna el elemento en el que se encuentra el valor buscado. Si retorna -1 no se encontro el valor.
 *
 */
int publicacion_buscarPrimeraOcurrenciaPublicaciones(EPublicacion array[],int cantElementos,int idPublicacion);

/** \brief Busca el primer lugar libre del array tipo EPublicacion.
 *
 * \param array[] EPublicacion Array de tipo EPublicacion.
 * \param cantElementos int Cantidad de elementos del array.
 * \return int -1 Error,<id> del elemento disponible del array.
 *
 */
int publicacion_buscarLibrePublicaciones(EPublicacion array[],int cantElementos);
#endif // publicacion_H_INCLUDED
