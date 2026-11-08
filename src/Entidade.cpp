#include "Entidade.h"
#include "SFML/Graphics.hpp"

namespace Entidades {

    Entidade::Entidade() : x(0), y(0), buffer(NULL) {}
    
    Entidade::Entidade(float x_, float y_, std::ostream* buff) : Ente(), x(x_), y(y_), buffer(buff)
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
}