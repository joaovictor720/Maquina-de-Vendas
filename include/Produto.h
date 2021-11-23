#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto
{
    public:
        Produto();
        Produto(std::string nome, double preco, std::string id, int qtd, char tipo, std::string categoria, std::string sabor);
        virtual ~Produto() = 0;

        virtual void setVolume(int vol){}
        virtual void setPeso(unsigned long peso){}

        virtual int getVolume(){return 0;}
        virtual unsigned long getPeso(){return 0;}

        void decQtd();
        void addQtd(int qtd);

        // setters
        void setNome(std::string nome);
        void setPreco(double preco);
        void setID(std::string id);
        void setQtd(int qtd);
        void setTipo(char tipo);
        void setCategoria(std::string categoria);
        void setSabor(std::string sabor);

        // getters
        std::string getNome();
        double getPreco();
        std::string getID();
        int getQtd();
        char getTipo();
        std::string getCategoria();
        std::string getSabor();

    protected:
        std::string nome;
        double preco;
        std::string id;
        int qtd;
        char tipo;
        std::string categoria;
        std::string sabor;
};

#endif // PRODUTO_H
