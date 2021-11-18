#ifndef MENU_H
#define MENU_H

#include "Maquina.h"

class Menu : public Maquina
{
    public:
        Menu();
        virtual ~Menu();

        void carregarEstoque();
        void menuUser();
        void salvaEstoque();

    private:
        void menuDev();
        string carregarSenha();

        string senha;
};

#endif // MENU_H
