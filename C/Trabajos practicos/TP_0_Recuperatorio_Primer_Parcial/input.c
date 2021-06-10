#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "input.h"
#include "validaciones.h"

//Muestra un menu de opciones recibido en un char y pide una opcion.
int input_menuOpciones(char* listaOpciones,int* opcionSeleccionada,int opcMin,int opcMax)
{
    int auxiliar,funcError=-1;
    char opcionChar[2];
    //Muestra las opciones disponibles y pide seleccionar una opcion.
    do
    {
        system("cls");
        printf("%s",listaOpciones);

        //Ingresa opcion seleccionada y valida que la opcion sea correcta.
        auxiliar=input_getStringNumeros("Opcion: ",opcionChar,opcMin,opcMax);
        if(auxiliar!=0)
        {
            printf("ERROR, opcion incorrecta.\n");
            system("pause");
        }
        else
            *opcionSeleccionada=atoi(opcionChar);
    }while(auxiliar!=0);
    funcError=0;
    return funcError;
}

//Muestra un texto y pide responder por si o por no.
int input_opcionSiNo(char* textoConsulta,char respSi,char respNo)
{
    char respuesta;
    respSi=toupper(respSi);
    respNo=toupper(respNo);

    //Hacer validaciones
    do
    {
        printf("%s",textoConsulta);
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta=toupper(respuesta);

        if(respuesta!=respSi && respuesta!=respNo)
            printf("\nERROR, respuesta incorrecta. Responda %c para SI, y %c para NO. Intente nuevamente.\n",respSi,respNo);
    }while(respuesta!=respSi && respuesta!=respNo);

    if(respuesta==respSi)
        return 1;
    else
        return 0;
}

//Solicita un numero flotante y lo devuelve con cantidad de intentos erroneos, maximo y minimo
int input_getFloat(char* msg,char* msgE,int cIntentos,float numMin,float numMax,float* result)
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

//Solicita un caracter y lo devuelve
char input_getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    //fpurge(stdin) Linux y OSx.
    scanf("%c",&auxiliar);
    return auxiliar;
}

//Genera un numero aleatorio en el rango configurado
char input_getNumeroAleatorio(int desde,int hasta,int iniciar)
{
    if(iniciar)
        srand(time(NULL));
    return desde + (rand()%(hasta+1-desde));
}

//Pide un string y lo devuelve
void input_getString(char mensaje[],char input[])
{
    printf(mensaje);
    fflush(stdin);
    scanf("%s",input);
}

//Pide valores alfanumericos con punto y coma, y lo devuelve
void input_getStringLetEsp(char mensaje[],char input[])
{
    printf(mensaje);
    fflush(stdin);
    scanf("%[a-zA-Z0-9., ]",input);
}

//Pide cadena de caracteres compuesta por letras y la devuelve
int input_getStringLetras(char mensaje[],char input[],int longMin,int longMax)
{
    char aux[256];
    int funcRetorno=-1;

    if((longMin>0 && longMax>0) && (longMin<=longMax) && longMax<=255)
    {
        input_getString(mensaje,aux);
        if(validaciones_esSoloLetras(aux) && strlen(aux)>=longMin && strlen(aux)<=longMax)
        {
            strcpy(input,aux);
            funcRetorno=0;
        }
    }
    return funcRetorno;
}

//Pide cadena de caracteres compuesta por letras y la devuelve
int input_getStringLetrasEspacios(char mensaje[],char input[],int longMin,int longMax)
{
    char aux[256];
    int funcRetorno=-1;

    if((longMin>0 && longMax>0) && (longMin<=longMax) && longMax<=255)
    {
        input_getStringLetEsp(mensaje,aux);
        if(validaciones_esAlfanumerico(aux))
        {
            strcpy(input,aux);
            funcRetorno=0;
        }
        else
            funcRetorno=-2;
    }
    return funcRetorno;
}

//Solicita numeros y los devuelve con rango de minimo y maximo
int input_getStringNumeros(char mensaje[],char input[],int minNum,int maxNum)
{
    char aux[256];
    int funcRetorno=-1;

    if(minNum<=maxNum)
    {
        input_getString(mensaje,aux);
        if(validaciones_esNumerico(aux) && (atoi(aux)>=minNum && atoi(aux)<=maxNum))
        {
            strcpy(input,aux);
            funcRetorno=0;
        }
    }

    return funcRetorno;
}

//Solicita numeros long con rango de minimo y maximo
int input_getStringNumerosLong(char mensaje[],char input[],long minNum,long maxNum)
{
    char aux[256];
    int funcRetorno=-1;

    if(minNum<=maxNum)
    {
        input_getString(mensaje,aux);
        if(validaciones_esNumerico(aux) && (atol(aux)>=minNum && atol(aux)<=maxNum))
        {
            strcpy(input,aux);
            funcRetorno=0;
        }
    }

    return funcRetorno;
}

//Solicita numeros flotantes
int input_getStringFloat(char mensaje[],char input[])
{
    char aux[256];
    input_getString(mensaje,aux);
    if(validaciones_esFlotante(aux))
    {
        strcpy(input,aux);
        return 0;
    }
    return -1;
}

//Inicializa un array de enteros
void input_inicializarArrayInt(int array[],int cantElementos,int valor)
{
    int i;
    for(i=0;i<cantElementos;i++)
        array[i]=valor;
}

//Solicita un numero entero con rango de minimo y maximo
int input_getInt(char* msg,char* msgE,int cIntentos,long numMin,long numMax,int* result)
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

//Carga secuencialmente un array de numeros enteros
int input_loadIntArrayElements(int* intArray,int qtyArrayElem)
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
                retGetInt=input_getInt("Ingrese un numero: ","Error desconocido!",100,-32768,32767,&intArray[i]);
            }while(retGetInt!=0);
        }
    }

    return error;
}

//Muestra un array de enteros con posibilidad de pausar cada 20 lineas
int input_mostrarArrayInt(int* array,int cantidad,int conPausa)
{
    int i;
    printf(" / ");
    for(i=0;i<cantidad;i++)
    {
        printf("%d ",array[i]);

        if(i!=0 && i%20==0 && conPausa!=0)
            system("pause");
    }
    return 0;
}

//Solicita al usuario ingresar un numero de CUIT
int input_getStringCUIT(char mensaje[],char input[],int longMin,int longMax)
{
    int funcRetorno=-1;
    char aux[256];

    if((longMin>0 && longMax>0) && (longMin<=longMax) && longMax<=255)
    {
        input_getString(mensaje,aux);
        if(validaciones_esCUIT(aux) && strlen(aux)>=longMin && strlen(aux)<=longMax)
        {
            strcpy(input,aux);
            funcRetorno=0;
        }
    }
    return funcRetorno;
}
