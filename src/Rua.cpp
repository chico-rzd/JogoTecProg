#include "Rua.h"
#include "Jogador.h"
#include <SFML/Graphics.hpp>

namespace Obstaculos {

    Rua::Rua() : chao(NULL){
        criaRua();
    }
    Rua::Rua(float x_, float y_) : Obstaculo(x_, y_), chao(NULL){
        criaRua();
    }
    
    void Rua::criaRua(){
        pFigura = new sf::RectangleShape(sf::Vector2f(400.0f, 100.0f));
        pFigura->setFillColor(sf::Color::Red);
        atualizarFigura();
    }
    Rua::~Rua(){}

    void Rua::obstaculizar(Entidades::Jogador* pJogador) 
    {
        if(pJogador == NULL)
            return;
        
    }

    void Rua::executar(){}

    void Rua::salvar(){}


}