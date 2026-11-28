#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

namespace Obstaculos {
    class Poca : public Obstaculo 
    {
        private:
            short int danosidade;

        public:
            Poca(short int dano = 50);
            Poca(float x_, float y_, short int dano = 50);
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


