#include "Gerenciador_Grafico.h"
#include "Ente.h"
#include "stdafx.h"

namespace Gerenciadores {

Gerenciador_Grafico::Gerenciador_Grafico() : Window(sf::VideoMode(1280, 700), "Cats Run")
{
    Window.setFramerateLimit(60);
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{}

void Gerenciador_Grafico::desenharEnte(Entidades::Ente* pE)
{ 
    if(pE){
        sf::RectangleShape* pF =  pE->getFigura();
        if(pF)
            Window.draw(*pF);
    }
}


/*funções para o tratamento da janela*/
bool Gerenciador_Grafico::JanelaAberta(){
    return Window.isOpen();
}

void Gerenciador_Grafico::trataEventos(){
    sf::Event event;
    
    while(Window.pollEvent(event))
    {
        switch (event.type){
            case sf::Event::Closed:
                Window.close();
                break;
            default:
            break;
        }
    }
}

void Gerenciador_Grafico::limparJanela(){
    Window.clear(sf::Color::White);
}

void Gerenciador_Grafico::mostrarConteudoJanela(){
     Window.display();
}

bool Gerenciador_Grafico::teclaPressionada(Movimento::Teclas t){

    switch (t)
    {
        
    case Movimento::Seta_cima:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    case Movimento::Seta_baixo:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    case Movimento::Seta_esquerda:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    case Movimento::Seta_direita:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

    case Movimento::Tecla_W:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    case Movimento::Tecla_S:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    case Movimento::Tecla_A:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    case Movimento::Tecla_D:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    
    default:
        return false;
    }
}
// sf::RenderWindow Gerenciador_Grafico::getWindow(){
//     return *Window;
// }
}