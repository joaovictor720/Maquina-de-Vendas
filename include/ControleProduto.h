#ifndef CONTROLEPRODUTO_H
#define CONTROLEPRODUTO_H

#include "Maquina.h"
#include "ControleApurado.h"
#include "Exibidor.h"

class ControleProduto : public ControleApurado, public Exibidor
{
    public:
        ControleProduto();
        virtual ~ControleProduto();

        void venderProduto(unsigned long id);

    protected:
        void cadastrarProduto();
        void atualizarProduto();
        void deletarProduto();
};

#endif // CONTROLEPRODUTO_H
