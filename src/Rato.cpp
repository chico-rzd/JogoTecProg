#include <SFML\Graphics.hpp>
#include "Rato.h"

namespace Personagens {

Personagens::Rato::Rato(float posX, float posY, int limE, int limD, sf::Color cor)
 : raio(0), limt_esq(limE), limt_dir(limD), vel(100.0f)
{
    pFigura = new sf::RectangleShape(sf::Vector2f(20.f,20.f));
    pFigura->setFillColor(cor);
    x = posX;
    y - posY;
    atualizarFigura();

}

Personagens::Rato::~Rato()
{

}

void Personagens::Rato::danificar(Entidades::Jogador* p) //Objetivo: tirar 1/2 ponto do jogador
{

}

void Personagens::Rato::mover() // Objetivo: ficar em cima da plataforma telhado
{

    if(x <= limt_esq){
        x -= vel;
    }
    if(x >= limt_dir)
    {
        x+= vel;
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