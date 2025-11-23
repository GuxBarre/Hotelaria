#ifndef CONTAINER_PESSOAL_H
#define CONTAINER_PESSOAL_H

#include "../dominios/Email.h"
#include "../dominios/Senha.h" // Necessário para criar o admin
#include "../dominios/Nome.h"  // Necessário para criar o admin
#include "../entidades/Gerente.h"
#include "../entidades/Hospede.h"
#include <vector>
#include <map>
#include <string>

class ContainerPessoal {
private:
    std::map<std::string, Gerente> dbGerentes;
    std::map<std::string, Hospede> dbHospedes;

public:
    ContainerPessoal(); 

    // Autenticação
    bool validarLogin(const Email& email, const Senha& senha);

    // CRUD Gerente
    bool criarGerente(const Gerente& gerente);
    bool lerGerente(const Email& email, Gerente* gerente);
    bool atualizarGerente(const Gerente& gerente);
    bool excluirGerente(const Email& email);

    // CRUD Hospede
    bool criarHospede(const Hospede& hospede);
    bool lerHospede(const Email& email, Hospede* hospede);
    bool atualizarHospede(const Hospede& hospede);
    bool excluirHospede(const Email& email);

    // Listagens
    std::vector<Hospede> listarHospedes();
};

#endif