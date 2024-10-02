#include <stdio.h>

int numerosDesordenados[10] ={4,6,7,8,3,9,0,1,4,5 };
int numerosOrdenados[] = {0,0,0,0,0,0,0,0,0,0};
int numeroActual = 0;
int numeroSiguiente = 0;

int main(){
    for(int i=0; i<10;i++){
        numeroActual = numerosDesordenados[i];
        numeroSiguiente = numerosDesordenados[i+1];
        printf("--------------------------------\n");
        printf("El valor actual es:%d, iteracion: %d \n",numeroActual,i);
        printf("El valor siguiente es:%d, iteracion:%d \n",numeroSiguiente,i);
        

        if(numeroActual<numeroSiguiente){
            numerosOrdenados[i]=numeroActual;
            numeroActual=numeroSiguiente;
        }
        else if(numeroActual>numeroSiguiente){
            numerosOrdenados[i]=numeroSiguiente;
            numerosOrdenados[i+1]=numeroActual;    
        }
        
    }
     printf("--------------------------------\n");
     printf("Finaliza ordenamiento\n");
     printf("--------------------------------\n");
    for(int i = 0; i<9; i++){
        printf("--------------------------------\n");
        printf("El valor es:%d \n",numerosOrdenados[i]);
         printf("iteracion: %d \n",i);
       
       printf("--------------------------------\n");
    }


    return 0;
}
