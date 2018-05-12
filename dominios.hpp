#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include<stdexcept>
#include<string>
#include<iostream>

using namespace std;


// definicoes das classes dos dominios, com seus atributos e metodos


class Nome {
    private:
        string nome;
        // funcao que verifica se a string eh valida
        void validar(const string &) throw (invalid_argument);

    public:
        // funcao que escreve no atributo
        void setNome(const string &) throw(invalid_argument);
        // funcao que retorna o atributo
        string getNome() const{
            return nome;
        }
};

// como a classe nome e sobrenome tem as mesmas restricoes, uma eh a copia da outra
class Sobrenome : public Nome {};


class Telefone {
    private:
        string tel;
        void validar(const string &) throw (invalid_argument);

    public:
        void setTel(const string &) throw(invalid_argument);
        string getTel() const{
            return tel;
        }
};


class Endereco {
    private:
        string endereco;
        void validar(const string&) throw (invalid_argument);

    public:
        void setEndereco(const string &) throw(invalid_argument);
        string getEndereco() const{
            return endereco;
        }
};


class Data {
    private:
        string data;
        void validar(const string&) throw (invalid_argument);

    public:
        void setData(const string &) throw(invalid_argument);
        string getData() const{
            return data;
        }
};


class Email {
    private:
        string email;
        void validar(const string&) throw (invalid_argument);

    public:
        void setEmail(const string &) throw(invalid_argument);
        string getEmail() const{
            return email;
        }
};

class Senha {
    private:
        string senha;
        void validar(const string&) throw (invalid_argument);

    public:
        void setSenha(const string &) throw(invalid_argument);
        string getSenha() const{
            return senha;
        }
};

class TextoDef {
    private:
        string textodef;
        void validar(const string&) throw (invalid_argument);

    public:
        void setTextoDef(const string &) throw(invalid_argument);
        string getTextoDef() const{
            return textodef;
        }
};

class Idioma {
    private:
        string idioma;
        void validar(const string&) throw (invalid_argument);

    public:
        void setIdioma(const string &) throw(invalid_argument);
        string getIdioma() const{
            return idioma;
        }
};

class ClasseTermo {
    private:
        string classetermo;
        void validar(const string&) throw (invalid_argument);

    public:
        void setClasseTermo(const string &) throw(invalid_argument);
        string getClasseTermo() const{
            return classetermo;
        }
};

#endif // DOMINIOS_H_INCLUDED
