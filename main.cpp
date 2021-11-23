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
        cout << "Desligando..." << endl;
    }

    return 0;
}
