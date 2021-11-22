#ifndef CONTROLEESTOQUE_H
#define CONTROLEESTOQUE_H

#include "Maquina.h"

class ControleEstoque : virtual public Maquina
{
    public:
        ControleEstoque();
        virtual ~ControleEstoque();

        void carregarEstoque();
        void salvaEstoque();
};

#endif // CONTROLEESTOQUE_H
