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
    try
    { 
        Jogo obj(escolha);
        obj.executar();   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
   
}