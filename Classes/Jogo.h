#pragma once 
#include "Gerenciador_Grafico.h"
#include "Fase.h"
#include "Dia.h"

namespace Entidades {
    namespace Personagens {
        class Jogador;
    }
}
namespace Obstaculos {
    class Plataforma;
    class Roseira;
    class Poça;
}

class Jogo {
    private:

        Gerenciadores::Gerenciador_Grafico GG;
        Entidades::Personagens::Jogador* pJogador1;
        Entidades::Personagens::Jogador* pJogador2;
        Fases::Fase* pFase;

    public:

        Jogo(int numJogadores = 1);
        ~Jogo();    
        void executar();
        void escolheQntJogadores(int escolha);

};  