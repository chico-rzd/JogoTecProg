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
                float fatorVelocidade;
                float tempoInvulneravel;

                Movimento::Controles controles;
                Estilos::Cores corJogador;

                void lerEntradas();
                void tentarPular();

            public:
                void colidir(Inimigo*    pInimigo);
                void executar();
                void salvar();
                void mover();
                int retornaIdJog();//tirar

                void pousar(float yTopo);          
                void baterCabeca(float yBase);     
                void setLentidao(float fator);     
                void sofrerDano(short int dano); 
                
                sf::FloatRect getLimitesEntidade() const;
        
            public: 
                Jogador();
                Jogador(float x_, float y_, Movimento::Controles control, Estilos::Cores corJog);   
                ~Jogador();
                Jogador& operator-=(short int dano);

        };

    }
}