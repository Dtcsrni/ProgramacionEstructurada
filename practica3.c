#include <stdio.h>
#define PI 3.141516


float radio = 0;
int opcion;
char mensajeBienvenida[50] = "Bienvenido. Introduce la operacion a realizar \n";
float calcularAreaCirculo();
void imprimirListaFunciones();
float calcularAreaCuadrado();
float calcularAreaRectangulo();
void calcularAreas(int opcion);

int main() {
    printf(mensajeBienvenida);
    imprimirListaFunciones();
    scanf("%d", &opcion);
    calcularAreas(opcion);
    

    return 0;
}
void imprimirListaFunciones(){
    printf("1. Area de Circulo \n 2. Area de Cuadrado \n 3. Area de Esfera \n 4. Area de rectángulo \n");
}
void calcularAreas(int opcion){
    switch (opcion)
    {
    case 1:
        calcularAreaCirculo();
        break;
    case 2: 
        calcularAreaCuadrado();
        break;
    case 3: 
        calcularAreaRectangulo();
        break;
    default:
        printf("La opcion no es valida");
        break;
    }
}
float calcularAreaEsfera(){
    float radio = 0;
    float area = 0;
    scanf("%f", &radio);
    area = 4*(float)PI * (radio*radio);
    printf("El area de la esfera es %f", area);
    return area;
}

float calcularAreaCirculo(){
    float areaCirculo = 0;
    scanf("%f",&radio);
    areaCirculo = (float)PI * ((radio)*(radio));
    printf("El valor del area del círculo es: %f", areaCirculo);
    return areaCirculo;
}
float calcularAreaCuadrado(){
    float areaCuadrado = 0;
    float lado = 0;
    scanf("%f",&lado);
    areaCuadrado = lado * lado;
    printf("El valor del area del cuadrado es: %f", areaCuadrado);
    return areaCuadrado;
}
float calcularAreaRectangulo(){
    float areaRectangulo = 0;
    float base = 0;
    float altura = 0;
    printf("Indique el valor de la base:");
    scanf("%f",&base);
    printf("Indique el valor de la altura:");
    scanf("%f",&altura);
    areaRectangulo = base*altura;
    return areaRectangulo;
}

void convertirCartesianoAEsferico(float *coordenadasx, float *coordenaday){

}
