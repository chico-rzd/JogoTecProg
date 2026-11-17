#pragma once
#include "Obstaculo.h"


namespace Obstaculos {
    class Poça : public Obstaculo 
    {
        private:
            short int danosidade;

        public:
            Poça(short int dano = 50);
            Poça(float x_, float y_, short int dano = 50);
            ~Poça();
        public:
            short int getDanosidade() const;
            void setDanosidade(short int dano);
            void salvarDataBuffer();
            void executar();
            void salvar();
            void obstaculizar(Entidades::Jogador* pJogador);
    };
}


