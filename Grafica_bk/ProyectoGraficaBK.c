#include <stdio.h>
#include <stdlib.h>
#include <string.h>//para trabajar con string de forma sencila
#include <stdbool.h>//para trabjar con booleanos
#include <time.h>   //para poder incluir la fecha

#define MAX_CREWS 100
/*
el struc crew esta asociado al primer archivo 

*/

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
    int canalesDigitales;
    /*int obejeticoCapacitacionbasica;
    int promedioCapacitacionExperto;
    int objetivoCapacitacionExperto;
    int aux;
    int aux1;*/
} Crew;
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
    int canalesDigitales;
    /*int obejeticoCapacitacionbasica;
    int promedioCapacitacionExperto;
    int objetivoCapacitacionExperto;
    int aux;
    int aux1;*/
} CrewNuevo;

Crew crews[MAX_CREWS];
CrewNuevo crewsNuevo[MAX_CREWS];
int totalCrewsPrimerArchivo = 0;
int totalCrewsSegundoArchivo=0;

void leerSegundoArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        perror("El segundo archivo no se pudo abrir, recuerda que debe ir sin espacios y con el .csv incluido");
        return;
    }

    char linea[1024];
    int fila = 0;

    while (fgets(linea, sizeof(linea), archivo)) {
        fila++;
        if (fila <= 10) continue; // el continue sirve para omitir esa iteracion y se va  la siguiente


        linea[strcspn(linea, "\r\n")] = 0; //elimino saltos de linea 

        char* campo = strtok(linea, ",");// separo por comas
        int columna = 0;
//atoi es para tomar el string de un numero como un numer
        while (campo != NULL) {
            switch (columna) {
                case 0: 
                crewsNuevo[totalCrewsPrimerArchivo].numero = atoi(campo);
                 break;
                case 1: 
                strncpy(crewsNuevo[totalCrewsPrimerArchivo].nombre, campo, sizeof(crewsNuevo[totalCrewsPrimerArchivo].nombre));
                 break;
                case 2:
                 strncpy(crewsNuevo[totalCrewsPrimerArchivo].fechaIngre, campo, sizeof(crewsNuevo[totalCrewsPrimerArchivo].fechaIngre));
                  break;
                case 3:
                 crewsNuevo[totalCrewsPrimerArchivo].principiosBasicos = atoi(campo);
                  break;
                case 4:
                 crewsNuevo[totalCrewsPrimerArchivo].limpieza = atoi(campo);
                  break;
                case 5: 
                crewsNuevo[totalCrewsPrimerArchivo].broilerYmesaPrincipal = atoi(campo);
                 break;
                case 6:
                 crewsNuevo[totalCrewsPrimerArchivo].papasfritas = atoi(campo); 
                 break;
                case 7: 
                crewsNuevo[totalCrewsPrimerArchivo].ingredientesDeCalidad = atoi(campo);
                 break;
                case 8:
                 crewsNuevo[totalCrewsPrimerArchivo].desayunos = atoi(campo);
                  break;
                case 9:
                 crewsNuevo[totalCrewsPrimerArchivo].bebidasYpostres = atoi(campo); 
                 break;
                case 10:
                 crewsNuevo[totalCrewsPrimerArchivo].CARE = atoi(campo);
                  break;
                case 11:
                 crewsNuevo[totalCrewsPrimerArchivo].servicioAlInvitado = atoi(campo);
                  break;
                case 12:
                crewsNuevo[totalCrewsPrimerArchivo].canalesDigitales = atoi(campo);
                 //campo vacio para no dejar copiar los promedios y esas cosas informacion irrelevante
                  break;
                case 13:
                  //campo vacio para no dejar copiar los promedios y esas cosas informacion irrelevante
                 break;
                case 14:
                 //campo vacio para no dejar copiar los promedios y esas cosas informacion irrelevante
                 break;
                case 15:
                 //campo vacio para no dejar copiar los promedios y esas cosas informacion irrelevante
                  break;
                case 16:
                  //campo vacio para no dejar copiar los promedios y esas cosas informacion irrelevante
                  break;
                case 17:
                 //campo vacio para no dejar copiar los promedios y esas cosas informacion irrelevante
                  break;
            }

            campo = strtok(NULL, ",");
            columna++;
        }

        totalCrewsPrimerArchivo++; //sirve para conpararla al final si agrege o elimine gente
    }

    fclose(archivo);

    //printf("Se cargaron %d crews \n", totalCrewsPrimerArchivo);
}
void leerPrimerArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        perror("El primer archivo no se pudo abrir, recuerda que debe ir sin espacios y con el .csv incluido");
        return;
    }

    char linea[1024];
    int fila = 0;

    while (fgets(linea, sizeof(linea), archivo)) {
        fila++;
        if (fila <= 10) continue; // el continue sirve para omitir esa iteracion y se va  la siguiente


        linea[strcspn(linea, "\r\n")] = 0; //elimino saltos de linea 

        char* campo = strtok(linea, ",");// separo por comas
        int columna = 0;
//atoi es para tomar el string de un numero como un numer
        while (campo != NULL) {
            switch (columna) {
                case 0: 
                crews[totalCrewsSegundoArchivo].numero = atoi(campo);
                 break;
                case 1: 
                strncpy(crews[totalCrewsSegundoArchivo].nombre, campo, sizeof(crews[totalCrewsSegundoArchivo].nombre));
                 break;
                case 2:
                 strncpy(crews[totalCrewsSegundoArchivo].fechaIngre, campo, sizeof(crews[totalCrewsSegundoArchivo].fechaIngre));
                  break;
                case 3:
                 crews[totalCrewsSegundoArchivo].principiosBasicos = atoi(campo);
                  break;
                case 4:
                 crews[totalCrewsSegundoArchivo].limpieza = atoi(campo);
                  break;
                case 5: 
                crews[totalCrewsSegundoArchivo].broilerYmesaPrincipal = atoi(campo);
                 break;
                case 6:
                 crews[totalCrewsSegundoArchivo].papasfritas = atoi(campo); 
                 break;
                case 7: 
                crews[totalCrewsSegundoArchivo].ingredientesDeCalidad = atoi(campo);
                 break;
                case 8:
                 crews[totalCrewsSegundoArchivo].desayunos = atoi(campo);
                  break;
                case 9:
                 crews[totalCrewsSegundoArchivo].bebidasYpostres = atoi(campo); 
                 break;
                case 10:
                 crews[totalCrewsSegundoArchivo].CARE = atoi(campo);
                  break;
                case 11:
                 crews[totalCrewsSegundoArchivo].servicioAlInvitado = atoi(campo);
                  break;
                case 12:
                 crews[totalCrewsSegundoArchivo].canalesDigitales = atoi(campo);
                  break;
                case 13:
                  //campo vacio para no dejar copiar los promedios y esas cosas informacion irrelevante
                 break;
                case 14:
                 //campo vacio para no dejar copiar los promedios y esas cosas informacion irrelevante
                 break;
                case 15:
                 //campo vacio para no dejar copiar los promedios y esas cosas informacion irrelevante
                  break;
                case 16:
                  //campo vacio para no dejar copiar los promedios y esas cosas informacion irrelevante
                  break;
                case 17:
                 //campo vacio para no dejar copiar los promedios y esas cosas informacion irrelevante
                  break;
            }

            campo = strtok(NULL, ",");
            columna++;
        }

        totalCrewsSegundoArchivo++; //sirve para conpararla al final si agrege o elimine gente
    }

    fclose(archivo);

    //printf("Se cargaron %d \n", totalCrewsSegundoArchivo);
}

void imprimirCrews(int opcion) {
    if(opcion==1){
        for (int i = 0; i < totalCrewsPrimerArchivo; i++) {
            printf("Crew %d: %s,principios basicos: %d,Limpieza: %d, broiler: %d, papas: %d, ingrediente: %d,desayunior: %d, bebidas: %d, CARE: %d, servicio: %d, canales: %d\n",
                crews[i].numero,
                crews[i].nombre,
                //crews[i].fechaIngre,, no me interesa la fecha de ingreeso pero la dejo por oden
                crews[i].principiosBasicos,
                crews[i].limpieza,
                crews[i].broilerYmesaPrincipal,
                crews[i].papasfritas,
                crews[i].ingredientesDeCalidad,
                crews[i].desayunos,
                crews[i].bebidasYpostres,
                crews[i].CARE,
                crews[i].servicioAlInvitado,
                crews[i].canalesDigitales
                /*
                crews[i].obejeticoCapacitacionbasica,
                crews[i].promedioCapacitacionExperto,
                crews[i].objetivoCapacitacionExperto,
                crews[i].aux,
                crews[i].aux1*/
        );  
        }
    }else if(opcion==2){
         for (int i = 0; i < totalCrewsSegundoArchivo; i++) {
            printf("Crew %d: %s,principios basicos: %d,Limpieza: %d, broiler: %d, papas: %d, ingrediente: %d,desayunior: %d, bebidas: %d, CARE: %d, servicio: %d, canales %d\n",
                crewsNuevo[i].numero,
                crewsNuevo[i].nombre,
                //crews[i].fechaIngre,, no me interesa la fecha de ingreeso pero la dejo por oden
                
                crewsNuevo[i].principiosBasicos,
                crewsNuevo[i].limpieza,
                crewsNuevo[i].broilerYmesaPrincipal,
                crewsNuevo[i].papasfritas,
                crewsNuevo[i].ingredientesDeCalidad,
                crewsNuevo[i].desayunos,
                crewsNuevo[i].bebidasYpostres,
                crewsNuevo[i].CARE,
                crewsNuevo[i].servicioAlInvitado,
                crewsNuevo[i].canalesDigitales
                /*
                crewsNuevo[i].obejeticoCapacitacionbasica,
                crewsNuevo[i].promedioCapacitacionExperto,
                crewsNuevo[i].objetivoCapacitacionExperto,
                crewsNuevo[i].aux,
                crewsNuevo[i].aux1*/
        );  
        }




        printf("aca el resto\n");
    }else{
        printf("ADIOS?\n");
    }
}


/*para verificar si estan eliminados debo toamar desde el primer archivo y compararlo con el segundo*/
void verificarEliminados(){
    for(int i=0; i<totalCrewsPrimerArchivo; i++){
        int j;
        for(j=0;j<totalCrewsSegundoArchivo;j++){
            if(strcmp(crews[i].nombre,crewsNuevo[j].nombre)==0){
               
                break;
            }

        }
        if(j== totalCrewsSegundoArchivo){
             
             printf("*%s",crews[i].nombre);
             printf(" Es Eliminado/a de la grafica. \n");
        }
       

    }
}
void veroficarAgregados(){
    for(int i=0;i<totalCrewsSegundoArchivo;i++){
        int j;
        for(j=0;j<totalCrewsPrimerArchivo;j++){
            if(strcmp(crewsNuevo[i].nombre,crews[j].nombre)==0){
                break;
            }
        }
        if(j==totalCrewsPrimerArchivo){
            printf("*%s", crewsNuevo[i].nombre);
            printf(" Es agregado/a la grafica.\n");
        }
    }

}
void verificacionGeneral(){
    for(int i=0; i<totalCrewsPrimerArchivo;i++){
        int j;
        int indiceCrewCambio=-1; //si esta en menos uno es que no hubo cambio
        bool cambioPrincipiosBasicos=false;
        bool cambioLimpieza=false;
        bool cambioBroilerYmesaPrincipal=false;
        bool cambioPapasfritas=false;
        bool cambioIngredientesDeCalidad=false;
        bool cambioDesayuno=false;
        bool cambioBebidas=false;
        bool cambioCARE=false;
        bool cambioServicio=false;
        bool cambioCanalesDigitales=false;
        //agregar todos los boole
        for(j=0;j<totalCrewsSegundoArchivo;j++){
            //esto sera cuando son iguales
            if(strcmp(crews[i].nombre,crewsNuevo[j].nombre)==0){
                //cuando lo encuentro guardo el valor en mi variable indiceCrewCambio
                indiceCrewCambio=j;
                if(crews[i].principiosBasicos!=crewsNuevo[j].principiosBasicos){
                    cambioPrincipiosBasicos=true;
                }
                if(crews[i].limpieza!=crewsNuevo[j].limpieza){
                    cambioLimpieza=true;
                } 
                if(crews[i].broilerYmesaPrincipal!=crewsNuevo[j].broilerYmesaPrincipal){
                    cambioBroilerYmesaPrincipal=true;
                }
                if(crews[i].papasfritas!=crewsNuevo[j].papasfritas){
                    cambioPapasfritas=true;
                }
                if(crews[i].ingredientesDeCalidad!=crewsNuevo[j].ingredientesDeCalidad){
                    cambioIngredientesDeCalidad=true;
                }
                if(crews[i].desayunos!=crewsNuevo[j].desayunos){
                    cambioDesayuno=true;
                }
                if(crews[i].bebidasYpostres!=crewsNuevo[j].bebidasYpostres){
                    cambioBebidas=true;
                }
                if(crews[i].CARE!=crewsNuevo[j].CARE){
                    cambioCARE=true;
                }
                if(crews[i].servicioAlInvitado!=crewsNuevo[j].servicioAlInvitado){
                    cambioServicio=true;
                }
                if(crews[i].canalesDigitales!=crewsNuevo[j].canalesDigitales){
                    cambioCanalesDigitales=true;
                }
                break; //cuando encuentra por lo menos un cambio sale de este ciclo para mantener el valor de j y que no sea sobre escrito
                
            }
        }
       
        //si encontro a un crew y no hubo cambio no impimira nada
         //estoy considerando que si se sube la principios basicos tambien se sube la limpieza
        if(indiceCrewCambio!=-1 && (cambioPrincipiosBasicos||cambioLimpieza||cambioBroilerYmesaPrincipal||cambioPapasfritas||cambioIngredientesDeCalidad||cambioDesayuno||cambioBebidas||cambioCARE||cambioServicio||cambioCanalesDigitales)){
            bool cambioAnterior=false;
            printf("* %s",crewsNuevo[indiceCrewCambio].nombre);
            printf("Se ha subido a ");
            if(cambioPrincipiosBasicos){
            printf("%d",crewsNuevo[indiceCrewCambio].principiosBasicos);
            printf(" en Principios basicos");
            cambioAnterior=true;
            }
            if(cambioLimpieza){
                printf(",tambien es subido a nivel %d ",crewsNuevo[indiceCrewCambio].limpieza);
                printf("en limpieza");
                
            }
            if(cambioBroilerYmesaPrincipal){
                if(cambioAnterior){
                    printf(", ademas es subido a nivel %d en Broiler y mesa principal",crewsNuevo[indiceCrewCambio].broilerYmesaPrincipal);
                }else{// si no es decir que este es el primer cambio
                    printf("%d",crewsNuevo[indiceCrewCambio].broilerYmesaPrincipal);
                    printf(" en broiler y mesa principal");
                    cambioAnterior=true;
                }
            }
            if(cambioPapasfritas){
                if(cambioAnterior){
                    printf(", tambien es subido a nivel %d en papas fritas y productos especiales",crewsNuevo[indiceCrewCambio].papasfritas);
                }else{
                    printf("%d",crewsNuevo[indiceCrewCambio].papasfritas);
                    printf(" en papas fritas y productos especiales");
                    cambioAnterior=true;
                }
            }
             if(cambioIngredientesDeCalidad){
                if(cambioAnterior){
                    printf(", igualmente es subido a nivel %d en ingredientes de calidad",crewsNuevo[indiceCrewCambio].ingredientesDeCalidad);
                }else{
                    printf("%d",crewsNuevo[indiceCrewCambio].ingredientesDeCalidad);
                    printf(" en ingredientes de calidad");
                    cambioAnterior=true;
                }
            }
            if(cambioDesayuno){
                if(cambioAnterior){
                    printf(", ademas es subido a nivel %d en desayunos",crewsNuevo[indiceCrewCambio].desayunos);
                }else{
                    printf("%d",crewsNuevo[indiceCrewCambio].desayunos);
                    printf(" en desayunos");
                    cambioAnterior=true;
                }
            }
            
            if(cambioBebidas){
                if(cambioAnterior){
                    printf(", tambien es subido a nivel %d en bebidas y postres",crewsNuevo[indiceCrewCambio].bebidasYpostres);
                }else{
                    printf("%d",crewsNuevo[indiceCrewCambio].bebidasYpostres);
                    printf(" en bebidas y postres");
                    cambioAnterior=true;
                }
            }
            if(cambioCARE){
                if(cambioAnterior){
                    printf(", ademas es subido a nivel %d en C.A.R.E.",crewsNuevo[indiceCrewCambio].CARE);
                }else{
                    printf("%d",crewsNuevo[indiceCrewCambio].CARE);
                    printf(" en C.A.R.E.");
                    cambioAnterior=true;
                }
            }
            if(cambioServicio){
                if(cambioAnterior){
                    printf(", igualmente es subido a nivel %d en servicio al invitado",crewsNuevo[indiceCrewCambio].servicioAlInvitado);
                }else{
                    printf("%d",crewsNuevo[indiceCrewCambio].servicioAlInvitado);
                    printf(" en servicio al invitado");
                    cambioAnterior=true;
                }
            }
            if(cambioCanalesDigitales){
                if(cambioAnterior){
                    printf(", por ultimo es subido a nivel %d en canales digitales",crewsNuevo[indiceCrewCambio].canalesDigitales);
                }else{
                    printf("%d",crewsNuevo[indiceCrewCambio].canalesDigitales);
                    printf(" en canales digitales");
                    //Es el ultimo por lo que no es necestario cambiar la variable de cambio anterior
                }
                
            }
            printf(".\n");
        }
        
    }
}
void redaccionCorreo(){
    time_t fecha = time(NULL);
    struct tm date = *localtime(&fecha);
    printf("Junto son saludar, hago envió de la grafica semanal de eficiencia correspondiente a ");
    printf("%02d/%02d/%d.",date.tm_mday,date.tm_mon+1,date.tm_year+1900);
    printf(" En esta se encuentran presente los siguientes cambios:\n");
    //las siguientes 3 lineas es el contendio del correo que funciona perfectamente
    verificarEliminados();
    veroficarAgregados();
    verificacionGeneral();
    printf("Estos fueron los cambios  en la grafica de esta semena, seguiremos trabajando en el entrenamiento de los crews. \n");
    printf("Buena semana\n");
}


int main() {
    char nombrePrimerArchivo[100];
    char nombreSegundoArchivo[100];

    printf("Debes ingresar primero el archivo antiguo\n");
    printf("primer archivo a abrir(copia y pega con el .csv, debe estar sin espacios): ");
    scanf("%99s", nombrePrimerArchivo);
    printf("Debes ingresar ahora el archivo nuevo\n");
     printf("segundo archivo a abrir(copia y pega con el .csv, debe estar sin espacios): ");
    scanf("%99s", nombreSegundoArchivo);
    
    leerPrimerArchivo(nombrePrimerArchivo);
    leerSegundoArchivo(nombreSegundoArchivo);   
    //si quieres ver o comprobar que los crews hayan sido agregados de forma correcta descomenta lo de abajo
    /*
   imprimirCrews(1);
    printf("_-_-_-_-FIN IMPRESION PRIMER ARCHIVO_-_-_-_-_-\n\n\n\n\n");
    printf("_-_-_-_-SEGUNDA IMPRESION DEL SEGUNDO ARCHIVO_-_-_-_-_-_-\n\n");
    imprimirCrews(2);
    */

   
    printf("\n\n\n");
    printf("-_-_-_-_-_CORREO REDACTADO ABAJO-_-_-_-_-_\n");
    printf("\n\n\n");
    redaccionCorreo();
    return 0;
}