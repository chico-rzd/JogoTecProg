#include <SFML\Graphics.hpp>
#include "Rato.h"

namespace Entidades {

Personagens::Rato::Rato(float posX, float posY, float limE, float limD, float vel, int dirc, int n_mal)
 : Inimigo(posX, posY, limE, limD, vel, dirc, n_mal), 
   pJogador (NULL)
{

    carregaImagem("assets/rato.png");

    if(pFigura)
        pFigura->setSize(sf::Vector2f(150.0f, 150.0f));

    atualizarFigura();

}

Personagens::Rato::~Rato()
{

}

void Personagens::Rato::danificar(Personagens::Jogador* p) //Objetivo: tirar 1 ponto do jogador
{
    if(p == NULL){
        return;
    }
    
    p->setVidas(p->getVidas() - 1);

}

void Personagens::Rato::mover() // Objetivo: ficar em cima da plataforma 
{
    x += velocidade * direcao;

    if (x >= lim_direita)
    {
        x = lim_direita;
        direcao = -1;
    }
    else if (x <= lim_esquerda)
    {
        x = lim_esquerda;
        direcao = 1;
    }

    atualizarFigura();

}

void Personagens::Rato::executar()
{
    mover();
}

void Personagens::Rato::salvar()
{

}

}