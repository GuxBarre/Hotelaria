#ifndef PESSOA_H
#define PESSOA_H

#include "../dominios/Nome.h"
#include "../dominios/Email.h"

/**
 * @brief Entidade que representa uma Pessoa no sistema.
 * * Classe base que contém os dados comuns a todos os usuários (Nome e Email).
 * Conforme diagrama, o Email é a chave primária (PK).
 */
class Pessoa {
private:
    Nome nome;
    Email email;

public:
    Pessoa();
    virtual ~Pessoa();

    void setNome(const Nome& nome);
    void setEmail(const Email& email);

    Nome getNome() const;
    Email getEmail() const;
};

#endif // PESSOA_H