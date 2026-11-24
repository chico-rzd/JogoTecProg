#include "Rua.h"
#include "Jogador.h"
#include <SFML/Graphics.hpp>

namespace Obstaculos {

    Rua::Rua() : Obstaculo() {
        criaElementos(200.0f, 100.0f, sf::Color::Black);
    }
    Rua::Rua(float x_, float y_) : Obstaculo(x_, y_) {
        criaElementos(1000.0f, 50.0f, sf::Color::Black);
    }
    
    Rua::~Rua(){}

    void Rua::obstaculizar(Entidades::Personagens::Jogador* pJogador) 
    {
        if(pJogador == NULL)
            return;
        
    }

    void Rua::executar(){}

    void Rua::salvar(){}


}