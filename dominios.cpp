#include "dominios.hpp"

// variaveis globais para auxiliar na validacao da data

#define JANEIRO 1
#define FEVEREIRO 2
#define MARCO 3
#define ABRIL 4
#define MAIO 5
#define JUNHO 6
#define JULHO 7
#define AGOSTO 8
#define SETEMBRO 9
#define OUTUBRO 10
#define NOVEMBRO 11
#define DEZEMBRO 12


// abaixo, seguem as funcoes 'Dominio::setDominio' e 'Dominio::validar' de cada campo
// a funcao setDominio recebe uma string, valida-a, e se estiver ok atribui ao objeto
// a funcao validar verifica se a string obedece aos requisitos de formato, tamanho, caracteres, etc.

/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    NOME / SOBRENOME    ////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Nome::setNome(const string &str) throw (invalid_argument){
    validar(str);
    this->nome = str;

    return;
}


void Nome::validar(const string &str) throw (invalid_argument){

    const int LIMITE = 20;
    int tamanho = str.size();
    char inicial = str.front();

    //verifica o tamanho do nome
        if (tamanho<1 || tamanho>LIMITE){
            throw invalid_argument ("O tamanho do nome excede as especificações.\n");
        }

    //verifica se a primeira letra eh maiuscula
        if (inicial<'A' || inicial>'Z'){
            throw invalid_argument ("A letra inicial deve ser maiúscula.\n");
        }

    //verifica se contem apenas letras
        for(int i=0; i<tamanho; i++){
            if ((str[i]<'A') || (str[i]>'Z' && str[i]<'a') || (str[i]>'z')){
                throw invalid_argument ("O nome possui caractere inválido.\n");
            }
        }

        return;
}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    TELEFONE     ///////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Telefone::setTel(const string &str) throw (invalid_argument){
    validar(str);
    this->tel = str;

    return;
}


void Telefone::validar(const string &str) throw (invalid_argument){

    int tamanho = str.size();

    const int LIMITE = 13;   //    AA NNNNN-NNNN

    //verificar se o telefone foi digitado corretamente no formato 'AA NNNNN-NNNN', onde A e N sao numeros

    if (tamanho != LIMITE ){
        throw invalid_argument (" Telefone não digitado no formato correto 'AA NNNNN-NNNN'.\n");
    }

    if (str[2] != ' ' || str[8] != '-'){
        throw invalid_argument (" Telefone não digitado no formato correto 'AA NNNNN-NNNN'.\n");
    }

    for(int i=0; i<tamanho; i++){

        if (i==2 || i==8) i++;
        if (str[i] <'0' || str[i]>'9') {
            throw invalid_argument ("Digite apenas números seguindo o formato corretamente.\n");
        }
    }

    return;
}



/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    ENDEREÇO     ///////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Endereco::setEndereco(const string &str) throw (invalid_argument){
    validar(str);
    this->endereco = str;
}


void Endereco::validar(const string &str) throw (invalid_argument){

    int tamanho = str.size();

    const int LIMITE = 20;   //

    //verificar se o tamanho da string excede 20 caracteres

    if (tamanho > LIMITE ){
        throw invalid_argument ("Máximo permitido é de 20 caracteres.\n");
    }

    //veriicar se o primeiro e ultimo caractere nao sao espaco

    if (str.front() == ' ' || str.back() == ' '){
        throw invalid_argument ("O primeiro e o último caractere não podem ser espaço.\n");
    }

    // verificar se possui apenas digitos: Letras, numeros, ponto, virgula, barra e espaco
    // verificar se nao existem 2 espacos consecutivos

    for(int i=0; i<tamanho; i++){

        if (i<tamanho-1 && str[i]==' ' && str[i+1]==' '){
            throw invalid_argument ("Não é permitido dois espaços consecutivos.\n");
        }

        if ( (str[i]<'A' || str[i]>'Z') && (str[i]<'a' || str[i]>'z') && (str[i]<'0' || str[i]>'9') && str[i]!='.' && str[i]!=',' && str[i]!='/' && str[i]!=' '){
            throw invalid_argument ("Caractere inválido digitado. São permitidos apenas letras, números, ponto, vírgula e barra.\n");
        }
    }

    return;
}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    DATA    ////////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Data::setData(const string &str) throw (invalid_argument){
    validar(str);
    this->data = str;
}

// funcao que recebe uma string no formato "DD/MM/AAAA" e atribui a 3 inteiros (dia, mes e ano) passados por ponteiro
void converteDMA(string str, int* dia, int* mes, int* ano){


    string DD=str, MM=str, AAAA=str;

    DD.erase(2,8);
    *dia = stoi(DD);

    MM.erase(5,5);
    MM.erase(0,3);
    *mes = stoi(MM);

    AAAA.erase(0,6);
    *ano = stoi(AAAA);

    return;
}


void Data::validar(const string &str) throw (invalid_argument){

    int tamanho = str.size();
    const int LIMITE = 10;   //    DD/MM/AAAA
    int dia, mes, ano;
    const int anoMin = 1900, anoMax = 2099; // faixa de valores de ano em que o sistema opera


    //verificar se a data foi digitada corretamente no formato 'DD/MM/AAAA'

    if (tamanho != LIMITE ){
        throw invalid_argument ("Data não digitada no formato correto 'DD/MM/AAAA'.\n");
    }

    if (str[2] != '/' || str[5] != '/'){
        throw invalid_argument ("Data não digitada no formato correto 'DD/MM/AAAA'.\n");
    }

    for(int i=0; i<tamanho; i++){

        if (i==2 || i==5) i++;
        if (str[i] <'0' || str[i]>'9') {
            throw invalid_argument ("Digite apenas números e barra seguindo o formato 'DD/MM/AAAA'.\n");
        }
    }

    // verificar se a semantica entre dias, meses e anos bissexto esta correta

    converteDMA(str, &dia, &mes, &ano);

    if (ano< anoMin || ano> anoMax){
        throw invalid_argument ("Ano inválido.\n");
    }


    // se o mes tem 31 dias
    if(mes == ABRIL  || mes == JUNHO || mes == SETEMBRO || mes == NOVEMBRO){

        if(dia<1 || dia>30){
            throw invalid_argument ("Dia inválido.\n");
        }

    }
    // se o mes tem 31 dias
    else if (mes == JANEIRO || mes == MARCO || mes == MAIO || mes == JULHO || mes == AGOSTO || mes == OUTUBRO || mes == DEZEMBRO){

        if(dia<1 || dia>31){
            throw invalid_argument ("Dia inválido.\n");
        }

    }
    // se o mes eh fevereiro, DEVE-SE CONSIDERAR ANOS BISSEXTOS: multiplos de 4 e 400, exceto multiplos de 100
    else if (mes == FEVEREIRO){
        bool bissexto=false;

        if (ano%4==0){
            if (ano%100!=0){
                if (ano%400 ==0){
                    bissexto = true;
                }
            }
        }

        if (bissexto==false){
            if(dia<1 || dia>28){
                throw invalid_argument ("Dia inválido.\n");
            }
        }
        else{
            if(dia<1 || dia>29){
                throw invalid_argument ("Dia inválido.\n");
            }
        }

    }
    // se nao for nenhum mes
    else{
        throw invalid_argument ("Número de mês inválido.\n");
    }

    return;
}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    EMAIL    ///////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Email::setEmail(const string &str) throw (invalid_argument){

    validar(str);
    this->email = str;

    return;
}

void Email::validar(const string &str) throw (invalid_argument){

    int tamanho = str.size();
    size_t posicaoAT = str.find('@'); //posicao da string em que se encontra o @
    string local = str, dominio = str; //string para armazenar apenas parte local e outra para o dominio

    //verificar se existe o separador @
    if(posicaoAT==string::npos){
        throw invalid_argument ("O email deve estar no formato: partelocal@dominio.\n");
    }

    //agora eh possivel definir posicoes da parte local e dominio
    local.erase(posicaoAT,tamanho-posicaoAT);
    dominio.erase(0,posicaoAT+1);

    int tamanhoLocal = local.size();
    int tamanhoDominio = dominio.size();


    // PARTE LOCAL

    //verificar se a parte local nao comeca nem termina com '.'
    if(local.front()=='.' || local.back()=='.'){
        throw invalid_argument ("A parte local não pode ser iniciada ou terminada em '.'.\n");
    }

    //verificar se os caracteres sao validos
    for(int i=0; i<tamanhoLocal; i++){

        if ( (local[i]<'!' || local[i]>'~') ||
             (local[i] == '"' || local[i] == '(' || local[i] == ')' || local[i] == ',' || local[i] == ':' || local[i] == '<' ||
              local[i] == '=' || local[i] == '>' || local[i] == '@' || local[i] == '[' || local[i] == 92  || local[i] == ']') ) { // 92 eh a contra barra

            throw invalid_argument ("Caractere inválido na parte local.\n");
        }
    }

    // DOMINIO

    //verificar se o dominio nao comeca nem termina com -
    if(dominio.front()=='-' || dominio.back()=='-'){
        throw invalid_argument ("O dominio não pode ser iniciado ou terminado em '-'.\n");
    }

    bool apenasNumero = true;

    //verificar se os caracteres sao validos e se nao possui apenas numeros
    for(int i=0; i<tamanhoDominio; i++){

        if ( (dominio[i]<'A' || dominio[i]>'Z') && (dominio[i]<'a' || dominio[i]>'z') && (dominio[i]<'0' || dominio[i]>'9') && dominio[i]!= '-'){
            throw invalid_argument ("Caractere inválido no dominio.\n");
        }
        if( dominio[i]<'0' || dominio[i]>'9' ) {
            apenasNumero = false;
        }
    }
    if (apenasNumero == true){
        throw invalid_argument ("O dominio não pode conter apenas numeros.\n");
    }



    return;
}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    SENHA    ///////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Senha::setSenha(const string &str) throw (invalid_argument){

    validar(str);
    this->senha = str;

    return;
}

void Senha::validar(const string &str) throw (invalid_argument){

    int tamanho = str.size();
    bool maiuscula = false;
    bool minuscula = false;
    bool numero = false; //variaveis auxiliares para cumprir requisitos


    const int LIMITE = 8;

    //verificar se contém 8 caracteres
    if(tamanho > LIMITE){
        throw invalid_argument ("A senha deve conter 8 dígitos.\n");
    }

    //verificar se os caracteres sao validos
    for(int i=0; i<tamanho; i++){

        if ( (str[i]<'A' || str[i]>'Z') && (str[i]<'a' || str[i]>'z') && (str[i]<'0' || str[i]>'9')){
            throw invalid_argument ("Caractere inválido na parte local.\n");
        }

        if(str[i]>='A' && str[i]<='Z') maiuscula = true;
        if(str[i]>='a' && str[i]<='z') minuscula = true;
        if(str[i]>='0' && str[i]<='9') numero = true;
    }

    // verificar se os requisitos de pelo menos uma maiuscula, uma minuscula e um numero foram cumpridos

    if (maiuscula == false || minuscula == false || numero == false){
        throw invalid_argument ("A senha deve conter, pelo menos, uma letra maiúscula, uma letra minúscula e um dígito.\n");
    }

    return;
}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    TEXTO DE DEFINIÇÃO    //////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TextoDef::setTextoDef(const string &str) throw (invalid_argument){
    validar(str);
    this->textodef = str;

    return;
}

void TextoDef::validar(const string &str) throw (invalid_argument){

    int tamanho = str.size();

    const int LIMITE = 30;

    //verificar se contém ate 30 caracteres
    if(tamanho > LIMITE){
        throw invalid_argument ("O texto não pode ter tamanho maior que 30 caracteres.\n");
    }

    return;
}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    IDIOMA    //////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Idioma::setIdioma(const string &str) throw (invalid_argument){
    validar(str);
    this->idioma = str;

    return;
}

void Idioma::validar(const string &str) throw (invalid_argument){


    //unicos idiomas disponiveis: ENG, FRA, GER, ITA, POR e SPA. Caso contrario, erro

    if(str!= "ENG" && str!= "FRA" && str!= "GER" && str!= "ITA" && str!= "POR" && str!= "SPA"){
        throw invalid_argument ("Idioma inválido.\n");
    }

    return;
}


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////////////////    CLASSE DE TERMO    /////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ClasseTermo::setClasseTermo(const string &str) throw (invalid_argument){
    validar(str);
    this->classetermo = str;

    return;
}

void ClasseTermo::validar(const string &str) throw (invalid_argument){

    // so pode ser PT ou NP, caso contrario, erro

    if(str!= "PT" && str!= "NP"){
        throw invalid_argument ("Classe de termo inválida.\n");
    }

    return;
}
