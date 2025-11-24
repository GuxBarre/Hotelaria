#include "CntrServicoAutenticacao.h"

bool CntrServicoAutenticacao::autenticar(const Email& email, const Senha& senha) {
    Gerente gerenteRecuperado;
    bool existe = container->lerGerente(email, &gerenteRecuperado);

    if (existe) {
        string senhaArmazenada = gerenteRecuperado.getSenha();
        string senhaFornecida = senha.getSenha();

        if (senhaArmazenada == senhaFornecida) {
            return true;
        }
    }
    return false;
}