#ifndef MAAUT_H_INCLUDED
#define MAAUT_H_INCLUDED

#include<stdexcept>

#include "interfaces.hpp"
#include "dominios.hpp"

using namespace std;

// DECLARACAO DE CLASSES CONTROLADORES

// Declaração de classe controladora de interação para o serviço de autenticação.

class Ctrl_IA_Autenticacao : public IA_Autenticacao {

private:

    // Referência para modulo de serviço.

    IS_Autenticacao *ctrl_IS_Autenticacao;

public:

    ResultadoAutenticacao autenticar(Email&, Senha&) throw(runtime_error);

    void setCtrl_IS_Autenticacao(IS_Autenticacao*);
};


void inline Ctrl_IA_Autenticacao::setCtrl_IS_Autenticacao(IS_Autenticacao *ctrl_IS_Autenticacao){
        this->ctrl_IS_Autenticacao = ctrl_IS_Autenticacao;
}


#endif // CONTROLADORES_H_INCLUDED

