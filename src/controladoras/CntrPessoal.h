#ifndef CNTR_SERVICO_PESSOAL_H
#define CNTR_SERVICO_PESSOAL_H

#include "../Interfaces.h"
#include "ContainerPessoal.h"
#include <vector>

class CntrServicoPessoal : public IServicoPessoal {
private:
    ContainerPessoal* container; // Ponteiro para o banco compartilhado

public:
    void setContainer(ContainerPessoal* c) { container = c; }

    bool criarHospede(const Hospede& hospede) override { return container->criarHospede(hospede); }
    bool lerHospede(const Email& email, Hospede* hospede) override { return container->lerHospede(email, hospede); }
    bool atualizarHospede(const Hospede& hospede) override { return container->atualizarHospede(hospede); }
    bool excluirHospede(const Email& email) override { return container->excluirHospede(email); }
    std::vector<Hospede> listarHospedes() override { return container->listarHospedes(); }

    bool criarGerente(const Gerente& gerente) override { return container->criarGerente(gerente); }
    bool lerGerente(const Email& email, Gerente* gerente) override { return container->lerGerente(email, gerente); }
    bool atualizarGerente(const Gerente& gerente) override { return container->atualizarGerente(gerente); }
    bool excluirGerente(const Email& email) override { return container->excluirGerente(email); }
};
#endif