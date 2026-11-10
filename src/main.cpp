#include "Jogo.h"
#include <iostream>

int main()
{   
    int escolha;

    std::cout << "Um ou Dois players? Digite 1 para um ou 2: " << std::endl;
    std::cin >> escolha;
    
    while(escolha > 2 || escolha <= 0)
    {
        std::cout << "Entrada invalida, escolha 1 ou 2. " << std::endl;
        std::cin >> escolha;
    }
    
    Jogo obj(escolha);
    obj.executar();   
   
}