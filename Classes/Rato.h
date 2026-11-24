#pragma once
#include <SFML\Graphics.hpp>
#include "Inimigo.h"
#include "Jogador.h"
#include "Personagem.h"
#include "Entidade.h"



namespace Entidades
{
    namespace Personagens
    {
        class Rato: public Inimigo
        {
            private:
                Jogador* pJogador;

            public:

                Rato(float posX, float posY, float limE, float limD, float vel,int dirc, int n_mal);
                ~Rato();

                void danificar(Entidades::Personagens::Jogador* p);
                void executar() ;
                void mover() ;
                void salvar();

                void setJogador(Jogador* j) { pJogador = j; }


        };
    } 
}