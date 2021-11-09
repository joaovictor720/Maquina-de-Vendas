#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto
{
    public:
        Produto();
        virtual ~Produto()=0;

        // setters
        void setNome(std::string nome);

    protected:
        std::string nome;
        double preco;
        std::string validade;
        int id;
        int qtd;
};

#endif // PRODUTO_H
