#include "ContainerPessoal.h"
#include <iostream>

using namespace std;

ContainerPessoal::ContainerPessoal() {
    // Criar Gerente Admin padrão ao iniciar o container
    try {
        // Construtores de domínio validam formato
        Email emailAdmin("admin@admin.com");
        Senha senhaAdmin("A1b%2"); 
        Nome nomeAdmin("Administrador");

        Gerente admin;
        admin.setEmail(emailAdmin);
        admin.setSenha(senhaAdmin);
        admin.setNome(nomeAdmin);

        // Usa getEmail() conforme sua classe Email
        dbGerentes[emailAdmin.getEmail()] = admin; 

        cout << "[ContainerPessoal] Admin criado com sucesso.\n";

    } catch (const exception& e) {
        cout << "[ContainerPessoal] Erro ao criar Admin: " << e.what() << "\n";
    }
}

// ----------------------------------------------------------------------
// AUTENTICAÇÃO
// ----------------------------------------------------------------------
bool ContainerPessoal::validarLogin(const Email& email, const Senha& senha) {
    string chave = email.getEmail(); // Corrigido de getValor()

    if (dbGerentes.count(chave) == 0)
        return false;

    // Corrigido de getValor() para getSenha()
    return (dbGerentes[chave].getSenha().getSenha() == senha.getSenha());
}

// ----------------------------------------------------------------------
// CRUD GERENTE
// ----------------------------------------------------------------------
bool ContainerPessoal::criarGerente(const Gerente& gerente) {
    string chave = gerente.getEmail().getEmail(); // Corrigido

    if (dbGerentes.count(chave) > 0)
        return false; // já existe

    dbGerentes[chave] = gerente;
    return true;
}

bool ContainerPessoal::lerGerente(const Email& email, Gerente* gerente) {
    string chave = email.getEmail(); // Corrigido

    if (dbGerentes.count(chave) == 0)
        return false;

    *gerente = dbGerentes[chave];
    return true;
}

bool ContainerPessoal::atualizarGerente(const Gerente& gerente) {
    string chave = gerente.getEmail().getEmail(); // Corrigido

    if (dbGerentes.count(chave) == 0)
        return false;

    dbGerentes[chave] = gerente;
    return true;
}

bool ContainerPessoal::excluirGerente(const Email& email) {
    string chave = email.getEmail(); // Corrigido

    if (dbGerentes.count(chave) == 0)
        return false;

    dbGerentes.erase(chave);
    return true;
}

// ----------------------------------------------------------------------
// CRUD HÓSPEDE
// ----------------------------------------------------------------------
bool ContainerPessoal::criarHospede(const Hospede& hospede) {
    string chave = hospede.getEmail().getEmail(); // Corrigido

    if (dbHospedes.count(chave) > 0)
        return false;

    dbHospedes[chave] = hospede;
    return true;
}

bool ContainerPessoal::lerHospede(const Email& email, Hospede* hospede) {
    string chave = email.getEmail(); // Corrigido

    if (dbHospedes.count(chave) == 0)
        return false;

    *hospede = dbHospedes[chave];
    return true;
}

bool ContainerPessoal::atualizarHospede(const Hospede& hospede) {
    string chave = hospede.getEmail().getEmail(); // Corrigido

    if (dbHospedes.count(chave) == 0)
        return false;

    dbHospedes[chave] = hospede;
    return true;
}

bool ContainerPessoal::excluirHospede(const Email& email) {
    string chave = email.getEmail(); // Corrigido

    if (dbHospedes.count(chave) == 0)
        return false;

    dbHospedes.erase(chave);
    return true;
}

// ----------------------------------------------------------------------
// LISTAGEM
// ----------------------------------------------------------------------
vector<Hospede> ContainerPessoal::listarHospedes() {
    vector<Hospede> lista;
    for (auto& par : dbHospedes) {
        lista.push_back(par.second);
    }
    return lista;
}