#include "Jogador.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Entidades {

    Jogador::Jogador() : Personagem(), pontos(0), velocidade(2.0f) {}
    
    Jogador::Jogador(float x_, float y_) : Personagem(x_, y_), pontos(0), velocidade(2.0f) 
    {
        pFigura = new sf::RectangleShape(sf::Vector2f(100.0f, 150.0f));
        pFigura->setFillColor(sf::Color::Black);
        atualizarFigura();
    }
    
    Jogador::~Jogador() {}

    void Jogador::colidir(Inimigo* pInimigo){}

    void Jogador::executar() {}
    void Jogador::salvar() {}

    void Jogador::mover() {
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            y -= velocidade;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            y += velocidade;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            x -= velocidade;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            x += velocidade;
        }
        atualizarFigura();
    }
}
