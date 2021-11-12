#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto
{
    public:
        Produto();
        virtual ~Produto() = 0;

        virtual void setVolume(double vol){}
        virtual void setPeso(double peso){}
        virtual void setTamPacote(std::string tamanho){}

        virtual double getVolume(){return 0;}
        virtual double getPeso(){return 0;}
        virtual std::string getTamPacote(){return "";}

        void decQtd();

        // setters
        void setNome(std::string nome);
        void setPreco(double preco);
        void setID(int id);
        void setQtd(int qtd);
        void setTipo(char tipo);
        void setCategoria(std::string categoria);

        // getters
        std::string getNome();
        double getPreco();
        int getID();
        int getQtd();
        char getTipo();
        std::string getCategoria();

    protected:
        std::string nome;
        double preco;
        int id;
        int qtd;
        char tipo;
        std::string categoria;
};

#endif // PRODUTO_H
