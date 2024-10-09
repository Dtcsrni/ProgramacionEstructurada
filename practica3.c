#include <stdio.h>
#include <math.h>
#define PI 3.141516

// Variables globales
float radio = 0;
int opcion;
float x = 0;
float y = 0;

// Arreglos para almacenar figuras y sus coordenadas
float figurasCuadrado[10];
float figurasTriangulo[10][10];
float figurasRectangulo[10][10];
float figurasCirculo[10];

float coordenadasCuadrados[10][2];
float coordenadasTriangulos[10][2];
float coordenadasRectangulos[10][2];
float coordenadasCirculo[10][2];

// Mensaje de bienvenida
char mensajeBienvenida[50] = "Bienvenido. Introduce la operacion a realizar \n";

// Declaración de funciones
float calcularAreaCirculo(float radio);
void imprimirListaFunciones();
float calcularAreaCuadrado(float lado);
float calcularAreaRectangulo(float base, float altura);
void calcularAreas(int opcion);
void trasladarCoordenadas(float *x, float *y, float desplazamientoX, float desplazamientoY);
void crearCuadrado();

int main() {
    printf("%s", mensajeBienvenida);
    imprimirListaFunciones();
    scanf("%d", &opcion);
    calcularAreas(opcion);
    
    return 0;
}

// Imprime la lista de funciones disponibles
void imprimirListaFunciones(){
    printf("1. Area de Circulo \n2. Area de Cuadrado \n3. Area de Esfera \n4. Area de Rectangulo \n5. Area de Triangulo \n6. Revisar Figuras \n7. Trasladar Figura\n");
}

// Administra las operaciones sobre las figuras
void administrarFigura(int tipo){
    switch (tipo)
    {
    case 1:
        printf("Crear figura\n");
        break;
    case 2: 
        printf("Modificar figura\n");
        break;
    case 3:
        printf("Graficar figura\n");
        break;
    case 4: 
        printf("Eliminar figura\n");
        break;
    default:
        printf("No existe esa figura\n");
        break;
    }
}

// Crea un cuadrado y almacena sus datos
void crearCuadrado(){
    int lado = 0;
    float area = 0;
    int cantidadFiguras = 0;
    
    printf("||Creacion de cuadrado||\n");
    printf("Introduzca el valor del lado en cm:\n");
    scanf("%d", &lado);
    area = calcularAreaCuadrado(lado);
    
    // Contar la cantidad de figuras actualmente almacenadas
    for (int i = 0; i < 10; i++) {
        if (figurasCuadrado[i] != 0) {
            cantidadFiguras++;
        }
    }
    
    if(cantidadFiguras < 10){
        figurasCuadrado[cantidadFiguras] = lado;
        coordenadasCuadrados[cantidadFiguras][0] = 10 + cantidadFiguras * 0.5;
        coordenadasCuadrados[cantidadFiguras][1] = 10 + cantidadFiguras * 0.5;
        printf("Cuadrado creado con lado de %d cm en la posición (%f, %f)\n", lado, coordenadasCuadrados[cantidadFiguras][0], coordenadasCuadrados[cantidadFiguras][1]);
    } else {
        printf("No se pueden crear más cuadrados, el límite es 10.\n");
    }
}

// Calcula el área de un cuadrado
float calcularAreaCuadrado(float lado){
    float areaCuadrado = lado * lado;
    printf("El valor del area del cuadrado es: %f\n", areaCuadrado);
    return areaCuadrado;
}
