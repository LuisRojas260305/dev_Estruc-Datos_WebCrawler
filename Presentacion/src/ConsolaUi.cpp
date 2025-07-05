#include "../include/ConsolaUi.h"

ConsolaUi::ConsolaUi() : crawler(nullptr) {}

ConsolaUi::~ConsolaUi()
{
    delete crawler;
}

void ConsolaUi::start()
{
    UrlyProfundidad();
    MostrarMenu();
}

void ConsolaUi::MostrarMenu()
{
    int opcion;

    do
    {
        limpiarConsola();

        std::cout << std::string(50, '=') << std::endl;
        std::cout << "================  Menu princial  ================" << std::endl;
        std::cout << std::string(50, '=') << std::endl;

        std::cout << std::string(50, '=') << std::endl;
        std::cout << std::string(50, '-') << std::endl;
        std::cout << "1.- Mostrar estadisticas." << std::endl;
        std::cout << "2.- Buscar palabra clave." << std::endl;
        std::cout << "3.- Exportar arbol." << std::endl;
        std::cout << "4.- Salir." << std::endl;
        std::cout << std::string(50, '-') << std::endl;
        std::cout << "Seleccion: " << std::endl;

        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << std::string(50, '-') << std::endl;
        std::cout << std::string(50, '=') << std::endl;

        switch (opcion)
        {
        case 1:
            MostrarEstadisticas();
            break;
        case 2:
            BuscarPalabraClave();
            break;
        case 3:
            ExportarArbol();
            break;
        case 4:
            std::cout << std::string(50, '=') << std::endl;
            std::cout << "Saliendo..." << std::endl;
            std::cout << std::string(50, '=') << std::endl;
            break;
        default:
            std::cout << std::string(50, '=') << std::endl;
            std::cout << "Opcion invalida" << std::endl;
            std::cout << std::string(50, '=') << std::endl;
            pausarConsola();
        }

    } while (opcion != 4);
}

bool ConsolaUi::UrlValida(std::string url)
{
    const std::regex patron(
        R"(^(https?|ftp):\/\/)"                           // Protocolo
        R"(([a-zA-Z0-9-]+\.)+)"                           // Subdominios
        R"([a-zA-Z]{2,})"                                 // Dominio principal
        R"((:\d+)?)"                                      // Puerto opcional
        R"((\/[a-zA-Z0-9-._~:\/\?#\[\]@!$&'()*+,;%=]*)?)" // Ruta/query/fragmento
        R"($)"                                            // Fin de cadena
    );

    return std::regex_match(url, patron);
}

void ConsolaUi::UrlyProfundidad()
{
    std::string url;
    int profundidad;

    limpiarConsola();

    do
    {
        std::cout << std::string(50, '=') << std::endl;
        std::cout << std::string(50, '-') << std::endl;
        std::cout << "Ingrese la url inicial: " << std::endl;
        std::getline(std::cin, url);
        std::cout << std::string(50, '-') << std::endl;

        if (!UrlValida(url))
        {
            std::cout << std::string(50, '=') << std::endl;
            std::cout << std::string(50, '-') << std::endl;
            std::cout << "Url invalida" << std::endl;
            std::cout << std::string(50, '-') << std::endl;
        }
        else
        {
            break;
        }

    } while (true);

    std::cout << "Ingrese la profundidad maxima: " << std::endl;
    std::cin >> profundidad;
    std::cin.ignore();
    std::cout << std::string(50, '-') << std::endl;

    crawler = new WebCrawler(url, profundidad);
    crawler->Explorar();
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "Exploracion completada" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    pausarConsola();
}

void ConsolaUi::MostrarEstadisticas()
{
    Estadisticas stats = crawler->getStats();

    limpiarConsola();

    std::cout << std::string(50, '=') << std::endl;
    std::cout << "=================  Estadisticas  ================" << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    std::cout << std::string(50, '=') << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "Total de enlaces: " << stats.getTotalLinks() << std::endl;
    std::cout << "Internos: " << stats.getInternalLinks() << std::endl;
    std::cout << "Externos: " << stats.getExternalLinks() << std::endl;
    std::cout << "Profundidad maxima: " << stats.getProfundidadMax() << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    pausarConsola();
}

void ConsolaUi::BuscarPalabraClave()
{
    limpiarConsola();

    std::string palabra;
    std::cout << std::string(50, '=') << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "Ingrese la palabra clave: ";
    std::getline(std::cin, palabra);
    std::cout << std::string(50, '-') << std::endl;

    int profundidad = crawler->PalabraClave(palabra);

    if (profundidad != -1)
    {
        std::cout << "Encontado en la profundidad: " << profundidad << std::endl;
        std::cout << std::string(50, '-') << std::endl;
        std::cout << std::string(50, '=') << std::endl;
    }
    else
    {
        std::cout << "Palabra no encontrada" << std::endl;
        std::cout << std::string(50, '-') << std::endl;
        std::cout << std::string(50, '=') << std::endl;
    }

    pausarConsola();
}

#include <cstdlib>

void ConsolaUi::ExportarArbol()
{
    crawler->exportTree("Busqueda.txt");

    limpiarConsola();

    std::cout << std::string(50, '=') << std::endl;
    std::cout << "Arbol exportado." << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    pausarConsola();
}

void ConsolaUi::limpiarConsola()
{
#ifdef _WIN32
    system("cls");
#elif __APPLE__
    system("clear");
#elif __linux__
    system("clear");
#endif
}

void ConsolaUi::pausarConsola()
{
#ifdef _WIN32
    system("pause");
#else
    std::cout << "Presione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
}