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


/*funções para a janela*/
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
// sf::RenderWindow Gerenciador_Grafico::getWindow(){
//     return *Window;
// }
}