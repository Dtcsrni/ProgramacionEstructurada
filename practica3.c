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

typedef enum { CUADRADO, CIRCULO, TRIANGULO, RECTANGULO } FiguraTipo;

// Declaración de funciones
void mostrarMenuPrincipal();
void gestionarFigura(FiguraTipo tipo, const char* accion);
void mostrarMenuFiguras();
float calcularArea(FiguraTipo tipo, float dimension1, float dimension2);

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
    int opcion, tipoFigura;
    do {
        printf("1. Crear Figura\n");
        printf("2. Modificar Figura\n");
        printf("3. Eliminar Figura\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);
        
        if (opcion >= 1 && opcion <= 3) {
            mostrarMenuFiguras();
            scanf("%d", &tipoFigura);
            if (tipoFigura >= 1 && tipoFigura <= 4) {
                gestionarFigura(tipoFigura - 1, opcion == 1 ? "crear" : (opcion == 2 ? "modificar" : "eliminar"));
            } else {
                printf("Opción no válida\n");
            }
        } else if (opcion != 4) {
            printf("Opción no válida\n");
        }
    } while(opcion != 4);
}

// Muestra el menú de tipos de figuras
void mostrarMenuFiguras(){
    printf("Seleccione el tipo de figura:\n");
    printf("1. Cuadrado\n");
    printf("2. Circulo\n");
    printf("3. Triangulo\n");
    printf("4. Rectangulo\n");
}

// Gestiona la creación, modificación o eliminación de una figura
void gestionarFigura(FiguraTipo tipo, const char* accion) {
    int idFigura;
    float dimension1, dimension2;
    int cantidadFiguras = 0;
    
    // Contar la cantidad de figuras actualmente almacenadas
    for (int i = 0; i < MAX_FIGURAS; i++) {
        switch(tipo) {
            case CUADRADO:
                if (figurasCuadrado[i] != 0) cantidadFiguras++;
                break;
            case CIRCULO:
                if (figurasCirculo[i] != 0) cantidadFiguras++;
                break;
            case TRIANGULO:
                if (figurasTriangulo[i][0] != 0) cantidadFiguras++;
                break;
            case RECTANGULO:
                if (figurasRectangulo[i][0] != 0) cantidadFiguras++;
                break;
        }
    }
    
    if (strcmp(accion, "crear") == 0) {
        if (cantidadFiguras >= MAX_FIGURAS) {
            printf("No se pueden crear más figuras, el límite es %d.\n", MAX_FIGURAS);
            return;
        }
        
        printf("Introduzca las dimensiones en cm:\n");
        if (tipo == CUADRADO || tipo == CIRCULO) {
            scanf("%f", &dimension1);
            dimension2 = 0;
        } else {
            scanf("%f %f", &dimension1, &dimension2);
        }
        
        switch(tipo) {
            case CUADRADO:
                figurasCuadrado[cantidadFiguras] = dimension1;
                coordenadasCuadrados[cantidadFiguras][0] = 10 + cantidadFiguras * 0.5;
                coordenadasCuadrados[cantidadFiguras][1] = 10 + cantidadFiguras * 0.5;
                printf("Cuadrado creado con lado de %.2f cm en la posición (%.2f, %.2f)\n", dimension1, coordenadasCuadrados[cantidadFiguras][0], coordenadasCuadrados[cantidadFiguras][1]);
                break;
            case CIRCULO:
                figurasCirculo[cantidadFiguras] = dimension1;
                coordenadasCirculo[cantidadFiguras][0] = 10 + cantidadFiguras * 0.5;
                coordenadasCirculo[cantidadFiguras][1] = 10 + cantidadFiguras * 0.5;
                printf("Círculo creado con radio de %.2f cm en la posición (%.2f, %.2f)\n", dimension1, coordenadasCirculo[cantidadFiguras][0], coordenadasCirculo[cantidadFiguras][1]);
                break;
            case TRIANGULO:
                figurasTriangulo[cantidadFiguras][0] = dimension1;
                figurasTriangulo[cantidadFiguras][1] = dimension2;
                coordenadasTriangulos[cantidadFiguras][0] = 10 + cantidadFiguras * 0.5;
                coordenadasTriangulos[cantidadFiguras][1] = 10 + cantidadFiguras * 0.5;
                printf("Triángulo creado con base de %.2f cm y altura de %.2f cm en la posición (%.2f, %.2f)\n", dimension1, dimension2, coordenadasTriangulos[cantidadFiguras][0], coordenadasTriangulos[cantidadFiguras][1]);
                break;
            case RECTANGULO:
                figurasRectangulo[cantidadFiguras][0] = dimension1;
                figurasRectangulo[cantidadFiguras][1] = dimension2;
                coordenadasRectangulos[cantidadFiguras][0] = 10 + cantidadFiguras * 0.5;
                coordenadasRectangulos[cantidadFiguras][1] = 10 + cantidadFiguras * 0.5;
                printf("Rectángulo creado con base de %.2f cm y altura de %.2f cm en la posición (%.2f, %.2f)\n", dimension1, dimension2, coordenadasRectangulos[cantidadFiguras][0], coordenadasRectangulos[cantidadFiguras][1]);
                break;
        }
        
    } else {
        printf("Introduzca el identificador de la figura a %s:\n", accion);
        scanf("%d", &idFigura);
        
        if (idFigura < 0 || idFigura >= MAX_FIGURAS) {
            printf("Identificador no válido.\n");
            return;
        }
        
        switch(tipo) {
            case CUADRADO:
                if (figurasCuadrado[idFigura] == 0) {
                    printf("No hay un cuadrado con el identificador %d.\n", idFigura);
                    return;
                }
                if (strcmp(accion, "modificar") == 0) {
                    printf("Cuadrado actual con id %d: lado = %.2f cm, coordenadas = (%.2f, %.2f)\n", idFigura, figurasCuadrado[idFigura], coordenadasCuadrados[idFigura][0], coordenadasCuadrados[idFigura][1]);
                    printf("Introduzca el nuevo valor del lado en cm:\n");
                    scanf("%f", &figurasCuadrado[idFigura]);
                    printf("Introduzca las nuevas coordenadas (x y):\n");
                    scanf("%f %f", &coordenadasCuadrados[idFigura][0], &coordenadasCuadrados[idFigura][1]);
                    printf("Cuadrado modificado: lado = %.2f cm, coordenadas = (%.2f, %.2f)\n", figurasCuadrado[idFigura], coordenadasCuadrados[idFigura][0], coordenadasCuadrados[idFigura][1]);
                } else {
                    figurasCuadrado[idFigura] = 0;
                    coordenadasCuadrados[idFigura][0] = 0;
                    coordenadasCuadrados[idFigura][1] = 0;
                    printf("Cuadrado con id %d eliminado.\n", idFigura);
                }
                break;
            case CIRCULO:
                if (figurasCirculo[idFigura] == 0) {
                    printf("No hay un círculo con el identificador %d.\n", idFigura);
                    return;
                }
                if (strcmp(accion, "modificar") == 0) {
                    printf("Círculo actual con id %d: radio = %.2f cm, coordenadas = (%.2f, %.2f)\n", idFigura, figurasCirculo[idFigura], coordenadasCirculo[idFigura][0], coordenadasCirculo[idFigura][1]);
                    printf("Introduzca el nuevo valor del radio en cm:\n");
                    scanf("%f", &figurasCirculo[idFigura]);
                    printf("Introduzca las nuevas coordenadas (x y):\n");
                    scanf("%f %f", &coordenadasCirculo[idFigura][0], &coordenadasCirculo[idFigura][1]);
                    printf("Círculo modificado: radio = %.2f cm, coordenadas = (%.2f, %.2f)\n", figurasCirculo[idFigura], coordenadasCirculo[idFigura][0], coordenadasCirculo[idFigura][1]);
                } else {
                    figurasCirculo[idFigura] = 0;
                    coordenadasCirculo[idFigura][0] = 0;
                    coordenadasCirculo[idFigura][1] = 0;
                    printf("Círculo con id %d eliminado.\n", idFigura);
                }
                break;
            case TRIANGULO:
                if (figurasTriangulo[idFigura][0] == 0) {
                    printf("No hay un triángulo con el identificador %d.\n", idFigura);
                    return;
                }
                if (strcmp(accion, "modificar") == 0) {
                    printf("Triángulo actual con id %d: base = %.2f cm, altura = %.2f cm, coordenadas = (%.2f, %.2f)\n", idFigura, figurasTriangulo[idFigura][0], figurasTriangulo[idFigura][1], coordenadasTriangulos[idFigura][0], coordenadasTriangulos[idFigura][1]);
                    printf("Introduzca el nuevo valor de la base en cm:\n");
                    scanf("%f", &figurasTriangulo[idFigura][0]);
                    printf("Introduzca el nuevo valor de la altura en cm:\n");
                    scanf("%f", &figurasTriangulo[idFigura][1]);
                    printf("Introduzca las nuevas coordenadas (x y):\n");
                    scanf("%f %f", &coordenadasTriangulos[idFigura][0], &coordenadasTriangulos[idFigura][1]);
                    printf("Triángulo modificado: base = %.2f cm, altura = %.2f cm, coordenadas = (%.2f, %.2f)\n", figurasTriangulo[idFigura][0], figurasTriangulo[idFigura][1], coordenadasTriangulos[idFigura][0], coordenadasTriangulos[idFigura][1]);
                } else {
                    figurasTriangulo[idFigura][0] = 0;
                    figurasTriangulo[idFigura][1] = 0;
                    coordenadasTriangulos[idFigura][0] = 0;
                    coordenadasTriangulos[idFigura][1] = 0;
                    printf("Triángulo con id %d eliminado.\n", idFigura);
                }
                break;
            case RECTANGULO:
                if (figurasRectangulo[idFigura][0] == 0) {
                    printf("No hay un rectángulo con el identificador %d.\n", idFigura);
                    return;
                }
                if (strcmp(accion, "modificar") == 0) {
                    printf("Rectángulo actual con id %d: base = %.2f cm, altura = %.2f cm, coordenadas = (%.2f, %.2f)\n", idFigura, figurasRectangulo[idFigura][0], figurasRectangulo[idFigura][1], coordenadasRectangulos[idFigura][0], coordenadasRectangulos[idFigura][1]);
                    printf("Introduzca el nuevo valor de la base en cm:\n");
                    scanf("%f", &figurasRectangulo[idFigura][0]);
                    printf("Introduzca el nuevo valor de la altura en cm:\n");
                    scanf("%f", &figurasRectangulo[idFigura][1]);
                    printf("Introduzca las nuevas coordenadas (x y):\n");
                    scanf("%f %f", &coordenadasRectangulos[idFigura][0], &coordenadasRectangulos[idFigura][1]);
                    printf("Rectángulo modificado: base = %.2f cm, altura = %.2f cm, coordenadas = (%.2f, %.2f)\n", figurasRectangulo[idFigura][0], figurasRectangulo[idFigura][1], coordenadasRectangulos[idFigura][0], coordenadasRectangulos[idFigura][1]);
                } else {
                    figurasRectangulo[idFigura][0] = 0;
                    figurasRectangulo[idFigura][1] = 0;
                    coordenadasRectangulos[idFigura][0] = 0;
                    coordenadasRectangulos[idFigura][1] = 0;
                    printf("Rectángulo con id %d eliminado.\n", idFigura);
                }
                break;
        }
    }
}

// Calcula el área de la figura
float calcularArea(FiguraTipo tipo, float dimension1, float dimension2) {
    float area = 0;
    switch(tipo) {
        case CUADRADO:
            area = dimension1 * dimension1;
            break;
        case CIRCULO:
            area = PI * dimension1 * dimension1;
            break;
        case TRIANGULO:
            area = (dimension1 * dimension2) / 2;
            break;
        case RECTANGULO:
            area = dimension1 * dimension2;
            break;
    }
    printf("El valor del área es: %.2f\n", area);
    return area;
}
