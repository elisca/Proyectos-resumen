#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int loadIntArrayElements(int* intArray,int qtyArrayElem,int numMin,int numMax)
{
    int error=-1;
    int retGetInt;
    int i;

    if(qtyArrayElem>0)
    {
        error=0;
        for(i=0;i<qtyArrayElem;i++)
        {
            do
            {
                retGetInt=getInt("Ingrese un numero: ","Error desconocido!",100,numMin,numMax,&intArray[i]);
            }while(retGetInt!=0);
        }
    }

    return error;
}

int loadFloatArrayElements(float* floatArray,int qtyArrayElem,float numMin,float numMax)
{
    int error=-1;
    int retGetFloat;
    int i;

    if(qtyArrayElem>0)
    {
        error=0;
        for(i=0;i<qtyArrayElem;i++)
        {
            do
            {
                retGetFloat=getFloat("Ingrese un numero: ","Error, ingrese numero nuevamente: ",100,numMin,numMax,&floatArray[i]);
            }while(retGetFloat!=0);
        }
    }

    return error;
}

int promIntArrayElements(int* intArray,int qtyArrayElem,float* promElem)
{
    int error=-1;
    int i;
    float acumIntNums=0;

    if(qtyArrayElem>0)
    {
        error=0;

        for(i=0;i<qtyArrayElem;i++)
            acumIntNums+=intArray[i];

        acumIntNums/=qtyArrayElem;

        *promElem=acumIntNums;
    }

    return error;
}

int promFloatArrayElements(float* floatArray,int qtyArrayElem,float* promElem)
{
    int error=-1;
    int i;
    float acumFloatNums=0;

    if(qtyArrayElem>0)
    {
        error=0;

        for(i=0;i<qtyArrayElem;i++)
            acumFloatNums+=floatArray[i];

        acumFloatNums/=qtyArrayElem;

        *promElem=acumFloatNums;
    }

    return error;
}

int mostrarArrayInt(int * array,int cantidad)
{
    int i;
    printf(" / ");
    for(i=0;i<cantidad;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}

int mostrarArrayEPublicacion(int* array,int cantidad,int debug,int conPausa,int pausaCantLineas)
{
    int i,funcRetorno=-1;

    if(cantidad>0 && ((conPausa && pausaCantLineas>0) || !conPausa))
    {
        for(i=0;i<cantidad;i++)
        {
            if(debug!=0)
                printf("[DEBUG] %d\n",array[i]);
            else
                printf("[RELEASE] %d\n",array[i]);

            if(i>=0 && (i+1)%pausaCantLineas==0 && conPausa)
                system("pause");
        }
        funcRetorno=0;
    }

    return funcRetorno;
}

void inicializarArrayInt(int array[],int cantElementos,int valor)
{
    int i;
    for(i=0;i<cantElementos;i++)
        array[i]=valor;
}

int buscarPrimeraOcurrencia(int array[],int cantElementos,int valor)
{
    int i;
    for(i=0;i<cantElementos;i++)
        if(array[i]==valor)
            return i;
    return -1;
}
