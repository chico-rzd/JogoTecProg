#pragma once
#include <SFML/Graphics.hpp>
#include "enum.h"

namespace Entidades {
    class Ente;
}

namespace Gerenciadores {

class Gerenciador_Grafico{
    private:
        sf::RenderWindow Window;

    public:
        Gerenciador_Grafico();
        ~Gerenciador_Grafico(); 

    public:
        
        void desenharEnte(Entidades::Ente* pE);
        bool JanelaAberta();
        void trataEventos();
        void limparJanela();
        void mostrarConteudoJanela();
        bool teclaPressionada(Movimento::Teclas t);
};  
}