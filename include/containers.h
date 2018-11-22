#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <list>
using namespace std;


class ContainerUsuario
{
private:
    list<Usuario> container;

public:
    ResultadoUsuario incluir(Usuario);
    ResultadoUsuario remover(Identificador);
    ResultadoUsuario pesquisar(Identificador);
};

#endif // CONTROLADORAS_H_INCLUDED
