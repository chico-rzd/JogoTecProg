#pragma once
#include "Ente.h"
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Entidades {

    class Entidade : public Ente {
        protected:
            float x;
            float y;
            bool naPlataforma;
            std::ostream* buffer; 
            
            sf::Vector2f vetorVelocidade;
            static const float gravidade;
        
        protected:
            void salvarDataBuffer();
            void atualizarFigura();
            void integrarPosicao();
            void aplicarFisica();

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
            
            sf::FloatRect getLimites() const;
    };
}