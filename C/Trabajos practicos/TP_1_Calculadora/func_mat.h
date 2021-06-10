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

/** \brief Indica si un numero es entero o fraccionario.
 *
 * \param float Numero a comprobar.
 * \return int 0-Es fraccionario, 1-Es entero.
 *
 */
