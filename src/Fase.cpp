#include "Fase.h"

namespace Fases
{
    Fase::Fase()
        : Ente(), lista_ents(NULL), GC(NULL), pRato(NULL)
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
        desenhar();
        lista_ents->desenharEntidades();
    }

    void Fase::criarInimFaceis()
    {
        pRato = new Entidades::Personagens::Rato(600.0f, 80.0f, 500.0f, 900.0f, 180.0f, 1, 1);

        lista_ents->incluir(pRato);
        GC->incluirInimigo(pRato);
    }

    void Fase::criarPlataformas()
    {
        incluirPlataforma(0.0f, 652.0f, 1288.0f, 48.0f);
        incluirPlataforma(250.0f, 480.0f, 276.0f, 48.0f);
        incluirPlataforma(715.0f, 480.0f, 276.0f, 48.0f);
    }

    void Fase::incluirPlataforma(float x, float y, float largura, float altura)
    {
        Obstaculos::Plataforma* pPlat = new Obstaculos::Plataforma(x, y, largura, altura);

        lista_ents->incluir(pPlat);
        GC->incluirObstaculo(pPlat);
    }

    void Fase::criarCenario()
    {
        carregaImagem("assets/cenario.png");

        pFigura->setSize(sf::Vector2f(1280.0f, 700.0f));
        pFigura->setPosition(0.f, 0.f);
    }

    void Fase::incluirJogador(Entidades::Personagens::Jogador* pJogador)
    {
        lista_ents->incluir(pJogador);
        GC->incluirJogador(pJogador);
    }
}