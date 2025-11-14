#ifndef GERENTE_H
#define GERENTE_H

#include "Pessoa.h" // Classe mãe
#include "../dominios/Ramal.h"
#include "../dominios/Senha.h"

// Herda publicamente da classe Pessoa
class Gerente : public Pessoa {
    private:
        Ramal ramal;
        Senha senha;

    public:
        Gerente(const Nome& nome, const Email& email, const Ramal& ramal, const Senha& senha);

        Ramal getRamal() const;
        void setRamal(const Ramal& ramal);

        Senha getSenha() const;
        void setSenha(const Senha& senha);
};
#endif
