#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_FIGURAS 100
#define ANCHO 80 // Ancho del canvas
#define ALTO 24  // Alto del canvas

typedef enum
{
    CIRCULO,
    CUADRADO,
    TRIANGULO,
    RECTANGULO,
    ELIPSE,
    TRAPECIO,
    ESFERA
} TipoFigura;

typedef struct
{
    TipoFigura tipo;
    float dimension1;
    float dimension2;
    float dimension3;
} Figura;

Figura figuras[MAX_FIGURAS];
int totalFiguras = 0;
void guardar_figura_almacenamiento(int identificador){

}
void eliminar_figura_almacenamiento(int identificador){

}
void eliminar_todas_figuras_almacenamiento(){

}

void cargar_figuras()
{
    FILE *f;
    char buffer[100];
    int i = 0;
    int x = 0;
    f = fopen("figuras.txt", "r+"); // Abre para lectura y escritura
    if (f == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    else
    {
        printf("Archivo abierto exitosamente\n");
    }
    while (fgets(buffer, 100, f) != NULL)
    {
        char *token = strtok(buffer, ",");
        float tipo;
        while (token != NULL)
        {   
            if (x==0)
            tipo = atof(token);
            if (x == 0)
            {  
                 if (tipo == 0.0)
                {
                    figuras[i].tipo = CIRCULO;
                    printf("Tipo: Circulo\n");
                }
                if (tipo == 1.0)
                {
                    figuras[i].tipo = CUADRADO;
                    printf("Tipo: Cuadrado\n");
                }
                if (tipo == 2.0)
                {
                    figuras[i].tipo = TRIANGULO;
                    printf("Tipo: Triangulo\n");
                }
                if (tipo == 3.0)
                {
                    figuras[i].tipo = RECTANGULO;
                    printf("Tipo: Rectangulo\n");
                }
                if (tipo == 4.0)
                {
                    figuras[i].tipo = ELIPSE;
                    printf("Tipo: Elipse\n");
                }
            }
            if (x == 1)
            {
                figuras[i].dimension1 = atof(token);
            }
            if (x == 2)
            {
                figuras[i].dimension2 = atof(token);
            }
            if (x == 3)
            {
                figuras[i].dimension3 = atof(token);
            }
            token = strtok(NULL, ",");
            x++;
        }
        printf("Figura cargada en identificador %d.\n", i);

        x = 0;
        i++;
        totalFiguras++;
    }
    i=0;
    printf("Todas las figuras cargadas exitosamente\n");
}
// Función para agregar figuras
void agregar_figura()
{
    if (totalFiguras >= MAX_FIGURAS)
    {
        printf("No se pueden agregar más figuras.\n");
        return;
    }

    int tipo;
    Figura figura;

    // Mostrar el menú para seleccionar el tipo de figura
    printf("\nSeleccione el tipo de figura:\n");
    printf("1. Círculo\n");
    printf("2. Cuadrado\n");
    printf("3. Triángulo\n");
    printf("4. Rectángulo\n");
    printf("5. Elipse\n");
    printf("6. Trapecio\n");
    printf("7. Esfera\n");
    printf("Seleccione una opción: ");
    scanf("%d", &tipo);

    // Capturar las dimensiones necesarias para el tipo de figura seleccionado
    switch (tipo)
    {
    case 1: // Círculo
        figura.tipo = CIRCULO;
        printf("Ingrese el radio del círculo (en cm): ");
        scanf("%f", &figura.dimension1);
        figura.dimension2 = figura.dimension3 = 0; // No se usan en círculo
        break;
    case 2: // Cuadrado
        figura.tipo = CUADRADO;
        printf("Ingrese el lado del cuadrado (en cm): ");
        scanf("%f", &figura.dimension1);
        figura.dimension2 = figura.dimension3 = 0; // No se usan en cuadrado
        break;
    case 3: // Triángulo
        figura.tipo = TRIANGULO;
        printf("Ingrese la base del triángulo (en cm): ");
        scanf("%f", &figura.dimension1);
        printf("Ingrese la altura del triángulo (en cm): ");
        scanf("%f", &figura.dimension2);
        figura.dimension3 = 0; // No se usa en triángulo
        break;
    case 4: // Rectángulo
        figura.tipo = RECTANGULO;
        printf("Ingrese la base del rectángulo (en cm): ");
        scanf("%f", &figura.dimension1);
        printf("Ingrese la altura del rectángulo (en cm): ");
        scanf("%f", &figura.dimension2);
        figura.dimension3 = 0; // No se usa en rectángulo
        break;
    case 5: // Elipse
        figura.tipo = ELIPSE;
        printf("Ingrese el radio mayor de la elipse (en cm): ");
        scanf("%f", &figura.dimension1);
        printf("Ingrese el radio menor de la elipse (en cm): ");
        scanf("%f", &figura.dimension2);
        figura.dimension3 = 0; // No se usa en elipse
        break;
    case 6: // Trapecio
        figura.tipo = TRAPECIO;
        printf("Ingrese la base mayor del trapecio (en cm): ");
        scanf("%f", &figura.dimension1);
        printf("Ingrese la base menor del trapecio (en cm): ");
        scanf("%f", &figura.dimension2);
        printf("Ingrese la altura del trapecio (en cm): ");
        scanf("%f", &figura.dimension3);
        break;
    case 7: // Esfera
        figura.tipo = ESFERA;
        printf("Ingrese el radio de la esfera (en cm): ");
        scanf("%f", &figura.dimension1);
        figura.dimension2 = figura.dimension3 = 0; // No se usan en esfera
        break;
    default:
        printf("Opción no válida.\n");
        return;
    }

    // Guardar la figura en el arreglo
    figuras[totalFiguras++] = figura;
    printf("Figura agregada con éxito.\n");
}

// Función para listar las figuras almacenadas
void listar_figuras()
{
    if (totalFiguras == 0)
    {
        printf("No hay figuras guardadas.\n");
        return;
    }

    printf("\nLista de figuras:\n");
    for (int i = 0; i < totalFiguras; i++)
    {
        printf("ID %d: ", i);
        switch (figuras[i].tipo)
        {
        case CIRCULO:
            printf("Círculo (Radio: %.2f cm)\n", figuras[i].dimension1);
            break;
        case CUADRADO:
            printf("Cuadrado (Lado: %.2f cm)\n", figuras[i].dimension1);
            break;
        case TRIANGULO:
            printf("Triángulo (Base: %.2f cm, Altura: %.2f cm)\n", figuras[i].dimension1, figuras[i].dimension2);
            break;
        case RECTANGULO:
            printf("Rectángulo (Base: %.2f cm, Altura: %.2f cm)\n", figuras[i].dimension1, figuras[i].dimension2);
            break;
        case ELIPSE:
            printf("Elipse (Radio mayor: %.2f cm, Radio menor: %.2f cm)\n", figuras[i].dimension1, figuras[i].dimension2);
            break;
        case TRAPECIO:
            printf("Trapecio (Base mayor: %.2f cm, Base menor: %.2f cm, Altura: %.2f cm)\n", figuras[i].dimension1, figuras[i].dimension2, figuras[i].dimension3);
            break;
        case ESFERA:
            printf("Esfera (Radio: %.2f cm)\n", figuras[i].dimension1);
            break;
        }
    }
}

// Función para modificar una figura existente
void modificar_figura(int id)
{
    if (id < 0 || id >= totalFiguras)
    {
        printf("ID no válido.\n");
        return;
    }

    printf("Modificando la figura con ID %d\n", id);
    agregar_figura();
    figuras[id] = figuras[totalFiguras - 1]; // Reemplaza la figura modificada
    totalFiguras--;
    printf("Figura modificada con éxito.\n");
}

// Función para eliminar una figura
void eliminar_figura(int id)
{
    if (id < 0 || id >= totalFiguras)
    {
        printf("ID no válido.\n");
        return;
    }

    for (int i = id; i < totalFiguras - 1; i++)
    {
        figuras[i] = figuras[i + 1]; // Desplazar figuras
    }
    totalFiguras--;
    printf("Figura eliminada con éxito.\n");
}

// Función para graficar una figura en el canvas
void graficar_figura(int id)
{
    if (id < 0 || id >= totalFiguras)
    {
        printf("ID no válido.\n");
        return;
    }

    // Crear el canvas
    char canvas[ALTO][ANCHO];
    for (int i = 0; i < ALTO; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            canvas[i][j] = ' ';
        }
    }

    // Graficar la figura seleccionada
    Figura figura = figuras[id];
    if (figura.tipo == CIRCULO)
    {
        int radio = (int)figura.dimension1;
        for (int y = -radio; y <= radio; y++)
        {
            for (int x = -radio; x <= radio; x++)
            {
                if (x * x + y * y <= radio * radio)
                {
                    canvas[ALTO / 2 + y][ANCHO / 2 + x] = '*';
                }
            }
        }
        printf("Dimensiones: Radio = %.2f cm\n", figura.dimension1);
    }
    else if (figura.tipo == CUADRADO)
    {
        int lado = (int)figura.dimension1;
        for (int i = 0; i < lado; i++)
        {
            for (int j = 0; j < lado; j++)
            {
                canvas[ALTO / 2 - lado / 2 + i][ANCHO / 2 - lado / 2 + j] = '*';
            }
        }
        printf("Dimensiones: Lado = %.2f cm\n", figura.dimension1);
    }
    else if (figura.tipo == TRIANGULO)
    {
        int base = (int)figura.dimension1;
        int altura = (int)figura.dimension2;
        for (int i = 0; i <= altura; i++)
        {
            for (int j = -i; j <= i; j++)
            {
                canvas[ALTO / 2 - i][ANCHO / 2 + j] = '*';
            }
        }
        printf("Dimensiones: Base = %.2f cm, Altura = %.2f cm\n", figura.dimension1, figura.dimension2);
    }
    // Aquí puedes agregar más casos para otras figuras...

    // Imprimir el canvas
    for (int i = 0; i < ALTO; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
    int opcion, id;

    while (1)
    {
        printf("\nMenu Principal\n");
        printf("1. Agregar figura\n");
        printf("2. Listar figuras\n");
        printf("3. Modificar figura\n");
        printf("4. Eliminar figura\n");
        printf("5. Graficar figura\n");
        printf("6. Cargar lista de figuras\n");
        printf("7. Guardar lista de figuras\n");
        printf("9. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregar_figura();
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
            cargar_figuras();
            break;
        case 7:
            printf("¿Que desea hacer?\n");
            printf("1. Guardar figura en disco\n");
            printf("2. Eliminar figura de disco\n");
            printf("3. Borrar todas las figuras de disco\n");
            scanf("%d", &opcion);
            switch (opcion)
            {
            case 1:
                printf("Ingrese el ID de la figura a guardar en disco: ");
                scanf("%d", &id);
                guardar_figura_almacenamiento(id);
                break;
            case 2:
                printf("Ingrese el ID de la figura a eliminar de disco: ");
                scanf("%d", &id);
                eliminar_figura_almacenamiento(id);
                break;
            case 3:
                printf("Borrando todas las figuras de disco...\n");
                eliminar_todas_figuras_almacenamiento();
                break;
            }
            break;
        case 9:
            printf("Saliendo...\n");
            exit(0);
        default:
            printf("Opción no válida.\n");
        }
    }

    return 0;
}
