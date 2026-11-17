#pragma once
#include <vector>
#include <list>
#include <set>

namespace Entidades
{
    class Entidade;
    class Projetil;

    namespace Personagens
    {
        class Inimigo;
        class Jogador;
    }
}

namespace Obstaculos
{
    class Obstaculo;
}

namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        private:
            std::vector<Entidades::Personagens::Inimigo*> LIs;
            std::list<Obstaculos::Obstaculo*> LOs;
            std::set<Entidades::Projetil*> LPs;

            Entidades::Personagens::Jogador* pJog1;
            Entidades::Personagens::Jogador* pJog2;

            const bool verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2);
            void tratarColisoesJogsObstaculos();
            void tratarColisoesInimigos();
            void tratarColisoesProjeteis();

        public:
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();

            void incluirInimigo(Entidades::Personagens::Inimigo* pi);
            void incluirObstaculo(Obstaculos::Obstaculo* po);
            void incluirProjeteil(Entidades::Projetil* pj);

            void executar();
    };
}