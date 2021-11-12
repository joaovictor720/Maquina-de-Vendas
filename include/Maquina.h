#ifndef MAQUINA_H
#define MAQUINA_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Produto.h"
#include "Bebida.h"
#include "Comida.h"
#include "ProdutoEsgotadoException.h"
using namespace std;

class Maquina
{
    public:
        Maquina();
        virtual ~Maquina();

        void venderProduto(int id);
        void cadastrarProduto();
        void mostrarOpcoes();
        void mostrarEstoque();

    protected: vector<Produto*> produtos;

    private: double apurado;
};

#endif // MAQUINA_H
