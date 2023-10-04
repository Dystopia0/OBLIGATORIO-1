/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/linea.h"
#include "../include/fila.h"
#include "../include/directorio.h"
#include "../include/archivo.h"
#include "string.h"
#include "stdio.h"

struct nodoArchivo{
    TArchivo archivo;
    nodoArchivo* sig;
};
typedef nodoArchivo *ListaArchivos;

struct _rep_directorio {
   Cadena nombre;
   _rep_directorio* raiz;
   _rep_directorio* sig;
   _rep_directorio* ant; 
   ListaArchivos archivos;
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
    
    ListaArchivos aux=directorio->archivos;
    while (aux != NULL) {
        if (strcmp(getFileName(aux->archivo), nombreArchivo) == 0) {
            return true;
        }
        aux = aux->sig;
    }
    return false;
}


TArchivo getFileDirectory(TDirectorio directorio, Cadena nombreArchivo) {
    ListaArchivos aux=directorio->archivos;
    while (aux != NULL) {
        if (strcmp(getFileName(aux->archivo), nombreArchivo) == 0) {
            return aux->archivo;
        }
        aux = aux->sig;
    }
    return NULL;
   
}

void separarExtension(const char* entrada, char* nombre, char* extension) {
    int i = strlen(entrada) - 1;
    // Buscar el punto desde el final de la cadena
    while (i >= 0 && entrada[i] != '.') {
        i--;
    }

    if (i >= 0) {
        // Copiar la extensión
        int j = 0;
        while (entrada[i] != '\0' && j <= 3) {
            extension[j] = entrada[i];
            i++;
            j++;
        }
        extension[j] = '\0'; 

        // Copiar el nombre del archivo
       for (int k = 0; k < i; k++) {
            nombre[k] = entrada[k];
        }
        nombre[i] = '\0'; 
    } else {

        strcpy(nombre, entrada);
        extension[0] = '\0'; // La extensión está vacía
    }
}

//setExtension
//pre-condicion: No existe en directorio un archivo de nombre "nombreArchivo"
//crea un archivo vacio con nombre nombreArchivo y permiso de lectura/escritura
void createFileInDirectory(TDirectorio& directorio, Cadena nombreArchivo) {
    Cadena extension;
    Cadena nombre;
    bool pe = true;

    separarExtension(nombreArchivo, nombre, extension);
   
    TArchivo archivo = createEmptyFile (nombre, extension);
    nodoArchivo* nuevo=new nodoArchivo;
    nuevo->archivo=archivo;
    nuevo->sig=directorio->archivos;
    directorio->archivos=nuevo;
         
    
}


//pre condicion: el archivo nombreArchivo existe en directorio
//pos-condicion: inserta una nueva fila al comienzo del archivo nombreArchivo conteniendo los chars texto
void insertTextFile(TDirectorio& directorio, Cadena nombreArchivo, Cadena texto){
    
    ListaArchivos aux = directorio->archivos;
    while(aux!=NULL && getFileName(aux->archivo)!=nombreArchivo)
    {
        aux=aux->sig;
    }
        insertRow ( firstRowFile( aux->archivo)); //DUDA
        modifyRow (aux->archivo, texto);
    
}


//pre condicion: el archivo nombreArchivo existe en directorio
//pos-condicion: agrega al comienzo de la primera fila del archivo de nombre nombreArchivo los caracteres de texto
//desplazando los caracteres existentes hacia la derecha
void insertCharsFileFirstLine(TDirectorio& directorio, Cadena nombreArchivo, Cadena texto){
    ListaArchivos aux = directorio->archivos;
    while(aux!=NULL && getFileName(aux->archivo)!=nombreArchivo)
    {
        aux=aux->sig;
    }
    insertChartsNewRow(aux->archivo, texto);


}

//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: elimina el archivo del directorio "directorio" y toda la memoria utilizada por este.
void deleteFileDirectory(TDirectorio& directorio, Cadena nombreArchivo) {
    ListaArchivos aux = directorio->archivos;
    while(aux!=NULL && getFileName(aux->archivo)!=nombreArchivo)
    {
        aux=aux->sig;
    }
    if(aux!=NULL)
    {
        destroyFile(aux->archivo); 
    }
} 

//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: elimina los "cantidad" caracteres iniciales del archivo nombreArchivo //DUDA
void deleteCharsFile(TDirectorio& directorio, Cadena nombreArchivo, int cantidad){
    ListaArchivos aux = directorio->archivos;
        while(aux!=NULL && getFileName(aux->archivo)!=nombreArchivo)
    {
        aux=aux->sig;
    }
    if(aux!=NULL)
    {
         
    }
}

//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: le setea el permiso de escritura al archivo de nombre nombreArchivo
void setFilePermission(TDirectorio& directorio, Cadena nombreArchivo, bool permisoEscritura){
    ListaArchivos aux = directorio->archivos;
    bool escritura = true;
    while(aux!=NULL && getFileName(aux->archivo)!=nombreArchivo)
    {
        aux=aux->sig;
    }

     setWritePermission(aux->archivo, escritura);
}


//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio" //DUDA
//pos-condicion: imprime el contenido del archivo "nombreArchivo"
void printFile(TDirectorio& directorio, Cadena nombreArchivo){
    ListaArchivos aux = directorio->archivos;
    while(aux!=NULL && getFileName(aux->archivo)!=nombreArchivo)
    {
        aux=aux->sig;
    }

}

void destroyDirectory (TDirectorio& directorio){
    ListaArchivos aux = directorio->archivos;
    while(aux!=NULL) //borro todos los archivos de directorio
    {
        ListaArchivos elim = aux;
        aux=aux->sig;
        destroyFile(elim->archivo);
    }

    delete directorio;

}


