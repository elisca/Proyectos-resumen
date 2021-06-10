//NOTA: Agregar funcion getStringLetEsp y corregir getStringLetrasEspacios.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "validaciones.h"

/*int getStringLetrasEspacios(char mensaje[],char input[],int longMin,int longMax)
{
    char aux[256];
    int funcRetorno=-1;

    if((longMin>0 && longMax>0) && (longMin<=longMax) && longMax<=255)
    {
        getStringLetEsp(mensaje,aux);
        if(esSoloLetras(aux))
        {
            strcpy(input,aux);
            funcRetorno=0;
        }
        else
            funcRetorno=-2;
    }
    return funcRetorno;
}*/

int getInt(char* msg,char* msgE,int cIntentos,long numMin,long numMax,int* result)
{
    int codError=-1;
    long auxNum;
    int intentos=cIntentos;

    do
    {
        printf("%s\n",msg);
        scanf("%ld",&auxNum);

        intentos--;

        if(auxNum<numMin || auxNum>numMax)
        {
            codError=-1;
            printf("%s\n",msgE);
        }
        else
            codError=0;
    }while(codError!=0 && intentos>0);

    if(intentos==0)
        codError=-1;
    else
    {
        codError=0;
        *result=auxNum;
    }

    return codError;
}

int getFloat(char* msg,char* msgE,int cIntentos,float numMin,float numMax,float* result)
{
    int codError=-1;
    float auxNum;
    int intentos=cIntentos;

    do
    {
        printf("%s\n",msg);
        scanf("%f",&auxNum);

        intentos--;

        if(auxNum<numMin || auxNum>numMax)
        {
            codError=-1;
            printf("%s\n",msgE);
        }
        else
            codError=0;
    }while(codError!=0 && intentos>0);

    if(intentos==0)
        codError=-1;
    else
    {
        codError=0;
        *result=auxNum;
    }

    return codError;
}

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    //fpurge(stdin) Linux y OSx.
    scanf("%c",&auxiliar);
    return auxiliar;
}

char getNumeroAleatorio(int desde,int hasta,int iniciar)
{
    if(iniciar)
        srand(time(NULL));
    return desde + (rand()%(hasta+1-desde));
}

void getString(char mensaje[],char input[])
{
    printf(mensaje);
    fflush(stdin);
    scanf("%s",input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringFloat(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
