#pragma once
#include "Inimigo.h"
#include "Jogador.h"
#include <SFML/Graphics.hpp>
#include <cmath>

constexpr float RAIO_PERSEGUIR_X = 200.0f;
constexpr float RAIO_PERSEGUIR_Y = 200.0f;


namespace Entidades
{
    namespace Personagens
    {
        class Gatao: public Inimigo
        {
            private:
                Jogador* pJogador;
        
            public:

                Gatao(float posX, float posY, float limE, float limD, float vel, int dirc, int n_mal);
                ~Gatao();

                void danificar(Entidades::Personagens::Jogador* p);
                void mover(float dt) override;
                void executar( float dt) override;
                void salvar();

                void setJogador(Jogador* j) { pJogador = j; }
        };
    }
}