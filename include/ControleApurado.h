#ifndef CONTROLEAPURADO_H
#define CONTROLEAPURADO_H

#include "Maquina.h"

class ControleApurado : virtual public Maquina
{
    public:
        ControleApurado();
        virtual ~ControleApurado();

        void salvarApurado();
        void carregarApurado();

    protected:
        void controleApurado();
        double apurado;
};

#endif // CONTROLEAPURADO_H
