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
}
void Maquina::cadastrarProduto(){
    string nome, tam_pacote, categoria;
    char tipo;
    double preco, volume, peso;
    int id, qtd;
    Produto *prod;
    ofstream arq = ofstream("..\\estoque.txt", ios::out | ios::app);
    if (!arq.is_open()){
        cout << "Falha ao abrir arquivo" << endl;
        return;
    }

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
        prod = new Bebida();
    else if (tipo == 'c' || tipo == 'C')
        prod = new Comida();

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

    arq << nome << "\n"
        << id << "\n"
        << preco << "\n"
        << qtd << "\n"
        << tipo << "\n";
    if (tipo == 'b' || tipo == 'B'){
        arq << volume << endl;
    }else if (tipo == 'c' || tipo == 'C'){
        arq << peso << "\n"
            << tam_pacote << endl;
    }
    arq.close();
}
void mostrarOpcoes(){
    for (int i = 0; i < 2; i++)
        1*1;

    return;
}
void mostrarEstoque(){}
