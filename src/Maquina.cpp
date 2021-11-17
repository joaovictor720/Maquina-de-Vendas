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
    for (unsigned long long i = 0; i < produtos.size(); i++){
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
}
void Maquina::cadastrarProduto(){
    string nome, tam_pacote, categoria;
    char tipo;
    double preco, volume, peso;
    int id, qtd;
    Produto *prod;
    ofstream arq = ofstream("C:\\Users\\João Victor\\Desktop\\LP1\\Maquina de Vendas - Projeto 3\\estoque.txt", ios::out | ios::app);
    if (!arq.is_open()){
        cout << "Falha ao abrir arquivo" << endl;
        return;
    }

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
        prod = new Bebida(nome, preco, id, qtd, tipo, categoria, volume);
    else if (tipo == 'c' || tipo == 'C')
        prod = new Comida(nome, preco, id, qtd, tipo, categoria, peso, tam_pacote);

    produtos.push_back(prod);

    arq << "\n" << nome << "\n"
        << id << "\n"
        << preco << "\n"
        << qtd << "\n"
        << tipo << "\n"
        << categoria << "\n";
    if (tipo == 'b' || tipo == 'B'){
        arq << volume;
    }else if (tipo == 'c' || tipo == 'C'){
        arq << peso << "\n"
            << tam_pacote;
    }
    arq.close();
}
void Maquina::mostrarOpcoes(){
    //cout << "DENTRO DE mostrarOpcoes()" << endl;
    //cout << "produtos.size() = " << produtos.size() << endl;
    for (unsigned long long i = 0; i < produtos.size(); i++){
        cout << "=========================================" << endl;
        cout << i+1 << " - " << produtos[i]->getNome() << " - R$ " << produtos[i]->getPreco() << endl;
        cout << "Quantidade: " << produtos[i]->getQtd() << endl;
        cout << "-----------------------------------------\n" << endl;
    }
}
void Maquina::mostrarEstoque(){
    //cout << "DENTRO DE mostrarEstoque()" << endl;
    //cout << "produtos.size() = " << produtos.size() << endl;
    cout << fixed << setprecision(2);
    for (unsigned long long i = 0; i < produtos.size(); i++){
        cout << "-----------------------------------------" << endl;
        cout << "Nome: " << produtos[i]->getNome() << endl;
        cout << "ID: " << produtos[i]->getID() << endl;
        cout << "Preco: R$ " << produtos[i]->getPreco() << endl;
        cout << "Quantidade: " << produtos[i]->getQtd() << endl;
        cout << "Tipo: " << produtos[i]->getTipo() << endl;
        cout << "Categoria: " << produtos[i]->getCategoria() << endl;

        if (produtos[i]->getTipo() == 'b' || produtos[i]->getTipo() == 'B'){
            cout << "Volume: " << produtos[i]->getVolume() << " mL" << endl;
        }else if (produtos[i]->getTipo() == 'c' || produtos[i]->getTipo() == 'C'){
            cout << "Peso: " << produtos[i]->getPeso() << endl;
            cout << "Tamanho: " << produtos[i]->getTamPacote() << endl;
        }

        cout << "-----------------------------------------\n" << endl;
    }
}
