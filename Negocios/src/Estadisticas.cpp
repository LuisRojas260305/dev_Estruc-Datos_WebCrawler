#include "../include/Estadisticas.h"

Estadisticas::Estadisticas() : LinksTotales(0), LinksInternos(0), LinksExternos(0), ProfundidadMax(0) {}

void Estadisticas::IncrementarTotal() { LinksTotales++; }
void Estadisticas::IncrementarInternos() { LinksInternos++; }
void Estadisticas::IncrementarExternos() { LinksExternos++; }

void Estadisticas::setProfundidadMax(int profundidad)
{
    if (profundidad > ProfundidadMax)
    {
        ProfundidadMax = profundidad;
    }
}

int Estadisticas::getTotalLinks() { return LinksTotales; }
int Estadisticas::getInternalLinks() { return LinksInternos; }
int Estadisticas::getExternalLinks() { return LinksExternos; }
int Estadisticas::getProfundidadMax() { return ProfundidadMax; }