#ifndef EXIBIDOR_H
#define EXIBIDOR_H

#include "Maquina.h"

class Exibidor : virtual public Maquina
{
    public:
        Exibidor();
        virtual ~Exibidor();

        void mostrarOpcoes();
        void mostrarEstoque();
};

#endif // EXIBIDOR_H
