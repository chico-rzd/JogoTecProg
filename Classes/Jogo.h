#pragma once 
#include "Gerenciador_Grafico.h"

namespace Entidades {
    class Jogador;
}
namespace Obstaculos {
    class Rua;
    class Telhado;
    class Poça;
}

class Jogo {
    private:
        Gerenciadores::Gerenciador_Grafico GG;
        Entidades::Jogador* pJogador1;
        Entidades::Jogador* pJogador2;
        Obstaculos::Rua*    pChao;
        Obstaculos::Telhado*    pTel;
        Obstaculos::Poça*    pPoca;
        
    public:
        Jogo(int numJogadores = 1);
        ~Jogo();    
        void executar();
        void escolheQntJogadores(int escolha);
};  