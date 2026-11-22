#include "Roseira.h"

namespace Obstaculos {

    Roseira::Roseira(float x_, float y_, float elast) : Obstaculo(x_, y_), elasticidade(elast) {
        criaElementos(100.0f, 150.0f, sf::Color::Green);
    } 
    Roseira::Roseira(float elast) : Obstaculo(), elasticidade(elast) {
        criaElementos(100.0f, 150.0f, sf::Color::Cyan);
    } 
    Roseira::~Roseira() {}

    float Roseira::getElasticidade() const{
        return elasticidade;
    }
    void Roseira::setElasticidade(float elastico) {
        elasticidade = elastico;
    }

    void Roseira::executar(){}
    void Roseira::obstaculizar(Entidades::Personagens::Jogador* pJogador) {}
    void Roseira::salvar() {}
}