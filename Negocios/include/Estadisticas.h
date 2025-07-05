#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

class Estadisticas
{
public:
    /* Constructor */
    Estadisticas();

    /* Getters y Setters */
    // Setters
    void IncrementarTotal();
    void IncrementarInternos();
    void IncrementarExternos();
    void setProfundidadMax(int profundidad);

    // Getters
    int getTotalLinks();
    int getInternalLinks();
    int getExternalLinks();
    int getProfundidadMax();

private:
    /* Atributos */
    int LinksTotales;
    int LinksInternos;
    int LinksExternos;
    int ProfundidadMax;
};

#endif // ESTADISTICAS_H