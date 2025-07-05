#include "../include/TablaHash.h"

TablaHash::TablaHash(int size) : Tamaño(size), tabla(size) {}

int TablaHash::hashFunction(std::string url)
{
    std::hash<std::string> hasher;
    return hasher(url) % Tamaño;
}

void TablaHash::insertar(std::string url)
{
    int index = hashFunction(url);

    for (const auto &var : tabla[index])
    {
        if (var == url)
            return; // la url ya existe
    }

    tabla[index].push_back(url);
}

bool TablaHash::existe(std::string url)
{
    int index = hashFunction(url);

    for (const auto &var : tabla[index])
    {
        if (var == url)
            return true;
    }

    return false;
}