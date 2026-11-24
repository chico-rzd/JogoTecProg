#include "Dia.h"

namespace Fases
{
    Dia::Dia() : Fase(), maxInimMedios(5), pCachorro(NULL), pPoca(NULL)
    {
        inicializar();      
        criarInimigos();
        criarObstaculo();
    }

    Dia::~Dia() {}

    void Dia::criarInimigos()
    {
        criarInimMedios();
    }

    void Dia::criarObstaculo()
    {
        criarObstMedios();
    }

    void Dia::criarInimMedios() 
    {   
        pCachorro = new Entidades::Personagens::Cachorro(900.0f, 500.0f, 500.0f, 900.0f, 180.0f, 1, 2);
        lista_ents->incluir(pCachorro);
        GC->incluirInimigo(pCachorro);
    }

    void Dia::criarObstMedios() 
    {
        pPoca = new Obstaculos::Poça(300.0f, 370.0f, 0);
        lista_ents->incluir(pPoca);
        GC->incluirObstaculo(pPoca);

    }   
}