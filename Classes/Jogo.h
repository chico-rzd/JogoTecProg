#pragma once 
#include "Gerenciador_Grafico.h"

namespace Entidades {
    namespace Personagens {
        class Jogador;
    }
}
namespace Obstaculos {
    class Rua;
    class Roseira;
    class Poça;
}

class Jogo {
    private:
        Gerenciadores::Gerenciador_Grafico GG;
        Entidades::Personagens::Jogador* pJogador1;
        Entidades::Personagens::Jogador* pJogador2;
        Obstaculos::Rua*    pChao;
        Obstaculos::Roseira*    pRos;
        Obstaculos::Poça*    pPoca;
    public:
        Jogo(int numJogadores = 1);
        ~Jogo();    
        void executar();
        void escolheQntJogadores(int escolha);
};  