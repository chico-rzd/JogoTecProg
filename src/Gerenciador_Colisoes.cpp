#include "Gerenciador_Colisoes.h"
#include "Ente.h"
#include "stdafx.h"
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

    void Gerenciador_Colisoes::incluirProjeteil(Entidades::Projetil* pj)
    {
        if(pj == NULL){
            cerr << "Erro em adicionar projetil" << endl;
            return;
        }
        LPs.insert(pj);
    }

    const bool Gerenciador_Colisoes::verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2)
    {
        return false;
    }

    void Gerenciador_Colisoes::tratarColisoesJogsObstaculos() {}
    void Gerenciador_Colisoes::tratarColisoesInimigos() {}
    void Gerenciador_Colisoes::tratarColisoesProjeteis() {}
    void Gerenciador_Colisoes::executar() {}
}