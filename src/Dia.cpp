#include "Dia.h"

namespace Fases
{
    Dia::Dia() : Fase(), maxInimMedios(5), pCachorro(NULL), pPoca(NULL)
    {
        inicializar();      
        criarInimigos();
        criarObstaculos();
    }

    Dia::~Dia() {}

    void Dia::criarInimigos()
    {
        criarInimMedios();
    }

    void Dia::criarObstaculos()
    {
        criarObstMedios();
    }

    void Dia::criarInimMedios() 
    {   
        pCachorro = new Entidades::Personagens::Cachorro(900.0f, 532.0f, 500.0f, 900.0f, 180.0f, 1, 2);
        lista_ents->incluir(pCachorro);
        GC->incluirInimigo(pCachorro);
    }

    void Dia::criarObstMedios() 
    {
        pPoca = new Obstaculos::Poça(600.0f, 344.0f, 0);
        lista_ents->incluir(pPoca);
        GC->incluirObstaculo(pPoca);

    }   
}