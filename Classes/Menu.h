#pragma once
#include "Ente.h"

namespace Principal { class Jogo; }

namespace Entidades {

class Menu : public Entidades::Ente {

    private:
        Principal::Jogo* pJogo;
    
    public:
        Menu();
        ~Menu();
        void executar();
};
}