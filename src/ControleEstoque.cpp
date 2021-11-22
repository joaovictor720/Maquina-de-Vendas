#include "ControleEstoque.h"

ControleEstoque::ControleEstoque()
{
    //ctor
}

ControleEstoque::~ControleEstoque()
{
    //dtor
}

void ControleEstoque::salvaEstoque(){
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

void ControleEstoque::carregarEstoque(){
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
            cout << "Tipo de produto inv�lido" << endl;
            usleep(DELAY);
            return;
        }

        produtos.push_back(prod);
    }
    cout << "Estoque carregado" << endl;
    arq.close();
    usleep(DELAY);
}