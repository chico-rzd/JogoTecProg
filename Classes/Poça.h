#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

namespace Obstaculos {
    class Poça : public Obstaculo 
    {
        private:
            short int danosidade;
            float tempo;

        public:
            Poça(short int dano);
            Poça(float x_, float y_, short int dano);
            ~Poça();
        public:
            short int getDanosidade() const;
            void setDanosidade(short int dano);
            void salvarDataBuffer();
            void executar();
            void salvar();
            void obstaculizar(Entidades::Personagens::Jogador* pJogador);
    };
}


