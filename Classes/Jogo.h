#pragma once 
#include "Gerenciador_Grafico.h"

namespace Entidades {
    class Jogador;
}

class Jogo {
    private:
        Gerenciadores::Gerenciador_Grafico GG;
        Entidades::Jogador* pJogador1;
        Entidades::Jogador* pJogador2;
        
    public:
        Jogo(int numJogadores = 1);
        ~Jogo();    
        void executar();
        void escolheQntJogadores(int escolha);
};  