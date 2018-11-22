
#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"
#include "entidades.h"
#include "containers.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>


class ComandoIUUsuario {

public:
    virtual void executar(ILNUsuario*) throw(runtime_error) = 0;
    virtual ~ComandoIUUsuario(){}
};

class ComandoIUUsuarioIncluir:public ComandoIUUsuario {
public:
    void executar(ILNUsuario*) throw(runtime_error);
};

class ComandoIUUsuarioRemover:public ComandoIUUsuario {
    void executar(ILNUsuario*) throw(runtime_error);
};

class ComandoIUUsuarioPesquisar:public ComandoIUUsuario {
    void executar(ILNUsuario*) throw(runtime_error);
};

class ComandoIUUsuarioEditar:public ComandoIUUsuario {
    void executar(ILNUsuario*) throw(runtime_error);
};

#endif // COMANDOS_H_INCLUDED

