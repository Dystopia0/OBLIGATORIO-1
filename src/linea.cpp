/* 1111111 */ // sustituiir con los 7 dígitos de la cédula
/*
 Modulo que implemente el archivo linea.h

 */
#include <stdio.h>
#include "../include/linea.h"

struct _rep_linea
{
    char letra;
    _rep_linea *sig;
};
typedef struct _rep_linea *TLinea;

TLinea createLine()
{
    return NULL; // Devolvemos un puntero nulo, que representa una línea vacía
}

bool isEmptyLine(TLinea linea)
{
    return linea == NULL;
}

void insertCharLine(char letra, TLinea &linea)
{
    TLinea nuevo = new _rep_linea;
    nuevo->letra = letra;
    nuevo->sig = linea;
    linea = nuevo;
}

char firstCharLine(TLinea linea)
{
    return linea->letra;
}

TLinea nextLine(TLinea linea)
{
    return linea->sig;
}

// Retorna la cantidad de elementos que tiene la linea "linea"
int countNodesLine(TLinea linea)
{
    int count = 0; // Inicializamos el contador a 0

    // Recorremos la lista enlazada y contamos los nodos
    while (linea != NULL)
    {
        count++;
        linea = linea->sig; // Avanzamos al siguiente nodo
    }

    return count;
}

// pre-condicion: linea != NULL
// pos-condicion: Elimina el primer nodo de la linea "linea"
void deleteFirstChar(TLinea &linea)
{

    TLinea aux = linea; // Guardamos una referencia al primer nodo
    linea = linea->sig; // Actualizamos la línea para que apunte al siguiente nodo
    delete aux;         // Liberamos la memoria del nodo eliminado
}

void deleteLastChar(TLinea &linea)
{
    if (linea->sig == NULL)
    {
        // Si solo hay un nodo en la línea, eliminamos ese nodo
        delete linea;
        linea = NULL; // Actualizamos la línea para que sea nula
    }
    else
    {
        TLinea temp = linea;
        while (temp->sig->sig != NULL)
        {
            temp = temp->sig;
        }
        // temp apunta al nodo antes del último nodo
        delete temp->sig;
        temp->sig = NULL; // Actualizamos el puntero al último nodo
    }
}

void destroyLine(TLinea &linea)
{
    while (linea != NULL)
    {
        TLinea temp = linea;
        linea = linea->sig;
        delete temp;
    }
}