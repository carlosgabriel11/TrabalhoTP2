#include "controladores.hpp"
#include "stubs.hpp"

ResultadoAutenticacao Controle::login(){

    // Ligação entre controladora na camada de apresentação e stub.

    // Instancia as controladoras.

    IA_Autenticacao *ctrl_IA_Autenticacao = new Ctrl_IA_Autenticacao();
    IS_Autenticacao *stub_IS_Autenticacao = new Stub_IS_Autenticacao();

    // Liga instância da controladora de interacao a instância do stub na camada de serviço.

    ctrl_IA_Autenticacao->setCtrl_IS_Autenticacao(stub_IS_Autenticacao);


    ResultadoAutenticacao resultado;

    while(true){

        // Simula a tela de apresentacao (tela inicial) de sistema.

        system("CLS");
        cout << "Tela de apresentacao de sistema." << endl;

        try{

            // Ilustra soliciatacao de serviço de autenticação.

            resultado = ctrl_IA_Autenticacao->autenticar(emailUsuario,senhaUsuario);

        }

        catch(const runtime_error &exp){
                cout << "Erro de sistema." << endl;

        }

        // Critica o resultado da autenticação.



        if(resultado.getValor() == ResultadoAutenticacao::SUCESSO || resultado.getValor() == ResultadoAutenticacao::CANCELAR) {
            break;
        }

        int novo;
        bool again=true;

        if(resultado.getValor() == ResultadoAutenticacao::FALHA){


            cout << endl << "(1) SIM" << endl << "(0) NÃO" << endl;
            cout << "Deseja tentar novamente? ";
            cin >> novo;

            if (novo == 0){
                again = false;
            }
            if (novo == 1){
                again = true;
            }
            if (novo!=1 && novo!=0) {
                cout << "Opcao invalida. Saindo. " << endl;
                again = false;
            }

        }

        if(again==false){
            resultado.setValor(ResultadoAutenticacao::CANCELAR);
            break;
        }

    }


    delete ctrl_IA_Autenticacao;
    delete stub_IS_Autenticacao;

    return resultado;

}

Resultado Controle::cadastrar(){










}

ResultadoInicializacao Controle::inicializar(){

    int opcao;
    ResultadoInicializacao resultadoInicializacao;
    ResultadoAutenticacao resultado;
    const int LOGIN = 1;
    const int CADASTRO = 2;
    const int SAIR = 0;


    system("CLS");
    cout << "***** INICIALIZANDO PROGRAMA ***** " << endl << endl;
    cout << "(1) Login " << endl << "(2) Cadastrar" << endl << "(0) Sair" << endl;
    cout << "Opcao escolhida: ";
    cin >> opcao;

    while(true){

        //BEGIN

        switch(opcao){
        default:
            cout << "Opcao invalida!"<<endl;
        case LOGIN:

                resultado = login();

                // SE OCORRER SUCESSO NO LOGIN, OCORREU SUCESSO NA INICIALIZACAO
                if (resultado.getValor()==Resultado::SUCESSO){
                    resultadoInicializacao.setValor(Resultado::SUCESSO);
                }
                // SE OCORRER FALHA NO LOGIN, OCORREU FALHA NA INICIALIZACAO
                if (resultado.getValor()==ResultadoAutenticacao::FALHA || resultado.getValor()==ResultadoAutenticacao::CANCELAR){
                    resultadoInicializacao.setValor(Resultado::FALHA);
                }

                break;
        /*
        case CADASTRAR:
            autenticar();
        */

        case SAIR:
            resultadoInicializacao.setValor(Resultado::SUCESSO);
            resultadoInicializacao.setSair(true);
            break;
        }

        if (resultadoInicializacao.getValor()==ResultadoInicializacao::SUCESSO || resultado.getValor()==ResultadoAutenticacao::CANCELAR)
            break;
    }

    return resultadoInicializacao;


}


void Controle::start(){

    ResultadoInicializacao resultadoInicializacao;

    while(true){

        resultadoInicializacao = this->inicializar();


        if(resultadoInicializacao.getValor() == ResultadoInicializacao::SUCESSO && resultadoInicializacao.getSair()==false){

            /// this->executar();

            cout << endl << "SIMULANDO EXECUCAO.... OK, REALIZAR LOGOUT." << endl;
            cout << "Logout realizado com sucesso. " << endl;
            system("PAUSE");

        }

        if (resultadoInicializacao.getSair() == true){
            cout << endl << "FINALIZANDO PROGRAMA..." << endl;
            break;
        }
    }

}
