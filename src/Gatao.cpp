#include "Gatao.h"
#include <cmath>
#include <SFML/Graphics.hpp>

namespace Entidades
{

    Personagens::Gatao::Gatao(float posX, float posY, float limE, float limD, float vel, int dirc, int n_mal)
    : Inimigo(posX, posY, limE, limD, vel, dirc, n_mal), pJogador(NULL)

    {   
        carregaImagem("assets/gatao.png");
        atualizarFigura();
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

    void Personagens::Gatao::mover() // Objetivo: Perseguir o jogador quando entra na area de alcance
    {
       
    }

    void Personagens::Gatao::executar()
    {

        mover();
    }

    void Personagens::Gatao::salvar()
    {

    }
}