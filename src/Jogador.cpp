#include "Jogador.h"
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "enum.h"
#include "Ente.h"

namespace Entidades {

Personagens::Jogador::Jogador() : Personagem(), pontos(0), velocidade(250.0f),  corJogador(Estilos::VERMELHO)
{
    controles.cima      = Movimento::Tecla_W;
    controles.baixo     = Movimento::Tecla_S;
    controles.esquerda  = Movimento::Tecla_A;
    controles.direita   = Movimento::Tecla_D;

    criarFigura(Estilos::VERMELHO);
}

Personagens::Jogador::Jogador(float x_, float y_, Movimento::Controles control, Estilos::Cores corJog) : Personagem(x_, y_, 5), pontos(0), velocidade(250.0f), controles(control), corJogador(corJog)
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

    vetorVelocidade.x = 0.0f; //zera a cada quadro para não andar infinitamente
    
    lerEntradas();
    tentarPular();
    aplicarFisica(); 
    integrarPosicao();
    
    if(y > 450.0f) { // REMOVER DEPOIS DE TER A PLATAFORMA FEITA
        y = 450.0f;
        vetorVelocidade.y = 0.0f;
        naPlataforma = true;
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
}

/* função que altera a velocidade do jogador em suas posições x e y */
void Personagens::Jogador::lerEntradas(){

    if(pGG->teclaPressionada(controles.esquerda)) 
    {
        vetorVelocidade.x = -velocidade;        
    }
    if(pGG->teclaPressionada(controles.direita)) 
    {
        vetorVelocidade.x = velocidade;
    }
    
}
/* Ação de pulo do jogador separado das demais ações*/
void Personagens::Jogador::tentarPular(){
    if(pGG->teclaPressionada(controles.cima) && naPlataforma) 
    {
        vetorVelocidade.y = -800.0f;
        naPlataforma = false;
    }
}

int Personagens::Jogador::retornaIdJog(){
    return this->id;
} //teste do id
}
