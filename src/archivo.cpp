/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/archivo.h"
#include "../include/linea.h"
#include "../include/fila.h"
#include <iostream>
#include <stdio.h>
#define MAX_CARACTERES 50


  struct _rep_archivo{
    Cadena nombre;
    Cadena exten;
    bool escritura;
    TFila fila;
    bool SoloLectura;
    int cantidadCaracter;
};
typedef struct _rep_archivo *TArchivo;

TArchivo createEmptyFile (Cadena nombreArchivo, Cadena extension){
    TArchivo nuevo = new _rep_archivo;
    nuevo->nombre = nombreArchivo;
    nuevo->exten = extension;
    nuevo->fila=NULL;
    nuevo->SoloLectura=false;
    nuevo->escritura=true;
    return nuevo;

}



bool haveWritePermission (TArchivo archivo){
    return (archivo->escritura);
       

}
    

TLinea getFirstRow (TArchivo archivo){
    headRow(archivo->fila);
}    


int getCountRow (TArchivo archivo){
    int contador=0;
    TFila aux=archivo->fila;
    while(aux != NULL){
        aux=nextRow(aux);
        contador++;
    }
    return contador;
}

//imprime la Linea del archivo indicada por "numero_linea"
//pre-condición el archivo tiene por lo menos numero_linea de lineas
void printLineFile(TArchivo archivo, int numero_linea){
        TFila aux=archivo->fila;
        TLinea actual = headRow(archivo->fila);

        int linea = getCountRow(archivo);
        while(linea != numero_linea){
                aux=nextRow(aux);
                linea++;
        }
       
        
            while (actual != NULL) {
                printf("%c", actual->letra);
                actual = actual->sig;
            }
}


void setName(TArchivo &archivo, Cadena nuevoNombre){
    archivo->nombre = nuevoNombre;
}


//Inserta el texto "texto" como una nueva fila al comienzo del archivo 
void insertChartsNewRow(TArchivo &archivo, Cadena texto){

}


//si valor == true se le asigna el permiso de escritura de "archivo"
//si valor == false se le quita el permiso de escritura de "archivo"
//pre-condicion archivo !=NULL
void setWritePermission(TArchivo &archivo, bool valor){
   if(valor == true){
    archivo->escritura == true;
   }else{
    archivo->escritura == false;
   }
}
