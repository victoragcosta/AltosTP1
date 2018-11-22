#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"
#include "containers.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

class CntrIUAutenticacao:public IUAutenticacao
{
private:
    ILNAutenticacao *cntrLNAutenticacao;
public:
    ResultadoAutenticacao autenticar() throw(runtime_error);
    void setCntrLNAutenticacao(ILNAutenticacao*);

};

void inline CntrIUAutenticacao::setCntrLNAutenticacao(ILNAutenticacao *cntrLNAutenticacao)
{
    this->cntrLNAutenticacao = cntrLNAutenticacao;
}


class CntrIUUsuario:public IUUsuario
{
private:
    const static int INCLUIR   = 1;
    const static int REMOVER   = 2;
    const static int PESQUISAR = 3;
    const static int EDITAR    = 4;
    const static int RETORNAR  = 5;
    ILNUsuario *cntrLNUsuario;
public:
    void executar(const Identificador&) throw(runtime_error);
    void setCntrLNUsuario(ILNUsuario *cntrLNUsuario)
    {
        this->cntrLNUsuario = cntrLNUsuario;
    }
};

// TODO: Serviço para usuário e para autenticação

class CntrLNAutenticacao:public ILNAutenticacao
{
public:
    Resultado autenticar(const Identificador&, const Senha&) throw(runtime_error);
};

class CntrLNUsuario:public ILNUsuario
{
public:
    static ContainerUsuario container;
    Resultado incluir(const Usuario&) throw(runtime_error);
    Resultado remover(const Identificador&) throw(runtime_error);
    ResultadoUsuario pesquisar(const Identificador&) throw(runtime_error);
    Resultado editar(const Usuario&) throw(runtime_error);
};

#endif // CONTROLADORAS_H_INCLUDED
