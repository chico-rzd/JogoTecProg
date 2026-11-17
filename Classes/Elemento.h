#pragma once
#include <cstddef>

namespace Listas {

    template <class TE>
    class Elemento {
        private:
            Elemento<TE>* pProx;
            TE* pInfo;

        public:
            Elemento() : pProx(NULL), pInfo(NULL) {}
            ~Elemento() { pProx = NULL; pInfo = NULL; }

            void setProx(Elemento<TE>* pE) { pProx = pE; }
            Elemento<TE>* getProx() const { return pProx; }

            void setInfo(TE* p) { pInfo = p; }
            TE* getInfo() const { return pInfo; }
    };

}
