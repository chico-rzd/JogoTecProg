#pragma once
#include "Personagem.h"
#include "Entidade.h"

namespace Entidades 
{
   
        namespace Personagens
        {
            class Jogador;

                class Inimigo : public Entidades::Personagem 
                {

                    protected: 
                        int nivel_maldade;
                        int direcao;
                        float lim_esquerda;
                        float lim_direita;
                        float velocidade;

                    public: 
                        Inimigo();
                        Inimigo(float posX, float posY, float esq, float dir, float vel, int dirc, int nl_mal);
                        ~Inimigo();

                    public:     
                        void salvarDataBuffer();
                        virtual void mover(float dt) = 0;
                        virtual void executar(float dt) = 0;
                        virtual void danificar(Entidades::Personagens::Jogador* p) = 0;
                        virtual void salvar() = 0;
                };
        }
}