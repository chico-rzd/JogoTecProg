#include "Fase.h"

namespace Fases
{
    Fase::Fase()
        : Ente(), lista_ents(NULL), GC(NULL), pRato(NULL), pRua(NULL)
    {
        lista_ents = new Listas::ListaEntidades();
        GC = new Gerenciadores::Gerenciador_Colisoes();
      
    }

    Fase::~Fase()
    {
        if(lista_ents){
            delete lista_ents;
            lista_ents = NULL;
        }

        if(GC){
            delete GC;
            GC = NULL;
        }
    }

    void Fase::inicializar()
    {
        criarCenario();
        criarInimFaceis();
        criarPlataformas();

    }

    void Fase::executar()
    {
        desenhar(); //Desenha cenario                      
        lista_ents->percorrer();               
        //GC->executar();  
    }        

    void Fase::criarInimFaceis()
    {
        pRato = new Entidades::Personagens::Rato(600.0f, 80.0f, 500.0f, 900.0f, 3.0f, 1, 1);
        
        lista_ents->incluir(pRato);
        GC->incluirInimigo(pRato);
 
    }

    void Fase::criarPlataformas()
    {
        pRua = new Obstaculos::Rua(210.0f,150.0f);

        lista_ents->incluir(pRua);
        GC->incluirObstaculo(pRua);
    }

    void Fase::criarCenario()
    {
        
        carregaImagem("assets/cenario.png");

        pFigura->setSize(sf::Vector2f(1280.0f,700.0f));
        pFigura->setPosition(0.f, 0.f);

    }
    
} 


