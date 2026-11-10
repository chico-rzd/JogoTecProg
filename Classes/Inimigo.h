#pragma once
#include "Personagem.h"

namespace Entidades {
    class Jogador;
} 


namespace Inimigos {

    class Inimigo : public Entidades::Personagem {
        
        protected: 
            int nivel_maldade;

        public: 
            Inimigo();
            ~Inimigo();

        public:     
            void salvarDataBuffer();
            virtual void executar() = 0;
            virtual void danificar(Entidades::Jogador* p) = 0;
            virtual void salvar() = 0;
    };
 }