#include "containers.h"

ResultadoUsuario ContainerUsuario::incluir(Usuario usuario)
{
    ResultadoUsuario resultado;
    string chave = usuario.getIdentificador().getIdentificador();
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getIdentificador().getIdentificador() == chave)
        {
            resultado.setValor(Resultado::FALHA);
            return resultado;
        }
    }
    // Incluir o elemento no container.
    container.push_back(usuario);
    resultado.setValor(Resultado::SUCESSO);
    return resultado;
}



ResultadoUsuario ContainerUsuario::remover(Identificador identificador)
{
    ResultadoUsuario resultado;
    string chave = identificador.getIdentificador();
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getIdentificador().getIdentificador() == chave)
        {
            // Elemento localizado.
            container.erase(elemento);
            resultado.setValor(Resultado::SUCESSO);
            return resultado;
        }
    }
    // Elemento não localizado.
    resultado.setValor(Resultado::FALHA);
    return resultado;
}



ResultadoUsuario ContainerUsuario::pesquisar(Identificador identificador)
{
    // Procurar elemento.
    ResultadoUsuario resultado;
    string chave = identificador.getIdentificador();

    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getIdentificador().getIdentificador() == chave)
        {
            // Elemento localizado.
            resultado.setUsuario(*elemento);
            resultado.setValor(Resultado::SUCESSO);
            return resultado;
        }
    }
    // Elemento não localizado.
    resultado.setValor(Resultado::FALHA);
    return resultado;
}
