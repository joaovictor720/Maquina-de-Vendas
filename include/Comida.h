#ifndef COMIDA_H
#define COMIDA_H

#include <Produto.h>


class Comida : public Produto
{
    public:
        Comida();
        virtual ~Comida();

        // setters
        void setPeso(double peso);
        void setTamPacote(std::string tamanho);

        // getters
        double getPeso();
        std::string getTamPacote();

    private:
        double peso;
        std::string tam_pacote;
};

#endif // COMIDA_H
