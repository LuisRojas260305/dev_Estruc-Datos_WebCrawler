#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H

#include <string>
#include <vector>

class NodoArbol
{
public:
    /* Constructor y desturctor */
    NodoArbol(std::string url, int profundidad);

    /* Metodos */
    void insertar(NodoArbol *nuevo);

    /* Getters y Setters */

    // Getters
    std::string getUrl();
    int getProfundidad();
    bool getIsExternal();
    bool getIsBroken();
    std::string getContenido();
    std::vector<NodoArbol *> getNodos();

    // Setters
    void setIsExternal(bool external);
    void setIsBroken(bool broken);
    void setContent(std::string content);

private:
    /* Atributos */
    std::string Url;
    int Profundidad;
    bool isExternal;
    bool isBroken;
    std::string contenido;
    std::vector<NodoArbol *> Hijos;
};

#endif // NODO_ARBOL_H