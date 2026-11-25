#include "Gerenciador_Colisoes.h"
#include "Entidade.h"
#include "stdafx.h"
#include "Obstaculo.h"
#include "Jogador.h"
using std::cerr;
using std::endl;

namespace Gerenciadores
{
    Gerenciador_Colisoes::Gerenciador_Colisoes()
    : LIs(), LOs(), LPs(), pJog1(NULL), pJog2(NULL)
    {
    }

    Gerenciador_Colisoes::~Gerenciador_Colisoes()
    {
        LIs.clear();
        LOs.clear();
        LPs.clear();

        pJog1 = NULL;
        pJog2 = NULL;
    }

    void Gerenciador_Colisoes::incluirInimigo(Entidades::Personagens::Inimigo* pi)
    {
        if(pi == NULL){
            cerr << "Erro em adicionar inimigo" << endl;
            return;
        }
        LIs.push_back(pi);
    }

    void Gerenciador_Colisoes::incluirObstaculo(Obstaculos::Obstaculo* po)
    {
        if(po == NULL){
            cerr << "Erro em adicionar obstaculo" << endl;
            return;
        }
        LOs.push_back(po);
    }

    void Gerenciador_Colisoes::incluirProjetil(Entidades::Projetil* pj)
    {
        if(pj == NULL){
            cerr << "Erro em adicionar projetil" << endl;
            return;
        }
        LPs.insert(pj);
    }
    void Gerenciador_Colisoes::incluirJogador(Entidades::Personagens::Jogador* pJog)
    {
        if(pJog1 == NULL)
            pJog1 =pJog;
        else if (pJog2 == NULL)
            pJog2 = pJog;
    }

    const bool Gerenciador_Colisoes::verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2)
    {
        if((pe1 == NULL) || (pe2 == NULL) )
            return false;

        return (pe1->getLimitesEntidade()).intersects(pe2->getLimitesEntidade());
    }

    void Gerenciador_Colisoes::tratarColisoesJogObstaculos(Entidades::Personagens::Jogador* pJog) 
    {
        if(pJog == NULL) return;
        
        std::list<Obstaculos::Obstaculo*>::iterator it;
        
        for(it = LOs.begin(); it != LOs.end(); ++it) 
        {
            if(verificarColisao(pJog, *it))
            (*it)->obstaculizar(pJog);
        }
    }
    void Gerenciador_Colisoes::tratarColisoesJogObstaculos()
    {
        tratarColisoesJogObstaculos(pJog1);
        tratarColisoesJogObstaculos(pJog2);
    } 

    void Gerenciador_Colisoes::tratarColisoesInimigos() {}
    void Gerenciador_Colisoes::tratarColisoesProjeteis() {}


    void Gerenciador_Colisoes::executar() 
    {
        tratarColisoesJogObstaculos();
    }
}