
/*
Módulo principal de la tarea 1.FILE SYSTEM

Intérprete de comandos para probar los módulos.

  Laboratorio de EDA 2023
  UTU - LATU - Turno Nocturno 
  Profesor Ferando Arrieta
*/

#include "include/archivo.h"
#include "include/linea.h"
#include "include/fila.h"
#include "include/directorio.h"
#include "include/utils.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstddef>
#define MAX_PALABRA 64
#define MAX_LINEA 256
#define MAX_RUTA 256
#define MAX_PARAMETRO 10
#define MAX_PARAMETRODIR 1
#define MAX_COMANDO 10
#define MAX_NOMBRE 15
#define MAX_EXTENSION 3
#define TEXTO_MAX 50

enum _retorno {OK, ERROR, NO_IMPLEMENTADA};
typedef enum _retorno TipoRet;
typedef char* Cadena;

  
TipoRet CREARSISTEMA(TDirectorio &s);
TipoRet CREATE (TDirectorio &sistema, char *nombreArchivo);
TipoRet DELETE (TDirectorio &sistema, char *nombreArchivo);
TipoRet ATTRIB (TDirectorio &sistema, char *nombreArchivo, char* parametro);
TipoRet IF (TDirectorio &sistema, char *nombreArchivo, char* texto);
TipoRet IN (TDirectorio &sistema, char *nombreArchivo, char* texto);
TipoRet DF (TDirectorio &sistema, Cadena nombreArchivo, int* cantidad);
TipoRet TYPE (TDirectorio &sistema, char *nombreArchivo);
TipoRet DESTRUIRSISTEMA (TDirectorio &sistema);



// programa principal
int main() {
    char restoLinea[MAX_LINEA + 1];
    char comando[MAX_PALABRA];
    char parametro[MAX_PALABRA];
    char texto[MAX_PALABRA];
    char nombrearchivo[MAX_NOMBRE];
    int cantidad [MAX_PALABRA];
    //char parametro;
    TDirectorio sistema;
    int sistemaInicializado=false;
    bool salir = false;
    while (!salir) {
        printf("#");	
        // leer el comando
        leerChars(comando);
        if (!strcmp(comando,"ATTRIB")){
            leerChars(nombrearchivo);
            leerChars(parametro);
            printf("El comando es:%s\n",comando); 
            printf("El nombre de archivo es:%s\n",nombrearchivo);
            printf("El parametro es:%s\n",parametro);
        }
        else if (!strcmp(comando,"CREATEFILE"))
                leerChars(nombrearchivo);
        
        else if (!strcmp(comando,"DELETE"))
                leerChars(nombrearchivo);
        
        else if (!strcmp(comando,"IF")){
                leerChars(nombrearchivo);
                leerRestoLinea(texto);
        }
        else if (!strcmp(comando,"IN")){
                leerChars(nombrearchivo);
                leerRestoLinea (texto);
                printf("El comando es:%s\n",comando); 
                printf("El nombre de archivo es:%s\n",nombrearchivo);
                printf("El texto es:%s\n",texto);
        }
        else if (!strcmp(comando,"DF")){
                leerChars(nombrearchivo);
        }        
        else if (!strcmp(comando,"TYPE"))
                leerChars(nombrearchivo);
                
        
        // *********************** Procesamiento de comandos ***********************************
        
        
        if (0 == strcmp(comando, "CREARSISTEMA")) {
            if (!sistemaInicializado){
                TipoRet salida=CREARSISTEMA(sistema);
                if (salida == OK){
                    sistemaInicializado=true;
                    printf("*** SYSTEM INICIALIZED ***\n");
                    printf("OK\n");
                }
            }   
            else 
                 printf("EL SISTEMA YA FUE INICIALIZADO\n");

        }else if (0 == strcmp(comando, "CREATEFILE")) {   
                printf("ingresa el nombre del archivo:\n"); 
                TipoRet salida= CREATE(sistema, nombrearchivo);
                if (salida == OK)
                        printf("OK\n");
                else if (salida == ERROR )
                                printf("NO_ANDA\n"); 

        } else if (0 == strcmp(comando, "DELETE")) {
            printf("DAME EL NOMBREEE");
                TipoRet salida=DELETE(sistema,nombrearchivo);
                if (salida == OK)
                        printf("OK\n");
                else if (salida == NO_IMPLEMENTADA )
                                printf("NO_IMPLEMENTADA\n");

        } else if (0 == strcmp(comando, "ATTRIB")) {
                TipoRet salida=ATTRIB(sistema, nombrearchivo,parametro);
                if (salida == OK)
                        printf("OK\n");
                else if (salida == NO_IMPLEMENTADA )
                                printf("NO_IMPLEMENTADA\n");
                
        } else if (0 == strcmp(comando, "IF")) {
                TipoRet salida=IF(sistema, nombrearchivo,texto);
                if (salida == OK)
                        printf("OK\n");
                else if (salida == NO_IMPLEMENTADA )
                                printf("NO_IMPLEMENTADA\n");
                
        } else if (0 == strcmp(comando, "IN")) {
                TipoRet salida=IN(sistema, nombrearchivo,texto);
                if (salida == OK)
                        printf("OK\n");
                else if (salida == NO_IMPLEMENTADA )
                                printf("NO_IMPLEMENTADA\n");
                
        } else if (0 == strcmp(comando, "DF")) {
                TipoRet salida=DF(sistema, nombrearchivo,cantidad);
                if (salida == OK)
                        printf("OK\n");
                else if (salida == NO_IMPLEMENTADA )
                                printf("NO_IMPLEMENTADA\n");
                
        } else if (0 == strcmp(comando, "TYPE")) {
                TipoRet salida=TYPE(sistema, nombrearchivo);
                if (salida == OK)
                        printf("OK\n");
                else if (salida == NO_IMPLEMENTADA )
                                printf("NO_IMPLEMENTADA\n");
                
        } else if (0 == strcmp(comando, "DESTRUIRSISTEMA")) {
                TipoRet salida=DESTRUIRSISTEMA(sistema);
                if (salida == OK)
                        printf("OK\n");
                else if (salida == NO_IMPLEMENTADA )
                                printf("NO_IMPLEMENTADA\n");
        }else
            printf("Comando no reconocido.\n");

        fgets(restoLinea, MAX_LINEA + 1, stdin);
    } // while
    return 0;
} // main



//****************************** Funciones a implementar ************************************

TipoRet CREARSISTEMA (TDirectorio &sistema){
         sistema = createRootDirectory();
         return OK;
}  

TipoRet CREATE(TDirectorio &sistema, Cadena nombreArchivo) {
    //Cadena extension = "txt";
   // Verificar si el nombre del archivo no está en uso en el directorio actual
    if (!existFileDirectory(sistema, nombreArchivo)) {
        // Crear un nuevo archivo vacío con el nombre proporcionado y extensión "txt"
       /*TArchivo nuevoArchivo = createEmptyFile(nombreArchivo, extension);
        
        // Agregar el nuevo archivo al directorio actual
        createFileInDirectory(sistema, getFileName (nuevoArchivo));*/
        
        return OK; // Éxito al crear el archivo
    } else {
        return ERROR; // El archivo ya existe en el directorio actual
    }
}





TipoRet DELETE(TDirectorio &directorio, Cadena nombreArchivo) {
    
    if (!existFileDirectory(directorio, nombreArchivo)) {
        return ERROR; // No existe el archivo en el directorio actual
    }

    deleteFileDirectory(directorio, nombreArchivo);

    return OK; 
}

TipoRet ATTRIB (TDirectorio &sistema, Cadena nombreArchivo, Cadena parametro){
    
    TArchivo archivo = getFileDirectory(sistema, nombreArchivo);

    if (archivo != NULL) {

        if (strcmp(parametro, "+W") == 0) {

            setWritePermission(archivo, true);
            return OK; 
        } else if (strcmp(parametro, "-W") == 0) {
       
            setWritePermission(archivo, false);
            return OK; 
        } else {
            return ERROR; 
        }
    } else {
        return ERROR; 
    }
}


TipoRet IF(TDirectorio &sistema, Cadena nombreArchivo, Cadena texto) {
    TArchivo archivo = getFileDirectory(sistema, nombreArchivo);


    insertChartsNewRow(archivo, texto);

    TLinea linea=getFirstRow (archivo);
     int cantidadCaracteres=countNodesLine(linea);
     int eliminar=cantidadCaracteres-TEXTO_MAX;
     for( int i=1;i<=eliminar;i++)
     {
        deleteLastChar(linea);
     }

    return OK;
}

TipoRet IN(TDirectorio &sistema, Cadena nombreArchivo, Cadena texto) {

    TArchivo archivo = getFileDirectory(sistema, nombreArchivo);

    if (!isEmptyFile(archivo)) {

        if (haveWritePermission(archivo)) {
        
            TLinea primeraLinea = getFirstLine(archivo);

            int longitudActual = getCountChars(archivo);

            int longitudTexto = strlen(texto);


            if (longitudActual + longitudTexto > TEXTO_MAX) {

                int caracteresAEliminar = longitudActual + longitudTexto - TEXTO_MAX;

                while (!isEmptyLine(primeraLinea) && caracteresAEliminar > 0) {
                    int longitudLinea = countNodesLine(primeraLinea);
                    if (caracteresAEliminar >= longitudLinea) {

                        caracteresAEliminar -= longitudLinea;
                        deleteFirstChar(primeraLinea);
                    } else {

                        for (int i = 0; i < caracteresAEliminar; i++) {
                            deleteFirstChar(primeraLinea);
                        }
                        caracteresAEliminar = 0;
                    }
                }
            }

            // Agregar el texto como primera línea
            insertChartsFirstRow(archivo, texto);

            return OK; // Éxito al agregar el texto
        } else {
            return ERROR; // El archivo no tiene permiso de escritura
        }
    } else {
        return ERROR; // El archivo no existe en el directorio actual
    }
}



TipoRet DF(TDirectorio &sistema, Cadena nombreArchivo, int cantidad) { //chequear posibles errores
  TArchivo archivo = getFileDirectory(sistema, nombreArchivo);
  
    TLinea linea=getFirstRow (archivo);
     for( int i=1;i<=cantidad;i++)
     {
        deleteFirstChar(linea);
     }

    return OK;
}


TipoRet TYPE(TDirectorio &sistema, Cadena nombreArchivo) {

    TArchivo archivo = getFileDirectory(sistema, nombreArchivo);

    if (!isEmptyFile(archivo)) {

        printf("Contenido del archivo \"%s\":\n", nombreArchivo);


        TLinea primeraLinea = getFirstLine(archivo);


        if (!isEmptyLine(primeraLinea)) {

            while (primeraLinea != NULL) {

                char primerCaracter = firstCharLine(primeraLinea);
                TLinea lineaActual = primeraLinea;

                while (lineaActual != NULL) {
                    printf("%c", primerCaracter);
                    lineaActual = nextLine(lineaActual);
                    if (lineaActual != NULL) {
                        primerCaracter = firstCharLine(lineaActual);
                    }
                }

                // Avanzar a la siguiente línea
                primeraLinea = nextLine(primeraLinea);

                // Imprimir una nueva línea si no es la última línea
                if (primeraLinea != NULL) {
                    printf("\n");
                }
            }

            printf("\n"); // Imprimir una línea en blanco al final
        } else {
            printf("El archivo no posee contenido.\n");
        }

        return OK; // Éxito al mostrar el contenido
    } else {
        return ERROR; // El archivo no existe en el directorio actual
    }
}

TipoRet DESTRUIRSISTEMA(TDirectorio &sistema) {
    return OK;
}
