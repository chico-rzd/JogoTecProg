#include "Poça.h"
#include "Ente.h"
#include "Jogador.h"
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>

static const char* const caminhoPoca = "assets/poca_cortada.png";

namespace Obstaculos {

Poça::Poça(float x_, float y_, short int dano) : Obstaculo(x_, y_), danosidade(dano), tempo(0.0f)
{
    danoso = false;
    criaElementos(89.0f, 16.0f, caminhoPoca);
}
Poça::Poça(short int dano) : Obstaculo(), danosidade(dano), tempo(0.0f){
    danoso = false; //qnd danoso é falso, a poça so desacelera. Quando é true, desalacera + causa dano
    criaElementos(89.0f, 16.0f, caminhoPoca);

}
Poça::~Poça() {};   

void Poça::salvarDataBuffer() {}

void Poça::executar() {
    tempo += pGG->getDeltaTempo();
    const float intervaloSegundos = 2.5f;

    if(tempo >= intervaloSegundos){
        tempo = 0;
        //p n esquecer: o danoso vai dizer se ele vai so deixar lento ou se deixa lento E da dano e a danosidade, sera o tanto de vida que tirará
        
        danoso = (rand() % 101 < 20); // danoso tem 20% de chance de rolar ou não
        if(pFigura){
            if(danoso)
                pFigura->setFillColor(sf::Color::Red);
            else
                pFigura->setFillColor(sf::Color::White);    
        }
    }
}    

void Poça::obstaculizar(Entidades::Personagens::Jogador* pJogador) 
{
    if(pJogador == NULL) return;
    pJogador->setLentidao(0.4f); 

    if(danoso) pJogador->sofrerDano(danosidade);

}

void Poça::salvar() {}

short int Poça::getDanosidade() const {
    return danosidade;
}

void Poça::setDanosidade(short int dano){
    danosidade = dano;
}
}