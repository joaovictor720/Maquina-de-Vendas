#ifndef MENU_H
#define MENU_H

#include "ControleProduto.h"
#include "ControleEstoque.h"

class Menu : public ControleProduto, public ControleEstoque
{
    public:
        Menu();
        virtual ~Menu();

        void menuUser();

    private:
        void menuDev();
        string carregarSenha();

        string senha;
};

#endif // MENU_H
