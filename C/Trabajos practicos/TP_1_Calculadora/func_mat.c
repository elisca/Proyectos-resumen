#include <stdio.h>
#include <stdlib.h>
#include "func_mat.h"

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
