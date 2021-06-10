#include <stdio.h>
#include <stdlib.h>
#include "informes.h"
#include "input.h"

#define F_ESTADO_LIBRE 0
#define F_ESTADO_OCUPADO 1
#define F_ESTADO_PAUSADO 2

//Cuenta los minimos de cada rubro de publicaciones activas
int informes_contarMinRubroPubliActivas(EPublicacion* arrayPublicacion,int cantPublicacion)
{
    int i,j,funcError=-1,contador=0,cantMinimo,numRubro;

    for(i=0;i<cantPublicacion;i++)
        if(arrayPublicacion[i].estado==F_ESTADO_OCUPADO)
        {
            contador=0;
            for(j=0;j<cantPublicacion;j++)
                if(arrayPublicacion[j].numRubro==arrayPublicacion[i].numRubro)
                    contador++;

            if(i==0 || contador<cantMinimo)
            {
                cantMinimo=contador;
                numRubro=arrayPublicacion[i].numRubro;
            }
        }

    printf("Rubro %d con cantidad mas baja de avisos. Cantidad de avisos: %d.\n",numRubro,cantMinimo);

    funcError=0;
    return funcError;
}

//Cuenta maximo rubro en publicaciones activas
int informes_contarMaxRubroPubliActivas(EPublicacion* arrayPublicacion,int cantPublicacion)
{
    int i,j,funcError=-1,contador=0,cantMaximo=0,numRubro;

    for(i=0;i<cantPublicacion;i++)
        if(arrayPublicacion[i].estado==F_ESTADO_OCUPADO)
        {
            contador=0;
            for(j=0;j<cantPublicacion;j++)
                if(arrayPublicacion[j].numRubro==arrayPublicacion[i].numRubro)
                    contador++;

            if(i==0 || contador>cantMaximo)
            {
                cantMaximo=contador;
                numRubro=arrayPublicacion[i].numRubro;
            }
        }

    printf("Rubro %d con cantidad mas alta de avisos. Cantidad de avisos: %d.\n",numRubro,cantMaximo);

    funcError=0;
    return funcError;
}

//Cuenta la cantidad de publicaciones activas que tiene un rubro especifico
int informes_contarPubliActivasRubroEspecifico(EPublicacion* arrayPublicacion,int cantPublicacion)
{
    int i,funcError=-1,contador=0,numRubro;
    char numRubroChar[8];

    if(input_getStringNumeros("Numero de Rubro: ",numRubroChar,0,65535)!=0)
    {
        printf("ERROR al intentar tomar el numero de rubro ingresado. Intente nuevamente.\n");
        return funcError;
    }
    numRubro=atoi(numRubroChar);

    for(i=0;i<cantPublicacion;i++)
        if(arrayPublicacion[i].numRubro==numRubro && arrayPublicacion[i].estado==F_ESTADO_OCUPADO)
            contador++;

    if(contador==0)
        printf("No hay publicaciones activas para el rubro %d.\n",numRubro);
    else
        printf("Hay %d publicacion/es activa/s para el rubro %d.\n",contador,numRubro);

    funcError=0;
    return funcError;
}

//Muestra el cliente que posee la maxima cantidad de avisos
int informes_mostrarMaxClienteAvisos(ECliente* arrayCliente,int cantCliente,EPublicacion* arrayPublicacion,int cantPublicacion,int estadoPublicacion)
{
    int i,funcError=-1,maxValorActivas,maxValorPausadas,maxValorAvisos;

    if(informes_contarAvisosClientes(arrayCliente,cantCliente,arrayPublicacion,cantPublicacion)!=0)
        return funcError;

    for(i=0;i<cantCliente;i++)
    {
        if(estadoPublicacion==F_ESTADO_OCUPADO)
        {
            if(i==0 || arrayCliente[i].contAvisosActivos>maxValorActivas)
                maxValorActivas=arrayCliente[i].contAvisosActivos;
        }
        else if(estadoPublicacion==F_ESTADO_PAUSADO)
        {
            if(i==0 || arrayCliente[i].contAvisosPausados>maxValorPausadas)
                maxValorPausadas=arrayCliente[i].contAvisosPausados;
        }
        else if(!estadoPublicacion)
        {

            if(i==0 || arrayCliente[i].contAvisos>maxValorAvisos)
                maxValorAvisos=arrayCliente[i].contAvisos;
        }
    }

    if(!maxValorActivas)
        printf("Ningun cliente posee publicaciones activas actualmente.\n");
    if(!maxValorPausadas)
        printf("Ningun cliente posee publicaciones pausadas actualmente.\n");
    if(!maxValorAvisos)
        printf("Ningun cliente posee publicaciones actualmente.\n");

    for(i=0;i<cantCliente;i++)
    {
        if(estadoPublicacion==F_ESTADO_OCUPADO)
        {
            if(arrayCliente[i].contAvisosActivos==maxValorActivas && maxValorActivas>0)
                printf("ID: %-3d \tNombre: %-12s \tApellido: %-12s \tCUIT: %-12s \tAvisos Act.: %-3d\n",arrayCliente[i].id,arrayCliente[i].nombre,arrayCliente[i].apellido,arrayCliente[i].CUIT,arrayCliente[i].contAvisosActivos);
        }
        else if(estadoPublicacion==F_ESTADO_PAUSADO)
        {
            if(arrayCliente[i].contAvisosPausados==maxValorPausadas && maxValorPausadas>0)
                printf("ID: %-3d \tNombre: %-12s \tApellido: %-12s \tCUIT: %-12s \tAvisos Pau.: %-3d\n",arrayCliente[i].id,arrayCliente[i].nombre,arrayCliente[i].apellido,arrayCliente[i].CUIT,arrayCliente[i].contAvisosPausados);
        }
        if(!estadoPublicacion)
        {
            if(arrayCliente[i].contAvisos==maxValorAvisos && maxValorAvisos>0)
                printf("ID: %-3d \tNombre: %-12s \tApellido: %-12s \tCUIT: %-12s \tAvisos: %-3d\n",arrayCliente[i].id,arrayCliente[i].nombre,arrayCliente[i].apellido,arrayCliente[i].CUIT,arrayCliente[i].contAvisos);
        }
    }

    funcError=0;
    return funcError;
}

//Cuenta la cantidad de avisos activos que posee cada cliente
int informes_contarAvisosClientes(ECliente* arrayCliente,int cantCliente,EPublicacion* arrayPublicacion,int cantPublicacion)
{
    int i,funcError=-1,auxIdCliente;

    for(i=0;i<cantCliente;i++)
    {
        arrayCliente[i].contAvisosActivos=0;
        arrayCliente[i].contAvisosPausados=0;
        arrayCliente[i].contAvisos=0;
    }

    for(i=0;i<cantPublicacion;i++)
    {
        auxIdCliente=cliente_buscarPrimeraOcurrenciaClientes(arrayCliente,cantCliente,arrayPublicacion[i].idCliente);

        if(arrayPublicacion[i].estado==F_ESTADO_OCUPADO)
        {
            arrayCliente[auxIdCliente].contAvisosActivos++;
            arrayCliente[auxIdCliente].contAvisos++;
        }
        else if(arrayPublicacion[i].estado==F_ESTADO_PAUSADO)
        {
            arrayCliente[auxIdCliente].contAvisosPausados++;
            arrayCliente[auxIdCliente].contAvisos++;
        }
    }

    funcError=0;
    return funcError;
}

//Muestra las publicaciones activas
int informes_mostrarPublicacionesActivas(ECliente* arrayCliente,int cantCliente,EPublicacion* arrayPublicacion,int cantPublicacion,int conPausa,int pausaCantLineas)
{
    int i,funcError=-1,auxIdCliente,registrosMostrados=0;

    for(i=0;i<cantPublicacion;i++)
    {
        if(arrayPublicacion[i].estado==F_ESTADO_OCUPADO)
        {
            auxIdCliente=cliente_buscarPrimeraOcurrenciaClientes(arrayCliente,cantCliente,arrayPublicacion[i].idCliente);
            printf("ID Aviso: %-3d N° Rubro: %-3d ID Cliente: %-3d CUIT Cliente: %-12s\n",arrayPublicacion[i].id,arrayPublicacion[i].numRubro,arrayPublicacion[i].idCliente,arrayCliente[auxIdCliente].CUIT);
            printf("Texto: %s\n",arrayPublicacion[i].texto);
            registrosMostrados++;

            if(registrosMostrados>0 && registrosMostrados%pausaCantLineas==0 && conPausa)
                system("pause");

        }
    }

    funcError=0;
    return funcError;
}

//Cuenta entre un rango de valores dentro de un array de enteros
int informes_contadorRangosArrayInt(int* arrayInt,int qtyArrayInt,int valorLimite,int buscarSuperior,int incluirLimite)
{
    int i;
    int contador=0;

    for(i=0;i<qtyArrayInt;i++)
        if(buscarSuperior==-1 && arrayInt[i]==valorLimite)
            contador++;
        else if(buscarSuperior==1 && incluirLimite==1 && arrayInt[i]>=valorLimite)
            contador++;
        else if(buscarSuperior==1 && incluirLimite==0 && arrayInt[i]>valorLimite)
            contador++;
        else if(buscarSuperior==0 && incluirLimite==1 && arrayInt[i]<=valorLimite)
            contador++;
        else if(buscarSuperior==0 && incluirLimite==0 && arrayInt[i]<valorLimite)
            contador++;
    return contador;
}

//Cuenta entre un rango de valores dentro de un array de puntos flotantes
int informes_contadorRangosArrayFloat(float* arrayFloat,int qtyArrayInt,float valorLimite,int buscarSuperior,int incluirLimite)
{
    int i;
    int contador=0;

    for(i=0;i<qtyArrayInt;i++)
        if(buscarSuperior==-1 && arrayFloat[i]==valorLimite)
            contador++;
        else if(buscarSuperior==1 && incluirLimite==1 && arrayFloat[i]>=valorLimite)
            contador++;
        else if(buscarSuperior==1 && incluirLimite==0 && arrayFloat[i]>valorLimite)
            contador++;
        else if(buscarSuperior==0 && incluirLimite==1 && arrayFloat[i]<=valorLimite)
            contador++;
        else if(buscarSuperior==0 && incluirLimite==0 && arrayFloat[i]<valorLimite)
            contador++;
    return contador;
}

//Cuenta entre un rango de valores dentro de un array de enteros largos
int informes_contadorRangosArrayLong(long* arrayLong,int qtyArrayInt,long valorLimite,int buscarSuperior,int incluirLimite)
{
    int i;
    int contador=0;

    for(i=0;i<qtyArrayInt;i++)
        if(buscarSuperior==-1 && arrayLong[i]==valorLimite)
            contador++;
        else if(buscarSuperior==1 && incluirLimite==1 && arrayLong[i]>=valorLimite)
            contador++;
        else if(buscarSuperior==1 && incluirLimite==0 && arrayLong[i]>valorLimite)
            contador++;
        else if(buscarSuperior==0 && incluirLimite==1 && arrayLong[i]<=valorLimite)
            contador++;
        else if(buscarSuperior==0 && incluirLimite==0 && arrayLong[i]<valorLimite)
            contador++;
    return contador;
}

//Busca el minimo entre un rango de valores dentro de un array de enteros
int informes_buscarMinIntArray(int* arrayInt,int qtyElem,int* minVal,int* idMinVal)
{
    int i=0;
    int minV=0;
    int idMinV=0;
    int funcError=-1;

    for(i=0;i<qtyElem;i++)

        if(i==0 || arrayInt[i]<minV)
        {
            minV=arrayInt[i];
            idMinV=i;
        }

    *minVal=minV;
    *idMinVal=idMinV;

    funcError=0;
    return funcError;
}

//Busca el msximo entre un rango de valores dentro de un array de enteros
int informes_buscarMaxIntArray(int* arrayInt,int qtyElem,int* maxVal,int* idMaxVal)
{
    int i=0;
    int maxV=0;
    int idMaxV=0;
    int funcError=-1;

    for(i=0;i<qtyElem;i++)
        if(i==0 || arrayInt[i]<maxV)
        {
            maxV=arrayInt[i];
            idMaxV=i;
        }

    *maxVal=maxV;
    *idMaxVal=idMaxV;

    funcError=0;
    return funcError;
}

//Busca el minimo entre un rango de valores dentro de un array de enteros largos
int informes_buscarMinLongArray(long* arrayLong,int qtyElem,long* minVal,long* idMinVal)
{
    int i=0;
    long minV=0;
    long idMinV=0;
    int funcError=-1;

    for(i=0;i<qtyElem;i++)

        if(i==0 || arrayLong[i]<minV)
        {
            minV=arrayLong[i];
            idMinV=i;
        }

    *minVal=minV;
    *idMinVal=idMinV;

    funcError=0;
    return funcError;
}

//Busca el maximo entre un rango de valores dentro de un array de enteros largos
int informes_buscarMaxLongArray(long* arrayLong,int qtyElem,long* maxVal,long* idMaxVal)
{
    int i=0;
    long maxV=0;
    long idMaxV=0;
    int funcError=-1;

    for(i=0;i<qtyElem;i++)
        if(i==0 || arrayLong[i]<maxV)
        {
            maxV=arrayLong[i];
            idMaxV=i;
        }

    *maxVal=maxV;
    *idMaxVal=idMaxV;

    funcError=0;
    return funcError;
}

//Busca el minumo en un array de puntos flotantes
int informes_buscarMinFloatArray(float* arrayFloat,int qtyElem,float* minVal,float* idMinVal)
{
    int i=0;
    float minV=0;
    float idMinV=0;
    int funcError=-1;

    for(i=0;i<qtyElem;i++)

        if(i==0 || arrayFloat[i]<minV)
        {
            minV=arrayFloat[i];
            idMinV=i;
        }

    *minVal=minV;
    *idMinVal=idMinV;

    funcError=0;
    return funcError;
}

//Busca el maximo en un array de puntos flotantes
int informes_buscarMaxFloatArray(float* arrayFloat,int qtyElem,float* maxVal,float* idMaxVal)
{
    int i=0;
    float maxV=0;
    float idMaxV=0;
    int funcError=-1;

    for(i=0;i<qtyElem;i++)
        if(i==0 || arrayFloat[i]<maxV)
        {
            maxV=arrayFloat[i];
            idMaxV=i;
        }

    *maxVal=maxV;
    *idMaxVal=idMaxV;

    funcError=0;
    return funcError;
}
