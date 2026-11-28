#include "Poca.h"

static const char* const caminhoPoca = "assets/poca_cortada.png";

namespace Obstaculos {

    Poca::Poca(float x_, float y_, short int dano) : Obstaculo(x_, y_), danosidade(dano) 
    {
        danoso = true;
        criaElementos(100.0f, 16.0f, caminhoPoca);
    }
    Poca::Poca(short int dano) : Obstaculo(), danosidade(dano){
        criaElementos(100.0f, 16.0f, caminhoPoca);

    }
    Poca::~Poca() {};   

    void Poca::salvarDataBuffer() {}
    void Poca::executar() {}    

    void Poca::obstaculizar(Entidades::Personagens::Jogador* pJogador) 
    {
        if(pJogador == NULL) return;

        pJogador->setLentidao(0.4f);
    }
    
    void Poca::salvar() {}

    short int Poca::getDanosidade() const {
        return danosidade;
    }

    void Poca::setDanosidade(short int dano){
        danosidade = dano;
    }
}