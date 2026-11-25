#include "Plataforma.h"
#include "Jogador.h"
#include <SFML/Graphics.hpp>

static const char* const caminhoPlataforma = "assets/ground_cortado.png";
namespace Obstaculos {

Plataforma::Plataforma() : Obstaculo() {
    criaElementos(100.0f, 100.0f, caminhoPlataforma, Texturas::REPETIR_FIGURA);
}
Plataforma::Plataforma(float x_, float y_, float largura_, float altura_) : Obstaculo(x_, y_) {
    criaElementos(largura_, altura_, caminhoPlataforma, Texturas::REPETIR_FIGURA);
}

Plataforma::~Plataforma(){}

void Plataforma::obstaculizar(Entidades::Personagens::Jogador* pJogador) 
{
    if(pJogador == NULL)
        return;

    sf::FloatRect bJog  = pJogador->getLimitesEntidade();
    sf::FloatRect bPlat = getLimitesEntidade();
    sf::FloatRect inter;

    if(!bJog.intersects(bPlat, inter)) return;

    if(inter.height < inter.width)
    {
        float centroYJog = bJog.top + bJog.height / 2.0f;
        float centroYPlat = bPlat.top + bPlat.height / 2.0f;
        
        if(centroYJog < centroYPlat)
        pJogador->pousar(bPlat.top);
        else
        pJogador->baterCabeca(bPlat.top + bPlat.height);
    }
    else 
    {
        float centroXJog = bJog.left + bJog.width / 2.0f;
        float centroXPlat = bPlat.left + bPlat.width / 2.0f;

        if(centroXJog < centroXPlat)
            pJogador->setPosicaoX(pJogador->getPosicaoX() + (bPlat.left - (bJog.left + bJog.width)));
        else
            pJogador->setPosicaoX(pJogador->getPosicaoX() + (bPlat.left + bPlat.width - bJog.left));
    }
}

void Plataforma::executar(){}

void Plataforma::salvar(){}


}