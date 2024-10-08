#include <stdio.h>
#include <math.h>
#define PI 3.141516


float radio = 0;
int opcion;
float x = 0;
float y = 0;

float figurasCuadrado[10];
float figurasTriangulo[10][10];
float figurasRectangulo[10][10];
float figurasCirculo[10];

float coordenadasCuadrados[10][10];
float coordenadasTriangulos[10][10];
float coordenadasRectangulos[10][10];
float coordenadasCirculo[10][10];

char mensajeBienvenida[50] = "Bienvenido. Introduce la operacion a realizar \n";
float calcularAreaCirculo(float radio);
void imprimirListaFunciones();
float calcularAreaCuadrado(float lado);
float calcularAreaRectangulo(float base, float altura);
void calcularAreas(int opcion);
void trasladarCoordenadas(float *x, float *y, float desplazamientoX, float desplazamientoY);

int main() {
    printf(mensajeBienvenida);
    imprimirListaFunciones();
    scanf("%d", &opcion);
    calcularAreas(opcion);
    

    return 0;
}
void imprimirListaFunciones(){
    printf("1. Area de Circulo \n 2. Area de Cuadrado \n 3. Area de Esfera \n 4. Area de rectangulo \n 5.Area de triangulo \n 6. Revisar figuras \n 7. Trasladar Figura");
}
void administrarFigura(int tipo){
    switch (tipo)
    {
    case 1:
        printf("Crear figura");
        break;
    case 2: 
        printf("Modificar figura");
        break;
    case 3:
        printf("Graficar figura");
        break;
    case 4: 
        printf("Eliminar figura");
    
    default:
        printf("No existe esa figura");
        break;
    }
}
void crearCuadrado(){
    int lado=0;
    int area= 0;
    int cantidadFiguras = 0;
    printf("||Creacion de cuadrado||\n");
    printf("Introduzca el valor del lado en cm:\n");
    scanf("%d",&lado);
    area = calcularAreaCuadrado(lado);
    cantidadFiguras = sizeof(figurasCuadrado);
    if(cantidadFiguras == 0){
        figurasCuadrado[0]= lado;
        coordenadasCuadrados[0][0] = 10+cantidadFiguras*0.5;
        coordenadasCuadrados[0][1] = 10+cantidadFiguras*0.5;
    }
    else{
        figurasCuadrado[(cantidadFiguras)+1]= lado;
        coordenadasCuadrados[cantidadFiguras*2+1][0] = 10+cantidadFiguras*0.5;
        coordenadasCuadrados[0][1] = 10+cantidadFiguras*0.5;
    }

}
int contarFiguras(int tipo){
    int tamanoFiguras=0;
    int tamanoCoordenadasFigurasx = 0;
    int tamanoCoordenadasFigurasy = 0;
switch (tipo)
{
case 1:
    tamanoFiguras = sizeof(figurasCuadrado);
    tamanoCoordenadasFigurasx = sizeof(coordenadasCuadrados[][]);
    break;

default:
    break;
}
}
void crearCirculo(){

}
void crearRectangulo(){

}
void crearTriangulo(){

}
void calcularAreas(int opcion){
    switch (opcion)
    {
    case 1:
        calcularAreaCirculo(float radio);
        break;
    case 2: 
        calcularAreaCuadrado(float lado);
        break;
    case 3: 
        calcularAreaRectangulo(float base, float altura);
        break;
    case 4:
        calcularAreaTriangulo(float base, float altura);    
    default:
        printf("La opcion no es valida");
        break;
    }
}
float calcularAreaCirculo(float radio){
    float areaCirculo = 0;
    areaCirculo = (float)PI * ((radio)*(radio));
    printf("El valor del area del círculo es: %f", areaCirculo);
    return areaCirculo;
}
float calcularAreaCuadrado(float lado){
    float areaCuadrado = 0;
    areaCuadrado = lado * lado;
    printf("El valor del area del cuadrado es: %f", areaCuadrado);
    return areaCuadrado;
}
float calcularAreaRectangulo(float base, float altura){
    float areaRectangulo = 0;
    float base = 0;
    float altura = 0;
    areaRectangulo = base*altura;
    return areaRectangulo;
}
float calcularAreaTriangulo(float base, float altura){
    float areaTriangulo = 0;
    areaTriangulo = (base*altura)/2;
    printf("El area del triangulo es: %f", areaTriangulo);
    return areaTriangulo;
}

void convertirCartesianoAEsfericofloat (float *x, float *y, float *radio, float *angulo){

*radio = sqrt((*x) * (*x) + (*y) * (*y));
*angulo = atan2(*y, *x);  

printf("Los valores son: angulo: %f, radio: %f",*radio,*angulo);
}

void trasladarCoordenadas(float *x, float *y, float desplazamientoX, float desplazamientoY){
     *x = *x + desplazamientoX;  // Actualiza el valor de x aplicando la traslación en x
    *y = *y + desplazamientoY;  // Actualiza el valor de y aplicando la traslación en y
}
