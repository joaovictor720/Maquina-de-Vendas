#include "Produto.h"

Produto::Produto()
{
    //ctor
}

Produto::~Produto()
{
    //dtor
}

void Produto::decQtd(){
    qtd--;
}

void Produto::setNome(std::string nome){
    this->nome = nome;
}
void Produto::setPreco(double preco){
    this->preco = preco;
}
void Produto::setID(int id){
    this->id = id;
}
void Produto::setQtd(int qtd){
    this->qtd = qtd;
}
void Produto::setTipo(char tipo){
    this->tipo = tipo;
}
void Produto::setCategoria(std::string categoria){
    this->categoria = categoria;
}

std::string Produto::getNome(){ return nome; }
double Produto::getPreco(){ return preco; }
int Produto::getID(){ return id; }
int Produto::getQtd(){ return qtd; }
char Produto::getTipo(){ return tipo; }
std::string Produto::getCategoria(){ return categoria; }
