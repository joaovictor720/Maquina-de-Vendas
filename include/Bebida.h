#ifndef BEBIDA_H
#define BEBIDA_H

#include <Produto.h>


class Bebida : public Produto
{
    public:
        Bebida();
        Bebida(std::string nome, double preco, int id, int qtd, char tipo, std::string categoria,
               double volume);
        virtual ~Bebida();

        // setters
        void setVolume(double vol);

        // getters
        double getVolume();

    private:
        double volume;
};

#endif // BEBIDA_H
