#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED

#include "entidades.hpp"

#include <string>

using namespace std;

// definicoes das classes correspondentes aos testes de cada dominio
// servem para testar algumas strings, se estao dentro dos requisitos ou nao
// cada teste de dominio tem um cenario de sucesso e pelo menos um de falha. Ja testes de entidade possuem apenas cenario de sucesso
// os testes lancam excessao em caso de falha


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    DOMINIOS    ////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TU_Nome {

    public:
        void executarTeste();
        bool sucesso; // variavel para identificar se o teste funcionou, independentemente do cenario

    private:
        Nome *nome;

        const string nomeValido = "Joao";
        const string nomeInvalido1 = "joao"; // inicial minuscula
        const string nomeInvalido2 = "Joao1"; //caractere invalido
        const string nomeInvalido3 = "Otorrinolaringologista"; // tamanho > 20

        void cenarioSucesso();
        void cenarioFalha(const string&);
        void montar();
        void desmontar();

};

class TU_Sobrenome : public TU_Nome {};

class TU_Telefone {

    public:
        void executarTeste();
        bool sucesso;

    private:
        Telefone *tel;

        const string telValido    = "61 98119-7229";
        const string telInvalido1 = "61981197229";
        const string telInvalido2 = "6198119-7229";
        const string telInvalido3 = "61 981197229";
        const string telInvalido4 = "61 8119-7229";

        void cenarioSucesso();
        void cenarioFalha(const string&);
        void montar();
        void desmontar();

};

class TU_Endereco {

    public:
        void executarTeste();
        bool sucesso;

    private:
        Endereco *endereco;

        const string enderecoValido    = "C.A.S, chac 94, lt 8";
        const string enderecoInvalido1 = "C.a.s,  chacara 94, lote 08, casa 3";
        const string enderecoInvalido2 = "C.A.S, +%&*~~";
        const string enderecoInvalido3 = " C.A.S, normal ";
        const string enderecoInvalido4 = "C.A.S dois  espacos";

        void cenarioSucesso();
        void cenarioFalha(const string&);
        void montar();
        void desmontar();

};

class TU_Data {

    public:
        void executarTeste();
        bool sucesso;

    private:
        Data *data;

        const string dataValida = "09/02/1996";
        const string dataInvalida1 = "09021996";
        const string dataInvalida2 = "09-02-1996";
        const string dataInvalida3 = "09/09/96";

        void cenarioSucesso();
        void cenarioFalha(const string&);
        void montar();
        void desmontar();

};

class TU_Email {

    public:
        void executarTeste();
        bool sucesso;

    private:
        Email *email;

        const string emailValido    = "jv_melop-96@gmail-com";
        const string emailInvalido1 = ".jv_melop.@gmail";
        const string emailInvalido2 = "jv_melop¬2@gmail";
        const string emailInvalido3 = "jv_melop@1928912";
        const string emailInvalido4 = "jv_melop.@-gmail";


        void cenarioSucesso();
        void cenarioFalha(const string&);
        void montar();
        void desmontar();

};

class TU_Senha {

    public:
        void executarTeste();
        bool sucesso;

    private:
        Senha *senha;

        const string senhaValida    = "hu3hu3BR";
        const string senhaInvalida1 = "hu3hu3B*";
        const string senhaInvalida2 = "huehueBR";
        const string senhaInvalida3 = "hu3hu3br";
        const string senhaInvalida4 = "HU3HU3BR";
        const string senhaInvalida5 = "hu3hu3Brasil";

        void cenarioSucesso();
        void cenarioFalha(const string&);
        void montar();
        void desmontar();

};

class TU_TextoDef {

    public:
        void executarTeste();
        bool sucesso;

    private:
        TextoDef *textodef;

        const string textoValido = "Aqui ha menos de 30 caracts";
        const string textoInvalido1 = "Aqui ha mais de 30 caracteres, pode ter ctz.";

        void cenarioSucesso();
        void cenarioFalha(const string&);
        void montar();
        void desmontar();

};

class TU_Idioma {

    public:
        void executarTeste();
        bool sucesso;

    private:
        Idioma *idioma;

        const string idiomaValido = "POR";
        const string idiomaInvalido1 = "JPN";

        void cenarioSucesso();
        void cenarioFalha(const string&);
        void montar();
        void desmontar();

};

class TU_ClasseTermo {

    public:
        void executarTeste();
        bool sucesso;

    private:
        ClasseTermo *classetermo;

        const string classeValida = "PT";
        const string classeInvalida1 = "NT";

        void cenarioSucesso();
        void cenarioFalha(const string&);
        void montar();
        void desmontar();

};


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    ENTIDADES    ///////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


class TU_Leitor {

    public:
        void executarTeste();
        bool sucesso;

    private:

        Leitor *leitor;

        const string nomeValido = "Joao";
        const string sobrenomeValido = "Peixoto";
        const string emailValido = "jvmelop@gmail-com";
        const string senhaValida = "hu3hu3BR";


        void montar();
        void cenarioSucesso();
        void desmontar();

};

class TU_Desenvolvedor {

    public:
        void executarTeste();
        bool sucesso;

    private:

        Desenvolvedor *desenvolvedor;

        const string nomeValido = "Joao";
        const string sobrenomeValido = "Peixoto";
        const string emailValido = "jvmelop@gmail-com";
        const string senhaValida = "joa4oOBR";
        const string dataValida = "09/02/1996";

        void montar();
        void cenarioSucesso();
        void desmontar();

};

class TU_Administrador {

    public:
        void executarTeste();
        bool sucesso;

    private:

        Administrador *administrador;

        const string nomeValido = "Joao";
        const string sobrenomeValido = "Peixoto";
        const string emailValido = "jvmelop@gmail-com";
        const string senhaValida = "joa4oOBR";
        const string dataValida = "09/02/1996";
        const string telValido = "61 98119-7229";
        const string enderecoValido = "C.A.S, chac 94, lt 8";


        void montar();
        void cenarioSucesso();
        void desmontar();

};

class TU_VocabularioCtrl{

    public:
        void executarTeste();
        bool sucesso;

    private:

        VocabularioCtrl *vocabulario;

        const string nomeValido = "Lista";
        const string dataValida = "14/04/2018";
        const string idiomaValido = "POR";


        void montar();
        void cenarioSucesso();
        void desmontar();

};

class TU_Termo{

    public:
        void executarTeste();
        bool sucesso;

    private:

        Termo *termo;

        const string nomeValido = "Exemplo";
        const string dataValida = "14/04/2018";
        const string classeValida = "NP";


        void montar();
        void cenarioSucesso();
        void desmontar();

};

class TU_Definicao{

    public:
        void executarTeste();
        bool sucesso;

    private:

        Definicao *definicao;

        const string dataValida = "14/04/2018";
        const string textoValido = "Apenas uma frase de teste aqui";


        void montar();
        void cenarioSucesso();
        void desmontar();

};

// classe que fara todos os testes de unidade ao mesmo tempo

class TU_Todos {

    private:

        TU_Nome testeNome;
        TU_Telefone testeTel;
        TU_Endereco testeEnd;
        TU_Data testeData;
        TU_Email testeEmail;
        TU_Senha testeSenha;
        TU_TextoDef testeTexto;
        TU_Idioma testeIdioma;
        TU_ClasseTermo testeClass;
        TU_Leitor testeLeitor;
        TU_Desenvolvedor testeDsv;
        TU_Administrador testeAdm;
        TU_VocabularioCtrl testeVocab;
        TU_Termo testeTermo;
        TU_Definicao testeDef;

    public:
        void executarTodosTestes();

};

#endif  // TESTE_H_INCLUDED
