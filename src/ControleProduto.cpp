#include "ControleProduto.h"

ControleProduto::ControleProduto()
{
    //ctor
}

ControleProduto::~ControleProduto()
{
    //dtor
}

void ControleProduto::venderProduto(std::string id){
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
    cout << "Produto não existe." << endl;
    usleep(DELAY);
}
void ControleProduto::cadastrarProduto(){
    string nome, tam_pacote, categoria, sabor, id;
    char tipo;
    double preco;
    unsigned long qtd, volume, peso;
    Produto *prod;

    cout << "Nome do produto: ";
    getline(cin, nome);
    cout << "ID: ";
    getline(cin, id);
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
    cout << "Sabor ( - para nenhum): ";
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
void ControleProduto::atualizarProduto(){
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
        cout << "Produto nao existe." << endl;
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
void ControleProduto::deletarProduto(){
    int opcao;

    mostrarOpcoes();

    cout << "Informe a opcao a deletar (0 para sair): ";
    cin >> opcao;
    if (opcao == 0){
        return;
    }
    if (opcao < 0 || opcao > produtos.size()){
        cout << "Opcao invalida." << endl;
        usleep(DELAY);
        return;
    }

    produtos.erase(produtos.begin() + (opcao - 1));
}
