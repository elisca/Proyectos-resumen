#include <stdio.h>
#include <stdlib.h>
#include "ordenamiento.h"

int burbujeoInt(int* nums,int tamArrayNums,int ascend)
{
    int fError=-1,auxSwap,i,j;

    if(tamArrayNums<1 || (ascend<0 || ascend>1))
        return fError;

    for(i=0;i<tamArrayNums-1;i++)
    {
        for(j=i+1;j<tamArrayNums;j++)
        {
            if((ascend==1 && nums[i]>nums[i+1]) || (ascend==0 && nums[i]<nums[i+1]))
            {
                auxSwap=nums[i];
                nums[i]=nums[i+1];
                nums[i+1]=auxSwap;
            }
        }
    }
    fError=0;
    return fError;
}

int burbujeoMejoradoInt(int* nums,int tamArrayNums,int ascend)
{
    int fError=-1,flagSwap,i,auxSwap;

    if(tamArrayNums<1 || (ascend<0 || ascend>1))
        return fError;

    do
    {
        flagSwap=0;

        for(i=0;i<tamArrayNums-1;i++)
        {
            if((ascend==1 && nums[i]>nums[i+1]) || (ascend==0 && nums[i]<nums[i+1]))
            {
                auxSwap=nums[i];
                nums[i]=nums[i+1];
                nums[i+1]=auxSwap;

                flagSwap=1;
            }
        }
        fError=0;
    }while(flagSwap==1);
    return fError;
}
int numsSwapInt(int* num1,int* num2)
{
    int fError=-1,auxSwap;

    auxSwap=*num1;
    *num1=*num2;
    *num2=auxSwap;

    fError=0;

    return fError;
}

//Optimizar el codigo, podria reducirse.
int numsDesplazaSegmentosInt(int* numsArray,int cantElementosArray,int sentido,int inicioSeg,int finalSeg)
{
    int auxSwap,i,fError;

    if (cantElementosArray<1 || (sentido!=0 && sentido!=1) || (sentido==0 && inicioSeg==0) || (sentido==1 && finalSeg==cantElementosArray-1) || (inicioSeg<0 || inicioSeg>finalSeg) || (finalSeg>cantElementosArray-1 || finalSeg<inicioSeg))
        fError=-1;
    else
    {
        if(sentido==0) //Desplazamiento hacia la izquierda
        {
            while(inicioSeg!=0)
            {
                auxSwap=numsArray[inicioSeg-1];
                for(i=inicioSeg;i<=finalSeg;i++)
                {
                    numsArray[i-1]=numsArray[i];
                }
                finalSeg--;
                inicioSeg--;

                numsArray[finalSeg+1]=auxSwap;
            }
        }
        else //Desplazamiento hacia la derecha
        {
            while(finalSeg!=cantElementosArray-1)
            {
                auxSwap=numsArray[finalSeg+1];
                for(i=finalSeg;i>=inicioSeg;i--)
                {
                    numsArray[i+1]=numsArray[i];
                }
                finalSeg++;
                inicioSeg++;

                numsArray[inicioSeg-1]=auxSwap;
            }
        }
        fError=0;
    }

    return fError;
}

int ordenarArrayIntInsertion(int* array,int cantidad,int ordenAscendente)
{
	int auxiliar,funcRetorno=-1;
    int j, i;

    if(cantidad>0 && (!ordenAscendente || ordenAscendente))
    {
        for(i = 1; i < cantidad; i++)
        {
            auxiliar = array[i];
            j = i;
            while(j > 0 && ((auxiliar < array[j - 1] && ordenAscendente==1) || (auxiliar > array[j - 1] && ordenAscendente==0)))
            {
                array[j] = array[j - 1];
                j--;
            }
            array[j] = auxiliar;
        }
        funcRetorno=0;
    }

    return funcRetorno;
}
