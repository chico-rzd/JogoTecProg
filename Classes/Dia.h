#pragma once
#include "Fase.h"
#include "Cachorro.h"
#include "Poça.h"
#include "Roseira.h"

namespace Fases
{
    class Dia : public Fase
    {
        private:
            const int maxInimMedios;
            Entidades::Personagens::Cachorro* pCachorro;
            Obstaculos::Poça* pPoca;
            Obstaculos::Roseira* pRoseira;

        protected:
            void criarInimMedios();
            void criarObstMedios();
            void criarObstDificeis();
            void criarInimigos();
            void criarObstaculos();

        public:
            Dia();
            ~Dia();
    };
}