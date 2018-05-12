#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.hpp"

#include <string>

using namespace std;

class Usuario {

protected:
    Nome nome;
    Nome sobrenome;
    Email email;
    Senha senha;

    //funcao que valida se a senha nao contem o nome
    void validar(string, string) throw (invalid_argument);

public:

    //funcoes que retornam as strings dos campos;

    string getNome() const {
        return nome.getNome();
    }

    string getSobrenome() const {
        return sobrenome.getNome();
    }
    string getEmail() const {
        return email.getEmail();
    }

    string getSenha() const {
        return senha.getSenha();
    }

};



class Leitor : public Usuario{

public:

    void setLeitor(const string&, const string&, const string&, const string&) throw (invalid_argument);

};

class Desenvolvedor : public Usuario{

private:

    Data data;

public:

    string getData() const {
        return data.getData();
    }

    void setDsv(const string&, const string&, const string&, const string&, const string&) throw (invalid_argument);

};

class Administrador : public Usuario{

private:

    Data data;
    Telefone telefone;
    Endereco endereco;

public:

    string getData() const {
        return data.getData();
    }
    string getTelefone() const {
        return telefone.getTel();
    }
    string getEndereco() const {
        return endereco.getEndereco();
    }



    void setAdm(const string&, const string&, const string&, const string&, const string&, const string&, const string&) throw (invalid_argument);

};


class VocabularioCtrl{

private:

    Nome nome;
    Idioma idioma;
    Data data;

public:

    string getData() const {
        return data.getData();
    }
    string getNome() const {
        return nome.getNome();
    }
    string getIdioma() const {
        return idioma.getIdioma();
    }



    void setVocab(const string&, const string&, const string&) throw (invalid_argument);

};

class Termo{

private:

    Nome nome;
    ClasseTermo classetermo;
    Data data;

public:

    string getData() const {
        return data.getData();
    }
    string getNome() const {
        return nome.getNome();
    }
    string getClasseTermo() const {
        return classetermo.getClasseTermo();
    }

    void setTermo(const string&, const string&, const string&) throw (invalid_argument);

};


class Definicao{

private:

    TextoDef texto;
    Data data;

public:

    string getData() const {
        return data.getData();
    }
    string getTextoDef() const {
        return texto.getTextoDef();
    }


    void setDefinicao(const string&, const string&) throw (invalid_argument);

};

#endif // ENTIDADES_H_INCLUDED
