#pragma once 
#include "Personagem.h"

namespace Entidades {

    class Inimigo;
    
    class Jogador : public Personagem {

        protected:
            int pontos;
            float velocidade;

        public:
            void colidir(Inimigo*    pInimigo);
            void executar();
            void salvar();
            void mover();
        
        public: 
            Jogador();
            Jogador(float x_, float y_);
            ~Jogador();
    };
}