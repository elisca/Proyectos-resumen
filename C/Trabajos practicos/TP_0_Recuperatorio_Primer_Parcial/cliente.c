#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cliente.h"
#include "publicacion.h"
#include "input.h"

#define QTY_CLIENTES 100
#define QTY_PUBLICACIONES 1000
#define F_ESTADO_LIBRE 0
#define F_ESTADO_OCUPADO 1
#define F_ESTADO_PAUSADO 2

//Hardcodea entradas de clientes.
void cliente_harcodeClientes(ECliente* arrayCliente)
{
    arrayCliente[0].id=0;
    strcpy(arrayCliente[0].nombre,"EZEQUIEL");
    strcpy(arrayCliente[0].apellido,"LISCA");
    strcpy(arrayCliente[0].CUIT,"100");
    arrayCliente[0].estado=F_ESTADO_OCUPADO;

    arrayCliente[1].id=1;
    strcpy(arrayCliente[1].nombre,"ARIEL");
    strcpy(arrayCliente[1].apellido,"LISCA");
    strcpy(arrayCliente[1].CUIT,"101");
    arrayCliente[1].estado=F_ESTADO_OCUPADO;

    arrayCliente[2].id=2;
    strcpy(arrayCliente[2].nombre,"VIVIANA");
    strcpy(arrayCliente[2].apellido,"SCIUME");
    strcpy(arrayCliente[2].CUIT,"102");
    arrayCliente[2].estado=F_ESTADO_OCUPADO;

    arrayCliente[3].id=3;
    strcpy(arrayCliente[3].nombre,"ADRIAN");
    strcpy(arrayCliente[3].apellido,"LISCA");
    strcpy(arrayCliente[3].CUIT,"103");
    arrayCliente[3].estado=F_ESTADO_OCUPADO;

    arrayCliente[4].id=4;
    strcpy(arrayCliente[4].nombre,"GUSTAVO");
    strcpy(arrayCliente[4].apellido,"SCIUME");
    strcpy(arrayCliente[4].CUIT,"104");
    arrayCliente[4].estado=F_ESTADO_OCUPADO;

    arrayCliente[5].id=5;
    strcpy(arrayCliente[5].nombre,"FAST");
    strcpy(arrayCliente[5].apellido,"FOOD");
    strcpy(arrayCliente[5].CUIT,"30-65493641-9");
    arrayCliente[5].estado=F_ESTADO_OCUPADO;
}

//Agrega una nueva publicacion en el array solicitando sus datos.
int cliente_nuevaPublicacion(ECliente* arrayCliente,int cantCliente,EPublicacion* arrayPublicacion,int cantPublicacion)
{
    static int proximoIdPublicacion=0;
    int idActualArrayPublicacion,idActualArrayCliente;
    char auxCharPublicacion[255];
    int auxIntPublicacion;

    //Busca elemento del array de clientes que se encuentre libre
    idActualArrayPublicacion=publicacion_buscarLibrePublicaciones(arrayPublicacion,cantPublicacion);
    if(idActualArrayPublicacion==-1)
    {
        printf("ERROR, base de datos llena.\n");
        return -1;
    }

    //Solicita ID del cliente y lo valida
    if(input_getStringNumeros("ID Cliente: ",auxCharPublicacion,0,cantCliente-1)!=0)
    {
        printf("ERROR en el ID de cliente. Verifique que los datos sean correctos.\n");
        return -1;
    }
    auxIntPublicacion=atoi(auxCharPublicacion);

    //Valida que el ID de cliente ingresado sea existente
    idActualArrayCliente=cliente_buscarPrimeraOcurrenciaClientes(arrayCliente,cantCliente,auxIntPublicacion);
    if(idActualArrayCliente<0)
    {
        printf("ID de cliente inexistente. Verifique que los datos sean correctos.\n");
        return -1;
    }
    arrayPublicacion[idActualArrayPublicacion].idCliente=auxIntPublicacion;

    //Solicita numero de rubro y lo valida
    auxIntPublicacion=input_getStringNumeros("N° Rubro: ",auxCharPublicacion,0,cantPublicacion-1);
    if(auxIntPublicacion!=0)
    {
        printf("ERROR en el numero de rubro. Verifique que los datos sean correctos.\n");
        return -1;
    }
    auxIntPublicacion=atoi(auxCharPublicacion);
    arrayPublicacion[idActualArrayPublicacion].numRubro=auxIntPublicacion;

    //Solicita ingresar un nombre y valida que sean solo letras desde 3 hasta 50 caracteres de longitud.
    if(input_getStringLetrasEspacios("Texto: ",auxCharPublicacion,3,64)!=0)
    {
        printf("ERROR al intentar ingresar el texto de esta publicacion. Verifique que los datos sean correctos.\n");
        return -1;
    }
    //Guarda en array el nombre ingresado
    strcpy(arrayPublicacion[idActualArrayPublicacion].texto,auxCharPublicacion);

    //Guarda el ID del usuario ingresado y calcula el proximo.
    arrayPublicacion[idActualArrayPublicacion].id=proximoIdPublicacion;
    proximoIdPublicacion++;

    //Marca ese elemento del array como ocupado.
    arrayPublicacion[idActualArrayPublicacion].estado=F_ESTADO_OCUPADO;

    printf("Publicacion enviada exitosamente. ID: %d\n",arrayPublicacion[idActualArrayPublicacion].id);

    return 0;
}

int cliente_altaCliente(ECliente* arrayCliente,int cantCliente)
{
    static int proximoIdClientes=0; //Proximo ID de Cliente
    int idActualArrayCliente;
    char auxCharClientes[255];

    //Busca elemento del array de clientes que se encuentre libre
    idActualArrayCliente=cliente_buscarLibreClientes(arrayCliente,cantCliente);
    if(idActualArrayCliente==-1)
    {
        printf("ERROR, base de datos llena.\n");
        return -1;
    }

    //Solicita ingresar un nombre y valida que sean solo letras desde 3 hasta 50 caracteres de longitud.
    if(input_getStringLetras("Nombre: ",auxCharClientes,3,50)!=0)
    {
        printf("ERROR al intentar ingresar el nombre del cliente. Verificar que solo sean letras y que la longitud este comprendida entre 3 caracteres y 50 caracteres.\n");
        return -1;
    }
    //Guarda en array el nombre ingresado
    strcpy(arrayCliente[idActualArrayCliente].nombre,auxCharClientes);

    //Solicita ingresar un nombre y valida que sean solo letras desde 3 hasta 50 caracteres de longitud.
    if(input_getStringLetras("Apellido: ",auxCharClientes,3,50)!=0)
    {
        printf("ERROR al intentar ingresar el apellido del cliente. Verificar que solo sean letras y que la longitud este comprendida entre 3 caracteres y 50 caracteres.\n");
        return -1;
    }
    //Guarda en array el nombre ingresado
    strcpy(arrayCliente[idActualArrayCliente].apellido,auxCharClientes);

    //Solicita ingresar un nombre y valida que sean solo letras desde 3 hasta 50 caracteres de longitud.
    if(input_getStringCUIT("CUIT Cliente: ",auxCharClientes,3,50)!=0)
    {
        printf("ERROR al intentar ingresar el N° de CUIT cliente. Verificar que solo sean numeros y guiones y que la longitud este comprendida entre 3 caracteres y 32 caracteres.\n");
        return -1;
    }
    //Guarda en array el nombre ingresado
    strcpy(arrayCliente[idActualArrayCliente].CUIT,auxCharClientes);

    //Almacena el ID en el array
    arrayCliente[idActualArrayCliente].id=proximoIdClientes;
    proximoIdClientes++;

    printf("Alta exitosa. ID de Cliente: %d\n",arrayCliente[idActualArrayCliente].id);

    //Indica que este elemento del array esta ocupado.
    arrayCliente[idActualArrayCliente].estado=F_ESTADO_OCUPADO;

    return 0;
}

//Solicita datos y modifica un cliente.
int cliente_modificarCliente(ECliente* arrayCliente,int cantCliente)
{
    int auxIntClientes,idActualArrayClientes;
    char auxCharClientes[255];

    //Solicita y valida ID del cliente
    if(input_getStringNumeros("ID Cliente: ",auxCharClientes,0,cantCliente-1)!=0)
    {
        printf("ERROR en ID Cliente ingresado. Verifique que los datos sean correctos.\n");
        return -1;
    }
    //Casting del ID de Char a Int
    auxIntClientes=atoi(auxCharClientes);

    //Busca el elemento del ID en el array
    idActualArrayClientes=cliente_buscarPrimeraOcurrenciaClientes(arrayCliente,cantCliente,auxIntClientes);
    if(idActualArrayClientes<0)
    {
        printf("ERROR, el ID de cliente ingresado es inexistente. Verifique que los datos sean correctos.\n");
        return -1;
    }

    //Solicita ingresar un nombre y valida que sean solo letras desde 3 hasta 50 caracteres de longitud.
    if(input_getStringLetras("Nombre: ",auxCharClientes,3,50)!=0)
    {
        printf("ERROR al intentar ingresar el nombre del cliente. Verificar que solo sean letras y que la longitud este comprendida entre 3 caracteres y 50 caracteres.\n");
        return -1;
    }
    //Guarda en array el nombre ingresado
    strcpy(arrayCliente[idActualArrayClientes].nombre,auxCharClientes);

    //Solicita ingresar un nombre y valida que sean solo letras desde 3 hasta 50 caracteres de longitud.
    if(input_getStringLetras("Apellido: ",auxCharClientes,3,50)!=0)
    {
        printf("ERROR al intentar ingresar el apellido del cliente. Verificar que solo sean letras y que la longitud este comprendida entre 3 caracteres y 50 caracteres.\n");
        return -1;
    }
    //Guarda en array el nombre ingresado
    strcpy(arrayCliente[idActualArrayClientes].apellido,auxCharClientes);

    //Solicita ingresar un nombre y valida que sean solo letras desde 3 hasta 50 caracteres de longitud.
    if(input_getStringCUIT("CUIT Cliente: ",auxCharClientes,3,50)!=0)
    {
        printf("ERROR al intentar ingresar el N° de CUIT cliente. Verificar que solo sean numeros y guiones y que la longitud este comprendida entre 3 caracteres y 32 caracteres.\n");
        return -1;
    }
    //Guarda en array el nombre ingresado
    strcpy(arrayCliente[idActualArrayClientes].CUIT,auxCharClientes);

    printf("Cliente con ID %d modificado exitosamente.\n",arrayCliente[idActualArrayClientes].id);

    return 0;
}

//Solicita ID y marca ocmo baja al cliente.
int cliente_bajaClientexID(ECliente* arrayCliente,int cantCliente,EPublicacion* arrayPublicacion,int cantPublicacion)
{
    int auxIntClientes,idActualArrayClientes;
    char auxCharClientes[255];

    //ID Cliente solicita ingresar
    if(input_getStringNumeros("ID Cliente: ",auxCharClientes,0,cantCliente-1)!=0)
    {
        printf("ERROR en ID Cliente ingresado. Verifique que los datos sean correctos.\n");
        return -1;
    }
    //Casting del ID de Char a Int
    auxIntClientes=atoi(auxCharClientes);

    //Busca el elemento del ID en el array
    idActualArrayClientes=cliente_buscarPrimeraOcurrenciaClientes(arrayCliente,QTY_CLIENTES,auxIntClientes);
    if(idActualArrayClientes<0)
    {
        printf("ERROR, el ID de cliente ingresado es inexistente. Verifique que los datos sean correctos.\n");
        return -1;
    }

    //Muestra las publicaciones del cliente al que se pide la baja
    if(publicacion_mostrarPublicacionesCliente(arrayPublicacion,cantPublicacion-1,auxIntClientes,1,1,100)!=0)
    {
        printf("ERROR al intentar mostrar las publicaciones realizadas por el cliente a dar baja.\n");
        return -1;
    }

    //Consulta si eliminar al cliente y sus publicacines, en ese caso toma accion.
    if(input_opcionSiNo("Desea eliminar todos los registros y a este ID de cliente? : ",'s','n'))
    {
        if(publicacion_bajaPublicacionesCliente(arrayPublicacion,cantPublicacion-1,auxIntClientes)!=0)
        {
            printf("ERROR al intentar eliminar las publicaciones realizadas por el cliente con ID %d. Corrobe los datos e intente nuevamente.\n",auxIntClientes);
            return -1;
        }

        //Marca el elemento del array del ID de cliente como disponible
        arrayCliente[idActualArrayClientes].estado=F_ESTADO_LIBRE;

        printf("Baja exitosa del cliente con ID %d.\n",arrayCliente[idActualArrayClientes]);
    }
    else
        printf("Se cancelo la eliminacion del cliente con ID %d.\n",auxIntClientes);

    return 0;
}

//Compacta un array.
int cliente_compactarECliente(ECliente* array,int tamArrayNums,int ascend)
{
    int fError=-1,flagSwap,i,conAltas=0;//auxIntSwap
    //char auxCharSwap[256];
    ECliente auxECliente;

    if(tamArrayNums<1 || (ascend<0 || ascend>1))
        return fError;

    do
    {
        flagSwap=0;

        for(i=0;i<tamArrayNums-1;i++)
        {
            if(array[i].estado || array[i+1].estado)
                conAltas=1;

            if((ascend && array[i].estado<array[i+1].estado) || (!ascend && array[i].estado>array[i+1].estado))
            {
                auxECliente=array[i];
                array[i]=array[i+1];
                array[i+1]=auxECliente;

                flagSwap=1;
            }
        }
        if(conAltas)
            fError=0;
        else
            fError=-2;
    }while(flagSwap==1);
    return fError;
}

//Indica si el array tiene al menos un alta.
int cliente_arrayEClienteConAltas(ECliente* lista,int cantLista,int valorAlta)
{
    int conAltas=0,i;

    for(i=0;i<cantLista;i++)
        if(lista[i].estado==valorAlta)
        {
            conAltas=1;
            break;
        }

    return conAltas;
}

//Iniciailiza todos los datos del array.
int cliente_initArrayClientes(ECliente lista[],int cantLista)
{
    int i,funcRetorno=-1;

    if(cantLista>0)
    {
        for(i=0;i<cantLista;i++)
        {
            lista[i].id=-1;
            strcpy(lista[i].nombre,"");
            strcpy(lista[i].apellido,"");
            strcpy(lista[i].CUIT,"");
            lista[i].contAvisosActivos=0;
            lista[i].contAvisosPausados=0;
            lista[i].contAvisos=0;
            lista[i].estado=F_ESTADO_LIBRE;
        }
        funcRetorno=0;
    }

    return funcRetorno;
}

//Busca en que elemento del array se encuentra un ID de cliente
int cliente_buscarPrimeraOcurrenciaClientes(ECliente array[],int cantElementos,int idCliente)
{
    int i,funcRetorno=-1;

    if(cantElementos>0 && idCliente>=0)
        for(i=0;i<cantElementos;i++)
            if(array[i].id==idCliente && array[i].estado)
                return i;

    return funcRetorno;
}

//Busca un elemento libre del array para guardar datos nuevos
int cliente_buscarLibreClientes(ECliente array[],int cantElementos)
{
    int i,funcRetorno=-1;

    if(cantElementos>0)
        for(i=0;i<cantElementos;i++)
            if(array[i].estado==F_ESTADO_LIBRE)
                return i;
    return funcRetorno;
}

//Muestra al array de clientes con posibilidad de pausar cada cierta cantidad de lineas o mostrar datos de diagnostico.
int cliente_mostrarArrayECliente(ECliente* array,int cantidad,int debug,int conPausa,int pausaCantLineas)
{
    int i,funcRetorno=-1,registrosMostrados=0;

    if(cantidad>0 && ((conPausa && pausaCantLineas>0) || !conPausa))
    {
        for(i=0;i<cantidad;i++)
        {
            if(debug!=0)
            {
                printf("[DEBUG] ID: %-3d \tNombre: %-12s \tApellido: %-12s \tCUIT: %-12s \tAvisos Act.: %-3d \tAvisos Pau.: %-3d \tEstado: %d\n",array[i].id,array[i].nombre,array[i].apellido,array[i].CUIT,array[i].contAvisosActivos,array[i].contAvisosPausados,array[i].estado);
                registrosMostrados++;
            }
            else if(array[i].estado)
            {
                printf("ID: %-3d \tNombre: %-12s \tApellido: %-12s \tCUIT: %-12s \tAvisos Act.: %-3d\n",array[i].id,array[i].nombre,array[i].apellido,array[i].CUIT,array[i].contAvisosActivos);
                registrosMostrados++;
            }

            if(registrosMostrados>0 && registrosMostrados%pausaCantLineas==0 && conPausa)
                system("pause");
        }
        funcRetorno=0;
    }

    return funcRetorno;
}

//Ordena el array por metodo de burbuja por nombres
int cliente_burbujeoMejoradoEClienteXNombres(ECliente* array,int tamArrayNums,int ascend)
{
    int fError=-1,flagSwap,i,conAltas=0;//auxIntSwap
    //char auxCharSwap[256];
    ECliente auxECliente;

    if(tamArrayNums<1 || (ascend<0 || ascend>1))
        return fError;

    do
    {
        flagSwap=0;

        for(i=0;i<tamArrayNums-1;i++)
        {
            if(array[i].estado || array[i+1].estado)
                conAltas=1;

            if((ascend==1 && strcmp(array[i].nombre,array[i+1].nombre)>0 && array[i].estado && array[i+1].estado) || (ascend==0 && strcmp(array[i].nombre,array[i+1].nombre)<0 && array[i].estado && array[i+1].estado))
            {
                auxECliente=array[i];
                array[i]=array[i+1];
                array[i+1]=auxECliente;

                flagSwap=1;
            }
        }
        if(conAltas)
            fError=0;
        else
            fError=-2;
    }while(flagSwap==1);
    return fError;
}
