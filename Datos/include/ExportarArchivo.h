#ifndef EXPORTAR_ARCHIVO_H
#define EXPORTAR_ARCHIVO_H

#include "../../Negocios/include/NodoArbol.h"

#include <string>
#include <fstream>
#include <stack>
#include <utility>

class ExportarArchivo
{
public:
    static void exportar(NodoArbol *raiz, std::string nombre);
};

#endif // EXPORTAR_ARCHIVO_H