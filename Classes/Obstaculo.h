#pragma once 
#include "Entidade.h" 
#include <SFML/Graphics.hpp>

namespace Entidades {
    class Jogador;
}

namespace Obstaculos {

    class Obstaculo : public Entidades::Entidade 
    {
        protected:
            bool danoso;
            float altura;
            float largura;
            void criaElementos(float largura_, float altura_, sf::Color cor);
        
        public:
            Obstaculo(float x_, float y_, std::ostream* bff = NULL);
            Obstaculo();    
            ~Obstaculo();
        
            public:
            void salvarDataBuffer();
            virtual void executar() = 0;
            virtual void obstaculizar(Entidades::Jogador* pJogador) = 0;
            virtual void salvar() = 0;
    };
}