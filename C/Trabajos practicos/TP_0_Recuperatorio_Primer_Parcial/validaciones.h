#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/** \brief Verifica si una cadena de caracteres corresponde a un numero entero.
 *
 * \param str[] char Cadena de caracteres a ser analizada.
 * \return int 0-No es entero,1-Es entero.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=OW1TqB6Xzdw&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV&index=6
 */
int validaciones_esNumerico(char str[]);

/** \brief Verifica si una cadena de caracteres tiene solamente espacios y letras (mayusculas y minusculas).
 *
 * \param str[] char Cadena de caracteres a ser analizada.
 * \return int 0-No contiene unicamente espacios y letras,1-Si los contiene.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=OW1TqB6Xzdw&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV&index=6
 */
int validaciones_esSoloLetras(char str[]);

/** \brief Verifica una cadena de caracteres mostrando si esta compuesta solo por letras, espacios y/o numeros.
 *
 * \param str[] char Cadena de caracteres a ser analizada.
 * \return int 0-No contiene unicamente dichos caracteres,1-Si los contiene.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=OW1TqB6Xzdw&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV&index=6
 */
int validaciones_esAlfanumerico(char str[]);

/** \brief Verifica una cadena de caracteres indicando si es un numero de telefono.
 *
 * \param str[] char Cadena de caracteres a ser analizada.
 * \return int 0-No es un numero telefonico,1-Si lo es.
 *
 * AVISO: Se modifica la validacion de la cantidad de guiones. Esta funcion admite un guion o mas.
 *
 * LINK DE FUENTE: https://www.youtube.com/watch?v=OW1TqB6Xzdw&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV&index=6
 */
int validaciones_esTelefono(char str[]);

/** \brief Comprueba si una cadena de caracteres corresponde a un numero flotante o entero.
 *
 * \param numFlot char* Cadena de caracteres que se desea analizar.
 * \return int 0-No es un numero flotante,1-Es un numero flotante.
 *
 */
int validaciones_esFlotante(char* numFlot);

/** \brief Comprueba si la direccion de email que se ingresa es valida.
 *
 * \param direccionEmail char* Direccion de email a comprobar.
 * \param longMinUsuario int Longitud minima del nombre de usuario.
 * \param longMinDominio int Longitud minima del nombre de dominio (antes del primer punto en el dominio).
 * \return int 0-No corresponde a un email,1-Corresponde a un email.
 *
 */
int validaciones_esEmailValido(char* direccionEmail,int longMinUsuario,int longMinDominio);

/** \brief Comprueba si se trata de un posible numero de CUIT.
 *
 * \param str[] char Cadena de caracteres a comprobar.
 * \return int 0 No es CUIT,1 Podria ser CUIT.
 *
 * NOTA: Ajustar al modelo de CUITs Argentino.
 */
int validaciones_esCUIT(char str[]);

#endif // VALIDACIONES_H_INCLUDED
