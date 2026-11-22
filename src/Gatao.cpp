#include "Gatao.h"
#include <cmath>
#include <SFML/Graphics.hpp>

namespace Entidades
{

    Personagens::Gatao::Gatao(float posX, float posY, float limE, float limD, float vel, int dirc, int n_mal)
    : Inimigo(posX, posY, limE, limD, vel, dirc, n_mal), pJogador(NULL)

    {   

    }

    Personagens::Gatao::~Gatao()
    {

    }


    void Personagens::Gatao::danificar(Personagens::Jogador* p) //Objetivo: tirar 3 pontos do jogador
    {
        if(p == NULL){
            return;
        }

        p->setVidas(p->getVidas() - 3);

    }

    void Personagens::Gatao::mover(float dt) // Objetivo: Perseguir o jogador quando entra na area de alcance
    {
       /* if( pJogador == NULL)
            return;

        float dirfX = pJogador->getPosicaoX() - x;
        float dirfY = pJogador->getPosicaoY() - y;

        if(fabs(dirfX) <= RAIO_PERSEGUIR_X && fabs(dirfY) <= RAIO_PERSEGUIR_Y){

            if(dirfX > 1.f)
            {
                x += velocidade * dt;
            }
            else if ( dirfX < -1.f)
            {
                x -= velocidade * dt;
            }
        }
        else{

            x += velocidade *direcao * dt;

            if( x >= lim_direita)
            {
                direcao = -1;
            }
            else if (x <= lim_esquerda)
            {
                direcao = 1;
            }
        }

        if( x < lim_esquerda) x = lim_esquerda;

        if( x > lim_direita) x = lim_direita;

        atualizarFigura();
        */
    }

    void Personagens::Gatao::executar( float dt)
    {

        mover(dt);
    }

    void Personagens::Gatao::salvar()
    {

    }
}