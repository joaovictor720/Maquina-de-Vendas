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
         << "3 - Atualizar precos\n"
         << "4 - Remover produto\n"
         << "5 - Controle de apurado\n"
         << "6 - Sair\n"
         << "7 - Desligar maquina\n" << endl;
}

string Menu::carregarSenha(){
    ifstream arq = ifstream("SenhaVendingMachine.dat");
    if (!arq.is_open()){
        cout << "Falha ao abrir binario da senha" << endl;
        usleep(DELAY);
        return 0;
    }
    char senha[20];

    arq.read(senha, sizeof(senha));
    string s(senha);
    return s;
}

void Menu::salvaEstoque(){
    ofstream arq = ofstream("estoque.txt", ios::out | ios::trunc);

    if (!arq.is_open()){
        cout << "Falha ao abrir arquivo" << endl;
        usleep(DELAY);
        return;
    }

    for (int i = 0; i < produtos.size(); i++){
        arq << produtos[i]->getNome() << endl;
        arq << produtos[i]->getID() << endl;
        arq << produtos[i]->getPreco() << endl;
        arq << produtos[i]->getQtd() << endl;
        arq << produtos[i]->getTipo() << endl;
        arq << produtos[i]->getCategoria() << endl;
        arq << produtos[i]->getSabor() << endl;

        if (produtos[i]->getTipo() == 'b' || produtos[i]->getTipo() == 'B'){
            arq << produtos[i]->getVolume() << endl;
        } else if (produtos[i]->getTipo() == 'c' || produtos[i]->getTipo() == 'C'){
            arq << produtos[i]->getPeso() << endl;
        }
    }
}

void Menu::carregarEstoque(){
    string nome, tam_pacote, categoria, sabor;
    char tipo;
    double preco;
    unsigned long id, qtd, volume, peso;
    Produto *prod;
    ifstream arq = ifstream("estoque.txt", ios::in);
    if (!arq.is_open()){
        cout << "Falha ao ler o arquivo." << endl;
        usleep(DELAY);
        return;
    }

    while (!arq.fail() && !arq.bad() && !arq.eof()){
        getline(arq, nome);
        if (nome == ""){
            break;
        }

        arq >> id;

        arq >> preco;

        arq >> qtd;

        arq >> tipo;
        arq.ignore();

        getline(arq, categoria);

        getline(arq, sabor);

        if (tipo == 'b' || tipo == 'B'){
            arq >> volume;
            arq.ignore();

            prod = new Bebida(nome, preco, id, qtd, tipo, categoria, sabor, volume);
        } else if (tipo == 'c' || tipo == 'C'){
            arq >> peso;
            arq.ignore();

            prod = new Comida(nome, preco, id, qtd, tipo, categoria, sabor, peso);
        }else{
            cout << "Tipo de produto inválido" << endl;
            usleep(DELAY);
            return;
        }

        produtos.push_back(prod);
    }
    cout << "Estoque carregado" << endl;
    arq.close();
    usleep(DELAY);
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
                cout << "Saindo..." << endl;
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
                    cout << "Senha invalida" << endl;
                    usleep(DELAY);
                }
            }
            continue; // volta a escolha de produto
        }
        if (opcao <= 0 || opcao > produtos.size()){
            cout << "Opcao invalida" << endl;
            usleep(DELAY);
            continue;
        }

        cout << "Quantos \"" << produtos[ opcao-1 ]->getNome() << "\"";
        if (produtos[ opcao-1 ]->getSabor() != "-"){
            cout << " Sabor \"" << produtos[ opcao-1 ]->getSabor() << "\"";
        }
        cout << " voce quer: ";
        cin >> num_compras;
        int id = produtos[ opcao-1 ]->getID();
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
