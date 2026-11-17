#include "Poça.h"

namespace Obstaculos {

    Poça::Poça(float x_, float y_, short int dano) : Obstaculo(x_, y_), danosidade(dano) 
    {
        danoso = true;
        criaElementos(50.0f, 50.0f, sf::Color::Magenta);
    }
    Poça::Poça(short int dano) : Obstaculo(), danosidade(dano){
        criaElementos(50.0f, 50.0f, sf::Color::Magenta);

    }
    Poça::~Poça() {};

    void Poça::salvarDataBuffer() {}
    void Poça::executar() {}    
    void Poça::obstaculizar(Entidades::Jogador* pJogador) {}
    void Poça::salvar() {}

    short int Poça::getDanosidade() const {
        return danosidade;
    }

    void Poça::setDanosidade(short int dano){
        danosidade = dano;
    }
}