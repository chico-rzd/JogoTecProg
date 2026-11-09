#pragma once 
#include "Personagem.h"
#include "enum.h"

namespace Entidades {
    class Inimigo;
    
    class Jogador : public Personagem {

        private: 
            void criarFigura(Estilos::Cores cor);
            
        protected:  
            int pontos;
            float velocidade;
            Movimento::Controles controles;
            Estilos::Cores corJogador;

        public:
            void colidir(Inimigo*    pInimigo);
            void executar();
            void salvar();
            void mover();
        
        public: 
            Jogador();
            Jogador(float x_, float y_, Movimento::Controles control, Estilos::Cores corJog);   
            ~Jogador();
    };
}