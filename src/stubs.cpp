#include "stubs.h"

Resultado StubLNAutenticacao::autenticar(const Identificador &identificador, const Senha &senha) throw(runtime_error)
{
    cout << endl << "StubLNAutenticacao::autenticar" << endl ;
    cout << "Identificador = " << identificador.getIdentificador() << endl ;
    cout << "Senha     = " << senha.getSenha()     << endl ;
    ResultadoAutenticacao resultado;

    if(identificador.getIdentificador() == TRIGGER_FALHA)
    {
        resultado.setValor(ResultadoAutenticacao::FALHA);
    }
    else if (identificador.getIdentificador() == TRIGGER_ERRO_SISTEMA)
    {
        throw runtime_error("Erro de sistema");
    }
    else
    {
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
    }

    return resultado;
}




Resultado StubLNUsuario::incluir(const Usuario &usuario) throw(runtime_error)
{
    cout << endl << "StubLNUsuario::incluir" << endl ;
    Resultado resultado;
    resultado.setValor(Resultado::SUCESSO);
	/*
    if(usuario.getIdentificador().getIdentificador() == TRIGGER_FALHA)
    {
        resultado.setValor(ResultadoAutenticacao::FALHA);
    }
    else if (usuario.getIdentificador().getIdentificador() == TRIGGER_ERRO_SISTEMA)
    {
        throw runtime_error("Erro de sistema");
    }
    else
    {
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
    }
    */
    resultado.setValor(ResultadoAutenticacao::SUCESSO);

    return resultado;
}

Resultado StubLNUsuario::remover(const Identificador &identificador) throw(runtime_error)
{
    cout << endl << "StubLNUsuario::remover" << endl ;
    Resultado resultado;
    resultado.setValor(Resultado::SUCESSO);

	/*
    if(identificador.getIdentificador() == TRIGGER_FALHA)
    {
        resultado.setValor(ResultadoAutenticacao::FALHA);
    }
    else if (identificador.getIdentificador() == TRIGGER_ERRO_SISTEMA)
    {
        throw runtime_error("Erro de sistema");
    }
    else
    {
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
    }
	*/
    resultado.setValor(ResultadoAutenticacao::SUCESSO);

    return resultado;
}

ResultadoUsuario StubLNUsuario::pesquisar(const Identificador &identificador) throw(runtime_error)
{
    cout << endl << "StubLNUsuario::pesquisar" << endl ;
    ResultadoUsuario resultado;
    resultado.setValor(Resultado::SUCESSO);

    // A seguir devem ser implementados os diferentes comportamentos.
    // Sucesso.
    // Falha.
    // Erro de sistema.

    return resultado;
}

Resultado StubLNUsuario::editar(const Usuario &usuario) throw(runtime_error)
{
    cout << endl << "StubLNUsuario::editar" << endl ;
    Resultado resultado;
    resultado.setValor(Resultado::SUCESSO);

    // A seguir devem ser implementados os diferentes comportamentos.
    // Sucesso.
    // Falha.
    // Erro de sistema.

    return resultado;
}
