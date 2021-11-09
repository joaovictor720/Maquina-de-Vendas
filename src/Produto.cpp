#include "Produto.h"

Produto::Produto()
{
    //ctor
}

Produto::~Produto()
{
    //dtor
}

void Produto::setNome(std::string nome){
    this->nome = nome;
}
void Produto::setPreco(double preco){
    this->preco = preco;
}
void Produto::setValidade(std::string val){
    validade = val;
}
void Produto::setID(int id){
    this->id = id;
}
void Produto::setQtd(int qtd){
    this->qtd = qtd;
}

std::string Produto::getNome(){
    return nome;
}
double Produto::getPreco(){
    return preco;
}
std::string Produto::getValidade(){
    return validade;
}
int Produto::getID(){
    return id;
}
int Produto::getQtd(){
    return qtd;
}
