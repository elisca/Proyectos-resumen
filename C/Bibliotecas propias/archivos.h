#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

/** \brief Comprueba si un archivo existe.
 *
 * \param path char* Ruta completa del archivo a comprobar.
 * \return int 0 Archivo Inexistente,1 Archivo existente.
 *
 * La funcion es dependiente de la libreria stdio.h.
 */
int existeArchivo(char* path);

/** \brief Indica el tamaño de un archivo (en bytes).
 *
 * \param archivo FILE* Puntero al archivo.
 * \return long int Tamaño del archivo (en bytes).
 */
long int tamArchivo(FILE* archivo);

/** \brief Desplaza el cursor de posicion en el archivo al inicio.
 *
 * \param archivo FILE* Puntero al archivo.
 * \return int -1 Error, puntero a archivo es nulo, 0 OK.
 *
 * Para correcto uso, el archivo a utilizar con esta funcion ya debe haber sido abierto previamente,
 */
int desplazarCursorInicioArchivo(FILE* archivo);

/** \brief Desplaza el cursor de posicion en el archivo al final.
 *
 * \param archivo FILE* Puntero al archivo.
 * \return int -1 Error, puntero a archivo es nulo, 0 OK.
 *
 * Para correcto uso, el archivo a utilizar con esta funcion ya debe haber sido abierto previamente,
 */
int desplazarCursorFinalArchivo(FILE* archivo);

/** \brief Desplaza el cursor de posicion del archivo hacia adelante o hacia atras la cantidad de posiciones que se indique.
 *
 * \param archivo FILE* Puntero al archivo.
 * \param cantBytes long int Cantidad de posiciones a desplazarse desde la posicion actual.
 * \param retroceder int 0-No retroceder, 1-Retroceder.
 * \return int -5 Excede el final del archivo, -4 Excede el inicio del archivo, -3 retroceder toma un valor incorrecto, -2 cantBytes toma un valor incorrecto, -1 archivo es NULL, 0 OK.
 *
 */
int desplazarCursorPosicionArchivo(FILE* archivo,long int cantBytes,int retroceder);
#endif // ARCHIVOS_H_INCLUDED
