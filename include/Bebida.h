#ifndef BEBIDA_H
#define BEBIDA_H

#include <Produto.h>


class Bebida : public Produto
{
    public:
        Bebida();
        Bebida(std::string nome, double preco, std::string id, int qtd, char tipo, std::string categoria, std::string sabor,
               int volume);
        virtual ~Bebida();

        // setters
        void setVolume(int vol);

        // getters
        int getVolume();

    private:
        int volume;
};

#endif // BEBIDA_H
