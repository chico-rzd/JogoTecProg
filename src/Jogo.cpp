#include "Jogo.h"
#include "Jogador.h"
#include "Plataforma.h"
#include "Roseira.h"
#include "Poça.h"
#include "Gerenciador_Grafico.h"

Jogo::Jogo(int numJogadores) : pJogador1(NULL), pJogador2(NULL), /*pChao(NULL)*/ pFase(NULL)
{
    Entidades::Ente::setGG(&GG);
    pFase = new Fases::Dia();
    
    Movimento::Controles controles_WASD = {Movimento::Tecla_W, Movimento::Tecla_S, Movimento::Tecla_A, Movimento::Tecla_D};
    pJogador1 = new Entidades::Personagens::Jogador(30.0f, 50.0f, controles_WASD, Estilos::VERMELHO);
    pFase->incluirJogador(pJogador1);
    
    if(numJogadores == 2)
    {
        Movimento::Controles controles_setas = {Movimento::Seta_cima, Movimento::Seta_baixo, Movimento::Seta_esquerda, Movimento::Seta_direita};
        pJogador2 = new Entidades::Personagens::Jogador(200.0f, 50.0f, controles_setas, Estilos::PRETO);
        pFase->incluirJogador(pJogador2);
    }
    
}

Jogo::~Jogo(){

    if(pFase)
    { delete pFase;
      pFase = NULL; 
    }
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
        GG.atualizaDeltaTempo();

        GG.trataEventos();

        GG.limparJanela();

        if(pFase){
            pFase->executar();
        }
        
        GG.mostrarConteudoJanela();
    }    
}

