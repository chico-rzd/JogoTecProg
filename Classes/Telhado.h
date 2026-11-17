#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
    class Telhado : public Obstaculo 
    {
        private:
            float elasticidade;
            
        public:
            Telhado(float elast = 50);
            Telhado(float x_, float y_, float elast = 50);
            ~Telhado(); 
        
        public:
            float getElasticidade() const;
            void setElasticidade(float elastico);
            void executar();
            void obstaculizar(Entidades::Personagens::Jogador* pJogador);
            void salvar();
    };
}
