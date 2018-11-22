#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED
#include <stdexcept>
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



/**
* @file dominiosClasses.hpp
* @author Henrique Lopes Curzio
* @date 21 de setembro 2018
* @brief Descricao acerca das classes de dominio, referindo-se a seus atributos e funcionalidades.
* As classes de dominio sao o menor nivel de abstracao abordado nesse projeto.
* Referem-se aos elementos que compoem as entidades.
*/



/**
* @brief classe abstrata com o intuito de guardar um numero de agencia.
*
* Possui os seguintes atributos de validacao:
* Deve possuir um formato fixo: XXXXX.
* XXXXX eh uma string onde X e um digito entro 0 e 9.
*
* A classe possui um metodo setAgencia, para receber uma string.
* A classe possui um metodo getAgencia, que apenas retorna a string contida em um eventual objeto da classe Agencia.
*/
class Agencia
{
private:
    string agencia;
    /**
    * @brief Valida o atributo do tipo string da classe Agencia.
    * Eh responsavel por validar a string recebida pela classe Agencia, de acordo com os seus atributos de valicacao.
    * @param string recebe a string da classe Agencia, para realizar a sua validacao.
    */
    void validar(string) throw (invalid_argument);
public:
    const static int TAM_AGENCIA = 5;
    /**
    * @brief Recebe uma string para guardar na classe Agencia, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Agencia.
    * @param agencia recebe a string da classe Agencia.
    */
    void setAgencia(string) throw (invalid_argument);
    string getAgencia() const
    {
        return agencia;
    }
};



/**
* @brief classe abstrata com o intuito de guardar um numero do banco.
*
* Possui os seguintes atributos de validacao:
* Deve possuir um formato fixo: XXX.
* XXX eh uma string onde X e um digito entro 0 e 9.
*
* A classe possui um metodo setBanco, para receber uma string.
* A classe possui um metodo getBanco, que apenas retorna a string contida em um eventual objeto da classe Banco.
*/
class Banco
{
private:
    string banco;
    /**
    * @brief Valida o atributo do tipo string da classe Banco.
    * Eh responsavel por validar a string recebida pela classe Banco, de acordo com os seus atributos de valicacao.
    * @param string recebe a string da classe Banco, para realizar a sua validacao.
    */
    void validar(string) throw (invalid_argument);
public:
    const static int TAM_BANCO = 3;
    /**
    * @brief Recebe uma string para guardar na classe Banco, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Banco.
    * @param agencia recebe a string da classe Banco.
    */
    void setBanco(string) throw (invalid_argument);
    string getBanco() const
    {
        return banco;
    }
};



/**
* @brief classe abstrata com o intuito de guardar um numero que representa a capacidade de uma acomodacao.
*
* Possui os seguintes atributos de validacao:
* E um numero inteiro entre 1 e 9.
*
* A classe possui um metodo setCapacidade, para receber um int.
* A classe possui um metodo getCapacidade, que apenas retorna o valor int contido em um eventual objeto da classe Capacidade.
*/
class Capacidade
{
private:
    int capacidade;
    /**
    * @brief Valida o atributo do tipo inteiro da classe Capacidade.
    * Eh responsavel por validar o valor inteiro recebido pela classe Capacidade, de acordo com os seus atributos de valicacao.
    * @param int recebe o valor inteiro da classe Capacidade, para realizar a sua validacao.
    */
    void validar(int) throw (invalid_argument);
public:
    const static int CAPACIDADE_MINIMA = 1;
    const static int CAPACIDADE_MAXIMA = 9;
    /**
    * @brief Recebe um valor inteiro para guardar na classe Capacidade, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Capacidade.
    * @param agencia recebe um valor inteiro da classe Capacidade.
    */
    void setCapacidade(int) throw (invalid_argument);
    int getCapacidade() const
    {
        return capacidade;
    }
};



/**
* @brief classe abstrata com o intuito de guardar um numero que representa o preco de uma diaria.
*
* Possui os seguintes atributos de validacao:
* E um numero ponto flutuante entre 1.00 e 10000.00.
*
* A classe possui um metodo setDiaria, para receber um float.
* A classe possui um metodo getDiaria, que apenas retorna o valor float contido em um eventual objeto da classe Diaria.
*/
class Diaria
{
private:
    float diaria;
    /**
    * @brief Valida o atributo do tipo string da classe Diaria.
    * Eh responsavel por validar a string recebida pela classe Diaria, de acordo com os seus atributos de valicacao.
    * @param string recebe a string da classe Diaria, para realizar a sua validacao.
    */
    void validar(float) throw (invalid_argument);
public:
    float DIARIA_MINIMA = 1.00;
    float DIARIA_MAXIMA = 10000.00;
    /**
    * @brief Recebe uma string para guardar na classe Diaria, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Diaria.
    * @param diaria recebe a string da classe Diaria.
    */
    void setDiaria(float) throw (invalid_argument);
    float getDiaria() const
    {
        return diaria;
    }
};



/**
* @brief classe abstrata com o intuito de guardar uma data.
*
* Possui os seguintes atributos de validacao:
* Deve possuir um formato fixo: DD/MMM/AAAA.
* DD eh uma string que representa um numero entre 01 e 31.
* MMM eh uma string que representa as três primeiras letras do mes
* AAAA eh uma string que representa um numero entre 2000 e 2099.
* As datas consideram os anos bissextos.
*
* A classe possui um metodo setData, para receber uma string.
* A classe possui um metodo getData, que apenas retorna a string contida em um eventual objeto da classe Data.
*/
class Data
{
private:
    string data;
    /**
    * @brief Valida o atributo do tipo string da classe Data.
    * Eh responsavel por validar a string recebida pela classe Data, de acordo com os seus atributos de valicacao.
    * @param string recebe a string da classe Data, para realizar a sua validacao.
    */
    void validar(string) throw (invalid_argument);
public:
    const static int TAM_MAX_DATA = 11;
    const static int STRING_VAZIA = 0;
    const static int DIA_MAX = 31;
    const static int DIA_MIN = 1;
    const static int MES_MAX = 12;
    const static int MES_MIN = 1;
    const static int ANO_MIN = 2000;
    const static int ANO_MAX = 2099;
    const static int FEVEREIRO = 2;
    const static int ABRIL = 4;
    const static int JUNHO = 6;
    const static int SETEMBRO = 9;
    const static int NOVEMBRO = 11;
    string MESES_VALIDOS[12] = {"jan", "fev", "mar", "abr",
                                "mai", "jun", "jul", "ago",
                                "set", "out", "nov", "dez"
                               };
    /**
    * @brief Recebe uma string para guardar na classe Data, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Data.
    * @param data recebe a string da classe Data.
    */
    void setData (string data) throw (invalid_argument);
    string getData() const
    {
        return data;
    }
};



/**
* @brief classe abstrata com o intuito de guardar uma data (de validade).
*
* Possui os seguintes atributos de validacao:
* Deve possuir um formato fixo: MM/AA.
* MM eh uma string que representa um numero entre 1 e 12.
* AA eh uma string que representa um numero entre 00 e 99.
*
* A classe possui um metodo setValidade, para receber uma string.
* A classe possui um metodo getValidade, que apenas retorna a string contida em um eventual objeto da classe Validade.
*/
class Validade
{
private:
    string validade;
    /**
    * @brief Valida o atributo do tipo string da classe Validade.
    * Eh responsavel por validar a string recebida pela classe Validade, de acordo com os seus atributos de valicacao.
    * @param string recebe a string da classe Validade, para realizar a sua validacao.
    */
    void validar(string) throw (invalid_argument);
public:
    const static int TAM_MAX_VALIDADE = 5;
    const static int STRING_VAZIA = 0;
    const static int MES_MAX = 12;
    const static int MES_MIN = 01;
    const static int ANO_MIN = 00;
    const static int ANO_MAX = 99;
    /**
    * @brief Recebe uma string para guardar na classe Validade, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Validade.
    * @param validade recebe a string da classe Validade.
    */
    void setValidade(string) throw (invalid_argument);
    string getValidade() const
    {
        return validade;
    }
};



/**
* @brief classe abstrata com o intuito de guardar uma string que representa a sigla de uma Regiao do Brasil.
*
* Possui os seguintes atributos de validacao:
* Deve ser uma das siglas a seguir: AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE,
* PI, RJ, RN, RS, RO, RR, SC, SP, SE, TO.
*
* A classe possui um metodo setData, para receber uma string.
* A classe possui um metodo getData, que apenas retorna a string contida em um eventual objeto da classe Regiao.
*/
class Regiao
{
private:
    string regiao;
    /**
    * @brief Valida o atributo do tipo string da classe Regiao.
    * Eh responsavel por validar a string recebida pela classe Regiao, de acordo com os seus atributos de valicacao.
    * @param string recebe a string da classe Regiao, para realizar a sua validacao.
    */
    void validar(string) throw (invalid_argument);
public:
    const static int TAM_REGIAO = 2;
    string REGIOES_VALIDAS[27] =  {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO",
                                   "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI",
                                   "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"
                                  };
    /**
    * @brief Recebe uma string para guardar na classe Regiao, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Regiao.
    * @param regiao recebe a string da classe Regiao.
    */
    void setRegiao(string) throw (invalid_argument);
    string getRegiao() const
    {
        return regiao;
    }
};



/**
* @brief classe abstrata com o intuito de guardar uma string que representa um identificador de usuario.
*
* Possui os seguintes atributos de validacao:
* A classe Identificador recebe uma string que deve possuir 5 caracteres.
* Cada caracter deve ser ums letra minuscula.
*
* A classe possui um metodo setIdentificador, para receber uma string.
* A classe possui um metodo getIdentificador, que apenas retorna a string contida em um eventual objeto da classe Identificador.
*/
class Identificador
{
private:
    string identificador;
    /**
    * @brief Valida o atributo do tipo string da classe Identificador.
    * Eh responsavel por validar a string recebida pela classe Identificador, de acordo com os seus atributos de valicacao.
    * @param string recebe a string da classe Identificador, para realizar a sua validacao.
    */
    void validar(string) throw (invalid_argument);
public:
    const static int TAM_IDENTIFICADOR = 5;
    /**
    * @brief Recebe uma string para guardar na classe Identificador, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Identificador.
    * @param identificador recebe a string da classe Identificador.
    */
    void setIdentificador(string) throw (invalid_argument);
    string getIdentificador() const
    {
        return identificador;
    }
};



/**
* @brief classe abstrata com o intuito de nomear (usuarios ou qualquer outra abstracao que possa receber um "nome").
*
* Possui os seguintes atributos de validacao:
* A classe Nome recebe uma string que pode possuir no maximo 15 caracteres.
* Cada caracter pode ser letra, espaço ou ponto.
* Não há espaços seguidos.
* Ponto deve ser precedido por letra.
*
* A classe possui um metodo setNome, para receber uma string.
* A classe possui um metodo getNome, que apenas retorna a string contida em um eventual objeto da classe Nome.
*/
class Nome
{
private:
    string nome;
    /**
    * @brief Valida o atributo do tipo string da classe Nome.
    * Eh responsavel por validar a string recebida pela classe Nome, de acordo com os seus atributos de valicacao.
    * @param string recebe a string da classe Nome, para realizar a sua validacao.
    */
    void validar (string) throw (invalid_argument);
public:
    const static int TAM_MAX_NOME = 15;
    const static int STRING_VAZIA = 0;
    /**
    * @brief Recebe uma string para guardar na classe Nome, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Nome.
    * @param nome recebe a string da classe Nome.
    */
    void setNome (string nome) throw (invalid_argument);
    string getNome() const
    {
        return nome;
    }
};



/**
* @brief classe abstrata com o intuito de guardar uma string que representa o numero de um cartao.
*
* Possui os seguintes atributos de validacao:
* Recebe uma string que deve possuir 16 caracteres.
* Cada caracter deve ser um digito entre 0 e 9.
* O numero deve ser valido segundo o Algoritmo de Luhn.
*
* A classe possui um metodo setCartao, para receber uma string.
* A classe possui um metodo getCartao, que apenas retorna a string contida em um eventual objeto da classe Cartao.
*/
class Cartao
{
private:
    string cartao;
    /**
    * @brief Valida o atributo do tipo string da classe Cartao.
    * Eh responsavel por validar a string recebida pela classe Cartao, de acordo com os seus atributos de valicacao.
    * @param string recebe a string da classe Cartao, para realizar a sua validacao.
    */
    void validar(string) throw (invalid_argument);
    bool checkLuhn(string);
public:
    const static int TAM_CARTAO = 16;
    /**
    * @brief Recebe uma string para guardar na classe Cartao, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Cartao.
    * @param cartao recebe a string da classe Cartao.
    */
    void setCartao(string) throw (invalid_argument);
    string getCartao() const
    {
        return cartao;
    }
};



/**
* @brief classe abstrata com o intuito de guardar uma string que representa o numero da conta.
*
* Possui os seguintes atributos de validacao:
* Recebe uma string que deve possuir 6 caracteres.
* Cada caracter deve ser um digito entre 0 e 9.
*
* A classe possui um metodo setConta, para receber uma string.
* A classe possui um metodo getConta, que apenas retorna a string contida em um eventual objeto da classe Conta.
*/
class Conta
{
private:
    string conta;
    /**
    * @brief Valida o atributo do tipo string da classe Conta.
    * Eh responsavel por validar a string recebida pela classe Conta, de acordo com os seus atributos de valicacao.
    * @param string recebe a string da classe Conta, para realizar a sua validacao.
    */
    void validar(string) throw (invalid_argument);
public:
    const static int TAM_CONTA = 6;
    /**
    * @brief Recebe uma string para guardar na classe Conta, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Conta.
    * @param conta recebe a string da classe Conta.
    */
    void setConta(string) throw (invalid_argument);
    string getConta() const
    {
        return conta;
    }
};



/**
* @brief classe abstrata com o intuito de guardar uma string que representa uma senha.
*
* Possui os seguintes atributos de validacao:
* Recebe uma string que deve possuir 8 caracteres.
* Cada caracter pode ser um simbolo (! # $ % &), uma letra maiúscula ou minúscula (A – Z, a – z) ou um dígito (0 a 9).
* Não ha caracters repetidos.
* Há, pelo menos, uma letra maiúscula, uma minúscula, um dígito e um símbolo.
*
* A classe possui um metodo setSenha, para receber uma string.
* A classe possui um metodo getSenha, que apenas retorna a string contida em um eventual objeto da classe Senha.
*/
class Senha
{
private:
    string senha;
    /**
    * @brief Valida o atributo do tipo string da classe Senha.
    * Eh responsavel por validar a string recebida pela classe Senha, de acordo com os seus atributos de valicacao.
    * @param string recebe a string da classe Senha, para realizar a sua validacao.
    */
    void validar(string) throw (invalid_argument);
public:
    const static int TAM_SENHA = 8;
    /**
    * @brief Recebe uma string para guardar na classe Senha, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Senha.
    * @param senha recebe a string da classe Senha.
    */
    void setSenha(string) throw (invalid_argument);
    string getSenha() const
    {
        return senha;
    }
};



/**
* @brief classe abstrata com o intuito de guardar uma string que representa um tipo de acomodacao.
*
* Possui os seguintes atributos de validacao:
* Deve ser uma dos tipos a seguir: Apartamento, Casa, Flat.
*
* A classe possui um metodo setTipo, para receber uma string.
* A classe possui um metodo getTipo, que apenas retorna a string contida em um eventual objeto da classe Tipo.
*/
class Tipo
{
private:
    string tipo;
    /**
    * @brief Valida o atributo do tipo string da classe Tipo.
    * Eh responsavel por validar a string recebida pela classe Tipo, de acordo com os seus atributos de valicacao.
    * @param string recebe a string da classe Tipo, para realizar a sua validacao.
    */
    void validar(string) throw (invalid_argument);
public:
    string TIPOS_VALIDOS[3] = {"Apartamento", "Casa", "Flat"};
    /**
    * @brief Recebe uma string para guardar na classe Tipo, de acordo com seus atributos privados.
    * O valor eh guardado somente se for validado pelo metodo de validacao.
    * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Tipo.
    * @param tipo recebe a string da classe Tipo.
    */
    void setTipo(string) throw (invalid_argument);
    string getTipo() const
    {
        return tipo;
    }
};

#endif // DOMINIOS_H_INCLUDED
