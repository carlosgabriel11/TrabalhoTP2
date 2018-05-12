#include "stubs.hpp"

//Defini��es de constantes.

//const string Stub_IS_Autenticacao::TRIGGER_FALHA_EMAIL;
//const string Stub_IS_Autenticacao::TRIGGER_FALHA_SENHA;
//const string Stub_IS_Autenticacao::TRIGGER_ERRO_SISTEMA;


// EXEMPLO
// --------------------------------------------------------

// Defini��es de m�todo da classe stub do controlador da l�gica de neg�cio de autentica��o.

ResultadoAutenticacao Stub_IS_Autenticacao::autenticar(const Email &email, const Senha &senha) throw(runtime_error) {

    // Apresentar dados recebidos.

    cout << endl << "Stub_IS_Autenticacao::autenticar" << endl ;

    cout << "Email = " << email.getEmail() << endl ;
    cout << "Senha     = " << senha.getSenha()     << endl ;

    ResultadoAutenticacao resultado;

    // Diferentes comportamentos dependendo do valor da matr�cula.


    if (email.getEmail() == TRIGGER_FALHA_EMAIL || senha.getSenha() == TRIGGER_FALHA_SENHA){
        resultado.setValor(ResultadoAutenticacao::FALHA);
    }
    else{
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
        resultado.setEmail(email);
        resultado.setSenha(senha);
    }
    if (email.getEmail() == TRIGGER_ERRO_SISTEMA || senha.getSenha() == TRIGGER_ERRO_SISTEMA){
        throw runtime_error("Erro de sistema");
    }



    return resultado;
}


