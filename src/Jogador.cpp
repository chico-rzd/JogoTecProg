#include "Jogador.h"
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "enum.h"

namespace Entidades {

    Personagens::Jogador::Jogador() : Personagem(), pontos(0), velocidade(2.0f), corJogador(Estilos::VERMELHO)
    {
        controles.cima      = Movimento::Tecla_W;
        controles.baixo     = Movimento::Tecla_S;
        controles.esquerda  = Movimento::Tecla_A;
        controles.direita   = Movimento::Tecla_D;

        criarFigura(Estilos::VERMELHO);
    }
    
    Personagens::Jogador::Jogador(float x_, float y_, Movimento::Controles control, Estilos::Cores corJog, int n_vidas) : Personagem(x_, y_, 5), pontos(0), velocidade(2.0f), controles(control), corJogador(corJog)
    {
        criarFigura(corJog);
    }
    
    Personagens::Jogador::~Jogador() {}
    

    void Personagens::Jogador::colidir(Inimigo* pInimigo){}

    void Personagens::Jogador::executar() 
    {
        mover();
    }

    void Personagens::Jogador::salvar() {}

    void Personagens::Jogador::mover() {

        if(pGG->teclaPressionada(controles.cima)) 
        {
            y -= velocidade;
        }
    
        if(pGG->teclaPressionada(controles.baixo)) 
        {
            y += velocidade;
        }
        if(pGG->teclaPressionada(controles.esquerda)) 
        {
            x -= velocidade;
        }
        if(pGG->teclaPressionada(controles.direita)) 
        {
            x += velocidade;
        }
    
        atualizarFigura();
    }

    void Personagens::Jogador::criarFigura(Estilos::Cores cor){
        pFigura = new sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
        switch (cor)
        {
        case Estilos::PRETO:
            pFigura->setFillColor(sf::Color::Black);
            break;
        case Estilos::VERMELHO:
            pFigura->setFillColor(sf::Color::Red);
            break;
        }
        atualizarFigura();
    }
    int Personagens::Jogador::retornaIdJog(){
        return this->id;
    } //teste do id
}
