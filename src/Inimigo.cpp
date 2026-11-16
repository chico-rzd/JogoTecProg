#include "Inimigo.h"
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>

namespace Entidades
{
    Personagens::Inimigo::Inimigo(float posX, float posY, float esq, float dir, float vel, int dirc, int nl_mal)
    : Personagem(posX, posY), lim_esquerda(esq), lim_direita(dir), velocidade (vel), direcao(dirc), nivel_maldade(nl_mal)
    {

    }
    Personagens::Inimigo::~Inimigo() {}

    void Personagens::Inimigo::salvarDataBuffer() {}
}