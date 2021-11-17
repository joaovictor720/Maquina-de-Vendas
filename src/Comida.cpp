#include "Comida.h"

Comida::Comida()
{
    //ctor
}

Comida::Comida(std::string nome, double preco, int id, int qtd, char tipo, std::string categoria,
               double peso, std::string tam_pacote)
: Produto(nome, preco, id, qtd, tipo, categoria)
{
    this->peso = peso;
    this->tam_pacote = tam_pacote;
}

Comida::~Comida()
{
    //dtor
}

void Comida::setPeso(double peso){
    this->peso = peso;
}
void Comida::setTamPacote(std::string tamanho){
    tam_pacote = tamanho;
}

double Comida::getPeso(){
    return peso;
}
std::string Comida::getTamPacote(){
    return tam_pacote;
}
