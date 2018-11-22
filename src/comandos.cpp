#include "comandos.h"

void ComandoIUUsuarioIncluir::executar(ILNUsuario* cntrLNUsuario) throw(runtime_error)
{
	ContainerUsuario container;
    Resultado resultado;

    Identificador *identificador;
	Usuario *usuario;

    identificador = new Identificador();
    usuario = new Usuario();

    string valor;

    while(true)
    {
        try
        {
            cout << "Digite o identificador: ";
            cin >> valor;
            identificador->setIdentificador(valor);
            usuario->setIdentificador(*identificador);
            break;
        }
        catch(invalid_argument &exp)
        {
            cout << "Identificador com formato incorreto" << endl;
        }
    }

    resultado = container.incluir(*usuario);
    //resultado = cntrLNUsuario->incluir(*usuario);

    if(resultado.getValor() == Resultado::SUCESSO)
    {
        cout << "Sucesso na execucao da operacao" << endl;
    }
    else
    {
        cout << "Falha na execucao da operacao" << endl;
    }
}


void ComandoIUUsuarioRemover::executar(ILNUsuario* cntrLNUsuario) throw(runtime_error)
{
	ContainerUsuario container;
    Resultado resultado;
    Identificador identificador;
    while(true)
    {
        try
        {
            string valor;
            cout << "Digite o identificador: ";
            cin >> valor;
            identificador.setIdentificador(valor);
            break;
        }
        catch(invalid_argument &exp)
        {
            cout << "Identificador com formato incorreto" << endl;
        }
    }

    resultado = container.remover(identificador);
    //resultado = cntrLNUsuario->remover(identificador);

    if(resultado.getValor() == Resultado::SUCESSO)
    {
        cout << "Sucesso na execucao da operacao" << endl;
    }
    else
    {
        cout << "Falha na execucao da operacao" << endl;
    }

}


void ComandoIUUsuarioPesquisar::executar(ILNUsuario* cntrLNUsuario) throw(runtime_error)
{
    ResultadoUsuario resultado;
    Identificador identificador;
    resultado = cntrLNUsuario->pesquisar(identificador);
    if(resultado.getValor() == Resultado::SUCESSO)
    {
        cout << "Sucesso na execucao da operacao" << endl;
    }
    else
    {
        cout << "Falha na execucao da operacao" << endl;
    }
}


void ComandoIUUsuarioEditar::executar(ILNUsuario* cntrLNUsuario) throw(runtime_error)
{
    Resultado resultado;
    Usuario usuario;
    resultado.setValor(Resultado::SUCESSO);
    cntrLNUsuario->editar(usuario);
    if(resultado.getValor() == Resultado::SUCESSO)
    {
        cout << "Sucesso na execucao da operacao" << endl;
    }
    else
    {
        cout << "Falha na execucao da operacao" << endl;
    }
}

