#pragma once 
#include "Gerenciador_Grafico.h"

class Jogo {
    private:
        Gerenciadores::Gerenciador_Grafico GG;
    
    public:
        Jogo();
        ~Jogo();    
        void executar();
};  