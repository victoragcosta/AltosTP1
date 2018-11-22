
#include <stdexcept>
#include <iostream>
#include <string>

#include "stubs.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladoras.h"

using namespace std;

int main()
{
    IUAutenticacao  *cntrIUAutenticacao;
    IUUsuario      *cntrIUUsuario;

    cntrIUAutenticacao = new CntrIUAutenticacao();
    cntrIUUsuario = new CntrIUUsuario();

    ILNAutenticacao *cntrLNAutenticacao;
    ILNUsuario      *cntrLNUsuario;

    cntrLNAutenticacao = new CntrLNAutenticacao();
    cntrLNUsuario = new CntrLNUsuario();

    cntrIUAutenticacao->setCntrLNAutenticacao(cntrLNAutenticacao);
    cntrIUUsuario->setCntrLNUsuario(cntrLNUsuario);

    //cout << "Identificador invalido          = " << Identificador::MATRICULA_INVALIDA << endl;
    //cout << "Senha invalida              = " << Senha::SENHA_INVALIDA << endl;

    ResultadoAutenticacao resultado;

    while(true){
        //cout << endl << "Tela de apresentacao de sistema." << endl;
        try{
            resultado = cntrIUAutenticacao->autenticar();

            if(resultado.getValor() == ResultadoAutenticacao::SUCESSO) {
                break;
            }

        }
        catch(const runtime_error &exp){
                 cout << "Erro de sistema." << endl;
        }
    }
    try{
		cout << "3" << endl;
        cntrIUUsuario->executar(resultado.getIdentificador());
    }
    catch(const runtime_error &exp){
        cout << "Erro de sistema." << endl;
    }

    delete cntrIUAutenticacao;
    delete cntrIUUsuario;
    delete cntrLNAutenticacao;
    delete cntrLNUsuario;

    return 0;
}
