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

//setExtension
//pre-condicion: No existe en directorio un archivo de nombre "nombreArchivo"
//crea un archivo vacio con nombre nombreArchivo y permiso de lectura/escritura
void createFileInDirectory(TDirectorio& directorio, Cadena nombreArchivo) {
  Cadena extension;
  bool pe = true;

    int largo=strlen(nombreArchivo);
  Cadena cadena=new char[3];
  Cadena extension=new char[largo-3];
  int i=largo-1;
  int j=2;
    while (i>=0 && nombreArchivo[i]!='.' && j>=0 )
    {
        extension[j]=nombreArchivo[i];
        i--;
        j--;
    }
    extension[largo]='\0';
  if(nombreArchivo[i]=='.')
  {
    char* nombre;
    if(j>=0)
    {
        int l=3-j;
        int k=0;
        while(k<3)
        {
            extension[k]=extension[l+1];
            k++;
           l--;
        }
     extension[k]='\0';
     nombre=new char[strlen(nombreArchivo)-(k+1)];
    
     nombre[strlen(nombreArchivo)-k]='\0';
    
    }

 for(int z=0;z<strlen(nombreArchivo)-i;z++)
     {
        nombre[z]=nombreArchivo[z];
     }
    TArchivo archivo = createEmptyFile (nombre, extension);
    nodoArchivo* nuevo=new nodoArchivo;
    nuevo->archivo=archivo;
    nuevo->sig=directorio->archivos;
    directorio->archivos=nuevo;
   
    
    
    
}}


//pre condicion: el archivo nombreArchivo existe en directorio
//pos-condicion: inserta una nueva fila al comienzo del archivo nombreArchivo conteniendo los chars texto
void insertTextFile(TDirectorio& directorio, Cadena nombreArchivo, Cadena texto){
    
    ListaArchivos aux = directorio->archivos;
    while(aux!=NULL && getFileName(aux->archivo)!=nombreArchivo)
    {
        aux=aux->sig;
    }
    if(aux!=NULL)
    {

        insertRow ( firstRowFile( aux->archivo));
        modifyRow (aux->archivo, texto);
    }
}




