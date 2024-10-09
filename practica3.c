/**
 * Programa para la gestión de figuras geométricas en C.
 *
 * Este programa permite al usuario crear, modificar y eliminar figuras geométricas
 * como cuadrados, círculos, triángulos y rectángulos. El área de cada figura se
 * calcula y almacena junto con sus coordenadas. El programa sigue los principios
 * de la programación estructurada, promoviendo la modularidad y la claridad.
 *
 * En programación estructurada, el código se organiza en funciones y bloques lógicos,
 * lo que facilita su comprensión y mantenimiento. Este paradigma evita el uso de
 * instrucciones GOTO y promueve el uso de estructuras de control bien definidas.
 *
 * Autor: I.S.C Erick Renato Vega Ceron
 * Fecha: 2024
 */

#include <stdio.h>
#include <math.h>

#define PI 3.141516
#define MAX_FIGURAS 10

// Declaración de funciones
void mostrarMenuPrincipal();
void crearFigura();
void modificarFigura();
void eliminarFigura();
void mostrarMenuFiguras();
void crearCuadrado();
void crearCirculo();
void crearTriangulo();
void crearRectangulo();
float calcularAreaCuadrado(float lado);
float calcularAreaCirculo(float radio);
float calcularAreaTriangulo(float base, float altura);
float calcularAreaRectangulo(float base, float altura);

// Variables globales y estructuras de datos
float figurasCuadrado[MAX_FIGURAS];
float figurasCirculo[MAX_FIGURAS];
float figurasTriangulo[MAX_FIGURAS][2];  // Base y altura
float figurasRectangulo[MAX_FIGURAS][2]; // Base y altura

float coordenadasCuadrados[MAX_FIGURAS][2];
float coordenadasCirculo[MAX_FIGURAS][2];
float coordenadasTriangulos[MAX_FIGURAS][2];
float coordenadasRectangulos[MAX_FIGURAS][2];

// Función principal
int main() {
    printf("Bienvenido. Introduce la operacion a realizar\n");
    mostrarMenuPrincipal();
    return 0;
}

// Muestra el menú principal y gestiona la operación seleccionada
void mostrarMenuPrincipal() {
    int opcion;
    do {
        printf("1. Crear Figura\n");
        printf("2. Modificar Figura\n");
        printf("3. Eliminar Figura\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                crearFigura();
                break;
            case 2:
                modificarFigura();
                break;
            case 3:
                eliminarFigura();
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida\n");
                break;
        }
    } while(opcion != 4);
}

// Muestra el menú para crear figuras y gestiona la creación de la figura seleccionada
void crearFigura() {
    int opcion;
    mostrarMenuFiguras();
    scanf("%d", &opcion);
    
    switch(opcion) {
        case 1:
            crearCuadrado();
            break;
        case 2:
            crearCirculo();
            break;
        case 3:
            crearTriangulo();
            break;
        case 4:
            crearRectangulo();
            break;
        default:
            printf("Opción no válida\n");
            break;
    }
}

// Muestra el menú de tipos de figuras
void mostrarMenuFiguras(){
    printf("Seleccione el tipo de figura a crear:\n");
    printf("1. Cuadrado\n");
    printf("2. Circulo\n");
    printf("3. Triangulo\n");
    printf("4. Rectangulo\n");
}

// Crea un cuadrado y almacena sus datos
void crearCuadrado() {
    float lado;
    int cantidadFiguras = 0;
    
    printf("||Creacion de cuadrado||\n");
    printf("Introduzca el valor del lado en cm:\n");
    scanf("%f", &lado);

    // Contar la cantidad de figuras actualmente almacenadas
    for (int i = 0; i < MAX_FIGURAS; i++) {
        if (figurasCuadrado[i] != 0) {
            cantidadFiguras++;
        }
    }
    
    if(cantidadFiguras < MAX_FIGURAS){
        figurasCuadrado[cantidadFiguras] = lado;
        coordenadasCuadrados[cantidadFiguras][0] = 10 + cantidadFiguras * 0.5;
        coordenadasCuadrados[cantidadFiguras][1] = 10 + cantidadFiguras * 0.5;
        printf("Cuadrado creado con lado de %.2f cm en la posición (%.2f, %.2f)\n", lado, coordenadasCuadrados[cantidadFiguras][0], coordenadasCuadrados[cantidadFiguras][1]);
    } else {
        printf("No se pueden crear más cuadrados, el límite es %d.\n", MAX_FIGURAS);
    }
}

// Crea un círculo y almacena sus datos
void crearCirculo() {
    float radio;
    int cantidadFiguras = 0;
    
    printf("||Creacion de circulo||\n");
    printf("Introduzca el valor del radio en cm:\n");
    scanf("%f", &radio);

    // Contar la cantidad de figuras actualmente almacenadas
    for (int i = 0; i < MAX_FIGURAS; i++) {
        if (figurasCirculo[i] != 0) {
            cantidadFiguras++;
        }
    }
    
    if(cantidadFiguras < MAX_FIGURAS){
        figurasCirculo[cantidadFiguras] = radio;
        coordenadasCirculo[cantidadFiguras][0] = 10 + cantidadFiguras * 0.5;
        coordenadasCirculo[cantidadFiguras][1] = 10 + cantidadFiguras * 0.5;
        printf("Circulo creado con radio de %.2f cm en la posición (%.2f, %.2f)\n", radio, coordenadasCirculo[cantidadFiguras][0], coordenadasCirculo[cantidadFiguras][1]);
    } else {
        printf("No se pueden crear más círculos, el límite es %d.\n", MAX_FIGURAS);
    }
}

// Crea un triángulo y almacena sus datos
void crearTriangulo() {
    float base, altura;
    int cantidadFiguras = 0;
    
    printf("||Creacion de triángulo||\n");
    printf("Introduzca el valor de la base en cm:\n");
    scanf("%f", &base);
    printf("Introduzca el valor de la altura en cm:\n");
    scanf("%f", &altura);

    // Contar la cantidad de figuras actualmente almacenadas
    for (int i = 0; i < MAX_FIGURAS; i++) {
        if (figurasTriangulo[i][0] != 0) {
            cantidadFiguras++;
        }
    }
    
    if(cantidadFiguras < MAX_FIGURAS){
        figurasTriangulo[cantidadFiguras][0] = base;
        figurasTriangulo[cantidadFiguras][1] = altura;
        coordenadasTriangulos[cantidadFiguras][0] = 10 + cantidadFiguras * 0.5;
        coordenadasTriangulos[cantidadFiguras][1] = 10 + cantidadFiguras * 0.5;
        printf("Triángulo creado con base de %.2f cm y altura de %.2f cm en la posición (%.2f, %.2f)\n", base, altura, coordenadasTriangulos[cantidadFiguras][0], coordenadasTriangulos[cantidadFiguras][1]);
    } else {
        printf("No se pueden crear más triángulos, el límite es %d.\n", MAX_FIGURAS);
    }
}

// Crea un rectángulo y almacena sus datos
void crearRectangulo() {
    float base, altura;
    int cantidadFiguras = 0;
    
    printf("||Creacion de rectángulo||\n");
    printf("Introduzca el valor de la base en cm:\n");
    scanf("%f", &base);
    printf("Introduzca el valor de la altura en cm:\n");
    scanf("%f", &altura);

    // Contar la cantidad de figuras actualmente almacenadas
    for (int i = 0; i < MAX_FIGURAS; i++) {
        if (figurasRectangulo[i][0] != 0) {
            cantidadFiguras++;
        }
    }
    
    if(cantidadFiguras < MAX_FIGURAS){
        figurasRectangulo[cantidadFiguras][0] = base;
        figurasRectangulo[cantidadFiguras][1] = altura;
        coordenadasRectangulos[cantidadFiguras][0] = 10 + cantidadFiguras * 0.5;
        coordenadasRectangulos[cantidadFiguras][1] = 10 + cantidadFiguras * 0.5;
        printf("Rectángulo creado con base de %.2f cm y altura de %.2f cm en la posición (%.2f, %.2f)\n", base, altura, coordenadasRectangulos[cantidadFiguras][0], coordenadasRectangulos[cantidadFiguras][1]);
    } else {
        printf("No se pueden crear más rectángulos, el límite es %d.\n", MAX_FIGURAS);
    }
}

// Calcula el área de un cuadrado
float calcularAreaCuadrado(float lado){
    float area = lado * lado;
    printf("El valor del área del cuadrado es: %.2f\n", area);
    return area;
}

// Calcula el área de un círculo
float calcularAreaCirculo(float radio){
    float area = PI * radio * radio;
    printf("El valor del área del círculo es: %.2f\n", area);
    return area;
}

// Calcula el área de un triángulo
float calcularAreaTriangulo(float base, float altura){
    float area = (base * altura) / 2;
    printf("El valor del área del triángulo es: %.2f\n", area);
    return area;
}

// Calcula el área de un rectángulo
float calcularAreaRectangulo(float base, float altura){
    float area = base * altura;
    printf("El valor del área del rectángulo es: %.2f\n", area);
    return area;
}

// Modificar una figura existente
void modificarFigura() {
    int tipoFigura, indice;
    
    printf("Seleccione el tipo de figura a modificar:\n");
    mostrarMenuFiguras();
    scanf("%d", &tipoFigura);
    
    printf("Seleccione el índice de la figura a modificar (0-%d):\n", MAX_FIGURAS - 1);
    scanf("%d", &indice);
    
    if (indice < 0 || indice >= MAX_FIGURAS) {
        printf("Índice no válido.\n");
        return;
    }
    
    switch(tipoFigura) {
        case 1:
            modificarCuadrado(indice);
            break;
        case 2:
            modificarCirculo(indice);
            break;
        case 3:
            modificarTriangulo(indice);
            break;
        case 4:
            modificarRectangulo(indice);
            break;
        default:
            printf("Opción no válida\n");
            break;
    }
}

// Modificar un cuadrado existente
void modificarCuadrado(int indice) {
    if (figurasCuadrado[indice] == 0) {
        printf("No hay un cuadrado en el índice %d.\n", indice);
        return;
    }
    
    printf("Cuadrado actual en el índice %d: lado = %.2f cm, coordenadas = (%.2f, %.2f)\n", 
           indice, figurasCuadrado[indice], coordenadasCuadrados[indice][0], coordenadasCuadrados[indice][1]);
    
    printf("Introduzca el nuevo valor del lado en cm:\n");
    scanf("%f", &figurasCuadrado[indice]);
    
    // Actualizar coordenadas si es necesario
    printf("Introduzca las nuevas coordenadas (x y):\n");
    scanf("%f %f", &coordenadasCuadrados[indice][0], &coordenadasCuadrados[indice][1]);
    
    printf("Cuadrado modificado: lado = %.2f cm, coordenadas = (%.2f, %.2f)\n", 
           figurasCuadrado[indice], coordenadasCuadrados[indice][0], coordenadasCuadrados[indice][1]);
}

// Funciones similares para círculo, triángulo y rectángulo
void modificarCirculo(int indice) {
    if (figurasCirculo[indice] == 0) {
        printf("No hay un círculo en el índice %d.\n", indice);
        return;
    }
    
    printf("Círculo actual en el índice %d: radio = %.2f cm, coordenadas = (%.2f, %.2f)\n", 
           indice, figurasCirculo[indice], coordenadasCirculo[indice][0], coordenadasCirculo[indice][1]);
    
    printf("Introduzca el nuevo valor del radio en cm:\n");
    scanf("%f", &figurasCirculo[indice]);
    
    // Actualizar coordenadas si es necesario
    printf("Introduzca las nuevas coordenadas (x y):\n");
    scanf("%f %f", &coordenadasCirculo[indice][0], &coordenadasCirculo[indice][1]);
    
    printf("Círculo modificado: radio = %.2f cm, coordenadas = (%.2f, %.2f)\n", 
           figurasCirculo[indice], coordenadasCirculo[indice][0], coordenadasCirculo[indice][1]);
}

void modificarTriangulo(int indice) {
    if (figurasTriangulo[indice][0] == 0) {
        printf("No hay un triángulo en el índice %d.\n", indice);
        return;
    }
    
    printf("Triángulo actual en el índice %d: base = %.2f cm, altura = %.2f cm, coordenadas = (%.2f, %.2f)\n", 
           indice, figurasTriangulo[indice][0], figurasTriangulo[indice][1], coordenadasTriangulos[indice][0], coordenadasTriangulos[indice][1]);
    
    printf("Introduzca el nuevo valor de la base en cm:\n");
    scanf("%f", &figurasTriangulo[indice][0]);
    printf("Introduzca el nuevo valor de la altura en cm:\n");
    scanf("%f", &figurasTriangulo[indice][1]);
    
    // Actualizar coordenadas si es necesario
    printf("Introduzca las nuevas coordenadas (x y):\n");
    scanf("%f %f", &coordenadasTriangulos[indice][0], &coordenadasTriangulos[indice][1]);
    
    printf("Triángulo modificado: base = %.2f cm, altura = %.2f cm, coordenadas = (%.2f, %.2f)\n", 
           figurasTriangulo[indice][0], figurasTriangulo[indice][1], coordenadasTriangulos[indice][0], coordenadasTriangulos[indice][1]);
}

void modificarRectangulo(int indice) {
    if (figurasRectangulo[indice][0] == 0) {
        printf("No hay un rectángulo en el índice %d.\n", indice);
        return;
    }
    
    printf("Rectángulo actual en el índice %d: base = %.2f cm, altura = %.2f cm, coordenadas = (%.2f, %.2f)\n", 
           indice, figurasRectangulo[indice][0], figurasRectangulo[indice][1], coordenadasRectangulos[indice][0], coordenadasRectangulos[indice][1]);
    
    printf("Introduzca el nuevo valor de la base en cm:\n");
    scanf("%f", &figurasRectangulo[indice][0]);
    printf("Introduzca el nuevo valor de la altura en cm:\n");
    scanf("%f", &figurasRectangulo[indice][1]);
    
    // Actualizar coordenadas si es necesario
    printf("Introduzca las nuevas coordenadas (x y):\n");
    scanf("%f %f", &coordenadasRectangulos[indice][0], &coordenadasRectangulos[indice][1]);
    
    printf("Rectángulo modificado: base = %.2f cm, altura = %.2f cm, coordenadas = (%.2f, %.2f)\n", 
           figurasRectangulo[indice][0], figurasRectangulo[indice][1], coordenadasRectangulos[indice][0], coordenadasRectangulos[indice][1]);
}

void eliminarFigura(){
    printf("Función de eliminación no implementada aún.\n");
}
