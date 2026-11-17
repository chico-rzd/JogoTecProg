#pragma once
#include "Obstaculo.h"

namespace Obstaculos {

    class Rua : public Obstaculos::Obstaculo 
    {            
        public:
            Rua();
            Rua(float x_, float y_);
            ~Rua();

        public:
            void executar();
            void salvar();
            void obstaculizar(Entidades::Personagens::Jogador* pJogador);
            
    };
}