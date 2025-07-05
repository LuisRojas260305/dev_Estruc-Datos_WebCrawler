#include "../include/WebCrawler.h"

// Funcion para obtener dominio
std::string WebCrawler::getDominio(std::string url)
{
    size_t pos = url.find("://");
    if (pos == std::string::npos)
        return "";
    std::string dominio = url.substr(pos + 3);
    pos = dominio.find('/');
    return (pos != std::string::npos) ? dominio.substr(0, pos) : dominio;
}

WebCrawler::WebCrawler(std::string UrlRaiz, int profundidad) : raiz(new NodoArbol(UrlRaiz, 0)), Profundidad(profundidad)
{
    urlVisitada.insertar(UrlRaiz);
    url = getDominio(UrlRaiz);
}

WebCrawler::~WebCrawler()
{
    delete raiz;
}

void WebCrawler::Explorar()
{
    ExploracionRecursiva(raiz, 0);
}

NodoArbol *WebCrawler::ExploracionRecursiva(NodoArbol *nodo, int profundidad)
{
    if (profundidad > profundidad)
        return nodo;

    try
    {
        // Descargar contenido
        std::string html = Http_client::dowladUrl(nodo->getUrl());
        nodo->setContent(html);
        nodo->setIsBroken(false);

        // Extraer enlaces
        std::vector<std::string> links = Html_parser::extraerLinks(html, nodo->getUrl());

        for (std::string link : links)
        {
            if (urlVisitada.existe(link))
                continue;
            urlVisitada.insertar(link);

            NodoArbol *nuevo = new NodoArbol(link, profundidad + 1);

            // Verificar si es externo
            if (getDominio(link) != url)
            {
                nuevo->setIsExternal(true);
            }

            nodo->insertar(nuevo);

            // Explorar solo si es interno y no supera profundidad
            if (!nuevo->getIsExternal() && (profundidad + 1) <= profundidad)
            {
                ExploracionRecursiva(nuevo, profundidad + 1);
            }
        }
    }
    catch (...)
    {
        nodo->setIsBroken(true);
    }
    return nodo;
}

Estadisticas WebCrawler::getStats()
{
    Estadisticas stats;
    std::queue<NodoArbol *> cola;
    cola.push(raiz);

    while (!cola.empty())
    {
        NodoArbol *actual = cola.front();
        cola.pop();

        stats.IncrementarTotal();
        if (actual->getIsExternal())
            stats.IncrementarExternos();
        else
            stats.IncrementarInternos();
        stats.setProfundidadMax(actual->getProfundidad());

        for (NodoArbol *hijo : actual->getNodos())
        {
            cola.push(hijo);
        }
    }
    return stats;
}

int WebCrawler::PalabraClave(std::string Palabra)
{
    std::queue<NodoArbol *> cola;
    cola.push(raiz);

    while (!cola.empty())
    {
        NodoArbol *actual = cola.front();
        cola.pop();

        if (actual->getContenido().find(Palabra) != std::string::npos)
        {
            return actual->getProfundidad();
        }

        for (NodoArbol *hijo : actual->getNodos())
        {
            cola.push(hijo);
        }
    }
    return -1; // No encontrado
}

std::vector<std::string> WebCrawler::getBrokenLinks()
{
    std::vector<std::string> broken;
    std::queue<NodoArbol *> cola;
    cola.push(raiz);

    while (!cola.empty())
    {
        NodoArbol *actual = cola.front();
        cola.pop();

        if (actual->getIsBroken())
        {
            broken.push_back(actual->getUrl());
        }

        for (NodoArbol *hijo : actual->getNodos())
        {
            cola.push(hijo);
        }
    }
    return broken;
}

void WebCrawler::exportTree(std::string nombre)
{
    ExportarArchivo::exportar(raiz, nombre);
}