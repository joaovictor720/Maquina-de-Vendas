#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    Menu menu = Menu();
    cout << "Carregando estoque..." << endl;
    menu.carregarEstoque();
    menu.carregarApurado();

    while (true){
        try {
            menu.menuUser();
        } catch (Desligamento& d){
            break;
        }
    }
    
    cout << "Desligando..." << endl;

    return 0;
}
