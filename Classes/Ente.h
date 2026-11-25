#pragma once
#include "enum.h"

namespace sf {
    class RectangleShape;
}
    
namespace Gerenciadores {
    class Gerenciador_Grafico;
}

namespace Entidades {

  class Ente {
    
    protected:

        int id;
        static Gerenciadores::Gerenciador_Grafico* pGG;
        sf::RectangleShape* pFigura;
        static int contador;

        void carregaImagem(const char* imagem, Texturas::Modo modo = Texturas::ESTICAR_FIGURA);

    public:
        Ente();         
        virtual ~Ente();
        virtual void executar() = 0;
        void desenhar();
        sf::RectangleShape* getFigura() const;
        static void setGG(Gerenciadores::Gerenciador_Grafico* pG);
    };
}
