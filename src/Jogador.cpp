#include "Jogador.h"
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "enum.h"
#include "Ente.h"

namespace Entidades {

    Personagens::Jogador::Jogador() : Personagem(), pontos(0), velocidade(2.0f), corJogador(Estilos::VERMELHO)
    {
        controles.cima      = Movimento::Tecla_W;
        controles.baixo     = Movimento::Tecla_S;
        controles.esquerda  = Movimento::Tecla_A;
        controles.direita   = Movimento::Tecla_D;

        criarFigura(Estilos::VERMELHO);
    }
    
    Personagens::Jogador::Jogador(float x_, float y_, Movimento::Controles control, Estilos::Cores corJog) : Personagem(x_, y_, 5), pontos(0), velocidade(2.0f), controles(control), corJogador(corJog)
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

        const char* arquivo = "assets/jogador2.png";

        switch (cor)
        {
        case Estilos::PRETO:
            arquivo = "assets/jogador1.png";
            break;
        case Estilos::VERMELHO:
            arquivo = "assets/jogador2.png";
            break;

        default:
            break;

        }

        carregaImagem(arquivo);

        if(pFigura)
        pFigura->setSize(sf::Vector2f(200.0f, 200.0f));
        
        atualizarFigura();

        if(pFigura)
            std::cout << "figura " << pFigura->getSize().x << "x" << pFigura->getSize().y
                << " pos " << pFigura->getPosition().x << "," << pFigura->getPosition().y << std::endl;
        else
            std::cout << "figura NULL" << std::endl;
    }

    int Personagens::Jogador::retornaIdJog(){
        return this->id;
    } //teste do id
}
