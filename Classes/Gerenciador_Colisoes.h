#pragma once
#include <vector>
#include<list>
#include<set>
#include <SFML/Graphics.hpp>


namespace Entidades
{
    class Inimigo;
    class Jogador;
    class Obstaculos;
    class Projetil;
    class Entidade;
}

namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        private:

        std::vector<Entidades::Inimigo*> LIs;
        std::list<Entidades::Obstaculos*> LOs;
        std::set<Entidades::Projetil*> LPs;

        Entidades::Jogador* pJog1;
        Entidades::Jogador* pJog2;

        private:

        const bool verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2);
        void tratarColisoesJogsObstaculos();
        void tratarColisoesInimigos();
        void tratarColisoesProjeteis();

        public:

        Gerenciador_Colisoes();
        ~Gerenciador_Colisoes();

        void incluirInimigo(Entidades::Inimigo* pi);
        void incluirObstaculo(Entidades::Obstaculos* po);
        void incluirProjeteil(Entidades::Projetil* pj);

        void executar();

    };
}