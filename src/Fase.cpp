#include "Fase.h"

namespace Fases
{
    Fase::Fase()
        : Ente(), lista_ents(NULL), GC(NULL), pRato(NULL), pPlataforma(NULL)
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
        lista_ents->executar();       
        GC->executar();        
        desenhar(); //Desenha cenario                      
        lista_ents->desenharEntidades(); 
    }        

    void Fase::criarInimFaceis()
    {
        pRato = new Entidades::Personagens::Rato(600.0f, 300.0f, 30.0f, 50.0f, 200.0f, 1, 1);
        
        lista_ents->incluir(pRato);
        GC->incluirInimigo(pRato);
        
    }
    
    void Fase::criarPlataformas()
    {
        pPlataforma = new Obstaculos::Plataforma(500.0f,400.0f);

        lista_ents->incluir(pPlataforma);
        GC->incluirObstaculo(pPlataforma);
    }
    
    void Fase::criarCenario()
    {
        
        carregaImagem("assets/cenario.png");
        
        pFigura->setSize(sf::Vector2f(1280.0f,700.0f));
        pFigura->setPosition(0.f, 0.f);
        
    }
    void Fase::incluirJogador(Entidades::Personagens::Jogador* pJogador){
        lista_ents->incluir(pJogador);
        GC->incluirJogador(pJogador);
    }
    
} 


