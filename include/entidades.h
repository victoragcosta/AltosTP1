#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED
#include "dominios.h"
#include <string>
using namespace std;



/**
 * @file entidades.h
 * @author Henrique Lopes Curzio
 * @date 21 de setembro de 2018
 * @brief Descricao acerca das classes de entidades, referindo-se a seus atributos e funcionalidades.
 * As classes de entidades são um nivel maior de abstracao abordado nesse projeto.
 * Referem-se aos elementos que compoem o sistema.
 */



/**
* @brief Classe abstrata com o intuito de armazenar os dados de um usuario.
* As formas de se utilizar essa classe sao pelo seu construtor Usuario() e pelos seus metodos set e get.
* Esta classe nao tem atributos de validacao.
*
* Possui:
* nome
* identificador
* senha
*/
class Usuario
{
private:
    Nome nome;
    Identificador identificador;
    Senha senha;
public:
    /**
    * @brief Recebe um objeto do tipo Nome para armazenar na classe Usuario, de acordo com seus atributos privados.
    * @param nome é o objeto que é passado para a classe Usuario, de acordo com seus atributos privados.
    */
    void setNome(const Nome &nome)
    {
        this->nome = nome;
    }
    /**
    * @brief Fornece o objeto do tipo Nome da classe Usuario.
    */
    Nome getNome()
    {
        return nome;
    }

    /**
    * @brief Recebe um objeto do tipo Identificador para armazenar na classe Usuario, de acordo com seus atributos privados.
    * @param identificador é o objeto que é passado para a classe Usuario, de acordo com seus atributos privados.
    */
    void setIdentificador(const Identificador &identificador)
    {
        this->identificador = identificador;
    }
    /**
    * @brief Fornece o objeto do tipo Identificador da classe Usuario.
    */
    Identificador getIdentificador()
    {
        return identificador;
    }

    /**
    * @brief Recebe um objeto do tipo Senha para armazenar na classe Usuario, de acordo com seus atributos privados.
    * @param senha é o objeto que é passado para a classe Usuario, de acordo com seus atributos privados.
    */
    void setSenha(const Senha &senha)
    {
        this->senha = senha;
    }
    /**
    * @brief Fornece o objeto do tipo Senha da classe Usuario.
    */
    Senha getSenha()
    {
        return senha;
    }
};

/**
* @brief Classe abstrata com o intuito de armazenar os dados de uma Acomodacao.
* As formas de se utilizar essa classe sao pelo seu construtor Acomodacao() e pelos seus metodos set e get.
* Esta classe nao tem atributos de validacao.
*
* Possui:
* identificador
* tipo
* capacidade
* dataInicio
* dataTermino
* cidade
* regiao
* diaria
*/
class Acomodacao
{

private:
    Identificador ident;
    Tipo tipo;
    Capacidade capacidade;
    Data dataInicio;
    Data dataTermino;
    Nome cidade;
    Regiao regiao;
    Diaria diaria;

public:
    /**
    * @brief Recebe um objeto do tipo Identificador para armazenar na classe Acomodacao, de acordo com seus atributos privados.
    * @param ident é o objeto que é passado para a classe Acomodacao, de acordo com seus atributos privados.
    */
    void setIdentificador(const Identificador &ident)
    {
        this->ident = ident;
    }
    /**
    * @brief Fornece o objeto do tipo Identificador da classe Acomodacao.
    */
    Identificador getIdentificador()
    {
        return ident;
    }

    /**
    * @brief Recebe um objeto do tipo Tipo para armazenar na classe Acomodacao, de acordo com seus atributos privados.
    * @param tipo é o objeto que é passado para a classe Acomodacao, de acordo com seus atributos privados.
    */
    void setTipo(const Tipo &tipo)
    {
        this->tipo = tipo;
    }
    /**
    * @brief Fornece o objeto do tipo Tipo da classe Acomodacao.
    */
    Tipo getTipo()
    {
        return tipo;
    }

    /**
    * @brief Recebe um objeto do tipo Capacidade para armazenar na classe Acomodacao, de acordo com seus atributos privados.
    * @param capacidade é o objeto que é passado para a classe Acomodacao, de acordo com seus atributos privados.
    */
    void setCapacidade(const Capacidade &capacidade)
    {
        this->capacidade = capacidade;
    }
    /**
    * @brief Fornece o objeto do tipo Capacidade da classe Acomodacao.
    */
    Capacidade getCapacidade()
    {
        return capacidade;
    }

    /**
    * @brief Recebe um objeto do tipo Data para armazenar na classe Acomodacao, de acordo com seus atributos privados.
    * @param dataInicio é o objeto que é passado para a classe Acomodacao, de acordo com seus atributos privados.
    */
    void setDataInicio(const Data &dataInicio)
    {
        this->dataInicio = dataInicio;
    }
    /**
    * @brief Fornece o objeto do tipo Data da classe Acomodacao.
    */
    Data getDataInicio()
    {
        return dataInicio;
    }

    /**
    * @brief Recebe um objeto do tipo Data para armazenar na classe Acomodacao, de acordo com seus atributos privados.
    * @param dataTermino é o objeto que é passado para a classe Acomodacao, de acordo com seus atributos privados.
    */
    void setDataTermino(const Data &dataTermino)
    {
        this->dataTermino = dataTermino;
    }
    /**
    * @brief Fornece o objeto do tipo Data da classe Acomodacao.
    */
    Data getDataTermino()
    {
        return dataTermino;
    }

    void setCidade(const Nome &cidade)
    {
        this->cidade = cidade;
    }
    /**
    * @brief Fornece o objeto do tipo Data da classe Acomodacao.
    */
    Nome getCidade()
    {
        return cidade;
    }

    /**
    * @brief Recebe um objeto do tipo Regiao para armazenar na classe Acomodacao, de acordo com seus atributos privados.
    * @param regiao é o objeto que é passado para a classe Acomodacao, de acordo com seus atributos privados.
    */
    void setRegiao(const Regiao &regiao)
    {
        this->regiao = regiao;
    }
    /**
    * @brief Fornece o objeto do tipo Regiao da classe Acomodacao.
    */
    Regiao getRegiao()
    {
        return regiao;
    }

    /**
    * @brief Recebe um objeto do tipo Diaria para armazenar na classe Acomodacao, de acordo com seus atributos privados.
    * @param diaria é o objeto que é passado para a classe Acomodacao, de acordo com seus atributos privados.
    */
    void setDiaria(const Diaria &diaria)
    {
        this->diaria = diaria;
    }
    /**
    * @brief Fornece o objeto do tipo Diaria da classe Acomodacao.
    */
    Diaria getDiaria()
    {
        return diaria;
    }

};

/**
* @brief Classe abstrata com o intuito de armazenar os dados de um Cartao de Credito.
* As formas de se utilizar essa classe sao pelo seu construtor CartaoDeCredito() e pelos seus metodos set e get.
* Esta classe nao tem atributos de validacao.
*
* Possui:
* cartao
* validade
*/
class CartaoDeCredito
{

private:
    Cartao cartao;
    Validade validade;

public:
    /**
    * @brief Recebe um objeto do tipo Cartao para armazenar na classe CartaoDeCredito, de acordo com seus atributos privados.
    * @param cartao é o objeto que é passado para a classe CartaoDeCredito, de acordo com seus atributos privados.
    */
    void setCartao(const Cartao &cartao)
    {
        this->cartao = cartao;
    }
    /**
    * @brief Fornece o objeto do tipo Cartao da classe CartaoDeCredito.
    */
    Cartao getCartao()
    {
        return cartao;
    }

    /**
    * @brief Recebe um objeto do tipo Validade para armazenar na classe CartaoDeCredito, de acordo com seus atributos privados.
    * @param validade é o objeto que é passado para a classe CartaoDeCredito, de acordo com seus atributos privados.
    */
    void setValidade(const Validade &validade)
    {
        this->validade = validade;
    }
    /**
    * @brief Fornece o objeto do tipo Validade da classe CartaoDeCredito.
    */
    Validade getValidade()
    {
        return validade;
    }
};

/**
* @brief Classe abstrata com o intuito de armazenar os dados de uma Conta Corrente.
* As formas de se utilizar essa classe sao pelo seu construtor ContaCorrente() e pelos seus metodos set e get.
* Esta classe nao tem atributos de validacao.
*
* Possui:
* conta
* agencia
* banco
*/
class ContaCorrente
{
private:
    Conta conta;
    Agencia agencia;
    Banco banco;
public:
    /**
    * @brief Recebe um objeto do tipo Conta para armazenar na classe ContaCorrente, de acordo com seus atributos privados.
    * @param conta é o objeto que é passado para a classe Contacorrente, de acordo com seus atributos privados.
    */
    void setConta(const Conta &conta)
    {
        this->conta = conta;
    }
    /**
    * @brief Fornece o objeto do tipo Conta da classe ContaCorrente.
    */
    Conta getConta()
    {
        return conta;
    }

    /**
    * @brief Recebe um objeto do tipo Agencia para armazenar na classe ContaCorrente, de acordo com seus atributos privados.
    * @param agencia é o objeto que é passado para a classe ContaCorrente, de acordo com seus atributos privados.
    */
    void setAgencia(const Agencia &agencia)
    {
        this->agencia = agencia;
    }
    /**
    * @brief Fornece o objeto do tipo Agencia da classe ContaCorrente.
    */
    Agencia getAgencia()
    {
        return agencia;
    }

    /**
    * @brief Recebe um objeto do tipo Banco para armazenar na classe ContaCorrente, de acordo com seus atributos privados.
    * @param banco é o objeto que é passado para a classe Contacorrente, de acordo com seus atributos privados.
    */
    void setBanco(const Banco &banco)
    {
        this->banco = banco;
    }
    /**
    * @brief Fornece o objeto do tipo Banco da classe ContaCorrente.
    */
    Banco getBanco()
    {
        return banco;
    }
};



class Resultado
{
protected:
    int valor;
public:
    const static int SUCESSO = 0;
    const static int FALHA   = 1;
    void setValor(int valor)
    {
        this->valor = valor;
    }
    int getValor() const
    {
        return valor;
    }
};

class ResultadoAutenticacao:public Resultado
{
private:
	Identificador identificador;
public:
    void setIdentificador(const Identificador &identificador)
    {
        this->identificador = identificador;
    }
    Identificador getIdentificador() const
    {
        return identificador;
    }
};

class ResultadoUsuario:public Resultado
{
private:
    Usuario usuario;
public:
    void setUsuario(const Usuario &usuario)
    {
        this->usuario = usuario;
    }
    Usuario getUsuario() const
    {
        return usuario;
    }
};


#endif // ENTIDADES_H_INCLUDED
