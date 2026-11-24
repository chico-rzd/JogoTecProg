#include "Poça.h"

namespace Obstaculos {

    Poça::Poça(float x_, float y_, short int dano) : Obstaculo(x_, y_), danosidade(dano) 
    {
        danoso = true;
        criaElementos(100.0f, 10.0f, sf::Color::Blue);
    }
    Poça::Poça(short int dano) : Obstaculo(), danosidade(dano){
        criaElementos(100.0f, 10.0f, sf::Color::Blue);

    }
    Poça::~Poça() {};

    void Poça::salvarDataBuffer() {}
    void Poça::executar() {}    
    void Poça::obstaculizar(Entidades::Personagens::Jogador* pJogador) {}
    void Poça::salvar() {}

    short int Poça::getDanosidade() const {
        return danosidade;
    }

    void Poça::setDanosidade(short int dano){
        danosidade = dano;
    }
}