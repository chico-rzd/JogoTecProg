#pragma once
#include "Inimigo.h"
#include <SFML\Graphics.hpp>

namespace Entidades {
    class Jogador;
}

namespace Personagens
{
    class Cachorro : public Inimigos::Inimigo 
    {
        private:
            int tamanho;
            float limt_esq;
            float limt_dir;
            float vel;

        public:

            Cachorro(float posX, float posY, float limE, float limD, sf::Color cor);
            ~Cachorro();
            void danificar(Entidades::Jogador* p);
            void mover();
            void executar();
            void salvar();


    };
}