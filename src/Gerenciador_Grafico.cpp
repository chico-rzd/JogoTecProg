#include "Gerenciador_Grafico.h"
#include "Ente.h"
#include "stdafx.h"

const float DT60FPS = 0.0167f;

namespace Gerenciadores {

Gerenciador_Grafico::Gerenciador_Grafico() : Window(sf::VideoMode(1280, 700), "Cats Run"), texturas(), deltaTempo(DT60FPS) 
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

sf::Texture& Gerenciador_Grafico::carregarTextura(const std::string& caminho)
{
    std::map<std::string, sf::Texture>::iterator it = texturas.find(caminho);
    
    if(it != texturas.end())
        return it->second;

    sf::Texture texturaNova;
    if(!texturaNova.loadFromFile(caminho))
        throw std::runtime_error("Erro ao carregar a textura: " + caminho);
    
    it = texturas.insert(std::make_pair(caminho, texturaNova)).first;
    return it->second;
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
    Window.clear(sf::Color(120, 120, 120));
    
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
void Gerenciador_Grafico::atualizaDeltaTempo(){
    deltaTempo = relogio.restart().asSeconds();
    if(deltaTempo > 0.05f) deltaTempo = 0.05f; // evita tunnelling
}

float Gerenciador_Grafico::getDeltaTempo() const {
    return deltaTempo;
}
// sf::RenderWindow Gerenciador_Grafico::getWindow(){
//     return *Window;
// }
}