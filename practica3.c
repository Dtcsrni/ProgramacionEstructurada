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
#include <stdlib.h>
#include <math.h>
#include <windows.h> // Necesario para la función FreeConsole y AllocConsole

#define MAX_FIGURAS 100 // Número máximo de figuras que se pueden almacenar
#define ANCHO 40        // Ancho del canvas
#define ALTO 40         // Alto del canvas
#ifndef M_PI // Definir M_PI si no está definido
#define M_PI 3.14159265358979323846
#endif

// Definición de los tipos de figuras
typedef enum {
    CUADRADO,
    CIRCULO,
    TRIANGULO,
    RECTANGULO,
    ELIPSE,
    TRAPECIO,
    ESFERA,
    MAX_TIPO
} TipoFigura;

// Estructura para almacenar información de una figura
typedef struct {
    TipoFigura tipo;
    float dimension1; // Dimensión 1 (ej: lado, radio, base)
    float dimension2; // Dimensión 2 (ej: altura, radio menor, base menor)
    float dimension3; // Dimensión 3 (ej: altura en el caso de un trapecio)
} Figura;

Figura figuras[MAX_FIGURAS]; // Array de figuras
int total_figuras = 0; // Contador de figuras agregadas

// Función para calcular el área de la figura
float calcular_area(TipoFigura tipo, float dim1, float dim2, float dim3) {
    switch (tipo) {
        case CUADRADO: return dim1 * dim1;
        case CIRCULO: return M_PI * dim1 * dim1;
        case TRIANGULO: return (dim1 * dim2) / 2;
        case RECTANGULO: return dim1 * dim2;
        case ELIPSE: return M_PI * dim1 * dim2;
        case TRAPECIO: return ((dim1 + dim2) * dim3) / 2;
        case ESFERA: return (4.0 / 3.0) * M_PI * pow(dim1, 3); // Volumen
        default: return 0.0;
    }
}

// Función para solicitar datos de la figura
void solicitar_datos_figura() {
    TipoFigura tipo;
    printf("\nSeleccione el tipo de figura a agregar:\n");
    printf("0 - Cuadrado\n");
    printf("1 - Círculo\n");
    printf("2 - Triángulo\n");
    printf("3 - Rectángulo\n");
    printf("4 - Elipse\n");
    printf("5 - Trapecio\n");
    printf("6 - Esfera\n");
    printf("Seleccione una opción: ");
    scanf("%d", (int *)&tipo); // Obtener tipo de figura

    float dim1, dim2 = 0, dim3 = 0;
    switch (tipo) {
        case CUADRADO:
            printf("Ingrese el lado del cuadrado (cm): ");
            scanf("%f", &dim1);
            break;
        case CIRCULO:
            printf("Ingrese el radio del círculo (cm): ");
            scanf("%f", &dim1);
            break;
        case TRIANGULO:
            printf("Ingrese la base del triángulo (cm): ");
            scanf("%f", &dim1);
            printf("Ingrese la altura del triángulo (cm): ");
            scanf("%f", &dim2);
            break;
        case RECTANGULO:
            printf("Ingrese la base del rectángulo (cm): ");
            scanf("%f", &dim1);
            printf("Ingrese la altura del rectángulo (cm): ");
            scanf("%f", &dim2);
            break;
        case ELIPSE:
            printf("Ingrese el radio mayor de la elipse (cm): ");
            scanf("%f", &dim1);
            printf("Ingrese el radio menor de la elipse (cm): ");
            scanf("%f", &dim2);
            break;
        case TRAPECIO:
            printf("Ingrese la base mayor del trapecio (cm): ");
            scanf("%f", &dim1);
            printf("Ingrese la base menor del trapecio (cm): ");
            scanf("%f", &dim2);
            printf("Ingrese la altura del trapecio (cm): ");
            scanf("%f", &dim3);
            break;
        case ESFERA:
            printf("Ingrese el radio de la esfera (cm): ");
            scanf("%f", &dim1);
            break;
        default:
            printf("Tipo de figura no válido.\n");
            return;
    }

    // Agregar la figura al array
    figuras[total_figuras].tipo = tipo;
    figuras[total_figuras].dimension1 = dim1;
    figuras[total_figuras].dimension2 = dim2;
    figuras[total_figuras].dimension3 = dim3;
    total_figuras++;
    printf("Figura agregada con ID %d.\n", total_figuras - 1);
}

// Función para listar las figuras
void listar_figuras() {
    printf("\nLista de figuras:\n");
    for (int i = 0; i < total_figuras; i++) {
        switch (figuras[i].tipo) {
            case CUADRADO:
                printf("ID %d: Cuadrado (Lado: %.2f cm)\n", i, figuras[i].dimension1);
                break;
            case CIRCULO:
                printf("ID %d: Círculo (Radio: %.2f cm)\n", i, figuras[i].dimension1);
                break;
            case TRIANGULO:
                printf("ID %d: Triángulo (Base: %.2f cm, Altura: %.2f cm)\n", i, figuras[i].dimension1, figuras[i].dimension2);
                break;
            case RECTANGULO:
                printf("ID %d: Rectángulo (Base: %.2f cm, Altura: %.2f cm)\n", i, figuras[i].dimension1, figuras[i].dimension2);
                break;
            case ELIPSE:
                printf("ID %d: Elipse (Radio mayor: %.2f cm, Radio menor: %.2f cm)\n", i, figuras[i].dimension1, figuras[i].dimension2);
                break;
            case TRAPECIO:
                printf("ID %d: Trapecio (Base mayor: %.2f cm, Base menor: %.2f cm, Altura: %.2f cm)\n", i, figuras[i].dimension1, figuras[i].dimension2, figuras[i].dimension3);
                break;
            case ESFERA:
                printf("ID %d: Esfera (Radio: %.2f cm)\n", i, figuras[i].dimension1);
                break;
            default:
                printf("ID %d: Figura desconocida.\n", i);
        }
    }
}

// Función para eliminar una figura
void eliminar_figura(int id) {
    if (id < 0 || id >= total_figuras) {
        printf("ID no válido.\n");
        return;
    }
    for (int i = id; i < total_figuras - 1; i++) {
        figuras[i] = figuras[i + 1]; // Desplazar figuras
    }
    total_figuras--; // Disminuir el total de figuras
    printf("Figura con ID %d eliminada.\n", id);
}

// Función para modificar una figura
void modificar_figura(int id) {
    if (id < 0 || id >= total_figuras) {
        printf("ID no válido.\n");
        return;
    }
    printf("Modificar figura con ID %d:\n", id);
    solicitar_datos_figura(); // Se reutiliza la función de solicitud de datos
    figuras[id] = figuras[total_figuras - 1]; // Reemplazar figura existente
    total_figuras--; // Disminuir el total de figuras porque se ha agregado una nueva figura
    printf("Figura con ID %d modificada.\n", id);
}

// Función para graficar la figura seleccionada
void graficar_figura(int id) {
    char canvas[ALTO][ANCHO]; // Canvas para graficar
    for (int i = 0; i < ALTO; i++)
        for (int j = 0; j < ANCHO; j++)
            canvas[i][j] = ' '; // Inicializar el canvas

    // Dibujar el plano cartesiano
    for (int i = 0; i < ALTO; i++)
        canvas[i][ANCHO / 2] = '|'; // Línea vertical
    for (int j = 0; j < ANCHO; j++)
        canvas[ALTO / 2][j] = '-'; // Línea horizontal

    // Dibujar graduaciones en el plano cartesiano
    for (int i = 1; i < ALTO; i++) {
        if (i % 2 == 0) {
            sprintf(&canvas[i][1], "%d", (ALTO / 2) - i); // Valores de graduación en el eje y
        }
    }
    for (int j = 1; j < ANCHO; j++) {
        if (j % 5 == 0) {
            sprintf(&canvas[ALTO / 2][j], "%d", j - (ANCHO / 2)); // Valores de graduación en el eje x
        }
    }

    // Graficar la figura seleccionada
    Figura figura = figuras[id];
    if (figura.tipo == CIRCULO) {
        int radio = (int)figura.dimension1;
        for (int y = -radio; y <= radio; y++) {
            for (int x = -radio; x <= radio; x++) {
                if (x * x + y * y <= radio * radio) {
                    canvas[ALTO / 2 + y][ANCHO / 2 + x] = '*';
                }
            }
        }
        printf("Dimensiones: Radio = %.2f cm\n", figura.dimension1);
    } else if (figura.tipo == CUADRADO) {
        int lado = (int)figura.dimension1;
        for (int i = 0; i < lado; i++) {
            for (int j = 0; j < lado; j++) {
                canvas[ALTO / 2 - lado / 2 + i][ANCHO / 2 - lado / 2 + j] = '*';
            }
        }
        printf("Dimensiones: Lado = %.2f cm\n", figura.dimension1);
    } else if (figura.tipo == TRIANGULO) {
        int base = (int)figura.dimension1;
        int altura = (int)figura.dimension2;
        for (int i = 0; i <= altura; i++) {
            for (int j = -base / 2; j <= base / 2; j++) {
                if (j == -base / 2 + (base / (altura + 1)) * i) {
                    canvas[ALTO / 2 - i][ANCHO / 2 + j] = '*';
                }
                if (j == base / 2 - (base / (altura + 1)) * i) {
                    canvas[ALTO / 2 - i][ANCHO / 2 + j] = '*';
                }
            }
        }
        printf("Dimensiones: Base = %.2f cm, Altura = %.2f cm\n", figura.dimension1, figura.dimension2);
    } else if (figura.tipo == RECTANGULO) {
        int base = (int)figura.dimension1;
        int altura = (int)figura.dimension2;
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < base; j++) {
                canvas[ALTO / 2 - altura / 2 + i][ANCHO / 2 - base / 2 + j] = '*';
            }
        }
        printf("Dimensiones: Base = %.2f cm, Altura = %.2f cm\n", figura.dimension1, figura.dimension2);
    } else if (figura.tipo == ELIPSE) {
        int radioMayor = (int)figura.dimension1;
        int radioMenor = (int)figura.dimension2;
        for (float y = -radioMenor; y <= radioMenor; y += 0.1) {
            for (float x = -radioMayor; x <= radioMayor; x += 0.1) {
                if ((x * x) / (radioMayor * radioMayor) + (y * y) / (radioMenor * radioMenor) <= 1) {
                    canvas[ALTO / 2 + (int)y][ANCHO / 2 + (int)x] = '*';
                }
            }
        }
        printf("Dimensiones: Radio mayor = %.2f cm, Radio menor = %.2f cm\n", figura.dimension1, figura.dimension2);
    } else if (figura.tipo == TRAPECIO) {
        int baseMayor = (int)figura.dimension1;
        int baseMenor = (int)figura.dimension2;
        int altura = (int)figura.dimension3;
        for (int i = 0; i <= altura; i++) {
            int b = baseMayor - ((baseMayor - baseMenor) * i) / altura;
            for (int j = -b / 2; j <= b / 2; j++) {
                canvas[ALTO / 2 - i][ANCHO / 2 + j] = '*';
            }
        }
        printf("Dimensiones: Base mayor = %.2f cm, Base menor = %.2f cm, Altura = %.2f cm\n", figura.dimension1, figura.dimension2, figura.dimension3);
    } else if (figura.tipo == ESFERA) {
        // La esfera no se puede graficar en 2D de manera efectiva, se omite.
        printf("Dimensiones: Radio = %.2f cm\n", figura.dimension1);
        printf("Nota: La esfera no se puede graficar en 2D.\n");
        return;
    } else {
        printf("Tipo de figura no reconocido.\n");
        return;
    }

    // Mostrar el canvas
    printf("\nCanvas:\n");
    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
}

// Función para crear una nueva consola
void crear_nueva_consola() {
    AllocConsole(); // Asigna una nueva consola
    FILE *nuevo_consola; // Archivo para redirigir stdout
    freopen("CONOUT$", "w", stdout); // Redirigir stdout a la nueva consola
}

int main() {
    crear_nueva_consola(); // Crear una nueva consola

    int opcion, id;

    do {
        printf("\nMenu:\n");
        printf("1. Agregar figura\n");
        printf("2. Listar figuras\n");
        printf("3. Modificar figura\n");
        printf("4. Eliminar figura\n");
        printf("5. Graficar figura\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                solicitar_datos_figura();
                break;
            case 2:
                listar_figuras();
                break;
            case 3:
                printf("Ingrese el ID de la figura a modificar: ");
                scanf("%d", &id);
                modificar_figura(id);
                break;
            case 4:
                printf("Ingrese el ID de la figura a eliminar: ");
                scanf("%d", &id);
                eliminar_figura(id);
                break;
            case 5:
                printf("Ingrese el ID de la figura a graficar: ");
                scanf("%d", &id);
                graficar_figura(id);
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}
