#ifndef MAQUINA_H
#define MAQUINA_H

#include <vector>
#include "Produto.h"

class Maquina
{
    public:
        Maquina();
        virtual ~Maquina();

        void venderProduto(int id);
        void cadastrarProduto();
        void mostrarOpcoes();
        void mostrarEstoque();

    private:
        std::vector<Produto*> produtos;
        double apurado;
};

#endif // MAQUINA_H
