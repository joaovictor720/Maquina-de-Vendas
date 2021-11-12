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

double Bebida::getVolume(){
    return volume;
}
