#include <iostream>
#include "ListaEntidades.h"
#include "Entidade.h"

using namespace Listas;

ListaEntidades::ListaEntidades() : LEs() {}

ListaEntidades::~ListaEntidades() { limpar(); }

void ListaEntidades::incluir(Entidades::Entidade* pE)
{
    if (pE == NULL)
        std::cerr << "Entidade nula. Nao incluida." << std::endl;
    else
        LEs.incluir(pE);
}

void ListaEntidades::remover(Entidades::Entidade* pE)
{
    if (pE != NULL)
        LEs.remover(pE);
}

size_t ListaEntidades::getTamanho() const { return LEs.getTamanho(); }

Entidades::Entidade* ListaEntidades::operator[](int indice) const { return LEs[indice]; }

void ListaEntidades::limpar() { LEs.limpar(); }

void ListaEntidades::percorrer() // Otimizacao para chamar na fase
{
    for (Elemento<Entidades::Entidade>* p = LEs.getPrimeiro(); p != NULL; p = p->getProx())
    {
        Entidades::Entidade* pE = p->getInfo();
        if (pE != NULL)
        {
            pE->executar();
            pE->desenhar();
        }
    }
}

void ListaEntidades::executar()
{
    for (Elemento<Entidades::Entidade>* p = LEs.getPrimeiro(); p != NULL; p = p->getProx())
    {
        Entidades::Entidade* pE = p->getInfo();
        if (pE != NULL)
            pE->executar();
    }
}

void ListaEntidades::desenharEntidades()
{
    for (Elemento<Entidades::Entidade>* p = LEs.getPrimeiro(); p != NULL; p = p->getProx())
    {
        Entidades::Entidade* pE = p->getInfo();
        if (pE != NULL)
            pE->desenhar();
    }
}
