#ifndef HOSPEDE_H
#define HOSPEDE_H

#include "Pessoa.h" 

#include "../dominios/Endereco.h"
#include "../dominios/Cartao.h"

class Hospede : public Pessoa{
private:
    Endereco endereco;
    Cartao cartao;

public:
    Hospede(const Nome& nome, const Email& email, const Endereco& endereco, const Cartao& cartao);

    void setEndereco(const Endereco& endereco);
    Endereco getEndereco() const;

    void setCartao(const Cartao& cartao);
    Cartao getCartao() const;
};
#endif
