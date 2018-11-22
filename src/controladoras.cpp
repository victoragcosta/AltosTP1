#include "controladoras.h"
#include "comandos.h"
#include "entidades.h"

ContainerUsuario CntrLNUsuario::container;

ResultadoAutenticacao CntrIUAutenticacao::autenticar() throw(runtime_error)
{

    ResultadoAutenticacao resultadoAutenticacao;
    Resultado resultado;

    Identificador *identificador;
    Senha *senha;

    identificador = new Identificador();
    senha = new Senha();

    string entrada;

    while(true)
    {
        try
        {
            cout << "Digite o identificador : ";
            cin >> entrada;
            identificador->setIdentificador(entrada);
            cout << "Digite a senha         : ";
            cin >> entrada;
            senha->setSenha(entrada);
            break;
        }
        catch (const invalid_argument &exp)
        {
            cout << endl << "Dado em formato incorreto." << endl;
        }
    }

    resultado = cntrLNAutenticacao->autenticar(*identificador, *senha);

    if(resultado.getValor() == ResultadoAutenticacao::FALHA)
    {
        cout << endl << "Falha na autenticacao." << endl;
    }

    resultadoAutenticacao.setValor(resultado.getValor());
    resultadoAutenticacao.setIdentificador(*identificador);

    return resultadoAutenticacao;
}


void CntrIUUsuario::executar(const Identificador &identificador) throw(runtime_error)
{
    ComandoIUUsuario *comando;
    int opcao;
    while(true)
    {
        cout << endl << "Gerenciamento de Usuario." << endl << endl;
        cout << "Incluir   - " << INCLUIR << endl;
        cout << "Remover   - " << REMOVER << endl;
        cout << "Pesquisar - " << PESQUISAR << endl;
        cout << "Editar    - " << EDITAR << endl;
        cout << "Retornar  - " << RETORNAR << endl << endl;
        cout << "Selecione uma opcao :";
        cin >> opcao;
        switch(opcao)
        {
        case INCLUIR:
            comando = new ComandoIUUsuarioIncluir();
            comando->executar(cntrLNUsuario);
            delete comando;
            break;
        case REMOVER:
            comando = new ComandoIUUsuarioRemover();
            comando->executar(cntrLNUsuario);
            delete comando;
            break;
        case PESQUISAR:
            comando = new ComandoIUUsuarioPesquisar();
            comando->executar(cntrLNUsuario);
            delete comando;
            break;
        case EDITAR:
            comando = new ComandoIUUsuarioEditar();
            comando->executar(cntrLNUsuario);
            delete comando;
            break;
        }
        if(opcao == RETORNAR)
        {
            break;
        }
    }

    return;
}

Resultado CntrLNAutenticacao::autenticar(const Identificador &identificador, const Senha &senha) throw(runtime_error)
{
    Usuario usuario;
    ResultadoUsuario resultado;
    Resultado retorno;

    CntrLNUsuario *cntrLNUsuario = new CntrLNUsuario();
    resultado = cntrLNUsuario->pesquisar(identificador);
    delete cntrLNUsuario;

    usuario = resultado.getUsuario();
    if(usuario.getSenha().getSenha() == senha.getSenha())
    {
        retorno.setValor(Resultado::SUCESSO);
    }
    else
    {
        retorno.setValor(Resultado::FALHA);
    }

    return retorno;
}

Resultado CntrLNUsuario::incluir(const Usuario &usuario) throw(runtime_error)
{
    Resultado resultado = container.incluir(usuario);
    return resultado;
}

Resultado CntrLNUsuario::remover(const Identificador &identificador) throw(runtime_error)
{
    Resultado resultado = container.remover(identificador);
    return resultado;
}

ResultadoUsuario CntrLNUsuario::pesquisar(const Identificador &identificador) throw(runtime_error)
{
    ResultadoUsuario resultado = container.pesquisar(identificador);
    return resultado;
}

Resultado CntrLNUsuario::editar(const Usuario &usuario) throw(runtime_error)
{
    Usuario aux = Usuario(usuario);

    Resultado resultado = container.remover(aux.getIdentificador());
    if(resultado.getValor() == Resultado::SUCESSO){
        resultado = container.incluir(usuario);
    }
    return resultado;
}
