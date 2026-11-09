#pragma once

namespace Movimento  {

    typedef enum  
    {
        Seta_cima, Seta_baixo, Seta_esquerda, Seta_direita,
        Tecla_W, Tecla_S, Tecla_A, Tecla_D
    } Teclas;

    typedef struct Controles {
        Teclas cima;
        Teclas baixo;
        Teclas esquerda;
        Teclas direita;
    } Controles;
}
namespace Estilos {

    typedef enum 
    {
        PRETO,
        VERMELHO
        
    } Cores;
}