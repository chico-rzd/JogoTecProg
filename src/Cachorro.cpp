#include "Cachorro.h"
#include "Gerenciador_Grafico.h"

namespace Entidades {

Personagens::Cachorro::Cachorro(float posX, float posY, float limE, float limD, float vel, int dirc,int n_mal)
    : Inimigo(posX, posY, limE, limD, vel, dirc, n_mal), pJogador(NULL)
{
    carregaImagem("assets/cachorro.png");

    if(pFigura)
        pFigura->setSize(sf::Vector2f(150.0f, 150.0f));

    atualizarFigura();

}

Personagens::Cachorro::~Cachorro()
{

}

void Personagens::Cachorro::danificar(Personagens::Jogador* p) // Objetivo: tirar um dois pontos do Jogador
{
    if(p == NULL){
        return;
    }
    
    p->setVidas(p->getVidas() - 2);
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

void Personagens::Cachorro::executar()
{
    mover();
}

void Personagens::Cachorro::salvar()
{

}

}