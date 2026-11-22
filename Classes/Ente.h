#pragma once

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
        sf::RectangleShape* pFigura;

        static Gerenciadores::Gerenciador_Grafico* pGG;
        static int contador;

    public:
        Ente();         
        virtual ~Ente();
        virtual void executar() = 0;
        void desenhar();
        void carregaImagem(const char* imagem);
        sf::RectangleShape* getFigura() const;
        static void setGG(Gerenciadores::Gerenciador_Grafico* pG);
    };
};
