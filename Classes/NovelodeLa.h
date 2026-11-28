#pragma once
#include "Entidade.h"
#include "Jogador.h"
#include "Gatao.h"
#include <SFML/Graphics.hpp>

namespace Entidades
{
    class NovelodeLa: public Entidade
    {   
        private:
            bool ativo;
            Personagens::Gatao* pGatao;

        public:
            NovelodeLa();
            ~NovelodeLa();

            void executar();
            void salvar();

    };
}