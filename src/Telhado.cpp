#include "Telhado.h"

namespace Obstaculos {

    Telhado::Telhado(float x_, float y_, float elast) : Obstaculo(x_, y_), elasticidade(elast) {
        criaElementos(100.0f, 150.0f, sf::Color::Green);
    } 
    Telhado::Telhado(float elast) : Obstaculo(), elasticidade(elast) {
        criaElementos(100.0f, 150.0f, sf::Color::Cyan);
    } 
    Telhado::~Telhado() {}

    float Telhado::getElasticidade() const{
        return elasticidade;
    }
    void Telhado::setElasticidade(float elastico) {
        elasticidade = elastico;
    }

    void Telhado::executar(){}
    void Telhado::obstaculizar(Entidades::Jogador* pJogador) {}
    void Telhado::salvar() {}
}