#include "Comida.h"

Comida::Comida()
{
    //ctor
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
