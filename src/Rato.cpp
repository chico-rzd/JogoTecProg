#include <SFML\Graphics.hpp>
#include "Rato.h"

namespace Entidades {

Personagens::Rato::Rato(float posX, float posY, float limE, float limD, float vel, int dirc, int n_mal)
 : Inimigo(posX, posY, limE, limD, vel, dirc, n_mal), pJogador (nullptr)
{
   

}

Personagens::Rato::~Rato()
{

}

void Personagens::Rato::danificar(Personagens::Jogador* p) //Objetivo: tirar 1 ponto do jogador
{
    if(p == nullptr){
        return;
    }
    
    p->setVidas(p->getVidas() - 1);

}

void Personagens::Rato::mover(float dt) // Objetivo: ficar em cima da plataforma telhado
{
    x += velocidade * direcao * dt;

    if( x >= lim_direita)
    {
        x = lim_direita;
        direcao = -1;
    }
    else if ( x <= lim_esquerda)
    {
        x = lim_esquerda;
        direcao = 1;
    }

    atualizarFigura();

}

void Personagens::Rato::executar(float dt)
{
    mover(dt);
}

void Personagens::Rato::salvar()
{

}
}