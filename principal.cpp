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
TipoRet DF (TDirectorio &sistema, char *nombreArchivo, char* cantidad);
TipoRet TYPE (TDirectorio &sistema, char *nombreArchivo);
TipoRet DESTRUIRSISTEMA (TDirectorio &sistema);



// programa principal
int main() {
    char restoLinea[MAX_LINEA + 1];
    char comando[MAX_PALABRA];
    char parametro[MAX_PALABRA];
    char texto[MAX_PALABRA];
    char nombrearchivo[MAX_NOMBRE];
    char cantidad [MAX_PALABRA];
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
                leerChars(cantidad);
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

                TipoRet salida= CREATE(sistema, nombrearchivo);
                if (salida == OK)
                        printf("OK\n");
                else if (salida == NO_IMPLEMENTADA )
                                printf("NO_IMPLEMENTADA\n"); 

        } else if (0 == strcmp(comando, "DELETE")) {
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
   // Verificar si el nombre del archivo no está en uso en el directorio actual
    if (!existFileDirectory(sistema, nombreArchivo)) {
        // Crear un nuevo archivo vacío con el nombre proporcionado y extensión "txt"
        TArchivo nuevoArchivo = createEmptyFile(nombreArchivo, "txt");
        
        // Agregar el nuevo archivo al directorio actual
        createFileInDirectory(sistema, getFileName (nuevoArchivo));
        
        return OK; // Éxito al crear el archivo
    } else {
        return ERROR; // El archivo ya existe en el directorio actual
    }
}




TipoRet DELETE(TDirectorio &sistema, Cadena nombreArchivo) {
    // Verificar si el archivo existe en el directorio
    if (!existFileDirectory(sistema, nombreArchivo)) {
        return ERROR; // El archivo no existe en el directorio
    }

    // Obtener el archivo del directorio
    TArchivo archivo = getFileDirectory(sistema, nombreArchivo);

    // Verificar si el archivo tiene permiso de escritura
    if (!haveWritePermission(archivo)) {
        return ERROR; // El archivo es de solo lectura y no puede ser eliminado
    }

    // Eliminar el archivo de la lista de archivos del directorio
        TFila anterior = NULL;
        TFila actual = firstRowFile(archivo);
        while (actual != NULL) {
        TLinea lineaActual = headRow(actual);
        if (strcmp(getFileName(lineaActual), nombreArchivo) == 0) {
                if (anterior == NULL) {
                archivo->fila = nextRow(actual);
                } else {
                anterior->sig = nextRow(actual);
                }
        destroyFile(lineaActual); // Liberar la memoria del archivo
        deleteFirstRow(actual); // Liberar la memoria de la fila
        return OK;
    }
    anterior = actual;
    actual = nextRow(actual);
}

        anterior = actual;
        actual = nextRow(actual;);
    }

    return ERROR; // No debería llegar aquí
}

TipoRet DELETE(TDirectorio &directorio, Cadena nombreArchivo) {
    // Verificar si el archivo existe en el directorio actual
    if (!existFileDirectory(directorio, nombreArchivo)) {
        return ERROR; // No existe el archivo en el directorio actual
    }

    // Buscar el archivo en la lista de archivos del directorio y eliminarlo
    deleteFileDirectory(directorio, nombreArchivo);

    return OK; // El archivo se eliminó exitosamente
}

TipoRet ATTRIB (TDirectorio &sistema, Cadena nombreArchivo, Cadena parametro){
        // Verificar si el archivo existe en el directorio actual
    TArchivo archivo = getFileDirectory(sistema, nombreArchivo);

    if (archivo != NULL) {
        // Verificar el valor de nuevosAtributos y realizar cambios en consecuencia
        if (strcmp(parametro, "+W") == 0) {
            // Agregar permiso de escritura al archivo
            setWritePermission(archivo, true);
            return OK; // Éxito al agregar permiso de escritura
        } else if (strcmp(parametro, "-W") == 0) {
            // Quitar permiso de escritura al archivo
            setWritePermission(archivo, false);
            return OK; // Éxito al quitar permiso de escritura
        } else {
            return ERROR; // Valor de nuevosAtributos no válido
        }
    } else {
        return ERROR; // El archivo no existe en el directorio actual
    }
}
6

TipoRet IF(TDirectorio &sistema, Cadena nombreArchivo, Cadena texto) {
    // Verificar si el archivo existe en el directorio
    if (!existFileDirectory(sistema, nombreArchivo)) {
        return ERROR; // El archivo no existe en el directorio
    }

    // Obtener el archivo del directorio
    TArchivo archivo = getFileDirectory(sistema, nombreArchivo);

    // Verificar si el archivo tiene permiso de escritura
    if (!haveWritePermission(archivo)) {
        return ERROR; // El archivo es de solo lectura y no puede ser modificado
    }

    // Creamos una nueva fila
    TFila nuevaFila = createRow();

    // Modificamos la nueva fila para agregarle el texto
    modifyRow(nuevaFila, texto);

    // Insertamos la nueva fila al comienzo del archivo
    nuevaFila->sig = archivo->fila; // Hacemos que la nueva fila apunte a la primera fila del archivo
    archivo->fila = nuevaFila; // Actualizamos el puntero de la primera fila del archivo a la nueva fila

    // Calcular el total de caracteres en el archivo
    int totalCaracteres = 0;
    TFila current = archivo->fila;
    while (current != NULL) {
        totalCaracteres += strlen(current->texto);
        current = current->sig;
    }

    // Truncar el texto si excede TEXTO_MAX
    if (totalCaracteres > TEXTO_MAX) {
        int caracteresAEliminar = totalCaracteres - TEXTO_MAX;
        // Aquí necesitarías una función para eliminar caracteres del final del archivo
    }

    return OK; // Retornamos OK si todo salió bien
}

TipoRet IN(TDirectorio &sistema, Cadena nombreArchivo, Cadena texto) {
    // Buscar el archivo en el directorio actual
    TArchivo archivo = getFileDirectory(sistema, nombreArchivo);

    if (archivo != NULL) {
        // Verificar si el archivo tiene permiso de escritura
        if (haveWritePermission(archivo)) {
            // Obtener la primera línea del archivo
            TLinea primeraLinea = getFirstLine(archivo);

            // Calcular la longitud actual del archivo
            int longitudActual = getCountChars(archivo);

            // Calcular la longitud del nuevo texto
            int longitudTexto = strlen(texto);

            // Verificar si se excede el límite TEXTO_MAX
            if (longitudActual + longitudTexto > TEXTO_MAX) {
                // Calcular la cantidad de caracteres que se deben eliminar
                int caracteresAEliminar = longitudActual + longitudTexto - TEXTO_MAX;

                // Eliminar caracteres de la última línea si es necesario
                while (!isEmptyLine(primeraLinea) && caracteresAEliminar > 0) {
                    int longitudLinea = countNodesLine(primeraLinea);
                    if (caracteresAEliminar >= longitudLinea) {
                        // Eliminar toda la línea
                        caracteresAEliminar -= longitudLinea;
                        deleteFirstChar(primeraLinea);
                    } else {
                        // Eliminar solo los caracteres necesarios
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



TipoRet DF(TDirectorio &sistema, Cadena nombreArchivo, Cadena cantidad) {
    // Convertir la cantidad de caracteres a eliminar a un número entero
    int K = atoi(cantidad);

    // Verificar si el archivo existe en el directorio
    if (!existFileDirectory(sistema, nombreArchivo)) {
        return ERROR; // El archivo no existe en el directorio
    }

    // Obtener el archivo del directorio
    TArchivo archivo = getFileDirectory(sistema, nombreArchivo);

    // Verificar si el archivo tiene permiso de escritura
    if (!haveWritePermission(archivo)) {
        return ERROR; // El archivo es de solo lectura y no puede ser modificado
    }

    // Eliminar los primeros K caracteres del archivo
    TFila* actual = archivo->fila;
    while (actual != NULL && K > 0) {
        int len = strlen(actual->texto);
        if (len <= K) {
            // Si la longitud de la fila es menor o igual a K, eliminamos toda la fila
            archivo->fila = actual->sig;
            delete[] actual->texto;
            delete actual;
            K -= len;
            actual = archivo->fila;
        } else {
            // Si la longitud de la fila es mayor que K, eliminamos los primeros K caracteres
            memmove(actual->texto, actual->texto + K, len - K + 1);
            K = 0;
        }
    }

    return OK;
}


TipoRet TYPE(TDirectorio &sistema, Cadena nombreArchivo) {
    // Buscar el archivo en el directorio actual
    TArchivo archivo = getFileDirectory(sistema, nombreArchivo);

    if (archivo != NULL) {
        // Imprimir el nombre del archivo
        printf("Contenido del archivo \"%s\":\n", nombreArchivo);

        // Obtener la primera línea del archivo
        TLinea primeraLinea = getFirstLine(archivo);

        // Verificar si el archivo tiene contenido
        if (!isEmptyLine(primeraLinea)) {
            // Iterar a través de las líneas del archivo y mostrarlas
            while (primeraLinea != NULL) {
                // Obtener el primer carácter de la línea
                char primerCaracter = firstCharLine(primeraLinea);
                TLinea lineaActual = primeraLinea;

                // Imprimir la línea caracter por caracter
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
    // Función recursiva para liberar la memoria de todos los archivos y sus filas
    void destruirArchivo(TArchivo archivo) {
        if (archivo == NULL) return;

        // Liberar todas las filas del archivo
        while (archivo->fila != NULL) {
            TFila filaActual = archivo->fila;
            archivo->fila = filaActual->sig;
            delete[] filaActual->texto; // Liberar la memoria del texto de la fila
            delete filaActual; // Liberar la memoria de la fila
        }

        // Liberar el nombre y la extensión del archivo
        delete[] archivo->nombre;
        delete[] archivo->extension;

        // Liberar la memoria del archivo
        delete archivo;
    }

    // Recorrer todos los archivos del directorio y liberar su memoria
    while (sistema->archivo != NULL) {
        TArchivo archivoActual = sistema->archivo;
        sistema->archivo = archivoActual->sig;
        destruirArchivo(archivoActual);
    }

    // Liberar la memoria del directorio
    delete sistema;
    sistema = NULL; // Establecer el puntero del sistema a NULL para evitar referencias a memoria liberada

    return OK;
}
