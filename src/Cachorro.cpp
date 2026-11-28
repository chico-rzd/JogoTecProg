#include "Cachorro.h"
#include "Gerenciador_Grafico.h"
#include <iostream>


namespace Entidades {

Personagens::Cachorro::Cachorro(float posX, float posY, float limE, float limD, float vel, int dirc,int n_mal = 2)
    : Inimigo(posX, posY, limE, limD, vel, dirc, n_mal), pJogador(NULL)
{
    carregaImagem("assets/cachorro.png");

    if(pFigura)
        pFigura->setSize(sf::Vector2f(120.0f, 120.0f));

    atualizarFigura();

}

Personagens::Cachorro::~Cachorro()
{

}

void Personagens::Cachorro::danificar(Personagens::Jogador* p) // A fazer: Objetivo: tirar dois pontos do Jogador
{
    if(p == NULL){
        return;
    }
    
    p->sofrerDano(nivel_maldade);

}

void Personagens::Cachorro::mover() //Objetivo: ficar em cima da plataforma rua
{
    x += velocidade * direcao * pGG->getDeltaTempo();

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

void Personagens::Cachorro::executar() // Fazer o cachorro pular
{
    mover();
}

void Personagens::Cachorro::salvar()
{

}

sf::FloatRect Personagens::Cachorro::getLimitesEntidade() const
{
    const float margemX = 0.15f;
    const float margemY = 0.20f;
    const float proporcaoLargura = 0.62f;
    const float proporcaoAltura = 0.40f;

    sf::FloatRect figura = Entidade::getLimitesEntidade();

    return sf::FloatRect(figura.left + margemX * figura.width,
                         figura.top + margemY * figura.height,
                         proporcaoLargura * figura.width,
                         proporcaoAltura * figura.height);
                         
}

}