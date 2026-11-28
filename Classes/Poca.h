#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

namespace Obstaculos {
    class Poca : public Obstaculo 
    {
        private:
            short int danosidade;
            float tempo;

        public:
            Poca(short int dano);
            Poca(float x_, float y_, short int dano);
            ~Poca();
        public:
            short int getDanosidade() const;
            void setDanosidade(short int dano);
            void salvarDataBuffer();
            void executar();
            void salvar();
            void obstaculizar(Entidades::Personagens::Jogador* pJogador);
    };
}


