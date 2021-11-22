#include "Maquina.h"

Maquina::Maquina()
{
    //ctor
}

Maquina::~Maquina()
{
    //dtor
}

void Maquina::desligar(){
    throw Desligamento();
}
