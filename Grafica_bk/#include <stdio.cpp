#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void leerArchivo(NombreARchivo){
    FILE* archivo = fopen(NombreARchivo".csv", "r");
    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    char linea[1024];
    while (fgets(linea, sizeof(linea), archivo)) {
        // Elimina salto de línea al final
        linea[strcspn(linea, "\r\n")] = 0;

        // Divide por comas
        char* campo = strtok(linea, ",");
        while (campo != NULL) {
            printf("Dato: %s\n", campo);
            campo = strtok(NULL, ",");
        }
        printf("-----\n");
    }

    fclose(archivo);
    
}
//void imprimirArchivo(){}
int main() {
    printf("cual es el nombre del arvhico a abrir\n");
    scanf("%s",NombreARchivo);
    leerArchivo(NombreARchivo)
    
    return 0;
}
