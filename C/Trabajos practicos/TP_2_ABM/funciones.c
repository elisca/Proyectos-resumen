#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"

#define F_ESTADO_LIBRE 0
#define F_ESTADO_OCUPADO 1

int compactarEPersona(EPersona* array,int tamArrayNums,int ascend)
{
    int fError=-1,flagSwap,i,conAltas=0;//auxIntSwap
    //char auxCharSwap[256];
    EPersona auxEPersona;

    if(tamArrayNums<1 || (ascend<0 || ascend>1))
        return fError;

    do
    {
        flagSwap=0;

        for(i=0;i<tamArrayNums-1;i++)
        {
            if(array[i].estado || array[i+1].estado)
                conAltas=1;

            if((ascend && array[i].estado>array[i+1].estado) || (!ascend && array[i].estado<array[i+1].estado))
            {
                auxEPersona=array[i];
                array[i]=array[i+1];
                array[i+1]=auxEPersona;

                flagSwap=1;
            }
        }
        if(conAltas)
            fError=0;
        else
            fError=-2;
    }while(flagSwap==1);
    return fError;
}

int arrayEPersonaConAltas(EPersona* lista,int cantLista,int valorAlta)
{
    int conAltas=0,i;

    for(i=0;i<cantLista;i++)
        if(lista[i].estado==valorAlta)
        {
            conAltas=1;
            break;
        }

    return conAltas;
}

int initArrayPersonas(EPersona lista[],int cantLista)
{
    int i,funcRetorno=-1;

    if(cantLista>0)
    {
        for(i=0;i<cantLista;i++)
        {
            lista[i].estado=F_ESTADO_LIBRE;
            lista[i].edad=0;
            lista[i].dni=0;
            strcpy(lista[i].nombre,"");
        }
        funcRetorno=0;
    }

    return funcRetorno;
}

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
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

int esNumerico(char str[])
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

int esSoloLetras(char str[])
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

int esAlfanumerico(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if((str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z') && (str[i]<'0' || str[i]>'9'))
            return 0;
        i++;
    }
    return 1;
}

int esTelefono(char str[])
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

void getString(char mensaje[],char input[])
{
    printf(mensaje);
    fflush(stdin);
    scanf("%s",input);
}

void getStringLetEsp(char mensaje[],char input[])
{
    printf(mensaje);
    fflush(stdin);
    scanf("%[a-zA-Z0-9 ]",input);
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

int getStringLetrasEspacios(char mensaje[],char input[],int longMin,int longMax)
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
}

int getStringNumeros(char mensaje[],char input[],int minNum,int maxNum)
{
    char aux[256];
    int funcRetorno=-1;

    if(minNum<=maxNum)
    {
        getString(mensaje,aux);
        if(esNumerico(aux) && (atoi(aux)>=minNum && atoi(aux)<=maxNum))
        {
            strcpy(input,aux);
            funcRetorno=0;
        }
    }

    return funcRetorno;
}

int getStringNumerosLong(char mensaje[],char input[],long minNum,long maxNum)
{
    char aux[256];
    int funcRetorno=-1;

    if(minNum<=maxNum)
    {
        getString(mensaje,aux);
        if(esNumerico(aux) && (atol(aux)>=minNum && atol(aux)<=maxNum))
        {
            strcpy(input,aux);
            funcRetorno=0;
        }
    }

    return funcRetorno;
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

void inicializarArrayInt(int array[],int cantElementos,int valor)
{
    int i;
    for(i=0;i<cantElementos;i++)
        array[i]=valor;
}

int buscarPrimeraOcurrencia(EPersona array[],int cantElementos,int dni)
{
    int i,funcRetorno=-1;

    if(cantElementos>0 && dni>=0)
        for(i=0;i<cantElementos;i++)
            if(array[i].dni==dni)
                return i;

    return funcRetorno;
}

int buscarLibre(EPersona array[],int cantElementos)
{
    int i,funcRetorno=-1;

    if(cantElementos>0)
        for(i=0;i<cantElementos;i++)
            if(array[i].estado==F_ESTADO_LIBRE)
                return i;
    return funcRetorno;
}

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

int loadIntArrayElements(int* intArray,int qtyArrayElem)
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
                retGetInt=getInt("Ingrese un numero: ","Error desconocido!",100,-32768,32767,&intArray[i]);
            }while(retGetInt!=0);
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

int mostrarArrayEPersona(EPersona* array,int cantidad,int debug)
{
    int i,funcRetorno=-1;

    if(cantidad>0)
    {
        for(i=0;i<cantidad;i++)
        {
            if(debug!=0)
                printf("[DEBUG] ID: %d \tNombre: %s \tEdad: %d \tDNI: %d \tEstado: %d\n",i,array[i].nombre,array[i].edad,array[i].dni,array[i].estado);
            else if(array[i].estado==1)
                printf("Nombre: %s \tEdad: %d \tDNI: %d\n",array[i].nombre,array[i].edad,array[i].dni);
        }
        funcRetorno=0;
    }

    return funcRetorno;
}

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

int burbujeoMejoradoEPersonaXNombres(EPersona* array,int tamArrayNums,int ascend)
{
    int fError=-1,flagSwap,i,conAltas=0;//auxIntSwap
    //char auxCharSwap[256];
    EPersona auxEPersona;

    if(tamArrayNums<1 || (ascend<0 || ascend>1))
        return fError;

    do
    {
        flagSwap=0;

        for(i=0;i<tamArrayNums-1;i++)
        {
            if(array[i].estado || array[i+1].estado)
                conAltas=1;

            if((ascend==1 && strcmp(array[i].nombre,array[i+1].nombre)>0 && array[i].estado) || (ascend==0 && strcmp(array[i].nombre,array[i+1].nombre)<0 && array[i].estado))
            {
                auxEPersona=array[i];
                array[i]=array[i+1];
                array[i+1]=auxEPersona;

                flagSwap=1;
            }
        }
        if(conAltas)
            fError=0;
        else
            fError=-2;
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

int esFlotante(char* numFlot)
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

int esEmailValido(char* direccionEmail,int longMinUsuario,int longMinDominio)
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

int graficoGruposEdades(EPersona* array,int cantArray,char caracterGrafico)
{
    int i,edad,cont18=0,cont19_35=0,cont36=0,contPersonasAlta=0,aConAltas=0,funcRetorno;

    if(cantArray<=0)
        funcRetorno=-1;
    else if(array==NULL)
        funcRetorno=-2;
    else if(caracterGrafico==' ')
        funcRetorno=-3;
    else
    {
        for(i=0;i<cantArray;i++)
        {
            if(array[i].estado)
            {
                aConAltas=1;
                contPersonasAlta++;

                edad=array[i].edad;
                if(edad<=18)
                    cont18++;
                else if(edad>=19 && edad<35)
                    cont19_35++;
                else if(edad>=36)
                    cont36++;
            }
        }

        if(!aConAltas)
           funcRetorno=-4;
        else
        {
            for(i=contPersonasAlta;i>0;i--)
            {
                if(cont18>0 && cont18>=contPersonasAlta)
                {
                    printf("\n   %c   ",caracterGrafico);
                    cont18--;
                }
                else
                    printf("\n       ",caracterGrafico);

                if(cont19_35>0 && cont19_35>=contPersonasAlta)
                {
                    printf("   %c   ",caracterGrafico);
                    cont19_35--;
                }
                else
                    printf("       ",caracterGrafico);

                if(cont36>0 && cont36>=contPersonasAlta)
                {
                    printf("   %c   ",caracterGrafico);
                    cont36--;
                }
                else
                    printf("       ",caracterGrafico);
                contPersonasAlta--;
            }

            printf("\n  <18   19a35   36+\n",caracterGrafico);

            funcRetorno=0;
        }
    }

    return funcRetorno;
}
