#ifndef MENU_H
#define MENU_H

#include "Maquina.h"

class Menu : public Maquina
{
    public:
        Menu();
        virtual ~Menu();

        void carregarEstoque();
        void salvaEstoque();
        void menuDev();
        void menuUser();
};

#endif // MENU_H
