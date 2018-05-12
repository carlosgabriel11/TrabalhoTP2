#ifndef CONTROLADORES_H_INCLUDED
#define CONTROLADORES_H_INCLUDED

#include "dominios.hpp"
#include "resultados.hpp"
#include "MAAut.hpp"


using namespace std;

// DECLARACAO DE CLASSES CONTROLADORES

// Declaração de classe controladora de interação para o serviço de autenticação.


class Controle {

private:

    Email emailUsuario;
    Senha senhaUsuario;

    //Nome nomeUsuario;
    //Nome sobrenomeUsuario;
    //Data dataUsuario;
    //Telefone telUsuario;
    //Endereco enderecoUsuario;

    Resultado cadastrar();
    ResultadoAutenticacao login(); // 0: OK  , 1: FALHOU
    ResultadoInicializacao inicializar();

    void executar();

public:

    void start();

    void getDados() const{
        cout << "email:" << emailUsuario.getEmail() << endl;
        cout << "senha:" << senhaUsuario.getSenha() << endl;
    }


};


#endif // CONTROLADORES_H_INCLUDED
