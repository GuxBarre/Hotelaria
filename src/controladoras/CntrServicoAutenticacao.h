#ifndef CNTR_SERVICO_AUTENTICACAO_H
#define CNTR_SERVICO_AUTENTICACAO_H

#include "../Interfaces.h"
#include "ContainerPessoal.h"
#include "../dominios/Email.h"
#include "../dominios/Senha.h"
#include "../entidades/Gerente.h"

class CntrServicoAutenticacao : public IServicoAutenticacao {
private:
    ContainerPessoal* container; 

public:
    void setContainer(ContainerPessoal* c) { 
        container = c; 
    }
    bool autenticar(const Email& email, const Senha& senha) override;
};

#endif