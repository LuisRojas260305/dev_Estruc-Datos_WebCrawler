#ifndef CONSOLA_UI_H
#define CONSOLA_UI_H

#include "../../Negocios/include/WebCrawler.h"
#include <string>
#include <iostream>
#include <limits>
#include <regex>

class ConsolaUi
{
public:
    /* Constructor y Destructor */
    ConsolaUi();
    ~ConsolaUi();

    /* Métodos publicos */
    void start();

private:
    /* Atributos privados */
    WebCrawler *crawler;

    /* Métodos privados */
    bool UrlValida(std::string url);
    void MostrarMenu();
    void LeerEntrada();
    void UrlyProfundidad();
    void MostrarEstadisticas();
    void BuscarPalabraClave();
    void ExportarArbol();
    void limpiarConsola();
    void pausarConsola();
};

#endif // CONSOLA_UI_H