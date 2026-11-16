#pragma once
#include "Obstaculo.h"
#include <SFML/Graphics.hpp>

namespace Obstaculos {

    class Rua : public Obstaculos::Obstaculo 
    {
        private:
            sf::RectangleShape* chao;
    
            
        public:
            Rua();
            Rua(float x_, float y_);
            ~Rua();

        public:
            void executar();
            void salvar();
            void obstaculizar(Entidades::Jogador* pJogador);
            void criaRua();

    };
}