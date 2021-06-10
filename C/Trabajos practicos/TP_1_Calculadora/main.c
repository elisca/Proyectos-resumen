#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //Unicamente para convertir a minuscula cualquier respuesta del usuario al intentar salir del programa.
#include "func_mat.h" //Funciones de calculos matematicos.
#include "input.h" //Mensajes y funciones para ingresar datos desde teclado.

int main()
{
    char salir='n'; //Respuesta opcion salir.
    int menuOpc; //Opcion seleccionada por el usuario en el menu.
    int menuMinOpc=1; //Opcion minima permitida en el menu.
    int menuMaxOpc=2; //Opcion maxima permitida en el menu (no incluye este limite a la opcion Salir).
    int flagOp1=0; //Bandera para indicar si el operando 1 ya fue cargado.
    int flagOp2=0; //Bandera para indicar si el operando 2 ya fue cargado.
    int resFactorial; //Resultado del factorial (siempre es entero).
    int nFactorial; //Numero para calcular su factorial (siempre es entero).
    float op1=0; //Operando 1.
    float op2=0; //Operando 2.
    float resultado; //Resultado de calculo.

    while(salir=='n')//Menu de opciones
    {
        system("cls");

        if(flagOp1==1 && flagOp2==1)//Si ya fueron cargados los dos operandos, muestra el menu completo y habilita esas opciones.
        {
            menuMaxOpc=9;

            printf("MENU DE OPCIONES:\n");
            printf("__________________________________________________\n\n");
            printf("1. Ingresar 1er operando (A=%.2f)\n",op1);
            printf("2. Ingresar 2do operando (B=%.2f)\n",op2);
            printf("3. Calcular la suma (A+B)\n");
            printf("4. Calcular la resta (A-B)\n");
            printf("5. Calcular la division (A/B)\n");
            printf("6. Calcular la multiplicacion (A*B)\n");
            printf("7. Calcular el factorial (A!)\n");
            printf("8. Calcular todas las operaciones\n");
        }
        else//Si falta cargar alguno de los operandos, unicamente se puede elegir cual cargar o salir, las demas opciones no se ven y estan inhabilitadas.
        {
            menuMaxOpc=2;

            printf("MENU DE OPCIONES:\n");
            printf("__________________________________________________\n\n");
            printf("Asigne un valor a los operandos antes de visualizar las opciones de calculo.\n");
            printf("1. Ingresar 1er operando (A=%.2f)\n",op1);
            printf("2. Ingresar 2do operando (B=%.2f)\n",op2);
        }
        printf("9. Salir\n");

        menuOpc=getInt("Opcion: ");

        while((menuOpc<menuMinOpc || menuOpc>menuMaxOpc) && menuOpc!=9)//Nos obliga a reingresar una opcion hasta elegir alguna que sea valida.
            menuOpc=getInt("ERROR: Opcion incorrecta. Reingrese por favor: ");

        system("cls");

        switch(menuOpc)//Actua segun la opcion seleccionada por el usuario.
        {
            case 1://Carga por teclado el operando 1.
                op1=getFloat("Ingrese el valor para el primer operando (A): ");
                flagOp1=1;
                break;
            case 2://Carga por teclado el operando 2.
                op2=getFloat("Ingrese el valor para el segundo operando (B): ");
                flagOp2=1;
                break;
            case 3://Suma y muestra el resultado si no hubo error.
                if(matSuma(op1,op2,&resultado)!=0)
                    printf("Error al intentar sumar. Revise que el posible resultado no exceda la memoria, y que haya ingresado solo numeros. Intente nuevamente.\n");
                else
                    printf("Resultado de la suma (%.2f+%.2f): %.2f\n",op1,op2,resultado);
                break;
            case 4://Resta y muestra el resultado si no hubo error.
                if(matResta(op1,op2,&resultado)!=0)
                    printf("Error al intentar restar. Revise que el posible resultado no exceda la memoria, y que haya ingresado solo numeros. Intente nuevamente.\n");
                else
                    printf("Resultado de la resta (%.2f-%.2f): %.2f\n",op1,op2,resultado);
                break;
            case 5://Divide y muestra el resultado si no hubo error.
                if(matDivision(op1,op2,&resultado)!=0)
                    printf("ERROR: Revise que el Operando 2(Divisor) no sea cero, y que haya ingresado solamente numeros. Intente nuevamente.\n",op1,op2,resultado);
                else
                    printf("Resultado de la division (%.2f/%.2f): %.2f\n",op1,op2,resultado);
                break;
            case 6://Multiplica y muestra el resultado si no hubo error.
                if(matMultipl(op1,op2,&resultado)!=0)
                    printf("Error al intentar multiplicar. Revise que el posible resultado no exceda la memoria, y que haya ingresado solo numeros. Intente nuevamente.\n");
                else
                    printf("Resultado de la multiplicacion (%.2f*%.2f): %.2f\n",op1,op2,resultado);
                break;
            case 7://Aplica factorial y muestra el resultado si no hubo error.
                nFactorial=(int)op1;

                if(matFactorial(nFactorial,&resFactorial)!=0)
                    printf("Error: Los factoriales deben ser de numeros enteros naturales o cero. Reintente nuevamente.\n");
                else
                    printf("Resultado del factorial %d!: %d\n",nFactorial,resFactorial);
                break;
            case 8://Calcula todas las operaciones y las muestra, o sus errores en caso de haberlos.
                if(matSuma(op1,op2,&resultado)!=0)
                    printf("Error al intentar sumar. Revise que el posible resultado no exceda la memoria, y que haya ingresado solo numeros. Intente nuevamente.\n");
                else
                    printf("Resultado de la suma (%.2f+%.2f): %.2f\n",op1,op2,resultado);

                if(matResta(op1,op2,&resultado)!=0)
                    printf("Error al intentar restar. Revise que el posible resultado no exceda la memoria, y que haya ingresado solo numeros. Intente nuevamente.\n");
                else
                    printf("Resultado de la resta (%.2f-%.2f): %.2f\n",op1,op2,resultado);

                if(matDivision(op1,op2,&resultado)!=0)
                    printf("ERROR: Revise que el Operando 2(Divisor) no sea cero, y que haya ingresado solamente numeros. Intente nuevamente\n",op1,op2,resultado);
                else
                    printf("Resultado de la division (%.2f/%.2f): %.2f\n",op1,op2,resultado);

                if(matMultipl(op1,op2,&resultado)!=0)
                    printf("Error al intentar multiplicar. Revise que el posible resultado no exceda la memoria, y que haya ingresado solo numeros. Intente nuevamente.\n");
                else
                    printf("Resultado de la multiplicacion (%.2f*%.2f): %.2f\n",op1,op2,resultado);

                if(op1<0)
                    printf("ERROR: No se admiten factoriales de numeros negativos. Modifique el primer operando antes de calcular.\n");
                else if(op1==0)
                {
                    resultado=1;//Por convencion matematica, el factorial de cero es 1.
                    printf("Resultado del factorial %d!: %d\n",(int)op1,(int)resultado);
                }
                else
                {
                    nFactorial=(int)op1;

                    if(matFactorial(nFactorial,&resFactorial)!=0)
                        printf("Error: Los factoriales deben ser de numeros enteros naturales o cero. Reintente nuevamente.\n");
                    else
                        printf("Resultado del factorial %d!: %d\n",nFactorial,resFactorial);
                    }
                break;
            case 9://Salir, nos pide confirmar la eleccion.
                do
                {
                    salir=getChar("Desea salir? (s/n): ");
                    salir=tolower(salir);
                }while(salir!='s' && salir!='n');
                break;
        }

        if(menuOpc!=1 && menuOpc!=2 && menuOpc!=9)//Si no es una opcion que muestre un resultado, debe pausarse la consola para visualizar el calculo y su resultado.
            system("pause");
    }

    return 0;
}
