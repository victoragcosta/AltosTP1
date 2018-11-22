#include "dominios.h"


// Definições de métodos da classe Agencia.
void Agencia::validar(string agencia) throw (invalid_argument)
{
    int tamanhoString = agencia.size();
    if((tamanhoString != TAM_AGENCIA))
    {
        throw invalid_argument("Quatidade errada de digitos");
    }
    else
    {
        for(int i = 0; i < tamanhoString; i++)
        {
            if(agencia[i] < '0' || agencia[i] > '9')
            {
                throw invalid_argument("Digito inserido invalido");
            }
        }
    }
}
void Agencia::setAgencia(string agencia) throw (invalid_argument)
{
    validar(agencia);
    this->agencia = agencia;
}



// Definições de métodos da classe Banco.
void Banco::validar(string banco) throw (invalid_argument)
{
    int tamanhoString = banco.size();
    if((tamanhoString != TAM_BANCO))
    {
        throw invalid_argument("Quatidade errada de digitos.");
    }
    else
    {
        for(int i = 0; i < tamanhoString; i++)
        {
            if(banco[i] < '0' || banco[i] > '9')
            {
                throw invalid_argument("Digito inserido invalido");
            }
        }
    }
}
void Banco::setBanco(string banco) throw (invalid_argument)
{
    validar(banco);
    this->banco = banco;
}



// Definições de métodos da classe Capacidade.
void Capacidade::validar(int capacidade) throw (invalid_argument)
{
    if((capacidade < CAPACIDADE_MINIMA)||(capacidade > CAPACIDADE_MAXIMA))
        throw invalid_argument("Valor invalido de capacidade.");
}
void Capacidade::setCapacidade(int capacidade) throw (invalid_argument)
{
    validar(capacidade);
    this->capacidade = capacidade;
}



// Definições de métodos da classe Diaria.
void Diaria::validar(float diaria) throw (invalid_argument)
{
    if((diaria < DIARIA_MINIMA)||(diaria > DIARIA_MAXIMA))
        throw invalid_argument("Valor invalido de diaria.");
}
void Diaria::setDiaria(float diaria) throw (invalid_argument)
{
    validar(diaria);
    this->diaria = diaria;
}



// Definições de métodos da classe Data.
void Data::validar(string data) throw (invalid_argument)
{
    int tamanho_vetor = data.size();
    string dia = "00";
    string mes;
    string ano = "0000";
    int dia_int;
    int ano_int;

    if (tamanho_vetor == STRING_VAZIA)
    {
        throw invalid_argument("Nao foi inserido nenhum caractere");
    }

    if(tamanho_vetor > TAM_MAX_DATA)
    {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }

    if(data[2] != '/' || data[6] != '/')
    {
        throw invalid_argument("Formato Invalido. Insira o formato correto: DD/MMM/AAAA");
    }

    for (int i = 0; i < tamanho_vetor; i++)
    {
        if((i < 2 && i > 6) && (data[i] < '0' || data[i] > '9'))
        {
            throw invalid_argument("Caractere invalido inserido");
        }
    }

    for (int i = 0; i < tamanho_vetor; i++)
    {
        if(i == 0 || i == 1)
        {
            dia += data[i];
        }
        if(i == 2 || i == 3 || i==4)
        {
            mes[i-2] = data[i];
        }
        if(i == 7 || i == 8 || i == 9 || i == 10)
        {
            ano += data[i];
        }
    }

    sscanf(dia.c_str(), "%d", &dia_int);
    sscanf(ano.c_str(), "%d", &ano_int);

    //dia_int = atoi(dia);
    //ano_int = atoi(ano);

    if(dia_int > DIA_MAX || dia_int < DIA_MIN)
    {
        throw invalid_argument("DD consiste em um numero de 01 a 31");
    }
    if(ano_int > ANO_MAX || ano_int < ANO_MIN)
    {
        throw invalid_argument("AAAA consiste em um numero de 2000 a 2099");
    }

    bool bissexto = false;
    if((ano_int % 4 == 0 && ano_int % 100 != 0) || (ano_int % 400 == 0))
    {
        bissexto = true;
    }

    if( (bissexto == false && (mes.compare("fev") == 0) && dia_int > 28) ||
            (bissexto == true && (mes.compare("fev") == 0) && dia_int > 29) )
    {
        throw invalid_argument("O Mes de fevereiro possui somente ate 29 dias em anos bissextos");
    }

    if( (mes.compare("abr") == 0)||
            (mes.compare("jun") == 0)||
            (mes.compare("set") == 0)||
            (mes.compare("nov") == 0)&&
            dia_int > 30)
    {
        throw invalid_argument("Os meses de Abril, Junho, Setembro e Novembro possuem ate 30 dias");
    }
}
void Data::setData(string data) throw (invalid_argument)
{
    validar(data);
    this->data = data;
}



// Definições de métodos da classe Validade
void Validade::validar(string validade) throw (invalid_argument)
{
    int tamanho_vetor = validade.size();
    string mes = "\0";
    string ano = "\0";
    int mes_int;
    int ano_int;
    if (tamanho_vetor == STRING_VAZIA)
    {
        throw invalid_argument("Nao foi inserido nenhum caractere");
    }
    if(tamanho_vetor > TAM_MAX_VALIDADE)
    {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }
    if(validade[2] != '/')
    {
        throw invalid_argument("Formato Invalido. Insira o formato correto: MM/AA");
    }
    for (int i = 0; i < tamanho_vetor; i++)
    {
        if((i != 2) && (validade[i] < '0' || validade[i] > '9'))
        {
            throw invalid_argument("Caractere invalido inserido");
        }
    }
    for (int i = 0; i < tamanho_vetor; i++)
    {
        if(i == 0 || i == 1)
        {
            mes += validade[i];
        }
        if(i == 3 || i == 4)
        {
            ano += validade[i];
        }
    }

    char mes_char[3] = "\0";
    mes_char[0] = mes[0];
    mes_char[1] = mes[1];
    mes_int = atoi(mes_char);
    char ano_char[3] = "\0";
    ano_char[0] = ano[0];
    ano_char[1] = ano[1];
    ano_int = atoi(ano_char);

    if(mes_int > MES_MAX || mes_int < MES_MIN)
    {
        throw invalid_argument("MM consiste em um numero de 01 a 12");
    }
    if(ano_int > ANO_MAX || ano_int < ANO_MIN)
    {
        throw invalid_argument("AAAA consiste em um numero de 00 a 99");
    }
}
void Validade::setValidade(string validade) throw (invalid_argument)
{
    validar(validade);
    this->validade = validade;
}



// Definições de métodos da classe Regiao.
void Regiao::validar(string regiao) throw (invalid_argument)
{
    int tamanhoString = regiao.size();
    if((tamanhoString != TAM_REGIAO))
    {
        throw invalid_argument("Quatidade errada de letras");
    }
    bool regiaoValida = 0;
    for(int i = 0; i < 27; i++)
    {
        if(REGIOES_VALIDAS[i].compare(regiao) == 0)
        {
            regiaoValida = 1;
            break;
        }
    }
    if(regiaoValida == 0)
    {
        throw invalid_argument("Regiao invalida.");
    }
}
void Regiao::setRegiao(string regiao) throw (invalid_argument)
{
    validar(regiao);
    this->regiao = regiao;
}



// Definições de métodos da classe Identificador.
void Identificador::validar(string identificador) throw (invalid_argument)
{
    int tamanhoString = identificador.size();
    if((tamanhoString != TAM_IDENTIFICADOR))
    {
        throw invalid_argument("Quatidade errada de caracteres.");
    }
    else
    {
        for(int i = 0; i < tamanhoString; i++)
        {
            if(identificador[i] < 'a' || identificador[i] > 'z')
            {
                throw invalid_argument("Caracter inserido invalido");
            }
        }
    }
}
void Identificador::setIdentificador(string identificador) throw (invalid_argument)
{
    validar(identificador);
    this->identificador = identificador;
}



// Definições de métodos da classe Nome.
void Nome::validar(string nome) throw (invalid_argument)
{
    int tamanho_vetor = nome.size();
    if(tamanho_vetor > TAM_MAX_NOME)
    {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }

    if(tamanho_vetor == STRING_VAZIA)
    {
        throw invalid_argument("Nao foi inserido nenhum caractere");
    }

    //Cada caracter pode ser letra, espaço ou ponto
    for(int i = 0; i < tamanho_vetor; i++)
    {
        if ( (nome[i] < 'a' || nome[i] > 'z') &&
                (nome[i] < 'A' || nome[i] > 'Z') &&
                (nome[i] != ' ') &&
                (nome[i] != '.') )
        {
            throw invalid_argument("Caractere invalido inserido");
        }
    }

    //Pelos menos um caracter deve ser letra
    bool TemLetra = 0;
    for(int i = 0; i < tamanho_vetor; i++)
    {
        if ( (nome[i] >= 'a' && nome[i] <= 'z') ||
                (nome[i] >= 'A' && nome[i] <= 'Z') )
        {
            TemLetra = 1;
            break;
        }
    }
    if(TemLetra == 0)
    {
        throw invalid_argument("Pelos menos um caracter deve ser letra");
    }

    //Pontos devem ser precedidos de letra
    for(int i = 0; i < tamanho_vetor; i++)
    {
        if (nome[i] == '.')
        {
            if ( (nome[i] < 'a' || nome[i] > 'z') &&
                    (nome[i] < 'A' || nome[i] > 'Z') )
            {
                throw invalid_argument("Pontos devem ser precedidos de letra");
                break;
            }
        }
    }
}

void Nome::setNome(string nome) throw (invalid_argument)
{
    validar(nome);
    this->nome = nome;
}



// Definições de métodos da classe Cartao.
bool Cartao::checkLuhn(string cartao)
{
    int nSum       = 0;
    int nDigits    = cartao.size();
    int nParity    = (nDigits-1) % 2;
    char cDigit[2] = "\0";
    for (int i = nDigits; i > 0 ; i--)
    {
        cDigit[0]  = cartao[i-1];
        int nDigit = atoi(cDigit);

        if (nParity == i % 2)
        {
            nDigit = nDigit * 2;
        }
        nSum += nDigit/10;
        nSum += nDigit%10;
    }
    return 0 == nSum % 10;
}
void Cartao::validar(string cartao) throw (invalid_argument)
{
    int tamanhoString = cartao.size();
    if((tamanhoString != TAM_CARTAO))
    {
        throw invalid_argument("Quatidade errada de digitos.");
    }
    else
    {
        for(int i = 0; i < tamanhoString; i++)
        {
            if(cartao[i] < '0' || cartao[i] > '9')
            {
                throw invalid_argument("Digito inserido invalido");
            }
        }
    }
    if(checkLuhn(cartao) == 0)
    {
        throw invalid_argument("Número válido segundo o algoritmo de Luhn.");
    }
}
void Cartao::setCartao(string cartao) throw (invalid_argument)
{
    validar(cartao);
    this->cartao = cartao;
}



// Definições de métodos da classe Conta.
void Conta::validar(string conta) throw (invalid_argument)
{
    int tamanhoString = conta.size();
    if((tamanhoString != TAM_CONTA))
    {
        throw invalid_argument("Quatidade errada de digitos.");
    }
    else
    {
        for(int i = 0; i < tamanhoString; i++)
        {
            if(conta[i] < '0' || conta[i] > '9')
            {
                throw invalid_argument("Digito inserido invalido");
            }
        }
    }
}
void Conta::setConta(string conta) throw (invalid_argument)
{
    validar(conta);
    this->conta = conta;
}



// Definições de métodos da classe Senha.
void Senha::validar(string senha) throw (invalid_argument)
{
    int tamanhoString = senha.size();
    if((tamanhoString != TAM_SENHA))
    {
        throw invalid_argument("Quatidade errada de caracteres.");
    }
    bool LetraMinuscula = 0, LetraMaiuscula = 0, Digito = 0, Simbolo = 0;
    for(int i = 0; i < tamanhoString; i++)
    {
        if (senha[i] >= 'a' && senha[i] <= 'z')
        {
            LetraMinuscula++;
        }
        else if (senha[i] >= 'A' && senha[i] <= 'Z')
        {
            LetraMaiuscula++;
        }
        else if (senha[i] >= '0' && senha[i] <= '9')
        {
            Digito++;
        }
        else if ((senha[i] == '!') || (senha[i] == '#') ||
                 (senha[i] == '$') || (senha[i] == '%') ||
                 (senha[i] == '&'))
        {
            Simbolo++;
        }
        else
        {
            throw invalid_argument("Caractere invalido inserido");
        }
        for(int j = 0; j < i; j++)
        {
            if(j == i)
            {
                throw invalid_argument("Não deve haver caracteres repetidos");
            }
        }
    }
    if (LetraMinuscula == 0 || LetraMaiuscula == 0 || Digito == 0 || Simbolo == 0)
    {
        throw invalid_argument("Deve haver, pelo menos, uma letra maiúscula, uma minúscula, um dígito e um símbolo");
    }
}
void Senha::setSenha(string senha) throw (invalid_argument)
{
    validar(senha);
    this->senha = senha;
}



// Definições de métodos da classe Tipo.
void Tipo::validar(string tipo) throw (invalid_argument)
{
    bool tipoValido = 0;
    for(int i = 0; i < 3; i++)
    {
        if(TIPOS_VALIDOS[i].compare(tipo) == 0)
        {
            tipoValido = 1;
            break;
        }
    }
    if(tipoValido == 0)
    {
        throw invalid_argument("Tipo de tipo invalido.");
    }
}
void Tipo::setTipo(string tipo) throw (invalid_argument)
{
    validar(tipo);
    this->tipo = tipo;
}
