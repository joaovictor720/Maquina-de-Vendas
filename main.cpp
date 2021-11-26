#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    Menu menu = Menu();

    menu.carregarEstoque();
    menu.carregarApurado();

    try {
        menu.menuUser();
    } catch (Desligamento& d){
        menu.salvaEstoque();
        menu.salvarApurado();
        cout << "Estoque e Apurado armazenados." << endl;
        cout << "Desligando..." << endl;
    }

    return 0;
}
