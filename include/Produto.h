#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto
{
    public:
        Produto();
        virtual ~Produto() = 0;

        // setters
        void setNome(std::string nome);
        void setPreco(double preco);
        void setValidade(std::string val);
        void setID(int id);
        void setQtd(int qtd);

        // getters
        std::string getNome();
        double getPreco();
        std::string getValidade();
        int getID();
        int getQtd();

    protected:
        std::string nome;
        double preco;
        std::string validade;
        int id;
        int qtd;
};

#endif // PRODUTO_H
