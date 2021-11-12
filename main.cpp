#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    string senha;
    Menu menu = Menu();

    while (true){
        getline(cin, senha);
        if (senha == "senhacerta"){
            menu.menuDev();
        }else{
            menu.menuUser();
        }
    }

    return 0;
}
