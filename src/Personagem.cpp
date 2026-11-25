#include "Personagem.h"
#include <SFML/Graphics.hpp> 

namespace Entidades {
    namespace Personagens {
        Personagem::Personagem() : Entidade(),  num_vidas(0) {}

        Personagem::Personagem(float x_, float y_, int vidas, std::ostream* buff) : Entidade(x_, y_, buff), num_vidas(vidas) {}

        Personagem::~Personagem() {}

        void Personagem::executar() {}
        void Personagem::salvar()   {}
        void Personagem::mover()    {}
    }
}
