#include "../include/NodoArbol.h"

NodoArbol::NodoArbol(std::string url, int profundidad) : Url(url), Profundidad(profundidad), isExternal(false), isBroken(false) {}

void NodoArbol::insertar(NodoArbol *nuevo)
{
    Hijos.push_back(nuevo);
}

// Getters
std::string NodoArbol::getUrl() { return Url; }
int NodoArbol::getProfundidad() { return Profundidad; }
bool NodoArbol::getIsExternal() { return isExternal; }
bool NodoArbol::getIsBroken() { return isBroken; }
std::string NodoArbol::getContenido() { return contenido; }
std::vector<NodoArbol *> NodoArbol::getNodos() { return Hijos; }

// Setters
void NodoArbol::setIsExternal(bool external) { isExternal = external; }
void NodoArbol::setIsBroken(bool broken) { isBroken = broken; }
void NodoArbol::setContent(std::string content) { contenido = content; }