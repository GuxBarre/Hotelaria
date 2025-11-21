#ifndef EMAIL_H
#define EMAIL_H

#include <string>

/**
 * Classe de domínio para representar um endereço de e-mail válido.
 */
class Email {
private:
    std::string valor;

    void validar(const std::string &email);

public:
    Email() = default;

    /**
     * Define o valor do e-mail após validar.
     * Lança std::invalid_argument se o e-mail for inválido.
     */
    void setValor(const std::string &email);

    /**
     * Retorna o e-mail armazenado.
     */
    std::string getValor() const;
};

#endif // EMAIL_H
