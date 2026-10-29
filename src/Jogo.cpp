#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo() : GG() {

}

Jogo::~Jogo(){

}

void Jogo::executar(){
    
    while(GG.JanelaAberta())
    {
        GG.trataEventos();
        GG.limparJanela();
        GG.mostrarConteudoJanela();
    }

}

