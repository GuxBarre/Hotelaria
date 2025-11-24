#ifndef PESSOA_H
#define PESSOA_H

#include "../dominios/Nome.h"
#include "../dominios/Email.h"

/**
 * @brief Entidade que representa uma Pessoa no sistema.
 * * Classe base que contém os dados comuns a todos os usuários do sistema.
 * Serve de generalização para as classes derivadas (Hospede e Gerente).
 * Conforme o diagrama de classes, o Email é utilizado como chave primária (PK).
 */
class Pessoa {
private:
    Nome nome;
    Email email;

public:
    /**
     * @brief Construtor padrão da classe Pessoa.
     * Inicializa uma instância sem dados definidos.
     */
    Pessoa();

    /**
     * @brief Destrutor virtual da classe Pessoa.
     * Essencial para garantir a destruição correta dos objetos das classes 
     * derivadas (Gerente e Hospede) quando manipulados via polimorfismo.
     */
    virtual ~Pessoa();

    /**
     * @brief Define o nome da pessoa.
     * @param nome Objeto da classe domínio Nome já validado.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Define o email da pessoa (Chave Primária).
     * @param email Objeto da classe domínio Email já validado.
     */
    void setEmail(const Email& email);

    /**
     * @brief Obtém o nome da pessoa.
     * @return Objeto da classe domínio Nome (cópia).
     */
    Nome getNome() const;

    /**
     * @brief Obtém o email da pessoa.
     * @return Objeto da classe domínio Email (cópia).
     */
    Email getEmail() const;
};

#endif // PESSOA_H