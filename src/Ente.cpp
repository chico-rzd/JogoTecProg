#include "stdafx.h"
#include "Ente.h"
#include "Gerenciador_Grafico.h"

Gerenciadores::Gerenciador_Grafico* Entidades::Ente::pGG = NULL;

//incluir o contador estatico
namespace Entidades {
    
    int Ente::contador = 0;
    
    Ente::Ente() : id(contador++), pFigura(NULL) {}

    Ente::~Ente(){
        id = -1;
        if(pFigura){
            delete pFigura;
            pFigura = NULL;
        }
    }

    void Ente::carregaImagem(const char* imagem)
    {
        if(!pGG)
            return;

        sf::Texture& tex = pGG->carregarTextura(imagem);

        if(!pFigura){
            pFigura = new sf::RectangleShape();
        }

       pFigura->setSize(sf::Vector2f((float)tex.getSize().x, (float)tex.getSize().y));
       pFigura->setTexture(&tex, true);

    }

    sf::RectangleShape* Ente::getFigura() const{
        return pFigura;
    }

    void Ente::setGG(Gerenciadores::Gerenciador_Grafico* pG){
        pGG = pG;
    }

    void Ente::desenhar(){
        if(pGG){
            pGG->desenharEnte(this);
        }
    }

}