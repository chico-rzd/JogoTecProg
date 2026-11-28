#pragma once

#include "Entidade.h"
#include "Inimigo.h"
#include "Jogador.h"
#include "NovelodeLa.h"
#include "Obstaculo.h"

#include <vector>
#include <list>
#include <set>


namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        private:
            std::vector<Entidades::Personagens::Inimigo*> LIs;
            std::list<Obstaculos::Obstaculo*> LOs;
            std::set<Entidades::NovelodeLa*> LPs;

            Entidades::Personagens::Jogador* pJog1;
            Entidades::Personagens::Jogador* pJog2;

            const bool verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2);
            void tratarColisoesJogObstaculos();
            void tratarColisoesJogObstaculos(Entidades::Personagens::Jogador* pJog);
            void tratarColisoesInimigos(Entidades::Personagens::Jogador* pJog);
            void tratarColisoesInimigos();
            void tratarColisoesProjeteis(Entidades::Personagens::Jogador* pJog);

        public:
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();

            void incluirInimigo(Entidades::Personagens::Inimigo* pi);
            void incluirObstaculo(Obstaculos::Obstaculo* po);
            void incluirProjetil(Entidades::NovelodeLa* pj);
            void incluirJogador(Entidades::Personagens::Jogador* pJog);

            void executar();
    };
}