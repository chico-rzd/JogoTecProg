#pragma once
#include "Cachorro.h"

namespace Personagens {

Personagens::Cachorro::Cachorro(float posX, float posY, float limE, float limD, sf::Color cor)
    : tamanho(3), vel(100.0f), limt_esq(limE), limt_dir(limD)
{
    pFigura = new sf::RectangleShape(sf::Vector2(70.0f, 70.0f));
    pFigura->setFillColor(cor);
    x = posX;
    y = posY;
    atualizarFigura();
}

Personagens::Cachorro::~Cachorro()
{

}

void Personagens::Cachorro::danificar(Entidades::Jogador* p) // Objetivo: tirar um ponto do Jogador
{

}

void Personagens::Cachorro::mover() //Objetivo: ficar em cima da plataforma rua
{
     if(x <= limt_esq){
        
        x -= vel;
    }
    if(x >= limt_dir)
    {
        x += vel;
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