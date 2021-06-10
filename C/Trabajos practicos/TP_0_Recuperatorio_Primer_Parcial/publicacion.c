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

void publicacion_hardcodePublicaciones(EPublicacion* arrayPublicacion)
{
    arrayPublicacion[0].id=0;
    arrayPublicacion[0].idCliente=0;
    arrayPublicacion[0].numRubro=10;
    strcpy(arrayPublicacion[0].texto,"HOLA EZE.");
    arrayPublicacion[0].estado=F_ESTADO_OCUPADO;

    arrayPublicacion[1].id=1;
    arrayPublicacion[1].idCliente=3;
    arrayPublicacion[1].numRubro=11;
    strcpy(arrayPublicacion[1].texto,"HOLA ADRIAN.");
    arrayPublicacion[1].estado=F_ESTADO_OCUPADO;

    arrayPublicacion[2].id=2;
    arrayPublicacion[2].idCliente=4;
    arrayPublicacion[2].numRubro=12;
    strcpy(arrayPublicacion[2].texto,"HOLA GUSTAVO.");
    arrayPublicacion[2].estado=F_ESTADO_OCUPADO;

    arrayPublicacion[3].id=3;
    arrayPublicacion[3].idCliente=2;
    arrayPublicacion[3].numRubro=11;
    strcpy(arrayPublicacion[3].texto,"HOLA VIVIANA.");
    arrayPublicacion[3].estado=F_ESTADO_OCUPADO;

    arrayPublicacion[4].id=4;
    arrayPublicacion[4].idCliente=0;
    arrayPublicacion[4].numRubro=10;
    strcpy(arrayPublicacion[4].texto,"HOLA EZE OTRA VEZ.");
    arrayPublicacion[4].estado=F_ESTADO_OCUPADO;
}

//Cambia el estado de una publicacion al que el usuario le facilite
int publicacion_cambiarEstadoPublicacion(EPublicacion* arrayPublicacion,int cantPublicacion,int nuevoEstado)
{
    int auxIntPublicacion;
    char auxCharPublicacion[255];
    int idActualArrayPublicacion;

    //Solicita y valida ID del cliente
    if(input_getStringNumeros("ID Publicacion: ",auxCharPublicacion,0,cantPublicacion-1)!=0)
    {
        printf("ERROR en ID Publicacion ingresado. Verifique que los datos sean correctos.\n");
        return -1;
    }
    //Casting del ID de Char a Int
    auxIntPublicacion=atoi(auxCharPublicacion);

    //Busca el elemento del ID en el array
    idActualArrayPublicacion=publicacion_buscarPrimeraOcurrenciaPublicaciones(arrayPublicacion,cantPublicacion,auxIntPublicacion);
    if(idActualArrayPublicacion<0)
    {
        printf("ERROR, el ID de publicacion ingresado es inexistente. Verifique que los datos sean correctos.\n");
        return -1;
    }

    //Marca el elemento del array del ID de cliente como pausado
    arrayPublicacion[idActualArrayPublicacion].estado=nuevoEstado;

    if(nuevoEstado==F_ESTADO_OCUPADO)
        printf("Publicacion con ID %d activada exitosamente.\n",arrayPublicacion[idActualArrayPublicacion].id);
    else if(nuevoEstado==F_ESTADO_PAUSADO)
        printf("Publicacion con ID %d pausada exitosamente.\n",arrayPublicacion[idActualArrayPublicacion].id);

    return 0;
}

//Marca como disponible el registro de cliente seleccionado
int publicacion_bajaPublicacionesCliente(EPublicacion* arrayPublicacion,int cantPublicacion,int idCliente)
{
    int i,funcRetorno=-1;

    if(cantPublicacion>0 && idCliente>=0)
    {
        for(i=0;i<cantPublicacion;i++)
            if(arrayPublicacion[i].idCliente==idCliente)
                arrayPublicacion[i].estado=F_ESTADO_LIBRE;

        funcRetorno=0;
    }

    return funcRetorno;
}

//Muestra las publicaciones realizadas por un determinado cliente
int publicacion_mostrarPublicacionesCliente(EPublicacion* array,int cantidad,int idCliente,int debug,int conPausa,int pausaCantLineas)
{
    int i,funcRetorno=-1,registrosMostrados=0;

    if(cantidad>0 && idCliente>=0 && ((conPausa && pausaCantLineas>0) || !conPausa))
    {
        for(i=0;i<cantidad;i++)
            if(array[i].idCliente==idCliente && array[i].estado>0)
            {
                if(debug!=0)
                {
                    printf("[DEBUG] ID Publicacion: %-3d \tN° Rubro: %-4d \tID Cliente: %-2d \tEstado: %d\n",array[i].id,array[i].numRubro,array[i].idCliente,array[i].estado);
                    printf("\tTexto: %s\n",array[i].texto);
                    registrosMostrados++;
                }
                else if(array[i].estado)
                {
                    printf("ID Publicacion: %-3d \tN° Rubro: %-4d \tID Cliente: %-2d\n",array[i].id,array[i].numRubro,array[i].idCliente);
                    printf("\tTexto: %s\n",array[i].texto);
                    registrosMostrados++;
                }

                if(registrosMostrados>0 && registrosMostrados%pausaCantLineas==0 && conPausa)
                    system("pause");
            }
        funcRetorno=0;
    }

    return funcRetorno;
}

//Compacta el array de publicaciones
int publicacion_compactarEPublicacion(EPublicacion* array,int tamArrayNums,int ascend)
{
    int fError=-1,flagSwap,i,conAltas=0;//auxIntSwap
    //char auxCharSwap[256];
    EPublicacion auxEPublicacion;

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
                auxEPublicacion=array[i];
                array[i]=array[i+1];
                array[i+1]=auxEPublicacion;

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

//Verifica si el array de publicaciones tiene altas
int publicacion_arrayEPublicacionConAltas(EPublicacion* lista,int cantLista,int valorAlta)
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

//Inicializa un array de publicaciones
int publicacion_initArrayPublicaciones(EPublicacion lista[],int cantLista)
{
    int i,funcRetorno=-1;

    if(cantLista>0)
    {
        for(i=0;i<cantLista;i++)
        {
            lista[i].idCliente=-1;
            lista[i].numRubro=-1;
            strcpy(lista[i].texto,"");
            lista[i].id=-1;
            lista[i].estado=F_ESTADO_LIBRE;
        }
        funcRetorno=0;
    }

    return funcRetorno;
}

//Busca en que sector del array se encuentra un ID de publicacion
int publicacion_buscarPrimeraOcurrenciaPublicaciones(EPublicacion array[],int cantElementos,int idPublicacion)
{
    int i,funcRetorno=-1;

    if(cantElementos>0 && idPublicacion>=0)
        for(i=0;i<cantElementos;i++)
            if(array[i].id==idPublicacion && array[i].estado)
                return i;

    return funcRetorno;
}

//Busca lugar libre en el array
int publicacion_buscarLibrePublicaciones(EPublicacion array[],int cantElementos)
{
    int i,funcRetorno=-1;

    if(cantElementos>0)
        for(i=0;i<cantElementos;i++)
            if(array[i].estado==F_ESTADO_LIBRE)
                return i;
    return funcRetorno;
}

int publicacion_mostrarArrayEPublicacion(EPublicacion* array,int cantidad,int debug,int conPausa,int pausaCantLineas)
{
    int i,funcRetorno=-1;

    if(cantidad>0 && ((conPausa && pausaCantLineas>0) || !conPausa))
    {
        for(i=0;i<cantidad;i++)
        {
            if(debug!=0)
            {
                printf("[DEBUG] ID Publicacion: %-3d \tN° Rubro: %-4d \tID Cliente: %-2d \tEstado: %d\n",array[i].id,array[i].numRubro,array[i].idCliente,array[i].estado);
                printf("\tTexto: %s\n",array[i].texto);
            }
            else if(array[i].estado)
            {
                printf("ID Publicacion: %-3d \tN° Rubro: %-4d \tID Cliente: %-2d\n",array[i].id,array[i].numRubro,array[i].idCliente);
                printf("\tTexto: %s\n",array[i].texto);
            }

            if(i>=0 && (i+1)%pausaCantLineas==0 && conPausa)
                system("pause");
        }
        funcRetorno=0;
    }

    return funcRetorno;
}

//Ordenamiento de nombres de publicaciones por burbujeo optimizado
int publicacion_burbujeoMejoradoEPublicacionXNombres(EPublicacion* array,int tamArrayNums,int ascend)
{
    int fError=-1,flagSwap,i,conAltas=0;//auxIntSwap
    //char auxCharSwap[256];
    EPublicacion auxEPublicacion;

    if(tamArrayNums<1 || (ascend<0 || ascend>1))
        return fError;

    do
    {
        flagSwap=0;

        for(i=0;i<tamArrayNums-1;i++)
        {
            if(array[i].estado || array[i+1].estado)
                conAltas=1;

            if((ascend==1 && strcmp(array[i].texto,array[i+1].texto)>0 && array[i].estado && array[i+1].estado) || (ascend==0 && strcmp(array[i].texto,array[i+1].texto)<0 && array[i].estado && array[i+1].estado))
            {
                auxEPublicacion=array[i];
                array[i]=array[i+1];
                array[i+1]=auxEPublicacion;

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
