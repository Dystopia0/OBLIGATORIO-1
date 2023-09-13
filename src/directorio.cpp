/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/linea.h"
#include "../include/fila.h"
#include "../include/directorio.h"
#include "../include/archivo.h"


struct _rep_directorio {
   char *nombre[15];
   _rep_directorio* raiz;
   _rep_directorio* sig;
   _rep_directorio* ant;
    *TArchivo listaArchivo;
};
typedef struct _rep_directorio *TDirectorio;