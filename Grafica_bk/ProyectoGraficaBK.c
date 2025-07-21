#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CREWS 100

typedef struct {
    int numero;
    char nombre[60];
    char fechaIngre[11];
    int principiosBasicos;
    int limpieza;
    int broilerYmesaPrincipal;
    int papasfritas;
    int ingredientesDeCalidad;
    int desayunos;
    int bebidasYpostres;
    int CARE;
    int servicioAlInvitado;
    int promedioCapacitacionbasica;
    int obejeticoCapacitacionbasica;
    int promedioCapacitacionExperto;
    int objetivoCapacitacionExperto;
    int aux;
    int aux1;
} Crew;

Crew crews[MAX_CREWS];
int totalCrews = 0;

void leerArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        perror("No se pudo abrir el archivo");
        return;
    }

    char linea[1024];
    int fila = 0;

    while (fgets(linea, sizeof(linea), archivo)) {
        fila++;
        if (fila <= 10) continue; // Saltar las primeras 10 filas

        if (totalCrews >= MAX_CREWS) break;

        linea[strcspn(linea, "\r\n")] = 0; // Elimina salto de línea

        char* campo = strtok(linea, ",");
        int columna = 0;

        while (campo != NULL) {
            switch (columna) {
                case 0: crews[totalCrews].numero = atoi(campo); break;
                case 1: strncpy(crews[totalCrews].nombre, campo, sizeof(crews[totalCrews].nombre)); break;
                case 2: strncpy(crews[totalCrews].fechaIngre, campo, sizeof(crews[totalCrews].fechaIngre)); break;
                case 3: crews[totalCrews].principiosBasicos = atoi(campo); break;
                case 4: crews[totalCrews].limpieza = atoi(campo); break;
                case 5: crews[totalCrews].broilerYmesaPrincipal = atoi(campo); break;
                case 6: crews[totalCrews].papasfritas = atoi(campo); break;
                case 7: crews[totalCrews].ingredientesDeCalidad = atoi(campo); break;
                case 8: crews[totalCrews].desayunos = atoi(campo); break;
                case 9: crews[totalCrews].bebidasYpostres = atoi(campo); break;
                case 10: crews[totalCrews].CARE = atoi(campo); break;
                case 11: crews[totalCrews].servicioAlInvitado = atoi(campo); break;
                case 12: crews[totalCrews].promedioCapacitacionbasica = atoi(campo); break;
                case 13: crews[totalCrews].obejeticoCapacitacionbasica = atoi(campo); break;
                case 14: crews[totalCrews].promedioCapacitacionExperto = atoi(campo); break;
                case 15: crews[totalCrews].objetivoCapacitacionExperto = atoi(campo); break;
                case 16: crews[totalCrews].aux = atoi(campo); break;
                case 17: crews[totalCrews].aux1 = atoi(campo); break;
            }

            campo = strtok(NULL, ",");
            columna++;
        }

        totalCrews++;
    }

    fclose(archivo);

    printf("Se cargaron %d crews correctamente.\n", totalCrews);
}

void imprimirCrews() {
    for (int i = 0; i < totalCrews; i++) {
        printf("Crew %d: %s, fecha: %s, promedio básico: %d\n",
            crews[i].numero,
            crews[i].nombre,
            crews[i].fechaIngre,
            crews[i].promedioCapacitacionbasica);
    }
}

int main() {
    char nombreArchivo[100];
    printf("Nombre del archivo a abrir (con extensión .csv): ");
    scanf("%99s", nombreArchivo);

    leerArchivo(nombreArchivo);
    imprimirCrews();

    return 0;
}
