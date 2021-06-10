#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main()
{
    float numero[5];
    int auxRet;

    auxRet=loadFloatArrayElements(numero,5,0,10);
    if(auxRet!=0)
        printf("ERRRRROOOOORR!!\n");

    for(int i=0;i<5;i++)
        printf("%d - %.2f\n",i,numero[i]);

    return 0;
}
