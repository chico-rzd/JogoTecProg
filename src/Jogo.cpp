#include "Jogo.h"
#include "Jogador.h"
#include "Rua.h"
#include "Telhado.h"
#include "Poça.h"

Jogo::Jogo(int numJogadores) : pJogador1(NULL), pJogador2(NULL), pChao(NULL), pTel(NULL), pPoca(NULL)
{
    Entidades::Ente::setGG(&GG);
    
    Movimento::Controles controles_WASD = {Movimento::Tecla_W, Movimento::Tecla_S, Movimento::Tecla_A, Movimento::Tecla_D};
    pJogador1 = new Entidades::Jogador(350.0f, 150.0f, controles_WASD, Estilos::VERMELHO);
    
    if(numJogadores == 2)
    {
        Movimento::Controles controles_setas = {Movimento::Seta_cima, Movimento::Seta_baixo, Movimento::Seta_esquerda, Movimento::Seta_direita};
        pJogador2 = new Entidades::Jogador(650.0f, 180.0f, controles_setas, Estilos::PRETO);
    }
    pChao = new Obstaculos::Rua(100.0f, 190.0f);
    pTel = new Obstaculos::Telhado(50.0f, 500.0f);
    pPoca = new Obstaculos::Poça(100.0f, 50.0f);
}

Jogo::~Jogo(){
    if(pJogador1){
        delete pJogador1;
        pJogador1 = NULL;
    }
    if(pJogador2){
        delete pJogador2;
        pJogador2 = NULL;
    }
    if(pChao){
        delete pChao;
        pChao = NULL;
    }
    if(pPoca){
        delete pPoca;
        pPoca = NULL;
    }
    if(pTel){
        delete pTel;
        pTel = NULL;
    }
}

void Jogo::executar(){

    while(GG.JanelaAberta())
    {
        GG.trataEventos();

        if(pJogador1){
            pJogador1->executar();
        }
        if(pJogador2){
            pJogador2->executar();
        } 
        if(pChao){
            pChao->executar();
        }
        GG.limparJanela();
        if(pChao){
            pChao->desenhar();
        }
        if(pJogador1){
            pJogador1->desenhar();
        }
        if(pJogador2){
            pJogador2->desenhar();
        }
        if(pTel){
            pTel->desenhar();
        }
        if(pPoca){
            pPoca->desenhar();
        }
        GG.mostrarConteudoJanela();
    }    
}

