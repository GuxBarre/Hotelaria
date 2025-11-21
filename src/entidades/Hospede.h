#ifndef HOSPEDE_H
#define HOSPEDE_H

#include "Pessoa.h" 
#include "../dominios/Endereco.h"
#include "../dominios/Cartao.h"

/**
 * @brief Entidade que representa um Hóspede.
 * Herda de Pessoa (Nome, Email) e adiciona Endereço e Cartão.
 */
class Hospede : public Pessoa {
private:
    Endereco endereco;
    Cartao cartao;

public:
    /**
     * @brief Construtor padrão.
     */
    Hospede();

    /**
     * @brief Destrutor virtual.
     */
    virtual ~Hospede();

    void setEndereco(const Endereco& endereco);
    Endereco getEndereco() const;

    void setCartao(const Cartao& cartao);
    Cartao getCartao() const;
};

#endif // HOSPEDE_H