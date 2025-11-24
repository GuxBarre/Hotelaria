#ifndef CNTRAPRESENTACAOAUTENTICACAO_H
#define CNTRAPRESENTACAOAUTENTICACAO_H

#include "../Interfaces.h"
#include "../dominios/Email.h"
#include "../dominios/Senha.h"
#include "../dominios/Nome.h"
#include "../dominios/Ramal.h"
#include "../entidades/Gerente.h"

class CntrApresentacaoAutenticacao {
private:
    IServicoAutenticacao* servicoAuth;
    IServicoPessoal* servicoPessoal;

public:
    void setServicoAutenticacao(IServicoAutenticacao* servico);
    void setServicoPessoal(IServicoPessoal* servico);

    bool autenticar(Email* email);
    void cadastrar();
};

#endif