/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/archivo.h"
#include "../include/linea.h"
#include "../include/fila.h"

#include <stdio.h>
#include <string.h>
#define MAX_CARACTERES 50


  struct _rep_archivo{
    Cadena nombre;
    Cadena exten;
    bool escritura;
    TFila fila;
    TFila actual;
    int cantidadElementos;
    bool SoloLectura;
    int cantidadCaracter;
};
typedef struct _rep_archivo *TArchivo;

TArchivo createEmptyFile (Cadena nombreArchivo, Cadena extension){
    TArchivo nuevo = new _rep_archivo;
    nuevo->nombre = nombreArchivo;
    nuevo->exten = extension;
    nuevo->fila=NULL;
    nuevo->actual=NULL;
    nuevo->SoloLectura=true;
    nuevo->escritura=true;
    nuevo->cantidadElementos=0;
    return nuevo;

}

char* getFileName (TArchivo archivo){//luis
        return archivo->nombre;
}

//Retorna retorna un puntero a la primer fila del archivo "archivo"
TFila firstRowFile (TArchivo archivo){
    return archivo->fila;
}

bool haveWritePermission (TArchivo archivo){
    return (archivo->escritura);
       
}

 //retorna true si archivo no tiene filas;
bool isEmptyFile(TArchivo archivo) {
    return  (archivo == NULL)||( archivo->fila == NULL); 
    }
    

TLinea getFirstRow (TArchivo archivo){
    archivo->actual=archivo->fila;
    return headRow(archivo->fila);
}    

//Retorna un puntero a la siguiente Fila de archivo
TLinea getNextRow(TArchivo archivo) {
    if (! isEmptyFile(archivo) && archivo->actual==NULL) {
       archivo->actual = nextRow(archivo->actual);
        if (archivo->actual != NULL) {
            return headRow(archivo->actual);
        }
    }
    return NULL; 
}


int getCountRow (TArchivo archivo){
    return archivo->cantidadElementos;
}

int getCountChars(TArchivo archivo) {// luis duda
    if (!isEmptyFile(archivo)) {
        int contador = 0;
        TFila filaActual = archivo->fila;

        TLinea linea = headRow(filaActual);
        while (linea != NULL) {
            
            contador=contador+countNodesLine(linea);
            linea = getNextRow(archivo);
        }

        return contador;
    } else {
        return 0; 
    }
}


//imprime la Linea del archivo indicada por "numero_linea"
//pre-condición el archivo tiene por lo menos numero_linea de lineas
void printLineFile(TArchivo archivo, int numero_linea){
       
        TLinea actual = headRow(archivo->fila);

        int numeroLinea = 1;
        while(numeroLinea != numero_linea){
                actual=getNextRow(archivo);
                numeroLinea++;
        }
       
       while(actual!=NULL)
       {
            char letra= firstCharLine(actual);
            printf("%c",letra);
            actual=nextLine(actual);
       }

       printf("\n");
    
         
}

void deleteCharterFile(TArchivo &archivo, int cant) {
    if (!isEmptyFile(archivo) && cant > 0) {
        TLinea lineaActual = headRow(archivo->fila);


        while(isEmptyLine(lineaActual) && cant>0){
            while (countNodesLine(lineaActual)!=0  && cant>0) {
                        
                        deleteFirstChar(lineaActual);
                        cant--;
                    }
            if(cant>0)
            {
               lineaActual= nextLine(lineaActual);
               TFila aux = archivo->fila;
               archivo->fila=nextRow(archivo->fila);
                archivo->actual=archivo->fila;
                deleteRows (aux);
            }

        }

    }
}


void setName(TArchivo &archivo, Cadena nuevoNombre){
    archivo->nombre = nuevoNombre;
}

void setExtension(TArchivo &archivo, Cadena nuevaExtension) {
    if (archivo != NULL) {
        // Libera la memoria de la extensión existente si la hay
        if (archivo->exten != NULL) {
            delete[] archivo->exten;
        }

        // Verifica la longitud de la nueva extensión
        if (strlen(nuevaExtension) >= 1 && strlen(nuevaExtension) <= 3) {
            // Asigna la nueva extensión al archivo
            archivo->exten = new char[strlen(nuevaExtension) + 1];
            strcpy(archivo->exten, nuevaExtension);
        } else {
            // Muestra un mensaje de error por pantalla
            printf("Tamaño de extensión no válido. Debe tener entre 1 y 3 caracteres.");
            // No asigna la nueva extensión
            archivo->exten = NULL;
        }
    }
}

//pre-condicion El archivo tiene por lo menos una fila
//Inserta el texto "texto" como una nueva fila al comienzo del archivo 
void insertChartsNewRow(TArchivo &archivo, Cadena texto){

    TFila principio = createRow();
    modifyRow (principio, texto);
    insertRow (principio); 
    archivo->cantidadElementos++;
}


//si valor == true se le asigna el permiso de escritura de "archivo"
//si valor == false se le quita el permiso de escritura de "archivo"
//pre-condicion archivo !=NULL
void setWritePermission(TArchivo &archivo, bool valor){
    archivo->escritura = valor;
}

//elimina toda la memoria utilizada por "archivo"
void destroyFile(TArchivo &archivo) {
    if (archivo != NULL) {
        // Libera la memoria de las filas y sus líneas si existen
        while (archivo->fila != NULL) {
            TFila filaAEliminar = archivo->fila;
            archivo->fila = nextRow(archivo->fila);
            
            // Elimina todas las líneas dentro de la fila
           deleteRows(filaAEliminar);
        }
        
        // Libera la memoria de la estructura _rep_archivo
        delete archivo;
        
        // Establecemos el puntero a NULL para evitar problemas de acceso
        archivo = NULL;
    }
}
