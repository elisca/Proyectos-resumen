#include <stdio.h>
#include <stdlib.h>

int getInt(char mensaje[])
{
    int num;

    printf("%s",mensaje);
    scanf("%d",&num);

    return num;
}

float getFloat(char mensaje[])
{
    float num;

    printf("%s",mensaje);
    scanf("%f",&num);

    return num;
}

char getChar(char mensaje[])
{
    char caracter;

    printf("%s",mensaje);
    fflush(stdin);
    //fpurge(stdin); Usar para Linux y OSx.
    scanf("%c",&caracter);

    return caracter;
}
