#pragma once
#include "Entidade.h"

namespace Entidades {

    class Personagem : public Entidade {

        protected:
            int num_vidas;
        
        protected:
            void salvarDataBuffer();

        public:
            Personagem();
            Personagem(float x_, float y_, int vidas = 3, std::ostream* buff = NULL);
            
            ~Personagem();

            virtual void executar() = 0;
            virtual void salvar()   = 0;
            virtual void mover()    = 0;

    };
}