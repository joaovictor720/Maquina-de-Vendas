#ifndef MENU_H
#define MENU_H

#include "Maquina.h"

class Menu
{
    public:
        Menu();
        virtual ~Menu();

        std::string getSenha();

    private:
        Maquina controle;
        std::string senha;
};

#endif // MENU_H
