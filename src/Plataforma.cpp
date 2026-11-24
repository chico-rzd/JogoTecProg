#include "Plataforma.h"
#include "Jogador.h"
#include <SFML/Graphics.hpp>

namespace Obstaculos {

    Plataforma::Plataforma() : Obstaculo() {
        criaElementos(100.0f, 100.0f, sf::Color::Black);
    }
    Plataforma::Plataforma(float x_, float y_) : Obstaculo(x_, y_) {
        criaElementos(100.0f, 100.0f, sf::Color::Black);
    }
    
    Plataforma::~Plataforma(){}

    void Plataforma::obstaculizar(Entidades::Personagens::Jogador* pJogador) 
    {
        if(pJogador == NULL)
            return;
        
    }

    void Plataforma::executar(){}

    void Plataforma::salvar(){}


}