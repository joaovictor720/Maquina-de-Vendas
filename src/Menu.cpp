#include "Menu.h"

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

void Menu::menuDev(){
    while (true){

    }
}
void Menu::menuUser(){
    int opcao, num_compras;
    while (true){
        //mostrarOpcoes();
        cout << "Escolha seu produto: ";
        cin >> opcao;
        if (opcao < 0 || opcao > produtos.size()){
            cout << "Opcao invalida" << endl;
            continue;
        }

        cout << "Quantos \"" << produtos[ opcao-1 ]->getNome() << "\" voce quer: ";
        cin >> num_compras;
        int id = produtos[ opcao-1 ]->getID();
        for (int i = 0; i < num_compras; i++){
            try{
                venderProduto(id);
            } catch (ProdutoEsgotadoException& esg){
                cout << "Produto esgotado!" << endl;
                cout << "Foram vendidos(as) " << i << '"' << produtos[ opcao-1 ]->getNome() << '"' << endl;
                break;
            }
        }
    }
}
