#pragma once
#include "Inimigo.h"
#include "Jogador.h"
#include <SFML\Graphics.hpp>

namespace Entidades 
{
    namespace Personagens
    {
        class Cachorro : public Inimigo 
        {
            private:
                Jogador* pJogador;
                
            public:

                Cachorro(float posX, float posY, float limE, float limD, float vel, int dirc, int n_mal);
                ~Cachorro();

                void danificar(Entidades::Personagens::Jogador* p);
                void mover(float dt) ;
                void executar( float dt) ;
                void salvar();

                void setJogador(Jogador* j) { pJogador = j; }


        };
    }
}