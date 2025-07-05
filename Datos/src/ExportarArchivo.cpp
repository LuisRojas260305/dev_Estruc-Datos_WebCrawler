#include "../include/ExportarArchivo.h"

void ExportarArchivo::exportar(NodoArbol *raiz, std::string nombre)
{
    std::ofstream archivo(nombre);

    if (!archivo.is_open())
    {
        throw std::runtime_error("No se pudo abrir el archivo");
    }

    std::stack<std::pair<NodoArbol *, int>> pila;
    pila.push({raiz, 0});

    while (!pila.empty())
    {
        auto [nodo, nivel] = pila.top();
        pila.pop();

        // Indetacion segun nivel de profundidad
        for (int i = 0; i < nivel; i++)
            archivo << " ";
        archivo << "- " << nodo->getUrl();

        if (nodo->getIsBroken())
            archivo << " [BROKEN]";
        else if (nodo->getIsExternal())
            archivo << " [EXTERNAL]";
        archivo << "\n";

        // Insertar hijos en orden inverso
        auto hijos = nodo->getNodos();
        for (auto it = hijos.rbegin(); it != hijos.rend(); ++it)
        {
            pila.push({*it, nivel + 1});
        }
    }
    archivo.close();
}