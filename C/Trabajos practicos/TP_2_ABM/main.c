//ERROR: Cuando se ingreso un DNI y luego se le dio la baja, posteriormente se vuelve a dar alta. Cuando se quiere dar baja por segunda vez no lo encuentra.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define QTY_PERSONAS 10
#define F_ESTADO_LIBRE 0
#define F_ESTADO_OCUPADO 1

int main()
{
    EPersona arrayPersonas[QTY_PERSONAS]; //Array de estructuras EPersona.
    char seguir='s'; //Menu de opciones, continuar o salir del mismo.
    char auxCharPersonas[255]; //Auxiliar para ingreso por teclado de caracteres.
    int opcion=0; //Opcion seleccionada por el usuario.
    int auxRetornos; //Auxiliar para retorno de distintas funciones a lo largo del programa.
    int idActualArray; //Elemento del array que se utiliza en ese momento para carga de datos.
    int auxIntPersonas; //Auxiliar para usos varios de numeros enteros.
    int auxDNIelem; //Auxiliar del elemento actual del array para bajas de DNI. Utilizo para comprobar si ya existe ese DNI.

    //Inicializa array y los marca como espacios disponibles para carga de datos.
    auxRetornos=initArrayPersonas(arrayPersonas,QTY_PERSONAS);
    if(auxRetornos!=0)
    {
        printf("ERROR al intentar inicializar el array de persoans EPersona. Se cerrara el programa.\n");
        exit(-1);
    }

    //Menu de opcioens
    while(seguir=='s')
    {
        //Muestra las opciones disponibles y pide seleccionar una opcion.
        do
        {
            system("cls");
            printf("1- Agregar persona\n");
            printf("2- Borrar persona\n");
            printf("3- Imprimir lista ordenada por nombre\n");
            printf("4- Imprimir grafico de edades\n");
            printf("5- Salir\n\n");

            //Ingresa opcion seleccionada y valida que la opcion sea correcta.
            printf("Opcion: ");
            scanf("%d",&opcion);

            if(opcion<0 || opcion>5)
            {
                printf("ERROR, opcion incorrecta.\n");
                system("pause");
            }
        }while(opcion<0 || opcion>5);

        //Segun opcion seleccionada toma una accion.
        switch(opcion)
        {
        case 0:
                mostrarArrayEPersona(arrayPersonas,QTY_PERSONAS,1);
                break;
            //Alta Persona.
            case 1:
                //Busca primer elemento del array marcado como disponible.
                idActualArray=buscarLibre(arrayPersonas,QTY_PERSONAS);
                if(idActualArray==-1)
                {
                    printf("ERROR, base de datos llena.\n");
                    break;
                }

                //Solicita ingresar un nombre y valida que sean solo letras y/o espaciones de 3 a 255 caracteres de longitud.
                auxRetornos=getStringLetrasEspacios("Nombre: ",auxCharPersonas,3,255);
                if(auxRetornos!=0)
                {
                    printf("ERROR al intentar ingresar el nombre de la persona. Verificar que solo lean letras y espacios y que respeta el minimo de 3 caracteres y el maximo de 255.\n");
                    break;
                }
                //Guarda en el array el nombre ingresado
                strcpy(arrayPersonas[idActualArray].nombre,auxCharPersonas);

                //Solicita ingresar la edad y valida que sean numeros desde 0 a 130.
                auxRetornos=getStringNumeros("Edad: ",auxCharPersonas,0,130);
                if(auxRetornos!=0)
                {
                    printf("ERROR al intentar ingresar la edad de la persona. Verificar que solo sean numeros comprendidos entre 0 y 130.\n");
                    break;
                }
                //Castea edad a entero y guarda el valor en el array
                auxIntPersonas=atoi(auxCharPersonas);
                arrayPersonas[idActualArray].edad=auxIntPersonas;

                //Solicita al usuario ingresar DNI y lo valida, numerico desde 0 a 999999999.
                auxRetornos=getStringNumeros("DNI: ",auxCharPersonas,0,999999999);
                if(auxRetornos!=0)
                {
                    printf("ERROR al intentar ingresar el DNI de la persona. Verificar que solo sean numeros comprendidos entre 0 y 999999999.\n");
                    break;
                }
                //Castea DNI
                auxIntPersonas=atoi(auxCharPersonas);

                //Se comprueba que el DNI que se guardara no este dado de alta de antemano en otro registro.
                auxDNIelem=buscarPrimeraOcurrencia(arrayPersonas,QTY_PERSONAS,auxIntPersonas);
                if(auxDNIelem!=-1 && arrayPersonas[auxDNIelem].estado)
                {
                    printf("ERROR, el DNI que se intenta ingresar ya existe.\n");
                    break;
                }
                //Almacena el DNI en el array
                arrayPersonas[idActualArray].dni=auxIntPersonas;

                //Indica que este elemento del array esta ocupado.
                arrayPersonas[idActualArray].estado=F_ESTADO_OCUPADO;

                break;
            //Baja Persona.
            case 2:
                //Comprueba si el array tiene altas.
                auxRetornos=arrayEPersonaConAltas(arrayPersonas,QTY_PERSONAS,F_ESTADO_OCUPADO);
                if(!auxRetornos)
                {
                    printf("ERROR array sin altas!.\n");
                    break;
                }

                //Solicita el DNI a ser dado de baja.
                auxRetornos=getStringNumeros("DNI: ",auxCharPersonas,0,999999999);
                if(auxRetornos!=0)
                {
                    printf("ERROR al intentar ingresar el DNI de la persona. Verificar que solo sean numeros comprendidos entre 0 y 999999999.\n");
                    break;
                }
                auxIntPersonas=atoi(auxCharPersonas);

                //Busca ese DNI en el array entre las altas.
                idActualArray=buscarPrimeraOcurrencia(arrayPersonas,QTY_PERSONAS,auxIntPersonas);
                if(idActualArray==-1 || !arrayPersonas[idActualArray].estado)
                {
                    printf("ERROR DNI inexistente. Verificar que este dado de alta o que haya sido correctamente tipeado.\n");
                    break;
                }

                //Marca como disponible ese elemento del array e informa al usuario la baja.
                arrayPersonas[idActualArray].estado=F_ESTADO_LIBRE;
                printf("DNI %d se dio de baja del sistema exitosamente.\n",auxIntPersonas);
                break;
            //Ordena el array por nombres y lo muestra.
            case 3:
                //Compacta array con estados ocupados primero, y ordena el array con el metodo de la burbuja.
                auxRetornos=compactarEPersona(arrayPersonas,QTY_PERSONAS,0);
                switch(auxRetornos)
                {
                    case 0://Sin errores.
                        auxRetornos=burbujeoMejoradoEPersonaXNombres(arrayPersonas,QTY_PERSONAS,1);
                        switch(auxRetornos)
                        {
                            case 0: //Ordenamiento sin errores.
                                mostrarArrayEPersona(arrayPersonas,QTY_PERSONAS,0);
                                break;
                            case -1: //Error en algun valor de algun argumento de la funcion de ordenamiento.
                                printf("ERROR, algun argumento de la funcion de ordenamiento esta incorrecto.\n");
                                break;
                            case -2: //Array sin altas, no se puede ordenar.
                                printf("ERROR, el array no tiene altas!.\n");
                                break;
                        }
                        break;
                    case -1://Error, argumentos de funcion incorrectos.
                        printf("ERROR al intentar compactar el array, argumentos incorrectos en la funcion.\n");
                        break;
                    case -2://Error, no hay elementos en alta.
                        printf("ERROR al intentar compactar el array, no se encontraron elementos en alta.\n");
                        break;
                }

                break;
            //Grafico de edades.
            case 4:
                auxRetornos=graficoGruposEdades(arrayPersonas,QTY_PERSONAS,'*');
                switch(auxRetornos)//Devuelve CERO y grafica si no hay errores.
                {
                    case -1://Error en cantidad de elementos del array que se ingresa en el argumento.
                        printf("ERROR, la cantidad de elementos del array que se recibe es incorrecta.\n");
                        break;
                    case -2://Error en el puntero al array, es NULL.
                        printf("ERROR, el puntero al array es NULL.\n");
                        break;
                    case -3://Error, el caracter grafico que se pide usar en el argumento es un espacio.
                        printf("ERROR, el caracter grafico con el que se pide graficar es un espacio.\n");
                        break;
                    case -4://Error, array sin altas.
                        printf("ERROR, el array no tiene altas!.\n");
                        break;
                }
                break;
            //Salir.
            case 5:
                //Pide responder desea salir, y valida la respuesta.
                do
                {
                    seguir=getChar("Desea continuar? (S/N): ");
                    seguir=tolower(seguir);
                }
                while(seguir!='s' && seguir!='n');
                break;
        }
        system("pause");
    }
    return 0;
}
