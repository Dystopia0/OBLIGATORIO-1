/* 1111111 */ // sustituiir con los 7 dígitos de la cédula
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "../include/fila.h"
#include "../include/linea.h"
typedef char* Cadena;

struct _rep_fila {
    TLinea linea;//la primera letra de la linea
    _rep_fila* sig;
};
typedef struct _rep_fila *TFila;

TFila createRow(){
    TFila nuevo = new _rep_fila;
    nuevo->linea = NULL;
    nuevo->sig = NULL;
    return nuevo;
}



//no idea
TLinea headRow(TFila fila){
    return fila->linea;
}

//Pos-Condición Inserta una nueva fila al principio de "fila"
 void insertRow (TFila &fila){
    TFila nuevo = createRow();
    nuevo->sig = fila;
    fila = nuevo;
    
 }

//pre-condicion: fila !=NULL
//pos-condicion: Retorna un puntero al siguente elemento de la fila "fila"
TFila nextRow (TFila fila){
    return fila->sig;
}

//pre-condicion: fila != NULL
//elimina el primer nodo de la fila "fila"
void deleteFirstRow (TFila &fila){
    TFila aux = new _rep_fila;
    aux = fila;
    fila = fila->sig;
    delete aux;
}

//Elimina toda la memoria de la fila "fila"
void deleteRows (TFila& fila){
    while(fila!=NULL)
    {
        TFila borrar=fila;
        fila=nextRow(fila);
        delete borrar;
    }
    
   
}

//Pos-Condición modifica el primer elemento de la fila "fila" agregando los caracteres al inicio del primer elemento "linea" de la fila.
void modifyRow (TFila &fila, Cadena caracteres){
    
}

bool isEmptyRow(TFila fila){
    return fila==NULL;
}