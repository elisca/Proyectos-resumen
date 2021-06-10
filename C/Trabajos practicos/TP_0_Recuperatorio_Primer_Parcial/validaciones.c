#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

//Valida si un dato ingresado es numerico
int validaciones_esNumerico(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]<'0' || str[i]>'9')
            return 0;
        i++;
    }
    return 1;
}

//Valida si un dato ingresado contiene solamente letras
int validaciones_esSoloLetras(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if((str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z'))
            return 0;
        i++;
    }
    return 1;
}

//Valida si un dato ingresado contiene letras,numeros,espacios,puntos y/o comas
int validaciones_esAlfanumerico(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if((str[i]!=' ') && (str[i]!='.') && (str[i]!=',') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z') && (str[i]<'0' || str[i]>'9'))
            return 0;
        i++;
    }
    return 1;
}

//Valida si un dato es telefono
int validaciones_esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;

    while(str[i]!='\0')
    {
        if((str[i]!=' ') && (str[i]!='-') && (str[i]<'0' || str[i]>'9'))
            return 0;
        if(str[i]=='-')
            contadorGuiones++;
        i++;
    }

    if(contadorGuiones>=1)
        return 1;

    return 0;
}

//Valida si un dato es flotante
int validaciones_esFlotante(char* numFlot)
{
    int esFlot=1,i,flagPuntos=0;

    for(i=0;numFlot[i]!='\0';i++)
        if((numFlot[i]<'0' || numFlot[i]>'9') && numFlot[i]!='.')
        {
            esFlot=0;
            break;
        }
        else if(numFlot[i]=='.')
        {
            if(flagPuntos==0)
            {
                flagPuntos=1;
            }
            else
            {
                esFlot=0;
                break;
            }
        }

    return esFlot;
}

//Valida si un dato corresponde a una direccion de email
int validaciones_esEmailValido(char* direccionEmail,int longMinUsuario,int longMinDominio)
{
    int esEmailOK=1,i,flagArroba=0,auxArroba,auxPunto;

    for(i=0;direccionEmail[i]!='\0';i++)
    {
        if((direccionEmail[i]<'a' || direccionEmail[i]>'z') && (direccionEmail[i]<'A' || direccionEmail[i]>'Z') && (direccionEmail[i]<'0' || direccionEmail[i]>'9') && direccionEmail[i]!='.' && direccionEmail[i]!='_' && direccionEmail[i]!='-' && direccionEmail[i]!='@')
        {
            esEmailOK=0;
            break;
        }
        else if(direccionEmail[i]=='@')
        {
            auxArroba=i;

            if(flagArroba==1 || auxArroba<longMinUsuario)
            {
                esEmailOK=0;
                break;
            }
            else
                flagArroba=1;
        }
        else if(direccionEmail[i]=='.')
        {
            if(flagArroba==1 && i-auxArroba<=longMinDominio)
            {
                esEmailOK=0;
                break;
            }
            else
                auxPunto=i;
        }
    }

    if(i-1-auxPunto<1)
        esEmailOK=0;

    return esEmailOK;
}

//Valida si un numero corresponde a un CUIT
int validaciones_esCUIT(char str[])
{
    int i=0;

    while(str[i]!='\0')
    {
        if(str[i]!='-' && (str[i]<'0' || str[i]>'9'))
            return 0;
        i++;
    }
    return 1;
}
