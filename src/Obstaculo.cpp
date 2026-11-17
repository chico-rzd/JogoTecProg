#include "Obstaculo.h"
#include <SFML/Graphics.hpp>

namespace Obstaculos {

    Obstaculo::Obstaculo(float x_, float y_, std::ostream* bff) : Entidade(x_, y_, bff), danoso(false), largura(0), altura(0) {}
    Obstaculo::Obstaculo() : Entidade(), danoso(false), largura(0), altura(0) {}

    Obstaculo::~Obstaculo() {
        danoso = false;
    }

    void Obstaculo::executar() {}
    void Obstaculo::salvar() {}
    
    void Obstaculo::obstaculizar(Entidades::Jogador* pJogador) {}
    void Obstaculo::salvarDataBuffer() {}

    void Obstaculo::criaElementos(float largura_, float altura_, sf::Color cor){
        if(pFigura) {
            return;
        }
        pFigura = new sf::RectangleShape(sf::Vector2f(largura_, altura_));
        pFigura->setFillColor(cor);
        largura = largura_;
        altura = altura_;
        atualizarFigura();

    }
}