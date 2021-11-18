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

void Menu::salvaEstoque(){
    ofstream arq = ofstream("estoque.txt", ios::out | ios::trunc);
    
    if (!arq.is_open()){
        cout << "Falha ao abrir arquivo" << endl;
        return;
    }

    for (int i = 0; i < produtos.size(); i++){
        arq << produtos[i]->getNome() << endl;
        arq << produtos[i]->getID() << endl;
        arq << produtos[i]->getPreco() << endl;
        arq << produtos[i]->getQtd() << endl;
        arq << produtos[i]->getTipo() << endl;
        arq << produtos[i]->getCategoria() << endl;
        
        if (produtos[i]->getTipo() == 'b' || produtos[i]->getTipo() == 'B'){
            arq << produtos[i]->getVolume() << endl;
        } else if (produtos[i]->getTipo() == 'c' || produtos[i]->getTipo() == 'C'){
            arq << produtos[i]->getPeso() << endl;
            arq << produtos[i]->getTamPacote() << endl;
        }
    }
}

void Menu::carregarEstoque(){
    string nome, tam_pacote, categoria;
    char tipo;
    double preco, volume, peso;
    int id, qtd;
    Produto *prod;
    ifstream arq = ifstream("estoque.txt", ios::in);
    if (!arq.is_open()){
        cout << "Falha ao ler o arquivo." << endl;
        return;
    }

    while (!arq.fail() && !arq.bad() && !arq.eof()){
    //while (arq.tellg() != -1){
        //system("cls");
        //cout << "VOU CARREGAR UM PRODUTO" << endl;

        getline(arq, nome);
        //cout << "tellg() nome " << arq.tellg() << endl;
        //cout << "leu nome " << nome << endl;

        arq >> id;
        //cout << "tellg() id " << arq.tellg() << endl;
        //cout << "leu id " << id << endl;

        arq >> preco;
        //cout << "tellg() preco " << arq.tellg() << endl;
        //cout << "leu preco " << preco << endl;

        arq >> qtd;
        //cout << "leu qtd " << qtd << endl;
        arq >> tipo;
        arq.ignore();
        //cout << "leu tipo " << tipo << endl;
        getline(arq, categoria);
        //cout << "leu categoria " << categoria << endl;
        if (tipo == 'b' || tipo == 'B'){
            //arq.seekg(15, ios::cur);
            arq >> volume;
            arq.ignore();
            //cout << "leu volume " << volume << endl;
            //cout << "tellg() volume " << arq.tellg() << endl;
            prod = new Bebida(nome, preco, id, qtd, tipo, categoria, volume);
        } else if (tipo == 'c' || tipo == 'C'){
            //arq.seekg(15, ios::cur);
            arq >> peso;
            arq.ignore();
            //cout << "tellg() peso " << arq.tellg() << endl;
            getline(arq, tam_pacote);
            //cout << "tellg() tam_pacote " << arq.tellg() << endl;
            prod = new Comida(nome, preco, id, qtd, tipo, categoria, peso, tam_pacote);
        }else{
            cout << "Tipo de produto inv�lido" << endl;
            return;
        }
       
        produtos.push_back(prod);
        //cout << "tellg() final " << arq.tellg() << endl;
        //cout << "produtos.size() = " << produtos.size() << endl;
    }
    arq.close();
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
                salvaEstoque();
                break;
            case 3:
                atualizarProduto();
                salvaEstoque();
                break;
            case 4:
                deletarProduto();
                salvaEstoque();
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
