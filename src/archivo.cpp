/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/archivo.h"
#include "../include/linea.h"

enum Extension {
    exe,
    jpg,
    txt,
};

struct _rep_archivo {
    char *nombre;
    enum Extension exten;
    char *contenido;
    bool soloLectura;
};
typedef struct _rep_archivo *TArchivo;
    