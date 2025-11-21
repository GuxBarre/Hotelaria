#ifndef CNTRAPRESENTACAOAUTENTICACAO_H
#define CNTRAPRESENTACAOAUTENTICACAO_H

#include "Interfaces.h"
#include "../dominios/Email.h"
#include "../dominios/Senha.h"

class CntrApresentacaoAutenticacao {
private:
    // Ponteiro para a interface do serviço (Desacoplamento)
    IServicoAutenticacao* servico;

public:
    // Injeta o serviço a ser usado
    void setServico(IServicoAutenticacao* servico);

    /**
     * @brief Executa o fluxo de autenticação.
     * @param email Ponteiro para armazenar o email autenticado (retorno).
     * @return true se login sucesso, false se falha.
     */
    bool autenticar(Email* email);
};

#endif