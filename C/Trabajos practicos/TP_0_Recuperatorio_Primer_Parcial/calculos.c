#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int matSuma(float op1,float op2,float* resultado)
{
    int flagError=0;

    op1+=op2;
    *resultado=op1;

    return flagError;
}

int matResta(float op1,float op2,float* resultado)
{
    int flagError=0;

    op1-=op2;
    *resultado=op1;

    return flagError;
}

int matMultipl(float op1,float op2,float* resultado)
{
    int flagError=0;

    op1*=op2;
    *resultado=op1;

    return flagError;
}

int matDivision(float op1,float op2,float* resultado)
{
    int flagError=-1;

    if(op2!=0)
    {
        op1/=op2;
        *resultado=op1;
        flagError=0;
    }

    return flagError;
}

int matFactorial(int N,int* resultado)
{
    int i,r=1,flagError=-1;

    if(N>=0)
    {
        for(i=N;i>=1;i--)
            r=r*i;

        *resultado=r;
        flagError=0;
    }

    return flagError;
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

int promLongArrayElements(long* longArray,int qtyArrayElem,float* promElem)
{
    int error=-1;
    int i;
    float acumLongNums=0;

    if(qtyArrayElem>0)
    {
        error=0;

        for(i=0;i<qtyArrayElem;i++)
            acumLongNums+=longArray[i];

        acumLongNums/=qtyArrayElem;

        *promElem=acumLongNums;
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

int totalIntArrayElements(int* intArray,int qtyArrayElem,int* totalElem)
{
    int error=-1;
    int i;
    int acumIntNums=0;

    if(qtyArrayElem>0)
    {
        error=0;

        for(i=0;i<qtyArrayElem;i++)
            acumIntNums+=intArray[i];

        *totalElem=acumIntNums;
    }

    return error;
}

int totalLongArrayElements(long* longArray,int qtyArrayElem,long* totalElem)
{
    int error=-1;
    int i;
    long acumLongNums=0;

    if(qtyArrayElem>0)
    {
        error=0;

        for(i=0;i<qtyArrayElem;i++)
            acumLongNums+=longArray[i];

        *totalElem=acumLongNums;
    }

    return error;
}

int totalFloatArrayElements(float* floatArray,int qtyArrayElem,float* totalElem)
{
    int error=-1;
    int i;
    float acumFloatNums=0;

    if(qtyArrayElem>0)
    {
        error=0;

        for(i=0;i<qtyArrayElem;i++)
            acumFloatNums+=floatArray[i];

        *totalElem=acumFloatNums;
    }

    return error;
}
