#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
#include "enum.h"

namespace Entidades {
    class Ente;     
}

namespace Gerenciadores {

class Gerenciador_Grafico{
    private:

        typedef std::pair<std::string, Texturas::Modo> ChaveTextura;
        sf::RenderWindow Window;
        std::map<ChaveTextura, sf::Texture> texturas;
        sf::Clock relogio;

        float deltaTempo;

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

        sf::Texture& carregarTextura(const std::string& caminho, Texturas::Modo modo = Texturas::ESTICAR_FIGURA);
        
        void atualizaDeltaTempo();
        float getDeltaTempo() const;
};  
}