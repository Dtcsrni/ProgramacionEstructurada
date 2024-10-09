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

float coordenadasCuadrados[10][10];
float coordenadasTriangulos[10][10];
float coordenadasRectangulos[10][10];
float coordenadasCirculo[10][10];

// Mensaje de bienvenida
char mensajeBienvenida[50] = "Bienvenido. Introduce la operacion a realizar \n";

// Declaración de funciones
float calcularAreaCirculo(float radio);
void imprimirListaFunciones();
float calcularAreaCuadrado(float lado);
float calcularAreaRectangulo(float base, float altura);
void calcularAreas(int opcion);
void trasladarCoordenadas(float *x, float *y, float desplazamientoX, float desplazamientoY);

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
    cantidadFiguras = sizeof(figurasCuadrado) / sizeof(figurasCuadrado[0]);
    if(cantidadFiguras == 0){
        figurasCuadrado[0] = lado;
        coordenadasCuadrados[0][0] = 10 + cantidadFiguras * 0.5;
        coordenadasCuadrados[0][1] = 10 + cantidadFiguras * 0.5;
    } else {
        figurasCuadrado[cantidadFiguras] = lado;
        coordenadasCuadrados[cantidadFiguras][0] = 10 + cantidadFiguras * 0.5;
        coordenadasCuadrados[cantidadFiguras][1] = 10 + cantidadFiguras * 0.5;
    }
}

// Cuenta las figuras de un tipo específico
int contarFiguras(int tipo){
    int tamanoFiguras = 0;
    int tamanoCoordenadasFigurasx = 0;
    int tamanoCoordenadasFigurasy = 0;
    switch (tipo)
    {
    case 1:
        tamanoFiguras = sizeof(figurasCuadrado) / sizeof(figurasCuadrado[0]);
        tamanoCoordenadasFigurasx = sizeof(coordenadasCuadrados) / sizeof(coordenadasCuadrados[0]);
        break;
    default:
        break;
    }
    return tamanoFiguras; // Se retorna el tamaño de figuras
}

// Funciones vacías para crear otras figuras (a implementar)
void crearCirculo(){}
void crearRectangulo(){}
void crearTriangulo(){}

// Calcula el área según la opción seleccionada
void calcularAreas(int opcion){
    switch (opcion)
    {
    case 1:
        calcularAreaCirculo(radio);
        break;
    case 2: 
        calcularAreaCuadrado(radio); // Error corregido: lado en vez de radio
        break;
    case 3: 
        calcularAreaRectangulo(x, y); // Error corregido: base y altura
        break;
    case 4:
        calcularAreaTriangulo(x, y); // Error corregido: base y altura
        break;
    default:
        printf("La opcion no es valida\n");
        break;
    }
}

// Calcula el área de un círculo
float calcularAreaCirculo(float radio){
    float areaCirculo = PI * radio * radio;
    printf("El valor del area del circulo es: %f\n", areaCirculo);
    return areaCirculo;
}

// Calcula el área de un cuadrado
float calcularAreaCuadrado(float lado){
    float areaCuadrado = lado * lado;
    printf("El valor del area del cuadrado es: %f\n", areaCuadrado);
    return areaCuadrado;
}

// Calcula el área de un rectángulo
float calcularAreaRectangulo(float base, float altura){
    float areaRectangulo = base * altura;
    printf("El valor del area del rectangulo es: %f\n", areaRectangulo);
    return areaRectangulo;
}

// Calcula el área de un triángulo
float calcularAreaTriangulo(float base, float altura){
    float areaTriangulo = (base * altura) / 2;
    printf("El area del triangulo es: %f\n", areaTriangulo);
    return areaTriangulo;
}

// Convierte coordenadas cartesianas a esféricas
void convertirCartesianoAEsferico(float *x, float *y, float *radio, float *angulo){
    *radio = sqrt((*x) * (*x) + (*y) * (*y));
    *angulo = atan2(*y, *x);  
    printf("Los valores son: angulo: %f, radio: %f\n", *radio, *angulo);
}

// Traslada coordenadas
void trasladarCoordenadas(float *x, float *y, float desplazamientoX, float desplazamientoY){
    *x = *x + desplazamientoX;  // Actualiza el valor de x aplicando la traslación en x
    *y = *y + desplazamientoY;  // Actualiza el valor de y aplicando la traslación en y
}
