#include "Maquina.h"

Maquina::Maquina()
{
    //ctor
}

Maquina::~Maquina()
{
    //dtor
}

void Maquina::venderProduto(int id){
    for (int i = 0; i < produtos.size(); i++){
        if (produtos[i]->getID() == id){
            if (produtos[i]->getQtd() <= 0){
                throw ProdutoEsgotadoException();
            }
            apurado += produtos[i]->getPreco();
            produtos[i]->decQtd();
            return;
        }
    }
    cout << "Produto n�o existe" << endl;
}
void Maquina::cadastrarProduto(){
    string nome, tam_pacote, categoria;
    char tipo;
    double preco, volume, peso;
    int id, qtd;
    Produto *prod;

    cout << "Nome do produto: ";
    getline(cin, nome);
    cout << "ID: ";
    cin >> id;
    cout << "Preco: ";
    cin >> preco;
    cout << "Quantidade: ";
    cin >> qtd;
    cin.ignore();
    cout << "Bebida ou Comida -> [B]-[b] ou [C]-[c]: ";
    cin >> tipo;
    cin.ignore();
    cout << "Categoria: ";
    getline(cin, categoria);
    if (tipo == 'b' || tipo == 'B'){
        cout << "Volume (em mL): ";
        cin >> volume;
    } else if (tipo == 'c' || tipo == 'C'){
        cout << "Peso (em g): ";
        cin >> peso;
        cin.ignore();
        cout << "Tamanho: ";
        getline(cin, tam_pacote);
    }

    if (tipo == 'b' || tipo == 'B')
        prod = new Bebida(nome, id, preco, qtd, tipo, categoria, volume);
    else if (tipo == 'c' || tipo == 'C')
        prod = new Comida(nome, id, preco, qtd, tipo, categoria, peso, tam_pacote);


    produtos.push_back(prod);

}

void Maquina::atualizarProduto(){
    int opcao;
    double preco;

    mostrarOpcoes();

    cout << "Informe a opcao a atualizar: ";
    cin >> opcao;
    cin.ignore();

    cout << "Novo preco: ";
    cin >> preco;

    if (produtos[opcao - 1]->getTipo() == 'b' || produtos[opcao - 1]->getTipo() == 'B')
        produtos[opcao - 1] = new Bebida(produtos[opcao - 1]->getNome(), produtos[opcao - 1]->getID(), preco, produtos[opcao - 1]->getQtd(), produtos[opcao - 1]->getTipo(), produtos[opcao - 1]->getCategoria(),produtos[opcao - 1]->getVolume() );

    else if (produtos[opcao - 1]->getTipo() == 'c' || produtos[opcao - 1]->getTipo() == 'C')
        produtos[opcao - 1] = new Comida(produtos[opcao - 1]->getNome(), produtos[opcao - 1]->getID(), preco, produtos[opcao - 1]->getQtd(), produtos[opcao - 1]->getTipo(), produtos[opcao - 1]->getCategoria(), produtos[opcao - 1]->getPeso(), produtos[opcao - 1]->getTamPacote());

}

void Maquina::deletarProduto(){
    int opcao;

    mostrarOpcoes();

    cout << "Informe a opcao a deletar: ";
    cin >> opcao;

    produtos.erase(produtos.begin() + (opcao - 1));
}

void Maquina::mostrarOpcoes(){
    for (int i = 0; i < produtos.size(); i++){
        cout << "-----------------------------------------" << endl;
        cout << i+1 << " - " << produtos[i]->getNome() << " - R$ " << produtos[i]->getPreco() << endl;
        cout << "Quantidade: " << produtos[i]->getQtd() << endl;
        cout << "-----------------------------------------\n" << endl;
    }
}
void Maquina::mostrarEstoque(){
    for (int i = 0; i < produtos.size(); i++){
        cout << "-----------------------------------------" << endl;
        cout << "Nome: " << produtos[i]->getNome() << endl;
        cout << "ID: " << produtos[i]->getID() << endl;
        cout << "Preco: " << produtos[i]->getPreco() << endl;
        cout << "Quantidade: " << produtos[i]->getQtd() << endl;
        cout << "Tipo: " << produtos[i]->getTipo() << endl;
        cout << "Categoria: " << produtos[i]->getCategoria() << endl;

        if (produtos[i]->getTipo() == 'b' || produtos[i]->getTipo() == 'B'){
            cout << "Volume: " << produtos[i]->getVolume() << endl;
        }else if (produtos[i]->getTipo() == 'c' || produtos[i]->getTipo() == 'C'){
            cout << "Peso: " << produtos[i]->getPeso() << endl;
            cout << "Tamanho: " << produtos[i]->getTamPacote() << endl;
        }

        cout << "-----------------------------------------\n" << endl;
    }
}
