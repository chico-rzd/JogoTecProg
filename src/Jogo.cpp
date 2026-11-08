#include "Jogo.h"
#include "Jogador.h"
// #include "Entidade.h"

Jogo::Jogo() {
    Entidades::Ente::setGG(&GG);
    executar();
}

Jogo::~Jogo(){

}

void Jogo::executar(){
    Entidades::Jogador teste(100.0f, 1.0f);
    teste.setPosicaoX(100.0f);
    teste.setPosicaoY(200.0f);
    while(GG.JanelaAberta())
    {
        GG.trataEventos();
        
        teste.mover();
        GG.limparJanela();
        teste.desenhar();
        GG.mostrarConteudoJanela();
    }
    std::cout << teste.getPosicaoX() << " | " << teste.getFigura()->getPosition().x << std::endl;
    
}

