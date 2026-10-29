#include "Gerenciador_Grafico.h"
#include "stdafx.h"

Gerenciador_Grafico::Gerenciador_Grafico() : Window(sf::VideoMode(1280, 700), "Cats Run")
{ 

}

Gerenciador_Grafico::~Gerenciador_Grafico()
{

}

void Gerenciador_Grafico::desenharEnte(Ente* pE)
{

}

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
    return Window.clear(sf::Color::Cyan);
}

void Gerenciador_Grafico::mostrarConteudoJanela(){
    return Window.display();
}
// sf::RenderWindow Gerenciador_Grafico::getWindow(){
//     return *Window;
// }

