//#include "teste.hpp"
#include <locale.h>

#include "MAAut.hpp"
#include "controladores.hpp";
#include "entidades.hpp"

using namespace std;

/*

    ALUNO:      JOAO VITOR DE MELO PEIXOTO
    MATRICULA:  14/0056408

*/

int main(){
    //habilita a acentuacao para o portugues
    setlocale(LC_ALL, "Portuguese");


    Controle programa;

    programa.start();



    return 0;
}
