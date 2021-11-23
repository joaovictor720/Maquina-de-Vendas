#include "Produto.h"

Produto::Produto()
{
    //ctor
}

Produto::Produto(std::string nome, double preco, std::string id, int qtd, char tipo, std::string categoria, std::string sabor){
    this->nome = nome;
    this->preco = preco;
    this->id = id;
    this->qtd = qtd;
    this->tipo = tipo;
    this->categoria = categoria;
    this->sabor = sabor;
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
void Produto::setID(std::string id){
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
void Produto::setSabor(std::string sabor){
    this->sabor = sabor;
}
void Produto::addQtd(int qtd){
    this->qtd += qtd;
}

std::string Produto::getNome(){ return nome; }
double Produto::getPreco(){ return preco; }
std::string Produto::getID(){ return id; }
int Produto::getQtd(){ return qtd; }
char Produto::getTipo(){ return tipo; }
std::string Produto::getCategoria(){ return categoria; }
std::string Produto::getSabor(){ return sabor; }
