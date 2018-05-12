#include "entidades.hpp"


//funcao validar para as entidades de Leitor, Desenvolvedor e Administrador
//verifica se dentro da senha nao esta contido o nome do usuario
void Usuario::validar(string strNome, string strSenha) throw (invalid_argument){

    size_t found;

    for(int i=0; i<strNome.size(); i++){

        if( strNome[i]>='A' && strNome[i]<='Z')
            strNome[i] = strNome[i]+32; //
    }
    for(int i=0; i<strSenha.size(); i++){
        if( strSenha[i]>='A' && strSenha[i]<='Z')
            strSenha[i] = strSenha[i]+32; //
    }

    found = strSenha.find(strNome);

    if(found != string::npos){
        throw invalid_argument ("A senha não pode conter o nome de seu usuário.");
    }

    return;
}

// abaixo, as funcoes setEntidade, que atribuem as strings aos atributos do objeto


void Leitor::setLeitor(const string &strNome, const string &strSobrenome, const string &strEmail, const string &strSenha) throw (invalid_argument){

    // primeiro checa as restrições
    validar(strNome,strSenha);

    // depois, se forem validas, as strings sao atribuidas aos campos da classe
    nome.setNome(strNome);
    sobrenome.setNome(strSobrenome);
    email.setEmail(strEmail);
    senha.setSenha(strSenha);

    return;
}

void Desenvolvedor::setDsv(const string &strNome, const string &strSobrenome, const string &strEmail, const string &strSenha, const string &strData) throw (invalid_argument){

    validar(strNome,strSenha);

    nome.setNome(strNome);
    sobrenome.setNome(strSobrenome);
    email.setEmail(strEmail);
    senha.setSenha(strSenha);
    data.setData(strData);

    return;
}

void Administrador::setAdm( const string &strNome, const string &strSobrenome, const string &strEmail, const string &strSenha, const string &strData, const string &strTelefone, const string &strEndereco) throw (invalid_argument){

    validar(strNome,strSenha);

    nome.setNome(strNome);
    sobrenome.setNome(strSobrenome);
    email.setEmail(strEmail);
    senha.setSenha(strSenha);
    data.setData(strData);
    telefone.setTel(strTelefone);
    endereco.setEndereco(strEndereco);

    return;
}



void VocabularioCtrl::setVocab(const string &strNome, const string &strData, const string &strIdioma) throw (invalid_argument){

    nome.setNome(strNome);
    data.setData(strData);
    idioma.setIdioma(strIdioma);

    return;
};


void Termo::setTermo(const string &strNome, const string &strData, const string &strClasseTermo) throw (invalid_argument){

    nome.setNome(strNome);
    data.setData(strData);
    classetermo.setClasseTermo(strClasseTermo);

    return;
};


void Definicao::setDefinicao(const string &strData, const string &strTexto) throw (invalid_argument){

    data.setData(strData);
    texto.setTextoDef(strTexto);

    return;
};
