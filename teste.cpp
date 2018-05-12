#include "teste.hpp"
#include <stdexcept>

// funcao que executa todos os testes de unidade ao mesmo tempo

void TU_Todos::executarTodosTestes(){

    testeNome.executarTeste();
    testeTel.executarTeste();
    testeEnd.executarTeste();
    testeData.executarTeste();
    testeEmail.executarTeste();
    testeSenha.executarTeste();
    testeTexto.executarTeste();
    testeIdioma.executarTeste();
    testeClass.executarTeste();
    testeLeitor.executarTeste();
    testeDsv.executarTeste();
    testeAdm.executarTeste();
    testeVocab.executarTeste();
    testeTermo.executarTeste();
    testeDef.executarTeste();

    return;
}

/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////            DOMINIOS            ///////////////////////////////////////////////////////////////////
/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    NOME E SOBRENOME    ////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


// funcao que cria novo objeto da classe
void TU_Nome::montar(){
    nome = new Nome;
    sucesso = true;
}

// funcao que destroi o novo objeto da classe
void TU_Nome::desmontar(){
    delete nome;
}

// funcao que testa um cenario de sucesso
void TU_Nome::cenarioSucesso(){
    try{
        //verificar se a string eh valida. Se sim, a string eh atribuida ao objeto. Se nao, lanca excecao
        nome->setNome(nomeValido);
        //apenas uma verificacao para ver se o nome recebido eh igual ao nome enviado
        if(nome->getNome() != nomeValido){
            sucesso = false;
        }

    }
    // caso de falha no teste, lanca excecao
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_Nome::cenarioFalha(const string& nomeInvalido){

    try{
        //verificar se a string eh valida. Se nao, o teste deu certo, se sim, falhou, lanca excecao
        nome->setNome(nomeInvalido);
            sucesso = false;
    }
    // se o teste falhar, lanca excecao
    catch(invalid_argument excecao){
        return;
    }
}

void TU_Nome::executarTeste(){

    montar();
    cenarioSucesso();
    cenarioFalha(nomeInvalido1);
    cenarioFalha(nomeInvalido2);
    cenarioFalha(nomeInvalido3);
    desmontar();

    cout << "Teste de nome/sobrenome: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    TELEFONE     ///////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_Telefone::montar(){
    tel = new Telefone;
    sucesso = true;
}


void TU_Telefone::desmontar(){
    delete tel;
}

void TU_Telefone::cenarioSucesso(){
    try{
        tel->setTel(telValido);
        if(tel->getTel() != telValido){
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_Telefone::cenarioFalha(const string &telInvalido){

    try{
        tel->setTel(telInvalido);
            sucesso = false;
    }
    catch(invalid_argument excecao){
        return;
    }
}

void TU_Telefone::executarTeste(){

    montar();
    cenarioSucesso();
    cenarioFalha(telInvalido1);
    cenarioFalha(telInvalido2);
    cenarioFalha(telInvalido3);
    cenarioFalha(telInvalido4);
    desmontar();

    cout << "Teste de telefone: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    TELEFONE     ///////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_Endereco::montar(){
    endereco = new Endereco;
    sucesso = true;
}


void TU_Endereco::desmontar(){
    delete endereco;
}

void TU_Endereco::cenarioSucesso(){
    try{
        endereco->setEndereco(enderecoValido);
        if(endereco->getEndereco() != enderecoValido){
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_Endereco::cenarioFalha(const string &enderecoInvalido){

    try{
        endereco->setEndereco(enderecoInvalido);
            sucesso = false;
    }
    catch(invalid_argument excecao){
        return;
    }
}

void TU_Endereco::executarTeste(){

    montar();
    cenarioSucesso();
    cenarioFalha(enderecoInvalido1);
    cenarioFalha(enderecoInvalido2);
    cenarioFalha(enderecoInvalido3);
    cenarioFalha(enderecoInvalido4);
    desmontar();

    cout << "Teste de endereço: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    DATA     ///////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_Data::montar(){
    data = new Data;
    sucesso = true;
}


void TU_Data::desmontar(){
    delete data;
}

void TU_Data::cenarioSucesso(){
    try{
        data->setData(dataValida);
        if(data->getData() != dataValida){
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_Data::cenarioFalha(const string &dataInvalida){
    try{
        data->setData(dataInvalida);
            sucesso = false;
    }
    catch(invalid_argument excecao){
        return;
    }
}

void TU_Data::executarTeste(){

    montar();
    cenarioSucesso();
    cenarioFalha(dataInvalida1);
    cenarioFalha(dataInvalida2);
    cenarioFalha(dataInvalida3);
    desmontar();

    cout << "Teste de data: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    EMAIL      /////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_Email::montar(){
    email = new Email;
    sucesso = true;
}


void TU_Email::desmontar(){
    delete email;
}

void TU_Email::cenarioSucesso(){
    try{
        email->setEmail(emailValido);
        if(email->getEmail() != emailValido){
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_Email::cenarioFalha(const string &emailInvalido){

    try{
        email->setEmail(emailInvalido);
            sucesso = false;
    }
    catch(invalid_argument excecao){
        return;
    }
}

void TU_Email::executarTeste(){

    montar();
    cenarioSucesso();
    cenarioFalha(emailInvalido1);
    cenarioFalha(emailInvalido2);
    cenarioFalha(emailInvalido3);
    cenarioFalha(emailInvalido4);
    desmontar();

    cout << "Teste de email: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    SENHA      /////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_Senha::montar(){
    senha = new Senha;
    sucesso = true;
}


void TU_Senha::desmontar(){
    delete senha;
}

void TU_Senha::cenarioSucesso(){
    try{
        senha->setSenha(senhaValida);
        if(senha->getSenha() != senhaValida){
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_Senha::cenarioFalha(const string &senhaInvalida){

    try{
        senha->setSenha(senhaInvalida);
            sucesso = false;
    }
    catch(invalid_argument excecao){
        return;
    }
}

void TU_Senha::executarTeste(){

    montar();
    cenarioSucesso();
    cenarioFalha(senhaInvalida1);
    cenarioFalha(senhaInvalida2);
    cenarioFalha(senhaInvalida3);
    cenarioFalha(senhaInvalida4);
    cenarioFalha(senhaInvalida5);
    desmontar();

    cout << "Teste de senha: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    TEXTO DE DEFINICAO      ////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_TextoDef::montar(){
    textodef = new TextoDef;
    sucesso = true;
}


void TU_TextoDef::desmontar(){
    delete textodef;
}

void TU_TextoDef::cenarioSucesso(){
    try{
        textodef->setTextoDef(textoValido);
        if(textodef->getTextoDef() != textoValido){
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_TextoDef::cenarioFalha(const string &textoInvalido){

    try{
        textodef->setTextoDef(textoInvalido);
            sucesso = false;
    }
    catch(invalid_argument excecao){
        return;
    }
}

void TU_TextoDef::executarTeste(){

    montar();
    cenarioSucesso();
    cenarioFalha(textoInvalido1);
    desmontar();

    cout << "Teste de texto de definicao: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    IDIOMA    //////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_Idioma::montar(){
    idioma = new Idioma;
    sucesso = true;
}


void TU_Idioma::desmontar(){
    delete idioma;
}

void TU_Idioma::cenarioSucesso(){
    try{
        idioma->setIdioma(idiomaValido);
        if(idioma->getIdioma() != idiomaValido){
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_Idioma::cenarioFalha(const string &idiomaInvalido){

    try{
        idioma->setIdioma(idiomaInvalido);
            sucesso = false;
    }
    catch(invalid_argument excecao){
        return;
    }
}

void TU_Idioma::executarTeste(){

    montar();
    cenarioSucesso();
    cenarioFalha(idiomaInvalido1);
    desmontar();

    cout << "Teste de idioma: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    CLASSE DE TERMOS    ////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_ClasseTermo::montar(){
    classetermo = new ClasseTermo;
    sucesso = true;
}


void TU_ClasseTermo::desmontar(){
    delete classetermo;
}

void TU_ClasseTermo::cenarioSucesso(){
    try{
        classetermo->setClasseTermo(classeValida);
        if(classetermo->getClasseTermo() != classeValida){
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_ClasseTermo::cenarioFalha(const string &classeInvalida){

    try{
        classetermo->setClasseTermo(classeInvalida);
            sucesso = false;
    }
    catch(invalid_argument excecao){
        return;
    }
}

void TU_ClasseTermo::executarTeste(){

    montar();
    cenarioSucesso();
    cenarioFalha(classeInvalida1);
    desmontar();

    cout << "Teste de classe de termo: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////            ENTIDADES            //////////////////////////////////////////////////////////////////
/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    LEITOR    //////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_Leitor::montar(){
    leitor = new Leitor;
    sucesso = true;
}


void TU_Leitor::desmontar(){
    delete leitor;
}

void TU_Leitor::cenarioSucesso(){

    try{

        leitor->setLeitor(nomeValido,sobrenomeValido,emailValido,senhaValida);

        if((leitor->getNome()!=nomeValido) && (leitor->getSobrenome()!=sobrenomeValido) && (leitor->getEmail()!=emailValido) && (leitor->getSenha()!=senhaValida)){
            sucesso = false;
        }
    }

    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_Leitor::executarTeste(){

    montar();
    cenarioSucesso();
    desmontar();

    cout << "Teste de leitor: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}

/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    DESENVOLVEDOR    ///////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_Desenvolvedor::montar(){
    desenvolvedor = new Desenvolvedor;
    sucesso = true;
}


void TU_Desenvolvedor::desmontar(){
    delete desenvolvedor;
}


void TU_Desenvolvedor::cenarioSucesso(){

    try{

        desenvolvedor->setDsv(nomeValido,sobrenomeValido,emailValido,senhaValida,dataValida);

        if((desenvolvedor->getNome() != nomeValido)           &&
           (desenvolvedor->getSobrenome() != sobrenomeValido) &&
           (desenvolvedor->getEmail() != emailValido)        &&
           (desenvolvedor->getSenha() != senhaValida)        &&
           (desenvolvedor->getData() != dataValida)) {
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_Desenvolvedor::executarTeste(){

    montar();
    cenarioSucesso();
    desmontar();

    cout << "Teste de desenvolvedor: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    ADMINISTRADOR    ///////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_Administrador::montar(){
    administrador = new Administrador;
    sucesso = true;
}


void TU_Administrador::desmontar(){
    delete administrador;
}


void TU_Administrador::cenarioSucesso(){

    try{

        administrador->setAdm(nomeValido,sobrenomeValido,emailValido,senhaValida,dataValida,telValido,enderecoValido);

        if((administrador->getNome() != nomeValido)             &&
           (administrador->getSobrenome() != sobrenomeValido)   &&
           (administrador->getEmail() != emailValido)           &&
           (administrador->getSenha() != senhaValida)           &&
           (administrador->getData() != dataValida)             &&
           (administrador->getTelefone() != telValido)          &&
           (administrador->getEndereco() != enderecoValido))    {
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_Administrador::executarTeste(){

    montar();
    cenarioSucesso();
    desmontar();

    cout << "Teste de administrador: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////        VOCABULARIO CONTROLADO        //////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_VocabularioCtrl::montar(){
    vocabulario = new VocabularioCtrl;
    sucesso = true;
}


void TU_VocabularioCtrl::desmontar(){
    delete vocabulario;
}


void TU_VocabularioCtrl::cenarioSucesso(){

    try{
        vocabulario->setVocab(nomeValido,dataValida,idiomaValido);

        if((vocabulario->getNome()!=nomeValido) && (vocabulario->getData()!=dataValida) && (vocabulario->getIdioma()!=idiomaValido)){
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_VocabularioCtrl::executarTeste(){

    montar();
    cenarioSucesso();
    desmontar();

    cout << "Teste de vocabulario: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////        TERMO        ///////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_Termo::montar(){
    termo = new Termo;
    sucesso = true;
}


void TU_Termo::desmontar(){
    delete termo;
}


void TU_Termo::cenarioSucesso(){

    try{

        termo->setTermo(nomeValido,dataValida,classeValida);

        if((termo->getNome()!=nomeValido) && (termo->getData()!=dataValida) && (termo->getClasseTermo()!=classeValida)){
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_Termo::executarTeste(){

    montar();
    cenarioSucesso();
    desmontar();

    cout << "Teste de termo: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////        DEFINICAO        ///////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TU_Definicao::montar(){
    definicao = new Definicao;
    sucesso = true;
}


void TU_Definicao::desmontar(){
    delete definicao;
}


void TU_Definicao::cenarioSucesso(){

    try{

        definicao->setDefinicao(dataValida,textoValido);

        if((definicao->getData()!=dataValida) && (definicao->getTextoDef()!=textoValido)){
            sucesso = false;
        }

    }
    catch(invalid_argument excecao){
        sucesso = false;
    }
}

void TU_Definicao::executarTeste(){

    montar();
    cenarioSucesso();
    desmontar();

    cout << "Teste de definicao: ";
    if (sucesso == true){
        cout << "SUCESSO." << endl;
    } else {
        cout << "FALHOU." << endl;
    }

    return;

}
