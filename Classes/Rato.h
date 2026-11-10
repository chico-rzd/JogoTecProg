#pragma once
#include <SFML\Graphics.hpp>
#include "Inimigo.h"

namespace Personagens
{
    class Rato: public Inimigos::Inimigo
    {
        private:

            float raio;
            float limt_esq;
            float limt_dir;
            float vel;
        
        public:

            Rato(float posX, float posY, int limE, int limD, sf::Color cor);
            ~Rato();

            void danificar(Entidades::Jogador* p);
            void executar();
            void mover();
            void salvar();


    };
} 
