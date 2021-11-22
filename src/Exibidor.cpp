#include "Exibidor.h"

Exibidor::Exibidor()
{
    //ctor
}

Exibidor::~Exibidor()
{
    //dtor
}

void Exibidor::mostrarOpcoes(){
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
void Exibidor::mostrarEstoque(){
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
