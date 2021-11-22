#ifndef PRODUTOESGOTADOEXCEPTION_H
#define PRODUTOESGOTADOEXCEPTION_H

#include <exception>

class ProdutoEsgotadoException : public std::exception
{
    public:
        ProdutoEsgotadoException();
        virtual ~ProdutoEsgotadoException();
};

#endif // PRODUTOESGOTADOEXCEPTION_H
