#ifndef MAQUINA_H
#define MAQUINA_H
#define DELAY 2500000

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include "Produto.h"
#include "Bebida.h"
#include "Comida.h"
#include "ProdutoEsgotadoException.h"
#include "Desligamento.h"
using namespace std;

class Maquina
{
    public:
        Maquina();
        virtual ~Maquina();

        /*void venderProduto(unsigned long id);
        void cadastrarProduto();
        void atualizarProduto();
        void deletarProduto();*/

        //void mostrarOpcoes();
        //void mostrarEstoque();

        /*void controleApurado();
        void salvarApurado();
        void carregarApurado();*/

    protected:
        void desligar();

        vector<Produto*> produtos;
        //double apurado;
};

#endif // MAQUINA_H
