#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;


class ILNAutenticacao;
class ILNUsuario;


class IUAutenticacao //Apresentação IU
{
public:
    virtual ResultadoAutenticacao autenticar() throw(runtime_error) = 0;
    virtual void setCntrLNAutenticacao(ILNAutenticacao *) = 0;
    virtual ~IUAutenticacao() {}
};
class ILNAutenticacao //Serviço LN
{
public:
    virtual Resultado autenticar(const Identificador&, const Senha&) throw(runtime_error)= 0;
    virtual ~ILNAutenticacao() {}
};

class IUUsuario
{
public:
    virtual void executar(const Identificador&) throw(runtime_error) = 0;
    virtual void setCntrLNUsuario(ILNUsuario *) = 0;
    virtual ~IUUsuario() {}
};
class ILNUsuario
{
public:
    virtual Resultado incluir(const Usuario&) throw(runtime_error) = 0;
    virtual Resultado remover(const Identificador&) throw(runtime_error) = 0;
    virtual ResultadoUsuario pesquisar(const Identificador&) throw(runtime_error) = 0;
    virtual Resultado editar(const Usuario&) throw(runtime_error) = 0;
    virtual ~ILNUsuario() {}
};

#endif // INTERFACES_H_INCLUDED
