#include "Poça.h"

static const char* const caminhoPoca = "assets/poca_cortada.png";

namespace Obstaculos {

    Poça::Poça(float x_, float y_, short int dano) : Obstaculo(x_, y_), danosidade(dano) 
    {
        danoso = true;
        criaElementos(89.0f, 16.0f, caminhoPoca);
    }
    Poça::Poça(short int dano) : Obstaculo(), danosidade(dano){
        criaElementos(89.0f, 16.0f, caminhoPoca);

    }
    Poça::~Poça() {};   

    void Poça::salvarDataBuffer() {}
    void Poça::executar() {}    

    void Poça::obstaculizar(Entidades::Personagens::Jogador* pJogador) 
    {
        if(pJogador == NULL) return;

        pJogador->setLentidao(0.4f);
    }
    
    void Poça::salvar() {}

    short int Poça::getDanosidade() const {
        return danosidade;
    }

    void Poça::setDanosidade(short int dano){
        danosidade = dano;
    }
}