#include <stdio.h>
#include "archivos.h"

int existeArchivo(char* path)
{
    FILE* archivo;
    if((archivo=fopen(path,"rb"))==NULL)
        return 0;
    else
    {
        fclose(archivo);
        return 1;
    }
}

long int tamArchivo(FILE* archivo)
{
    long int cursorArchivo=0;

    if(archivo==NULL)
        return -1;
    else
    {
        fseek(archivo,0,SEEK_END);
        cursorArchivo=ftell(archivo);
        return cursorArchivo;
    }
}

int desplazarCursorInicioArchivo(FILE* archivo)
{
    if(archivo==NULL)
        return -1;
    else
    {
        rewind(archivo);
        return 0;
    }
}

int desplazarCursorFinalArchivo(FILE* archivo)
{
    if(archivo==NULL)
        return -1;
    else
    {
        fseek(archivo,0,SEEK_END);
        return 0;
    }
}

int desplazarCursorPosicionArchivo(FILE* archivo,long int cantBytes,int retroceder)
{
    if(archivo==NULL)
        return -1;
    if(cantBytes<0)
        return -2;
    if(retroceder!=1 && retroceder!=0)
        return -3;
    if(ftell(archivo)<cantBytes && retroceder)
        return -4;
    if((ftell(archivo)<(ftell(archivo)+cantBytes)) && !retroceder)
        return -5;

    if(!retroceder)
        fseek(archivo,cantBytes,SEEK_CUR);
    else
        fseek(archivo,-(cantBytes),SEEK_CUR);

    return 0;
}
