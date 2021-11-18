#ifndef COMIDA_H
#define COMIDA_H

#include <Produto.h>


class Comida : public Produto
{
    public:
        Comida();
        Comida(std::string nome, double preco, unsigned long id, int qtd, char tipo, std::string categoria, std::string sabor,
               unsigned long peso);
        virtual ~Comida();

        // setters
        void setPeso(unsigned long peso);

        // getters
        unsigned long getPeso();

    private:
        unsigned long peso;
};

#endif // COMIDA_H
