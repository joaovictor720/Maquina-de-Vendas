#include "Bebida.h"

Bebida::Bebida()
{
    //ctor
}

Bebida::~Bebida()
{
    //dtor
}

void Bebida::setVolume(double vol){
    volume = vol;
}
void Bebida::setTipo(std::string tipo){
    this->tipo = tipo;
}

double Bebida::getVolume(){
    return volume;
}
std::string Bebida::getTipo(){
    return tipo;
}
