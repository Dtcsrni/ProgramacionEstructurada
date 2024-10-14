#include <stdio.h>

int main() {
    FILE *f;
    int contador = 0;
    
    
    while(contador < 3){
    f = fopen("datos.txt", "r+");  // Abre para lectura y escritura
    if (f == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Leer el contenido existente
    char buffer[100];
    int num[5];

    printf("Contenido actual:\n");
    while (fgets(buffer, 100, f) != NULL) {
        printf("%s", buffer);
    }
    printf("\n Escribe 5 numeros:");
    for (int i = 0; i < 5; i++)
    {
        printf("Numero %d: ", i+1);
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < 5; i++)
    {   
        fprintf(f, "%d\n", num[i]);
        printf("Los numeros son: %d\n", num[i]);
    }
    contador++;
    
    fclose(f);  // Cierra el archivo
    
    }
    
    

    return 0;
}
