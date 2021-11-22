#include "Maquina.h"

Maquina::Maquina()
{
    //ctor
}

Maquina::~Maquina()
{
    //dtor
}
/*
void Maquina::venderProduto(unsigned long id){
    for (unsigned long i = 0; i < produtos.size(); i++){
        if (produtos[i]->getID() == id){
            if (produtos[i]->getQtd() <= 0){
                throw ProdutoEsgotadoException();
            }
            apurado += produtos[i]->getPreco();
            produtos[i]->decQtd();
            return;
        }
    }
    cout << "Produto não existe" << endl;
    usleep(DELAY);
}
void Maquina::cadastrarProduto(){
    string nome, tam_pacote, categoria, sabor;
    char tipo;
    double preco;
    unsigned long id, qtd, volume, peso;
    Produto *prod;

    cout << "Nome do produto: ";
    getline(cin, nome);
    cout << "ID: ";
    cin >> id;
    cout << "Preco: R$ ";
    cin >> preco;
    cout << "Quantidade: ";
    cin >> qtd;
    cin.ignore();
    cout << "Bebida ou Comida <-> [B]-[b] ou [C]-[c]: ";
    cin >> tipo;
    cin.ignore();
    cout << "Categoria: ";
    getline(cin, categoria);
    cout << "Sabor ( '-' para nenhum): ";
    getline(cin, sabor);
    if (tipo == 'b' || tipo == 'B'){
        cout << "Volume (em mL): ";
        cin >> volume;
    } else if (tipo == 'c' || tipo == 'C'){
        cout << "Peso (em g): ";
        cin >> peso;
        cin.ignore();
    }

    if (tipo == 'b' || tipo == 'B')
        prod = new Bebida(nome, preco, id, qtd, tipo, categoria, sabor, volume);
    else if (tipo == 'c' || tipo == 'C')
        prod = new Comida(nome, preco, id, qtd, tipo, categoria, sabor, peso);

    produtos.push_back(prod);
}

void Maquina::atualizarProduto(){
    string opcao, sabor;
    double preco;
    bool produtoExiste = false, produtoTemSabor = true;
    int qtd;

    mostrarOpcoes();

    cout << "Informe o nome do produto a atualizar: ";
    getline(cin, opcao);

    for (int i = 0; i < produtos.size(); i++){
        if (produtos[i]->getNome().find(opcao) != string::npos){
            produtoExiste = true;
            if (produtos[i]->getSabor() == "-"){
                produtoTemSabor = false;
            }
        }
    }
    if (!produtoExiste){
        cout << "Produto nao existe" << endl;
        usleep(DELAY);
        return;
    }

    cout << "Novo preco (0 para manter): ";
    cin >> preco;

    cout << "Quantidade adicionada (0 para manter): ";
    cin >> qtd;
    cin.ignore();
    if (produtoTemSabor && (qtd != 0) ){
        cout << "Qual sabor sera adicionado: ";
        getline(cin, sabor);
    }

    for (int i = 0; i < produtos.size(); i++){
        if (produtos[i]->getNome().find(opcao) != string::npos){
            if (preco != 0){
                produtos[i]->setPreco(preco);
            }
            if (produtos[i]->getSabor() == sabor || produtos[i]->getSabor() == "-"){
                produtos[i]->addQtd(qtd);
            }
        }
    }
}

void Maquina::deletarProduto(){
    int opcao;

    mostrarOpcoes();

    cout << "Informe a opcao a deletar (0 para sair): ";
    cin >> opcao;
    if (opcao == 0){
        return;
    }
    if (opcao < 0 || opcao > produtos.size()){
        cout << "Opcao invalida" << endl;
        usleep(DELAY);
        return;
    }

    produtos.erase(produtos.begin() + (opcao - 1));
}
*/
/*
void Maquina::mostrarOpcoes(){
    for (unsigned long i = 0; i < produtos.size(); i++){
        cout << "=========================================" << endl;
        cout << i+1 << " - " << produtos[i]->getNome() << " - R$ " << produtos[i]->getPreco() << endl;
        cout << "Sabor: " << produtos[i]->getSabor() << endl;
        cout << "Quantidade: " << produtos[i]->getQtd() << endl;

        if (produtos[i]->getTipo() == 'b' || produtos[i]->getTipo() == 'B'){
            cout << "Volume: " << produtos[i]->getVolume() << " mL" << endl;
        }else if (produtos[i]->getTipo() == 'c' || produtos[i]->getTipo() == 'C'){
            cout << "Peso: " << produtos[i]->getPeso() << " g" << endl;
        }
        cout << "-----------------------------------------\n" << endl;
    }
}
void Maquina::mostrarEstoque(){
    cout << fixed << setprecision(2);
    for (unsigned long i = 0; i < produtos.size(); i++){
        cout << "-----------------------------------------" << endl;
        cout << "Nome: " << produtos[i]->getNome() << endl;
        cout << "ID: " << produtos[i]->getID() << endl;
        cout << "Preco: R$ " << produtos[i]->getPreco() << endl;
        cout << "Quantidade: " << produtos[i]->getQtd() << endl;
        cout << "Tipo: " << produtos[i]->getTipo() << endl;
        cout << "Categoria: " << produtos[i]->getCategoria() << endl;
        cout << "Sabor: " << produtos[i]->getSabor() << endl;

        if (produtos[i]->getTipo() == 'b' || produtos[i]->getTipo() == 'B'){
            cout << "Volume: " << produtos[i]->getVolume() << " mL" << endl;
        }else if (produtos[i]->getTipo() == 'c' || produtos[i]->getTipo() == 'C'){
            cout << "Peso: " << produtos[i]->getPeso() << " g" << endl;
        }

        cout << "-----------------------------------------\n" << endl;
    }
}
*/
void Maquina::desligar(){
    throw Desligamento();
}
/*
void Maquina::controleApurado(){
    int opcao;
    double saque;
    while (true){
        system("cls");
        cout << "Apurado: R$ " << apurado << endl;
        cout << "Voce deseja sacar o dinheiro:" << endl;
        cout << "[1] SIM - [0] SAIR" << endl;
        cin >> opcao;
        if (opcao){
            cout << "Digite o saque: R$ ";
            cin >> saque;
            if (saque > apurado || saque < 0){
                cout << "Nao foi possivel realizar operacao" << endl;
                usleep(DELAY);
            }else{
                apurado -= saque;
            }
        }else{
            salvarApurado();
            return;
        }
        salvarApurado();
    }
}

void Maquina::salvarApurado(){
    ofstream arq = ofstream("apurado.txt", ios::out | ios::trunc);
    if (!arq.is_open()){
        cout << "Falha ao criar/abrir apurado" << endl;
        usleep(DELAY);
        return;
    }

    arq << apurado;
    arq.close();
}

void Maquina::carregarApurado(){
    ifstream arq = ifstream("apurado.txt");
    if (!arq.is_open()){
        cout << "Falha ao abrir apurado" << endl;
        usleep(DELAY);
        return;
    }

    arq >> apurado;
    arq.close();
}
*/
