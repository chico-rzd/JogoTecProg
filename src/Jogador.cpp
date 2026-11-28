#include "Jogador.h"
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "enum.h"
#include "Ente.h"
#include "Inimigo.h"

namespace Entidades {

Personagens::Jogador::Jogador() : Personagem(), pontos(0), velocidade(250.0f), fatorVelocidade(1.0f), tempoInvulneravel(0.0f), velocidadeEmpurrao(0.0f), corJogador(Estilos::VERMELHO), morto(false)
{
    controles.cima      = Movimento::Tecla_W;
    controles.baixo     = Movimento::Tecla_S;
    controles.esquerda  = Movimento::Tecla_A;
    controles.direita   = Movimento::Tecla_D;

    criarFigura(Estilos::VERMELHO);
}

Personagens::Jogador::Jogador(float x_, float y_, Movimento::Controles control, Estilos::Cores corJog) : Personagem(x_, y_, 10), pontos(0), velocidade(250.0f), fatorVelocidade(1.0f), tempoInvulneravel(0.0f), controles(control), corJogador(corJog)
{
    criarFigura(corJog);
}

Personagens::Jogador::~Jogador() {}


void Personagens::Jogador::colidir(Inimigo* pInimigo)
{
    if(pInimigo == NULL) return;

    if(morto) return;

    if(tempoInvulneravel > 0.0f) return;

    pInimigo->danificar(this);

    sf::FloatRect bJog = getLimitesEntidade();
    sf::FloatRect bIni = pInimigo->getLimitesEntidade();

    float centroXjog = bJog.left + bJog.width / 2.0f;
    float centroXini = bIni.left + bIni.width / 2.0f;

    const float forca = 300.0f;

    if(centroXjog < centroXini)
    {
        velocidadeEmpurrao -= forca;
    }
    else 
        velocidadeEmpurrao = forca;

   std::cout << "empurrao = " << velocidadeEmpurrao << std::endl;

}

Personagens::Jogador& Personagens::Jogador::operator-=(short int dano)
{
    num_vidas -= dano;
    if(num_vidas < 0)
        num_vidas = 0;

    return *this;
}

void Personagens::Jogador::executar() 
{
    mover();
}

void Personagens::Jogador::salvar() {}

void Personagens::Jogador::mover() {

    vetorVelocidade.x = 0.0f; //zera a cada quadro para não andar infinitamente
    if(tempoInvulneravel > 0.0f) tempoInvulneravel -= pGG->getDeltaTempo();

    const float atrito = 1333.0f;
    float reducao = atrito * pGG->getDeltaTempo();

    if(velocidadeEmpurrao > 0.0f)
    {
        velocidadeEmpurrao -= reducao;
        if(velocidadeEmpurrao < 0.0f)
            velocidadeEmpurrao = 0.0f;
    }
    else if(velocidadeEmpurrao < 0.0f){

        velocidadeEmpurrao += reducao;
        if(velocidadeEmpurrao > 0.0f)
            velocidadeEmpurrao = 0.0f;
    }

    if(!morto)
    {
        lerEntradas();
        vetorVelocidade.x += velocidadeEmpurrao;
        tentarPular();
    }

    aplicarFisica(); 
    integrarPosicao();
    
    fatorVelocidade = 1.0f;
    atualizarFigura();
}

void Personagens::Jogador::morrer()
{
    if(morto)
        return;

    morto = true;

       const char* arquivo = "assets/jogador2morto.png";
    
        switch (corJogador)
        {
            case Estilos::PRETO:
            arquivo = "assets/jogador2morto.png";
            break;
            case Estilos::VERMELHO:
            arquivo = "assets/jogadormorto.png";
            break;
        
            default:
            break;

        }

        carregaImagem(arquivo);

        if(pFigura)
        pFigura->setSize(sf::Vector2f(200.0f, 200.0f));
    
        atualizarFigura();


}

void Personagens::Jogador::criarFigura(Estilos::Cores cor){
    
    const char* arquivo = "assets/jogador2.png";
    
    switch (cor)
    {
        case Estilos::PRETO:
        arquivo = "assets/jogador1.png";
        break;
        case Estilos::VERMELHO:
        arquivo = "assets/jogador2.png";
        break;
        
        default:
        break;

    }

    carregaImagem(arquivo);

    if(pFigura)
    pFigura->setSize(sf::Vector2f(200.0f, 200.0f));
    
    atualizarFigura();
}

/* função que altera a velocidade do jogador em suas posições x e y */
void Personagens::Jogador::lerEntradas(){

    if(pGG->teclaPressionada(controles.esquerda)) 
    {
        vetorVelocidade.x = -velocidade * fatorVelocidade;        
    }
    if(pGG->teclaPressionada(controles.direita)) 
    {
        vetorVelocidade.x = velocidade * fatorVelocidade;
    }
    
}
/* Ação de pulo do jogador separado das demais ações*/
void Personagens::Jogador::tentarPular(){
    if(pGG->teclaPressionada(controles.cima) && naPlataforma) 
    {
        vetorVelocidade.y = -800.0f;
        naPlataforma = false;
    }
}
void Personagens::Jogador::pousar(float yTopo)
{
    sf::FloatRect limites = getLimitesEntidade();
    y += yTopo - (limites.top + limites.height);
    vetorVelocidade.y = 0.0f;
    naPlataforma = true;
    atualizarFigura();
}

void Personagens::Jogador::baterCabeca(float yBase)
{
    y += yBase - getLimitesEntidade().top;
    if(vetorVelocidade.y < 0.0f) vetorVelocidade.y = 0.0f;
    atualizarFigura();
}

sf::FloatRect Personagens::Jogador::getLimitesEntidade() const
{
    const float margemX = 0.15f;
    const float margemY = 0.20f;
    const float proporcaoLargura = 0.62f;
    const float proporcaoAltura = 0.40f;

    sf::FloatRect figura = Entidade::getLimitesEntidade();

    return sf::FloatRect(figura.left + margemX * figura.width,
                         figura.top + margemY * figura.height,
                         proporcaoLargura * figura.width,
                         proporcaoAltura * figura.height);

}

void Personagens::Jogador::setLentidao(float fator)
{
    fatorVelocidade = fator;
}

void Personagens::Jogador::sofrerDano(short int dano)
{
    if(morto) return;

    if(tempoInvulneravel > 0.0f)
        return;

    *this -= dano;
    tempoInvulneravel = 1.0f;

    std::cout << "Levou dano! Vidas: " << num_vidas << std::endl;

    *this -= dano;
    tempoInvulneravel = 1.0f;

    if(num_vidas <= 0)
    morrer();

}

int Personagens::Jogador::retornaIdJog(){
    return this->id;
} //teste do id
}
