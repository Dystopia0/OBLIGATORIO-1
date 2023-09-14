/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/archivo.h"
#include "../include/linea.h"
#include "../include/fila.h"
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
    return archivo->fila;
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
