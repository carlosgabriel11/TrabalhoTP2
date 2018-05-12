#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.hpp"

#include <string>
#include <stdexcept>
#include <iostream>
#include <typeinfo>

using namespace std;

// Declaração de classe stub da interface ILNAutenticacao.

class Stub_IS_Autenticacao:public IS_Autenticacao{

public:

    // Definições de valores a serem usados como gatilhos para notificações de erros.

    const string TRIGGER_FALHA_EMAIL        = "jvmelop@gmaiu";
    const string TRIGGER_FALHA_SENHA        = "Senha123";
    const string TRIGGER_ERRO_SISTEMA = "erro";

    // Declaração de método previsto na interface.

    ResultadoAutenticacao autenticar(const Email&, const Senha&) throw(runtime_error);
};


#endif // STUBS_H_INCLUDED

