#include "Menu.h"

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

void ExibirOpcoes(){
    cout << "--- CONTROLE DA MAQUINA ---\n\n"
         << "1 - Mostrar estoque\n"
         << "2 - Cadastrar produto\n"
         << "3 - Atualizar precos e quantidades\n"
         << "4 - Remover produto\n"
         << "5 - Controle de apurado\n"
         << "6 - Sair\n"
         << "7 - Desligar maquina\n" << endl;
}

string Menu::carregarSenha(){
    ifstream arq = ifstream("SenhaVendingMachine.dat");
    if (!arq.is_open()){
        cout << "Falha ao carregar binario da senha." << endl;
        usleep(DELAY);
        return 0;
    }
    char senha[20];

    arq.read(senha, sizeof(senha));
    string s(senha);
    return s;
}

void Menu::menuDev(){
    int opcao;
    while (true){
        ExibirOpcoes();
        cout << "Digite uma opcao: ";
        cin >> opcao;
        cin.ignore();
        system("cls");

        switch (opcao){
            case 1:
                mostrarEstoque();
                continue;
            case 2:
                cadastrarProduto();
                break;
            case 3:
                atualizarProduto();
                break;
            case 4:
                deletarProduto();
                break;
            case 5:
                controleApurado();
                break;
            case 6:
                cout << "Voltando ao menu de usuario..." << endl;
                usleep(DELAY);
                return;
            case 7:
                desligar();
                break;
        }
        system("cls");
        salvaEstoque();
    }
}
void Menu::menuUser(){
    int opcao, num_compras;
    while (true){
        system("cls");
        mostrarOpcoes();

        cout << "Escolha seu produto: ";
        cin >> opcao;
        cin.ignore();

        if (opcao == 999){
            string senha, scorreta;
            scorreta = carregarSenha();

            while (true){
                system("cls");
                cout << "Insira a senha de acesso (ou 0 para sair): ";
                getline(cin, senha);

                if (senha == scorreta){
                    system("cls");
                    menuDev();
                    break;
                }else if (senha == "0"){
                    break;
                }else{
                    cout << "Senha invalida." << endl;
                    usleep(DELAY);
                }
            }
            continue; // volta a escolha de produto
        }
        if (opcao <= 0 || opcao > produtos.size()){
            cout << "Opcao invalida." << endl;
            usleep(DELAY);
            continue;
        }

        cout << "Quantos(as) \"" << produtos[ opcao-1 ]->getNome() << "\"";
        if (produtos[ opcao-1 ]->getSabor() != "-"){
            cout << " de Sabor \"" << produtos[ opcao-1 ]->getSabor() << "\"";
        }
        cout << " voce quer: ";
        cin >> num_compras;
        string id = produtos[ opcao-1 ]->getID();
        for (int i = 0; i < num_compras; i++){
            try{
                venderProduto(id);
            } catch (ProdutoEsgotadoException& esg){
                cout << "\nProduto esgotado!" << endl;
                cout << "Foram vendidos(as) " << i << " \"" << produtos[ opcao-1 ]->getNome() << "\"" << endl;
                usleep(DELAY);
                break;
            }
        }
        salvaEstoque();
    }
}
