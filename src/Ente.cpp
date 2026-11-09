#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include "stdafx.h"

Gerenciadores::Gerenciador_Grafico* Entidades::Ente::pGG = NULL;

namespace Entidades {

Ente::Ente() : id(0), pFigura(NULL) {}

Ente::~Ente(){
    id = -1;
    if(pFigura){
        delete pFigura;
        pFigura = NULL;
    }
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