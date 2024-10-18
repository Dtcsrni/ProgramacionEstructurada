#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUMEROS 5
int opcion = 0;
int numeros[NUMEROS];
float sumarNumeros(int numeros[]);


int main()
{
    printf("Indica la opcion a elegir \n 1. Sumar\n 2. Restar\n 3. Multiplicar \n");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
    printf("Suma\n");
    printf("Ingresa %d numeros\n", NUMEROS);
        for (int i = 0; i < NUMEROS; i++)
        {
            printf("Ingresa el numero %d\n", i+1);
            scanf("%d", &numeros[i]);
        }
        if(numeros[0]<2){
            printf("El primer valor es menor que 2 \n");
        }
        if(numeros[1]>5){
            printf("El segundo valor es mayor que 5 \n");
        }
        if (numeros[0] == numeros[1])
        {
            printf("Los numeros en la posicion 0 y 1 son iguales\n");
        }
        else
        {
            printf("Los numeros en la posicion 1 y 2 no son iguales\n");
        }
        if(numeros[0]+numeros[1]+numeros[2]+numeros[3]+numeros[4]>10){
            printf("La suma de los numeros es mayor a 10\n");
        }

        if(sumarNumeros(numeros)>0){
            printf("La suma de los numeros es positiva\n");
        }
        else{
            printf("La suma de los numeros es negativa\n");
        }    

        
        
        break;

    default:
        break;
    }
    return 0;
}

float sumarNumeros(int numeros[]){
    float resultados = 0;
    int i = 0;
    while(resultados >0 && i<NUMEROS){
        resultados = resultados + numeros[i];
        i++;
    }
    return resultados;
}
