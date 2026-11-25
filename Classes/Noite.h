#pragma once
#include "Fase.h"


namespace Fases {

class Noite : public Fase {

    private:
        const int maxChefoes;
    
    private:
        void criarChefoes();
        void criarObsDificil();
        void criarProjeteis();


    public:
        Noite();
        ~Noite();
};
}