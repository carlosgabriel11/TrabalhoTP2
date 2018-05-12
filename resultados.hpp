#ifndef RESULTADOS_H_INCLUDED
#define RESULTADOS_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

#include <string>

using namespace std;

// Declara��es de classes que modelam resultados.

class Resultado {

protected:

    int valor;

public:

    const static int SUCESSO = 0;
    const static int FALHA = 1;

    // Declara��es de poss�veis resultados.

    void setValor(int valor){
        this->valor = valor;
    }

    int getValor() const {
        return valor;
    }
};

// Modelo de resultado da interface de apresenta��o de autenticacao

class ResultadoAutenticacao : public Resultado {

private:
    Email email;
    Senha senha;

public:

    // ERRO SINTATICO DE EMAIL E SENHA SAO TRATADAS INTERNAMENTE NO MA_AUT

    const static int CANCELAR = 2;

    void setEmail(const Email &email){      // passagem por refer�ncia.
        this->email = email;
    }

    void setSenha(const Senha &senha){      // passagem por refer�ncia.
        this->senha = senha;
    }

    Email getEmail() const {
        return email;
    }

    Senha getSenha() const{
        return senha;
    }
};

class ResultadoInicializacao : public Resultado{

private:
    bool sair = false;

public:

    void setSair(bool sair){
        this->sair = sair;
    }
    bool getSair() const{
        return this->sair;
    }

};


/*
class ResultadoUsuario: public Resultado{

private:

    Leitor leitor;
    Desenvolvedor desenvolvedor;
    Administrador administrador;

public:

    void setLeitor(const Leitor &leitor){      // passagem por refer�ncia.
        this->leitor = leitor;
    }

    Leitor getLeitor() const {
        return leitor;
    }

    void setDesenvolvedor(const Desenvolvedor &desenvolvedor){      // passagem por refer�ncia.
        this->desenvolvedor = desenvolvedor;
    }

    Desenvolvedor getDesenvolvedor() const{
        return desenvolvedor;
    }

    void setAdministrador(const Administrador &administrador){
        this->administrador = administrador;
    }

    Administrador getAdministrador() const {
        return administrador;
    }
};


*/
#endif // RESULTADOS_H_INCLUDED


