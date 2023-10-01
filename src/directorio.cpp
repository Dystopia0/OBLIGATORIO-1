/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/linea.h"
#include "../include/fila.h"
#include "../include/directorio.h"
#include "../include/archivo.h"
#include "string.h"
#include "stdio.h"


struct _rep_directorio {
   Cadena nombre;
   _rep_directorio* raiz;
   _rep_directorio* sig;
   _rep_directorio* ant;
   TArchivo archivos; 
};
typedef struct _rep_directorio *TDirectorio;

TDirectorio createRootDirectory() {
    TDirectorio raiz = new _rep_directorio;
    raiz->nombre = new char[strlen("Raíz")+1];
    strcpy(raiz->nombre, "Raíz");
    raiz->raiz = raiz;
    raiz->sig = NULL;
    raiz->ant = NULL;
    return raiz;
}

bool isEmptyDirectory(TDirectorio directorio) {
    return (directorio != NULL && directorio->archivos == NULL);
}

bool existFileDirectory(TDirectorio directorio, Cadena nombreArchivo) {
    while (directorio != NULL) {
        if (strcmp(getFileName(directorio->archivos), nombreArchivo) == 0) {
            return true;
        }
        directorio = directorio->sig;
    }
    return false;
}


TArchivo getFileDirectory(TDirectorio directorio, Cadena nombreArchivo) {
    while (directorio != NULL) {
        if (strcmp(getFileName(directorio->archivos), nombreArchivo) == 0) {
            return directorio->archivos;
        }
        directorio = directorio->sig;
    }
    return false;
    return NULL; // Si no se encuentra el archivo
}

//setExtension
//pre-condicion: No existe en directorio un archivo de nombre "nombreArchivo"
//crea un archivo vacio con nombre nombreArchivo y permiso de lectura/escritura
void createFileInDirectory(TDirectorio& directorio, Cadena nombreArchivo) {
  Cadena extension;
  bool pe = true;
  TArchivo archivo = createEmptyFile (nombreArchivo, extension);
  setWritePermission(archivo, pe);
  if(directorio->sig == NULL){
    directorio->sig->archivos = archivo;
  }else{
    directorio = directorio->sig;
  }
}


//pre condicion: el archivo nombreArchivo existe en directorio
//pos-condicion: inserta una nueva fila al comienzo del archivo nombreArchivo conteniendo los chars texto
void insertTextFile(TDirectorio& directorio, Cadena nombreArchivo, Cadena texto){
    
}




