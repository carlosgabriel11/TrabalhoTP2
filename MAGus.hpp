#ifndef MAGUS_H_INCLUDED
#define MAGUS_H_INCLUDED

#include<stdexcept>

#include "interfaces.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include <cstdlib>

using namespace std;


/*

// Exemplifica controladora com m�ltiplos servi�os providos.

class Cntr_IA_GestaoUsuario:public IA_GestaoUsuario {

private:

    const static int INCLUIR   = 1;
    const static int REMOVER   = 2;
    const static int PESQUISAR = 3;
    const static int EDITAR    = 4;
    const static int RETORNAR  = 0;

    // Refer�ncia para servidor.

    IS_GestaoUsuario *ctrl_IS_GestaoUsuario;

    // M�todos respons�veis por prover os servi�os.

    void incluir();
    void remover();
    void pesquisar();
    void editar();

public:

    // M�todo previsto na interface por meio do qual � solicitada execu��o da controladora.

    void executar(const Email&);

    // M�todo por meio do qual � estabelecido relacionamento com o servidor.

    void setCtrl_IS_GestaoUsuario(IS_GestaoUsuario *ctrl_IS_GestaoUsuario){
        this->ctrl_IS_GestaoUsuario = ctrl_IS_GestaoUsuario;
    }
};
*/
#endif
