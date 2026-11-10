#pragma once
#include "Inimigo.h"
#include <SFML/Graphics.hpp>

namespace Entidades {
    class Jogador;
}

namespace Personagens
{
    class Gatao: public Inimigos::Inimigo
    {
        private:
            short int forca;
            float limt_esq;
            float limt_dir;
            float vel;
        
        public:

            Gatao(float posX, float posY, float limE, float limD, sf::Color cor);
            ~Gatao();

            void danificar(Entidades::Jogador* p);
            void mover();
            void executar();
            void salvar();
    };
}