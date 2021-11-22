#ifndef MENU_H
#define MENU_H

//#include "Maquina.h"
#include "ControleProduto.h"
//#include "ControleApurado.h"
#include "ControleEstoque.h"

class Menu : public ControleProduto, public ControleEstoque
{
    public:
        Menu();
        virtual ~Menu();

        //void carregarEstoque();
        //void salvaEstoque();
        void menuUser();

    private:
        void menuDev();
        string carregarSenha();

        string senha;
};

#endif // MENU_H
