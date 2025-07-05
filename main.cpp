#include "Presentacion/include/ConsolaUi.h"
#include "Negocios/include/WebCrawler.h"
#include <iostream>
#include <vector>
#include <string>

// --- CONFIGURACIÓN DE PRUEBAS ---
// Cambiar a 1 para ejecutar el conjunto de pruebas en lugar del modo interactivo.
// Cambiar a 0 para ejecutar el programa normalmente.
#define EJECUTAR_PRUEBAS 0

// Estructura para definir un caso de prueba
struct CasoDePrueba {
    std::string nombre;
    std::string url;
    int profundidad;
    std::string palabraClave;
    int profundidadEsperada;
};

// Función que contiene y ejecuta todos los casos de prueba
void ejecutarPruebas() {
    std::cout << "--- INICIANDO CONJUNTO DE PRUEBAS ---" << std::endl;

    std::vector<CasoDePrueba> pruebas = {
        {"Palabra clave en la raiz", "https://www.wikipedia.org/", 0, "Wikipedia", 0},
        {"Palabra clave en profundidad 1 (fsf.org)", "https://www.fsf.org/", 1, "licensing", 0},
        {"Palabra clave no encontrada", "https://www.gnu.org/", 2, "Microsoft", -1},
        {"Palabra clave fuera de la profundidad maxima", "https://www.w3.org/", 1, "Perceivable", -1},
        {"Palabra clave 'copyleft' en fsf.org", "https://www.fsf.org/", 1, "copyleft", -1}
    };

    int pruebasPasadas = 0;
    for (size_t i = 0; i < pruebas.size(); ++i) {
        const auto& p = pruebas[i];
        std::cout << "\n--- Ejecutando Prueba " << i + 1 << ": " << p.nombre << " ---" << std::endl;
        std::cout << "URL: " << p.url << ", Profundidad: " << p.profundidad << ", Palabra: '" << p.palabraClave << "'" << std::endl;

        WebCrawler crawler(p.url, p.profundidad);
        crawler.Explorar();
        int profundidadReal = crawler.PalabraClave(p.palabraClave);

        if (profundidadReal == p.profundidadEsperada) {
            std::cout << "-> EXITO. Resultado: " << profundidadReal << " (Esperado: " << p.profundidadEsperada << ")" << std::endl;
            pruebasPasadas++;
        } else {
            std::cout << "-> FALLO. Resultado: " << profundidadReal << " (Esperado: " << p.profundidadEsperada << ")" << std::endl;
        }
    }

    std::cout << "\n--- RESUMEN DE PRUEBAS ---" << std::endl;
    std::cout << "Pruebas pasadas: " << pruebasPasadas << " de " << pruebas.size() << std::endl;
}

int main() {
#if EJECUTAR_PRUEBAS
    ejecutarPruebas();
#else
    ConsolaUi ui;
    ui.start();
#endif
    return 0;
}