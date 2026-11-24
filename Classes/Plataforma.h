#pragma once
#include "Obstaculo.h"

namespace Obstaculos {

    class Plataforma : public Obstaculos::Obstaculo 
    {            
        public:
            Plataforma();
            Plataforma(float x_, float y_);
            ~Plataforma();

        public:
            void executar();
            void salvar();
            void obstaculizar(Entidades::Personagens::Jogador* pJogador);
            
    };
}