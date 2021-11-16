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
    cout << "1 - Mostrar estoque\n"
         << "2 - Cadastrar produto\n"
         << "3 - Atualizar precos\n"
         << "4 - Remover produto\n"
         << "5 - Sair\n" << endl;
}

void Menu::carregarEstoque(){
    string nome, tam_pacote, categoria;
    char tipo;
    double preco, volume, peso;
    int id, qtd;
    Produto *prod;
    ifstream arq = ifstream("C:\\Users\\João Victor\\Desktop\\LP1\\Maquina-de-Vendas\\estoque.txt", ios::in);
    if (arq.is_open() == 0){
        cout << "Falha ao abrir o arquivo." << endl;
        return;
    }

    while (arq.eof()){
        getline(arq, nome);
        arq >> id;
        arq >> preco;
        arq >> qtd;
        arq >> tipo;
        getline(arq, categoria);
        if (tipo == 'b' || tipo == 'B'){
            arq >> volume;
            prod = new Bebida();
        } else if (tipo == 'c' || tipo == 'C'){
            arq >> peso;
            getline(arq, tam_pacote);
            prod = new Comida();
        }else{
            cout << "Tipo de produto inválido" << endl;
            return;
        }

        prod->setNome(nome);
        prod->setID(id);
        prod->setPreco(preco);
        prod->setQtd(qtd);
        prod->setTipo(tipo);
        prod->setCategoria(categoria);
        if (tipo == 'b' || tipo == 'B'){
            prod->setVolume(volume);
        }else if (tipo == 'c' || tipo == 'C'){
            prod->setPeso(peso);
            prod->setTamPacote(tam_pacote);
        }

        produtos.push_back(prod);
    }
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
                break;
            case 2:
                cadastrarProduto();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                cout << "Saindo..." << endl;
                return;
        }
    }
}
void Menu::menuUser(){
    int opcao, num_compras;
    while (true){
        system("cls");
        mostrarOpcoes();
        cout << "Escolha seu produto: ";
        cin >> opcao;
        if (opcao == 999){
            menuDev();
            continue;
        }
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
