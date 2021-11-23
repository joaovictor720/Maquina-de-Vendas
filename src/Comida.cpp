#include "Comida.h"

Comida::Comida()
{
    //ctor
}

Comida::Comida(std::string nome, double preco, std::string id, int qtd, char tipo, std::string categoria, std::string sabor,
               unsigned long peso)
: Produto(nome, preco, id, qtd, tipo, categoria, sabor)
{
    this->peso = peso;
}

Comida::~Comida()
{
    //dtor
}

void Comida::setPeso(unsigned long peso){
    this->peso = peso;
}

unsigned long Comida::getPeso(){
    return peso;
}
