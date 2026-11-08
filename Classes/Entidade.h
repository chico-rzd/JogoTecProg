#pragma once
#include "Ente.h"
#include <iostream>

namespace Entidades {

    class Entidade : public Ente {
        protected:
            float x;
            float y;
            std::ostream* buffer; 
        
        protected:
            void salvarDataBuffer();
            void atualizarFigura();

        public:
            Entidade();
            Entidade(float x_, float y_, std::ostream* buff);
            virtual ~Entidade();

            virtual void executar() = 0;
            virtual void salvar() = 0;

        public:
            void setPosicaoX(float xP);
            void setPosicaoY(float yP);
            float getPosicaoX() const;
            float getPosicaoY() const;
    };
}