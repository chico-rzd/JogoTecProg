#pragma once

#include "Gerenciador_Colisoes.h"
#include "Gerenciador_Grafico.h"
#include "ListaEntidades.h"
#include "Ente.h"
#include "Rato.h"
#include "Plataforma.h"

namespace Fases
{
    class Fase: public Entidades::Ente
    {
        protected:

            Listas::ListaEntidades* lista_ents;
            Gerenciadores::Gerenciador_Colisoes* GC;
            Entidades::Personagens::Rato* pRato;
            Obstaculos::Plataforma* pPlataforma;

        protected:

            void inicializar();
            void criarInimFaceis();
            void criarPlataformas();
            void criarCenario();

            virtual void criarInimigos() = 0;
            virtual void criarObstaculo() = 0;

        public:

            Fase();
            ~Fase();

            virtual void executar();   

    };

}
