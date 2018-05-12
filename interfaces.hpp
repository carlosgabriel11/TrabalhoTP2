#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "resultados.hpp"

#include <stdexcept>

using namespace std;

// Declaração adiantada.

class IS_Autenticacao;

// Declaração de interface para serviço de autenticação na camada de apresentação.

class IA_Autenticacao {
public:

    // Método por meio do qual é solicitado serviço.

    virtual ResultadoAutenticacao autenticar(Email&, Senha&) throw(runtime_error) = 0;

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.

    virtual void setCtrl_IS_Autenticacao(IS_Autenticacao *) = 0;

    // Método destrutor virtual.

    virtual ~IA_Autenticacao(){}
};

// Declaração de interface para serviço de autenticação na camada de serviço.

class IS_Autenticacao {
public:

    // Método por meio do qual é solicitado serviço.

    virtual ResultadoAutenticacao autenticar(const Email&, const Senha&) throw(runtime_error)= 0;

   // Método destrutor virtual.

    virtual ~IS_Autenticacao(){}

};

/*

//Declaração adiantada.

class IS_GestaoUsuario;

// Declaração de interface da camada de apresentação.

class IA_GestaoUsuario {
public:

    // Método por meio do qual é solicitado serviço.

    virtual void executar(const Email&) = 0;

    // Método por meio do qual é estabelecida ligação (link) com a controladora de negócio.

    virtual void setCtrl_IS_GestaoUsuario(IS_GestaoUsuario*) = 0;

    // Destrutor virtual.

    virtual ~IA_GestaoUsuario(){}

};

// Declaração de interface da camada de negócio
// ------------------------------------------------------------------

class IS_GestaoUsuario {
public:

    // Métodos por meio dos quais são solicitados serviços.

    virtual Resultado incluirLeitor(const Leitor&) throw(runtime_error) = 0;
    virtual Resultado incluirDesenvolvedor(const Desenvolvedor&) throw(runtime_error) = 0;
    virtual Resultado incluirAdministrador(const Administrador&) throw(runtime_error) = 0;

    virtual Resultado remover(const Email&) throw(runtime_error) = 0;

    virtual ResultadoUsuario pesquisar(const Email&) throw(runtime_error) = 0;

    virtual Resultado editarLeitor(const Leitor&) throw(runtime_error) = 0;
    virtual Resultado editarDesenvolvedor(const Desenvolvedor&) throw(runtime_error) = 0;
    virtual Resultado editarAdministrador(const Administrador&) throw(runtime_error) = 0;


    // Destrutor virtual.

    virtual ~IS_GestaoUsuario(){}
};

*/
#endif // INTERFACES_H_INCLUDED




