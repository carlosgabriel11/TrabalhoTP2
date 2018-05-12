#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "resultados.hpp"

#include <stdexcept>

using namespace std;

// Declara��o adiantada.

class IS_Autenticacao;

// Declara��o de interface para servi�o de autentica��o na camada de apresenta��o.

class IA_Autenticacao {
public:

    // M�todo por meio do qual � solicitado servi�o.

    virtual ResultadoAutenticacao autenticar(Email&, Senha&) throw(runtime_error) = 0;

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.

    virtual void setCtrl_IS_Autenticacao(IS_Autenticacao *) = 0;

    // M�todo destrutor virtual.

    virtual ~IA_Autenticacao(){}
};

// Declara��o de interface para servi�o de autentica��o na camada de servi�o.

class IS_Autenticacao {
public:

    // M�todo por meio do qual � solicitado servi�o.

    virtual ResultadoAutenticacao autenticar(const Email&, const Senha&) throw(runtime_error)= 0;

   // M�todo destrutor virtual.

    virtual ~IS_Autenticacao(){}

};

/*

//Declara��o adiantada.

class IS_GestaoUsuario;

// Declara��o de interface da camada de apresenta��o.

class IA_GestaoUsuario {
public:

    // M�todo por meio do qual � solicitado servi�o.

    virtual void executar(const Email&) = 0;

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora de neg�cio.

    virtual void setCtrl_IS_GestaoUsuario(IS_GestaoUsuario*) = 0;

    // Destrutor virtual.

    virtual ~IA_GestaoUsuario(){}

};

// Declara��o de interface da camada de neg�cio
// ------------------------------------------------------------------

class IS_GestaoUsuario {
public:

    // M�todos por meio dos quais s�o solicitados servi�os.

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




