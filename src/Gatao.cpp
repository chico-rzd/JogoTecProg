#include "Gatao.h"
#include <SFML/Graphics.hpp>

namespace Personagens {

Personagens::Gatao::Gatao(float posX, float posY, float limE, float limD, sf::Color cor)
    : forca(5), vel(100.0f), limt_esq(limE), limt_dir(limD)
{
    pFigura = new sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
    pFigura->setFillColor(cor);
    x = posX;
    y = posY;
    atualizarFigura();
}

Personagens::Gatao::~Gatao()
{

}

void Personagens::Gatao::danificar(Entidades::Jogador* p) //Objetivo: tirar 2 pontos do jogador
{

}

void Personagens::Gatao::mover() // Objetivo: perseguir o jogador
{

}

void Personagens::Gatao::executar()
{
    mover();
}

void Personagens::Gatao::salvar()
{

}
}