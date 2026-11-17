#pragma once
#include <cstddef>
#include "Lista.h"

namespace Entidades {
    class Entidade;
}

namespace Listas {

    class ListaEntidades {
        private:
            Lista<Entidades::Entidade> LEs;

        public:
            ListaEntidades();
            ~ListaEntidades();

            void incluir(Entidades::Entidade* pE);
            void remover(Entidades::Entidade* pE);
            size_t getTamanho() const;
            Entidades::Entidade* operator[](int indice) const;

            void limpar();
            void percorrer() const;
            void executar();
    };

}
