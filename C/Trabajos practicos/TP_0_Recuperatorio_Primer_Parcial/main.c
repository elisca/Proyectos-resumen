#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h" //Funciones del array de clientes.
#include "publicacion.h" //Funciones del array de publicaciones.
#include "validaciones.h" //Funciones varias para validar datos varios.
#include "input.h"
#include "informes.h"

#define QTY_CLIENTES 100 //Capacidad de clientes en base de datos
#define QTY_PUBLICACIONES 1000 //Capacidad de publicaciones en base de datos
#define F_ESTADO_LIBRE 0 //Registro en estado disponible
#define F_ESTADO_OCUPADO 1 //Registro en estado activo
#define F_ESTADO_PAUSADO 2 //Registro en estado pausado

//Funcion principal
int main()
{
    //Variables de programa
    char seguir='s'; //Menu de opciones, continuar o salir del mismo y terminar el programa.
    int opcion=0; //Opcion seleccionada por el cliente.

    //Variables de Clientes
    ECliente arrayClientes[QTY_CLIENTES]; //Array de estructuras ECliente.
    int auxRetornosClientes; //Auxiliar para retorno de distintas cliente a lo largo del programa.

    //Variables de Publicaciones
    EPublicacion arrayPublicaciones[QTY_PUBLICACIONES]; //Array de estructuras ECliente.
    int auxRetornosPublicaciones; //Auxiliar para retorno de distintas cliente a lo largo del programa.

    //Inicializa array y los marca como espacios disponibles para carga de datos.
    auxRetornosClientes=cliente_initArrayClientes(arrayClientes,QTY_CLIENTES);
    if(auxRetornosClientes!=0)
    {
        printf("ERROR al intentar inicializar el array de clientes ECliente. Se cerrara el programa.\n");
        exit(-1);
    }

    //Inicializa array y los marca como espacios disponibles para carga de datos.
    auxRetornosPublicaciones=publicacion_initArrayPublicaciones(arrayPublicaciones,QTY_PUBLICACIONES);
    if(auxRetornosPublicaciones!=0)
    {
        printf("ERROR al intentar inicializar el array de publicaciones EPublicacion. Se cerrara el programa.\n");
        exit(-1);
    }

    //Menu de opcioens
    while(seguir=='s')
    {
        if(input_menuOpciones("1- Agregar Cliente\n2- Modificar Cliente\n3- Baja Cliente\n4- Agregar Publicacion\n5- Pausar Publicacion\n6- Reanudar Publicacion\n7- Imprimir Clientes\n8- Imprimir Publicaciones\n9- Informar Clientes\n10- Informar Publicacion\n11- Salir\n\n",&opcion,1,11)!=0)
            printf("ERROR, opcion incorrecta.\n");
        //Segun opcion seleccionada toma una accion.
        switch(opcion)
        {
            case 1:
                cliente_altaCliente(arrayClientes,QTY_CLIENTES); //Solicita datos y da alta de cliente
                break;
            case 2:
                cliente_modificarCliente(arrayClientes,QTY_CLIENTES); //Solicita datos y modificar cliente
                break;
            case 3:
                cliente_bajaClientexID(arrayClientes,QTY_CLIENTES,arrayPublicaciones,QTY_PUBLICACIONES); //Solicita datos y da baja Cliente
                break;
            case 4:
                cliente_nuevaPublicacion(arrayClientes,QTY_CLIENTES,arrayPublicaciones,QTY_PUBLICACIONES); //Solicita datos y realiza una nueva Publicacion
                break;
            case 5:
                publicacion_cambiarEstadoPublicacion(arrayPublicaciones,QTY_PUBLICACIONES,F_ESTADO_PAUSADO); //Solicita datos y pausa Publicacion
                break;
            case 6:
                publicacion_cambiarEstadoPublicacion(arrayPublicaciones,QTY_PUBLICACIONES,F_ESTADO_OCUPADO); //Solicita datos y reanuda una publicacion
                break;
            case 7:
                informes_contarAvisosClientes(arrayClientes,QTY_CLIENTES,arrayPublicaciones,QTY_PUBLICACIONES); //Informa la cantidad de avisos activos y pausados, y muestra a los clientes
                if(cliente_mostrarArrayECliente(arrayClientes,QTY_CLIENTES,0,1,20)!=0)
                    printf("Error.\n");
                break;
            case 8:
                informes_mostrarPublicacionesActivas(arrayClientes,QTY_CLIENTES,arrayPublicaciones,QTY_PUBLICACIONES,1,100); //Informa todas las publicaciones activas y el CUIT de su cliente
                break;
            case 9:
                if(input_menuOpciones("ELIJA ENTRE EL SUBMENU DE OPCIONES:\n\t1- Cliente/s con mas avisos activos\n\t2- Cliente/s con mas avisos pausados\n\t3- Cliente/s con mas avisos\n\n",&opcion,1,3)!=0) //Submenu de opciones a mostrar
                    printf("ERROR, opcion incorrecta.\n");

                switch(opcion)
                {
                    case 1:
                        informes_mostrarMaxClienteAvisos(arrayClientes,QTY_CLIENTES,arrayPublicaciones,QTY_PUBLICACIONES,F_ESTADO_OCUPADO); //Informa cliente con la mayot cantidad de avisos activos
                        break;
                    case 2:
                        informes_mostrarMaxClienteAvisos(arrayClientes,QTY_CLIENTES,arrayPublicaciones,QTY_PUBLICACIONES,F_ESTADO_PAUSADO); //Informa cliente con la mayot cantidad de avisos pausados
                        break;
                    case 3:
                        informes_mostrarMaxClienteAvisos(arrayClientes,QTY_CLIENTES,arrayPublicaciones,QTY_PUBLICACIONES,0); //Informa cliente con la mayot cantidad de avisos activos y pausados
                        break;
                }
                break;
            case 10:
                if(input_menuOpciones("ELIJA ENTRE EL SUBMENU DE OPCIONES:\n\t1- Cantidad de publicaciones de un rubro activas\n\t2- Rubro con mayor cantidad de publicaciones activas\n\t3- Rubro con menor cantidad de publicaciones activas\n\n",&opcion,1,3)!=0) //Submenu de opciones
                    printf("ERROR, opcion incorrecta.\n");

                switch(opcion)
                {
                    case 1:
                        informes_contarPubliActivasRubroEspecifico(arrayPublicaciones,QTY_PUBLICACIONES); //Informa cantidad de publicaciones de un rubro especifico
                        break;
                    case 2:
                        informes_contarMaxRubroPubliActivas(arrayPublicaciones,QTY_PUBLICACIONES); //Informa rubro con mayor cantidad de publicaciones activas.
                        break;
                    case 3:
                        informes_contarMinRubroPubliActivas(arrayPublicaciones,QTY_PUBLICACIONES); //Informa rubro con menor cantidad de publicaciones activas.
                        break;
                }

                break;
            case 11:
                if(input_opcionSiNo("Desea salir del programa? (S/N): ",'S','N')) //Menu salir del programa.
                return 0;
        }
        system("pause");
    }

    return 0;
}
