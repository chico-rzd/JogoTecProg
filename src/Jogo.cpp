#include "Jogo.h"
#include "Jogador.h"

Jogo::Jogo(int numJogadores) : pJogador1(NULL), pJogador2(NULL) 
{
    Entidades::Ente::setGG(&GG);
    
    Movimento::Controles controles_WASD = {Movimento::Tecla_W, Movimento::Tecla_S, Movimento::Tecla_A, Movimento::Tecla_D};
    pJogador1 = new Entidades::Jogador(100.0f, 100.0f, controles_WASD, Estilos::VERMELHO);
    
    if(numJogadores == 2)
    {
        Movimento::Controles controles_setas = {Movimento::Seta_cima, Movimento::Seta_baixo, Movimento::Seta_esquerda, Movimento::Seta_direita};
        pJogador2 = new Entidades::Jogador(400.0f, 400.0f, controles_setas, Estilos::PRETO);
    }

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
        GG.limparJanela();
        if(pJogador1){
            pJogador1->desenhar();
        }
        if(pJogador2){
            pJogador2->desenhar();
        }
        GG.mostrarConteudoJanela();
    }    
}

