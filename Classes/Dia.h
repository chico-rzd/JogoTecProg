#pragma once
#include "Fase.h"
#include "Cachorro.h"
#include "Poça.h"

namespace Fases
{
    class Dia : public Fase
    {
        private:
            const int maxInimMedios;
            Entidades::Personagens::Cachorro* pCachorro;
            Obstaculos::Poça* pPoca;

        protected:
            void criarInimMedios();
            void criarObstMedios();
            void criarInimigos();
            void criarObstaculos();

        public:
            Dia();
            ~Dia();
    };
}