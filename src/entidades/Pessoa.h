#ifndef PESSOA_H
#define PESSOA_H


#include "../dominios/Nome.h"
#include "../dominios/Email.h"

class Pessoas {
    private:
        Nome nome;
        Email email;

    public:

    // Construtor
    Pessoa(const Nome& nome, const Email& email):;

    // Nome pode ser alterado
    void setNome(const Nome& nome);
    Nome getNome() const;

    // Email não pode ser alterado
    Email getEmail() const;

};

#endif