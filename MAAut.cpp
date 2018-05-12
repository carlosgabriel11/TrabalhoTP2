#include "MAAut.hpp"

/*
void MA_Autenticacao::printaInicio(){

    cout << "**********  GESTOR DE VOCABULÁRIOS CONTROLADOS  **********" << endl << endl;
    cout << "(1) Login \n";
    cout << "(2) Criar conta \n";
    cout << "(0) Encerrar programa \n";
    cout << "Opcao escolhida: ";

    cin >> opcaoAut;

    system("CLS");

    return;
}


int MA_Autenticacao::loginAut() {


    system("CLS");
    cout << "**********  GESTOR DE VOCABULÁRIOS CONTROLADOS  **********" << endl;
    cout << "**********                 LOGIN                **********" << endl << endl;

    //const string emailUsuario = "jvmelop@gmail";
    //const string senhaUsuario = "Hu3bR";

    string emailUsuario;
    string senhaUsuario;

    cout << "Digite o email: ";
    cin >> emailUsuario;
    cout << "Digite a senha: ";
    cin >> senhaUsuario;


    try{
            email.setEmail(emailUsuario);
            senha.setSenha(senhaUsuario);
            cout << "Os formatos de email e senha são validos.\n";
    }
    catch(invalid_argument excecao){
        cout << "ENTRADA INVALIDA! Tente novamente.\n\n";
        system("PAUSE");
        return 1;
    }

    return 0;
}


int MA_Autenticacao::criarAut(){

    int tipoConta=1;

    string emailUsuario;
    string senhaUsuario;
    string nomeUsuario;
    string sobrenomeUsuario;
    string dataUsuario;
    string telUsuario;
    string enderecoUsuario;


    system("CLS");
    cout << "**********  GESTOR DE VOCABULÁRIOS CONTROLADOS  **********" << endl;
    cout << "**********              CRIAR CONTA             **********" << endl << endl;

    cout << "Tipos de conta:"<<endl;
    cout << "(1)Leitor" << endl;
    cout << "(2)Desenvolvedor" << endl;
    cout << "(3)Administrador" << endl<<endl;
    cout << "Escolhe o tipo de conta que deseja criar: ";
    cin >> tipoConta;

    if (tipoConta!=1 && tipoConta!=2 && tipoConta!=3){
        cout << "Opcao invalida. "<<endl<<endl;
        system("PAUSE");

        return 1;
    }

    try{

        system("CLS");
        cout << "**********  GESTOR DE VOCABULÁRIOS CONTROLADOS  **********" << endl;
        cout << "**********              CRIAR CONTA             **********" << endl;

        switch(tipoConta){

            case 1: // Leitor

                cout << "**********                LEITOR                **********" << endl << endl;

                cout << "Digite o email:     ";
                cin >> emailUsuario;
                cout << "Digite a senha:     ";
                cin >> senhaUsuario;
                cout << "Digite o nome:      ";
                cin >> nomeUsuario;
                cout << "Digite o sobrenome: ";
                cin >> sobrenomeUsuario;

                email.setEmail(emailUsuario);
                senha.setSenha(senhaUsuario);
                nome.setNome(nomeUsuario);
                sobrenome.setNome(sobrenomeUsuario);

                cout << "Todas entradas sao validas."<<endl;

                break;

            case 2: // Desenv
                cout << "**********             DESENVOLVEDOR            **********" << endl << endl;

                cout << "Digite o email:              ";
                cin >> emailUsuario;
                cout << "Digite a senha:              ";
                cin >> senhaUsuario;
                cout << "Digite o nome:               ";
                cin >> nomeUsuario;
                cout << "Digite o sobrenome:          ";
                cin >> sobrenomeUsuario;
                cout << "Digite a data de nascimento: ";
                cin >> dataUsuario;

                email.setEmail(emailUsuario);
                senha.setSenha(senhaUsuario);
                nome.setNome(nomeUsuario);
                sobrenome.setNome(sobrenomeUsuario);
                data.setData(dataUsuario);

                cout << "Todas entradas sao validas."<<endl;

                break;

            case 3: // Administrador

                cout << "**********             ADMINISTRADOR            **********" << endl << endl;

                cout << "Digite o email:              ";
                cin >> emailUsuario;
                cout << "Digite a senha:              ";
                cin >> senhaUsuario;
                cout << "Digite o nome:               ";
                cin >> nomeUsuario;
                cout << "Digite o sobrenome:          ";
                cin >> sobrenomeUsuario;
                cout << "Digite a data de nascimento: ";
                cin >> dataUsuario;
                cout << "Digite o telefone:           ";
                cin >> telUsuario;
                cout << "Digite o endereco:           ";
                cin >> enderecoUsuario;

                email.setEmail(emailUsuario);
                senha.setSenha(senhaUsuario);
                nome.setNome(nomeUsuario);
                sobrenome.setNome(sobrenomeUsuario);
                data.setData(dataUsuario);
                telefone.setTel(telUsuario);
                endereco.setEndereco(enderecoUsuario);

                cout << "Todas entradas sao validas."<<endl;

                break;
        }


    }
    catch(invalid_argument excecao){
        cout << "UMA OU MAIS ENTRADAS INVALIDAS! Tente novamente.\n\n";
        system("PAUSE");
        return 1;
    }

    return 0;
}


int MA_Autenticacao::processarAut(){

        printaInicio();
        int retorno=0;

        switch(opcaoAut){

            case 0:
                cout << "**********  GESTOR DE VOCABULÁRIOS CONTROLADOS  **********" << endl<<endl;
                cout << "Programa finalizado." << endl;
                break;

            /// LOGIN
            case 1:

                // checar se login e senha sao possiveis
                do{
                    retorno = loginAut();
                }while(retorno == 1);

                break;

            case 2:
                do{
                    retorno = criarAut();
                }while(retorno == 1);
                break;

            default:
                cout << "Opcao invalida." << endl;
        }


    return retorno;

};
*/


/// ////////////
/// ////////
/// /////////
/// ////////////
/// ////////
/// /////////
/// ////////////
/// ////////
/// /////////



#include "MAAut.hpp"

// Definições de métodos da classe CntrIUAutenticacao.

ResultadoAutenticacao Ctrl_IA_Autenticacao::autenticar(Email& email, Senha& senha) throw(runtime_error) {

    ResultadoAutenticacao resultado;

    string entrada;
    int novo;
    bool again = true;

    // Solicitar matricula e senha.

    while(true) {

        cout << endl << "Autenticacao de usuario." << endl << endl;

        try {
            cout << "Digite o email : ";
            cin >> entrada;
            email.setEmail(entrada);
            cout << "Digite a senha : ";
            cin >> entrada;
            senha.setSenha(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cerr << endl << exp.what() <<endl;

            cout << "(1) SIM" << endl << "(0) NÃO" << endl;
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
                again = true;
            }

            //cout << "Email ou senha em formato incorreto." << endl;
        }

        if (again == false){
            resultado.setValor(ResultadoAutenticacao::CANCELAR);
            break;
        }

    }

    // Solicitar autenticação.

    if(again==true){
            resultado = ctrl_IS_Autenticacao->autenticar(email, senha);

        // Informar resultado da autenticação.

        if(resultado.getValor() == ResultadoAutenticacao::FALHA){
            cout << endl << "Falha na autenticacao." << endl;
            system("PAUSE");
        }else{
            cout << endl << "Autenticacao feita com sucesso. Executando programa. " ;
            system("PAUSE");
        }
    }


    return resultado;
}

