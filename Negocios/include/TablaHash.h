#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <vector>
#include <string>
#include <list>
#include <functional>

class TablaHash
{
public:
    /* Constructor y destructuor */
    TablaHash(int size = 1000);

    /* Metodos */
    void insertar(std::string url);
    bool existe(std::string url);

private:
    /* Atributos */
    std::vector<std::list<std::string>> tabla;
    int Tamaño;

    /* Metodos */
    int hashFunction(std::string url);
};

#endif // TABLA_HASH_H