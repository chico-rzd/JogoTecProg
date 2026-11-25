#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

namespace Obstaculos {
    class Roseira : public Obstaculo 
    {
        private:
            float danosidade; //pensar em outro atributo
            
        public:
            Roseira(float elast = 50);
            Roseira(float x_, float y_, float elast = 50);
            ~Roseira(); 
        
        public:
            float getElasticidade() const;
            void setElasticidade(float elastico);
            void executar();
            void obstaculizar(Entidades::Personagens::Jogador* pJogador);
            void salvar();
    };
}
