/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/linea.h"
#include "../include/fila.h"
#include "../include/directorio.h"
#include "../include/archivo.h"
#include "string.h"
#include "stdio.h"


struct listaArchivos{
  TArchivo archivos;
  listaArchivos* sig;
};

struct _rep_directorio {
   char *nombre[15];
   _rep_directorio* raiz;
   _rep_directorio* sig;
   _rep_directorio* ant;
   listaArchivos* listaArchivo;
};
typedef struct _rep_directorio *TDirectorio;



//Crea el directorio de nombre Raíz del filesystem 
TDirectorio createRootDirectory() {
    TDirectorio raiz = new _rep_directorio;
    
    // Asignar nombre al directorio raíz (por ejemplo, "Raíz")
    raiz->nombre = new char[6]; // Tamaño 6 para incluir el carácter nulo
    strcpy(raiz->nombre, "Raíz");
    
    // Inicializar el puntero a raíz y los otros punteros a NULL
    raiz->raiz = raiz;  // El puntero a raíz apunta al propio directorio raíz
    raiz->sig = NULL;
    raiz->ant = NULL;
    raiz->filas = NULL;

    return raiz;
}

//retorna true si el directorio "directorio" no tiene archivos
bool isEmptyDirectory(TDirectorio directorio) {// en teoria creo q con el primero falta
    return (directorio != NULL && directorio->filas == NULL);
}
//retorna true si el archivo de nombre "nombreArchivo existe en el directorio "directorio"
bool existFileDirectory(TDirectorio directorio, Cadena nombreArchivo) {//se podria agregar mas comentarios
    if (directorio != NULL && directorio->filas != NULL) {
        // Recorrer la lista de archivos en el directorio
        TFila* f;as = directorio->filas;
        while (lista != NULL) {
            if (strcmp(getFileName(lista->), nombreArchivo) == 0) {
                // Se encontró un archivo con el mismo nombre
                return true;
            }
            lista = lista->sig;
        }
    }
    // No se encontró un archivo con el nombre especificado
    return false;
}




//pre-condicion existe el archivo de nombre nombreArchivo en el directorio "directorio"
//pos-condicion: retorna un puntero al archivo de nombre "nombreArchivo"
TArchivo getFileDirectory(TDirectorio directorio, Cadena nombreArchivo) {
    // Recorrer la lista de archivos en el directorio
    listaArchivos* lista = directorio->filas;
    while (lista != NULL) {
        if (strcmp(getFileName(lista->archivos), nombreArchivo) == 0) {
            // Se encontró un archivo con el mismo nombre
            return lista->archivos;
        }
        lista = lista->sig;
    }
    // Si no se encuentra el archivo, retornar NULL
    return NULL;
}

//pre condicion: el archivo nombreArchivo existe en directorio
//pos-condicion: inserta una nueva fila al comienzo del archivo nombreArchivo conteniendo los chars texto
void insertTextFile(TDirectorio& directorio, Cadena nombreArchivo, Cadena texto) {// duda de las ultimas 2 lineas
    // Buscar el archivo por nombre en el directorio
    TArchivo archivo = getFileDirectory(directorio, nombreArchivo);

    if (archivo != NULL) {
        // Crear una nueva fila y una nueva línea para el texto
        insertRow(getFirstRow (directorio->listaArchivo));
        modifyRow(directorio->filas,texto);

    }

}


void insertTextFile(TDirectorio& directorio, Cadena nombreArchivo, Cadena texto) {

    
}

//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: elimina el archivo del directorio "directorio" y toda la memoria utilizada por este.
void deleteFileDirectory(TDirectorio& directorio, Cadena nombreArchivo) {
    // Buscar el archivo por nombre en el directorio
    listaArchivos* lista = directorio->filas;
    listaArchivos* prevLista = NULL;

    while (lista != NULL) {
        if (strcmp(getFileName(lista->archivos), nombreArchivo) == 0) {
            // Se encontró el archivo, eliminarlo
            if (prevLista == NULL) {
                // El archivo es el primer elemento de la lista
                directorio->filas = lista->sig;
            } else {
                // El archivo no es el primer elemento de la lista
                prevLista->sig = lista->sig;
            }

            // Liberar la memoria del archivo y sus filas y líneas
            destroyFile(lista->archivos);
            delete lista;
            return;  // Salir de la función
        }
        prevLista = lista;
        lista = lista->sig;
    }
}

//esta no la revise a profundidad, mucho texto, aunq usa las funciones q ya creo, asi q tiene buena pinta
//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: elimina los "cantidad" caracteres iniciales del archivo nombreArchivo
void deleteCharsFile(TDirectorio& directorio, Cadena nombreArchivo, int cantidad) {
    // Buscar el archivo por nombre en el directorio
    TArchivo archivo = getFileDirectory(directorio, nombreArchivo);

    if (archivo != NULL && getFirstRow(archivo) != NULL) {
        // Eliminar los caracteres iniciales de la primera línea del archivo
        TFila primeraFila = firstRowFile (archivo); //con funcion nueva
        TLinea primeraLinea = headRow(primeraFila);

        if (primeraLinea != NULL) {
            for (int i = 0; i < cantidad; i++) {
                if (primeraLinea != NULL) {
                    deleteFirstChar(primeraLinea);
                    if (isEmptyLine(primeraLinea)) {
                        // Si la línea está vacía, eliminarla de la fila
                        deleteFirstRow(primeraFila);
                    }
                } else {
                    // No quedan más caracteres en la línea actual
                    // Moverse a la siguiente línea si está disponible
                    primeraFila = nextRow(primeraFila);
                    if (primeraFila != NULL) {
                        primeraLinea = headRow(primeraFila);
                    }
                }
            }
        }
    }
}

//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: le setea el permiso de escritura al archivo de nombre nombreArchivo
void setFilePermission(TDirectorio& directorio, Cadena nombreArchivo, bool permisoEscritura) {
    // Buscar el archivo por nombre en el directorio
    TArchivo archivo = getFileDirectory(directorio, nombreArchivo);

    if (archivo != NULL) {
        // Establecer el nuevo valor de permiso de escritura
        archivo->escritura = permisoEscritura;
    }
}


//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: imprime el contenido del archivo "nombreArchivo"
void printFile(TDirectorio& directorio, Cadena nombreArchivo) {
    // Buscar el archivo por nombre en el directorio
    TArchivo archivo = getFileDirectory(directorio, nombreArchivo);

    TFila filaActual = firstRowFile (archivo);
    while (filaActual != NULL) {
        TLinea lineaActual = headRow(filaActual);
        while (lineaActual != NULL) {
            printf("%c", firstCharLine(lineaActual));
            lineaActual = nextLine(lineaActual);
        }
        filaActual = nextRow(filaActual);
    }

    printf("\n"); // Agregar una nueva línea después de imprimir el contenido
}

//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: elimina el archivo del directorio "directorio" y toda la memoria utilizada por este.
void deleteFileDirectory(TDirectorio& directorio, Cadena nombreArchivo)
{

}