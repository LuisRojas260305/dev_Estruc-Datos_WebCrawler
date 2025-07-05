#ifndef WEB_CRAWLER_H
#define WEB_CRAWLER_H

#include "NodoArbol.h"
#include "TablaHash.h"
#include "Estadisticas.h"
#include "Html_parser.h"
#include "../../Datos/include/Http_client.h"
#include "../../Datos/include/ExportarArchivo.h"

#include <string>
#include <queue>
#include <algorithm>

class WebCrawler
{
public:
    /* Constructor y destructor */
    WebCrawler(std::string rootUrl, int deep);
    ~WebCrawler();

    /* Metodos */
    void Explorar();
    Estadisticas getStats();
    int PalabraClave(std::string Palabra);
    std::vector<std::string> getBrokenLinks();
    void exportTree(std::string nombre);

    std::string getDominio(std::string url);

private:
    /* Atributos */
    NodoArbol *raiz;
    int Profundidad;
    std::string url;
    TablaHash urlVisitada;

    /* Metodos */
    NodoArbol *ExploracionRecursiva(NodoArbol *nodo, int profundidad);
    std::vector<std::string> ExtraerLinks(std::string html, std::string url);
    std::string descargarUrl(std::string url);
};

#endif // WEB_CRAWLER_H