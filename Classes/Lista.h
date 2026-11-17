#pragma once
#include <cstddef>
#include <iostream>
#include "Elemento.h"

namespace Listas {

    template <class TL>
    class Lista {
        private:
            Elemento<TL>* pPrimeiro;
            Elemento<TL>* pUltimo;
            size_t tamanho;

            Lista(const Lista<TL>&);
            Lista<TL>& operator=(const Lista<TL>&);

            void desligar(Elemento<TL>* pAnte, Elemento<TL>* pAtual);

        public:
            Lista();
            ~Lista();

            size_t getTamanho() const;
            Elemento<TL>* getPrimeiro() const;

            void incluir(TL* p);
            void remover(TL* p);        // remove pela informacao
            void remover(size_t indice); // remove pela posicao (sobrecarga)

            TL* operator[](int indice) const;

            void percorrer() const;
            void limpar();
    };

    template <class TL>
    Lista<TL>::Lista() : pPrimeiro(NULL), pUltimo(NULL), tamanho(0) {}

    template <class TL>
    Lista<TL>::~Lista() { limpar(); }

    template <class TL>
    size_t Lista<TL>::getTamanho() const { return tamanho; }

    template <class TL>
    Elemento<TL>* Lista<TL>::getPrimeiro() const { return pPrimeiro; }

    template <class TL>
    void Lista<TL>::incluir(TL* p)
    {
        if (p == NULL) {
            std::cerr << "Ponteiro nulo. Nao incluido na lista." << std::endl;
            return;
        }

        Elemento<TL>* pNovo = new Elemento<TL>();
        pNovo->setInfo(p);

        if (pPrimeiro == NULL) {
            pPrimeiro = pNovo;
        } else {
            pUltimo->setProx(pNovo);
        }
        pUltimo = pNovo;
        tamanho++;
    }

    template <class TL>
    void Lista<TL>::desligar(Elemento<TL>* pAnte, Elemento<TL>* pAtual)
    {
        if (pAnte == NULL)
            pPrimeiro = pAtual->getProx();      // removeu o primeiro
        else
            pAnte->setProx(pAtual->getProx());

        if (pAtual == pUltimo)
            pUltimo = pAnte;                    // removeu o ultimo (ou o unico: vira NULL)

        delete pAtual;
        tamanho--;
    }

    template <class TL>
    void Lista<TL>::remover(TL* p)
    {
        Elemento<TL>* pAnte = NULL;
        Elemento<TL>* pAtual = pPrimeiro;

        while (pAtual != NULL && pAtual->getInfo() != p) {
            pAnte = pAtual;
            pAtual = pAtual->getProx();
        }

        if (pAtual != NULL)
            desligar(pAnte, pAtual);
    }

    template <class TL>
    void Lista<TL>::remover(size_t indice)
    {
        if (indice >= tamanho)
            return;

        Elemento<TL>* pAnte = NULL;
        Elemento<TL>* pAtual = pPrimeiro;

        for (size_t i = 0; i < indice; i++) {
            pAnte = pAtual;
            pAtual = pAtual->getProx();
        }

        desligar(pAnte, pAtual);
    }

    template <class TL>
    TL* Lista<TL>::operator[](int indice) const
    {
        if (indice < 0 || static_cast<size_t>(indice) >= tamanho)
            return NULL;

        Elemento<TL>* pAux = pPrimeiro;
        for (int i = 0; i < indice; i++)
            pAux = pAux->getProx();

        return pAux->getInfo();
    }

    // Lista elemento por elemento (util para depuracao).
    template <class TL>
    void Lista<TL>::percorrer() const
    {
        int i = 0;
        for (Elemento<TL>* pAux = pPrimeiro; pAux != NULL; pAux = pAux->getProx()) {
            std::cout << "[" << i << "] " << pAux->getInfo() << std::endl;
            i++;
        }
    }

    template <class TL>
    void Lista<TL>::limpar()
    {
        Elemento<TL>* pAux = NULL;
        while (pPrimeiro != NULL) {
            pAux = pPrimeiro->getProx();
            delete pPrimeiro;
            pPrimeiro = pAux;
        }
        pUltimo = NULL;
        tamanho = 0;
    }

}
