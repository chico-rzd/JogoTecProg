#include "Jogo.h"
#include <iostream>

int main()
{   
    int escolha;
    std::cout << "Um ou Dois players? Digite 1 para um ou 2: " << std::endl;
    std::cin >> escolha;
    
    Jogo obj(escolha);
    obj.executar();   
   
}