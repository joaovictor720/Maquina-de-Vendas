#include "Bebida.h"

Bebida::Bebida()
{
    //ctor
}

Bebida::Bebida(std::string nome, double preco, int id, int qtd, char tipo, std::string categoria,
               double volume)
: Produto(nome, preco, id, qtd, tipo, categoria)
{
    this->volume = volume;
}

Bebida::~Bebida()
{
    //dtor
}

void Bebida::setVolume(double vol){
    volume = vol;
}

double Bebida::getVolume(){
    return volume;
}
