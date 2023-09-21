/*
  Módulo de definición de 'TArchivo'.

  Laboratorio de EDA Turno Nocturno.
  UTU-LATU 2023
 * Profesor Fernando Arrieta
*/

#ifndef _ARCHIVO_H
#define _ARCHIVO_H

#include "../include/archivo.h"
#include "../include/linea.h"
#include "../include/fila.h"

#include <cstddef>


// Representación de 'archivo'.
// Se debe definir en 'archivo.cpp'.
// struct _rep_archivo;
// Declaración del tipo 'TArchivo'

typedef struct _rep_archivo *TArchivo;

//Crea un archivo vacío con nombre nombreArchivo, extensión extension y con permiso de lectura/escritura
//El archivo no contiene filas.
TArchivo createEmptyFile (Cadena nombreArchivo, Cadena extension); //FERNAO

//Retorna un puntero a un array con el nombre del archivo "archivo"
char* getFileName (TArchivo archivo);

//Retorna retorna un puntero a la primer fila del archivo "archivo"
TFila firstRowFile (TArchivo archivo);

//Retorna true si archivo tiene permiso de escritura
bool haveWritePermission (TArchivo archivo);  //FERNAO

//retorna true si archivo no tiene filas;
bool isEmptyFile(TArchivo archivo);

//Retorna un puntero a la primer Fila de archivo
TLinea getFirstRow (TArchivo archivo); //FERNAO

//Retorna un puntero a la siguiente Fila de archivo
TLinea getNextRow (TArchivo archivo);

//Retorna la cantidad de Fila que tiene el archvio "archivo"
int getCountRow (TArchivo archivo); //FERNAO

//Retorna la cantidad de caracteres que tiene el archvio "archivo"
int getCountChars (TArchivo archivo);

//imprime la Linea del archivo indicada por "numero_linea"
//pre-condición el archivo tiene por lo menos numero_linea de lineas
void printLineFile(TArchivo archivo, int numero_linea); //FERNAO
    
//Elimina los cant cantidad de caracteres finales del "archivo"
//En caso que el archivo tenga menos caracteres los elimina a todos
void deleteCharterFile (TArchivo &archivo, int cant);
    
//Cambia el nombre del archivo "archivo" por nuevoNombre
void setName(TArchivo &archivo, Cadena nuevoNombre); //FERNAO

//Cambia la extension del "archivo" por nuevoNombre
void setExtension(TArchivo &archivo, Cadena nuevaExtension);

//Inserta el texto "texto" como una nueva fila al comienzo del archivo 
void insertChartsNewRow(TArchivo &archivo, Cadena texto); //FERNAO

//pre-condicion El archivo tiene por lo menos una fila
//Inserta el texto "texto" al inicio de la primer fila del archivo
void insertChartsFirstRow(TArchivo &archivo, Cadena texto);

//si valor == true se le asigna el permiso de escritura de "archivo"
//si valor == false se le quita el permiso de escritura de "archivo"
//pre-condicion archivo !=NULL
void setWritePermission(TArchivo &archivo, bool valor); //FERNAO

//elimina toda la memoria utilizada por "archivo"
void destroyFile (TArchivo &archivo); 

//pos-condición: Retorna un puntero a la linea de la primer fila del archivo "archivo"
TLinea getFirstLine (TArchivo archivo); //FERNAO


#endif
