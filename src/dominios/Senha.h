#ifndef SENHA_H
#define SENHA_H

#include <string>

/**
 * Classe de domínio para representar uma senha válida.
 */
class Senha {
private:
    std::string valor;

    void validar(const std::string &senha);

public:
    Senha() = default;

    /**
     * Define o valor da senha após validar.
     * Lança std::invalid_argument se a senha for inválida.
     */
    void setValor(const std::string &senha);

    /**
     * Retorna a senha armazenada.
     */
    std::string getValor() const;
};

#endif // SENHA_H
