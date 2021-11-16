#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    Menu menu = Menu();
    cout << "Carregando..." << endl;
    menu.carregarEstoque();

    while (true){
        menu.menuUser();
    }

    return 0;
}
