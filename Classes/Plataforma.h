#pragma once
#include "Obstaculo.h"

namespace Obstaculos {

    class Plataforma : public Obstaculos::Obstaculo 
    {            
        public:
            Plataforma();
            Plataforma(float x_, float y_, float largura_ = 100.0f, float altura_ = 100.0f);
            ~Plataforma();

        public:
            void executar();
            void salvar();
            void obstaculizar(Entidades::Personagens::Jogador* pJogador);
            
    };
}