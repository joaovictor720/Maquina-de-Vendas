#ifndef BEBIDA_H
#define BEBIDA_H

#include <Produto.h>


class Bebida : public Produto
{
    public:
        Bebida();
        virtual ~Bebida();

        // setters
        void setVolume(double vol);

        // getters
        double getVolume();

    private:
        double volume;
};

#endif // BEBIDA_H
