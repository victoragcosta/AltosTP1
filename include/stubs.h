#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.h"
#include <stdexcept>
#include <iostream>
#include <string.h>

using namespace std;


class StubLNAutenticacao:public ILNAutenticacao{
public:
    const string TRIGGER_FALHA        = "celia";
    const string TRIGGER_ERRO_SISTEMA = "luisa";
    Resultado autenticar(const Identificador&, const Senha&) throw(runtime_error);
};




class StubLNUsuario:public ILNUsuario{  // classe implementa a interface.

public:

    // Defini��es de valores a serem usados como gatilhos para notifica��es de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    Resultado incluir(const Usuario&) throw(runtime_error);
    Resultado remover(const Identificador&) throw(runtime_error);
    ResultadoUsuario pesquisar(const Identificador&) throw(runtime_error);
    Resultado editar(const Usuario&) throw(runtime_error);
};

#endif // STUBS_H_INCLUDED
