#pragma once
#include "Ente.h"
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Entidades {

    class Entidade : public Ente {
        protected:
            float x;
            float y;
            std::ostream* buffer; 
        
        protected:
            void salvarDataBuffer();
            void atualizarFigura();
            void integrarPosicao();
            void aplicarFisica();
            bool naPlataforma;

            sf::Vector2f vetorVelocidade;
            static const float gravidade;

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