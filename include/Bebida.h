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
        void setTipo(std::string tipo);

        // getters
        double getVolume();
        std::string getTipo();

    private:
        double volume;
        std::string tipo;
};

#endif // BEBIDA_H
