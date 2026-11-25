#include "Roseira.h"

namespace Obstaculos {

    Roseira::Roseira(float x_, float y_, float dano) : Obstaculo(x_, y_), danosidade(dano) {
        danoso = true;
        criaElementos(100.0f, 150.0f, "assets/roseira.png");
    } 
    Roseira::Roseira(float dano) : Obstaculo(), danosidade(dano) {
        danoso = true;
        criaElementos(100.0f, 150.0f, "assets/roseira.png");
    } 
    Roseira::~Roseira() {}

    float Roseira::getElasticidade() const{
        return danosidade;
    }
    void Roseira::setElasticidade(float dano) {
        danosidade = dano;
    }

    void Roseira::executar(){}
    void Roseira::obstaculizar(Entidades::Personagens::Jogador* pJogador) 
    {
        if(pJogador == NULL) return;
        pJogador->sofrerDano(1);
        std::cout << "vidas: " << pJogador->getVidas() << std::endl;
    }   
    void Roseira::salvar() {}
}