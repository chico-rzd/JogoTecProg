#include "Gatao.h"
#include <cmath>
#include <SFML/Graphics.hpp>

namespace Entidades
{

    Personagens::Gatao::Gatao(float posX, float posY, float limE, float limD, float vel, int dirc, int n_mal = 4)
    : Inimigo(posX, posY, limE, limD, vel, dirc, n_mal), pJogador(NULL)

    {   
        carregaImagem("assets/gatao.png");

        if(pFigura)
        pFigura->setSize(sf::Vector2f(180.0f, 180.0f));

        atualizarFigura();
    }

    Personagens::Gatao::~Gatao()
    {

    }


    void Personagens::Gatao::danificar(Personagens::Jogador* p) // A fazer: Objetivo: tirar dois pontos do Jogador
    {
        if(p == NULL){
        return;
        }
    
        p->sofrerDano(nivel_maldade);

        
    }

    void Personagens::Gatao::mover() // A fazer: Objetivo: Perseguir o jogador quando entra na area de alcance
    {
       
    }

    void Personagens::Gatao::executar() // A fazer
    {

        mover();

    }

    void Personagens::Gatao::salvar()
    {

    }

    sf::FloatRect Personagens::Gatao::getLimitesEntidade() const
    {
        const float margemX = 0.15f;
        const float margemY = 0.20f;
        const float proporcaoLargura = 0.62f;
        const float proporcaoAltura = 0.40f;

        sf::FloatRect figura = Entidade::getLimitesEntidade();

        return sf::FloatRect(figura.left + margemX * figura.width,
                            figura.top + margemY * figura.height,
                            proporcaoLargura * figura.width,
                            proporcaoAltura * figura.height);
                         
    }
}