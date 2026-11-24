#pragma once 
#include "Personagem.h"
#include "enum.h"

namespace Entidades {

    namespace Personagens{
        
        class Inimigo;
    
        class Jogador : public Personagem {

            private: 
                void criarFigura(Estilos::Cores cor);
            
            protected:  

                int pontos;
                float velocidade;
                Movimento::Controles controles;
                Estilos::Cores corJogador;

                void lerEntradas();
                void tentarPular();

            public:
                void colidir(Inimigo*    pInimigo);
                void executar();
                void salvar();
                void mover();
                int retornaIdJog();
        
            public: 
                Jogador();
                Jogador(float x_, float y_, Movimento::Controles control, Estilos::Cores corJog);   
                ~Jogador();

        };

    }
}