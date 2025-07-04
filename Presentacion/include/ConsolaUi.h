#ifndef CONSOLA_UI_H
#define CONSOLA_UI_H

#include "../../Negocios/include/WebCrawler.h"
#include <string>

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
    void MostrarMenu();
    void LeerEntrada();
    void UrlyProfundidad();
    void MostrarEstadisticas();
    void BuscarPalabraClave();
    void ExportarArbol();
};

#endif // CONSOLA_UI_H