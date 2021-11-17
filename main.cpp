#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    Menu menu = Menu();
    cout << "Carregando estoque..." << endl;
    menu.carregarEstoque();
    cout << "Estoque carregado" << endl;
    //cout << "VOU CHAMAR mostrarEstoque()" << endl;
    //menu.mostrarEstoque();

    while (true){
        menu.menuUser();
    }

    return 0;
}
