#include "Entidade.h"
#include "SFML/Graphics.hpp"
#include "Gerenciador_Grafico.h"

namespace Entidades {

const float Entidade::gravidade = 1500.0f;

Entidade::Entidade() : x(0), y(0), naPlataforma(false), buffer(NULL), vetorVelocidade(0.0f, 0.0f) {}

Entidade::Entidade(float x_, float y_, std::ostream* buff) : Ente(), x(x_), y(y_), buffer(buff), naPlataforma(false), vetorVelocidade(0.0f, 0.0f)
{}

Entidade::~Entidade(){}

void Entidade::salvarDataBuffer() {}

void Entidade::setPosicaoX(float xP) {
    x = xP;
    atualizarFigura();
}
void Entidade::setPosicaoY(float yP) {
    y = yP;
    atualizarFigura(); //faz a figura acompanhar a posicao
}

float Entidade::getPosicaoX() const {
    return x;
}
float Entidade::getPosicaoY() const {
    return y;
}

void Entidade::atualizarFigura() {
    if(pFigura){
        pFigura->setPosition(x, y);
    }
}
void Entidade::integrarPosicao(){
    x += vetorVelocidade.x * pGG->getDeltaTime();
    y += vetorVelocidade.y * pGG->getDeltaTime();
}

void Entidade::aplicarFisica(){ /* equação horária da velocidade v(t) = v0 + a * t */
    vetorVelocidade.y += gravidade * pGG->getDeltaTime();
    naPlataforma = false;
}
sf::FloatRect Entidade::getLimitesEntidade() const {
    if(pFigura)
        return pFigura->getGlobalBounds();
    return sf::FloatRect(x, y, 0.0f, 0.0f);
}
}