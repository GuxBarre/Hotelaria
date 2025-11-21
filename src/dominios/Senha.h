#ifndef SENHA_H
#define SENHA_H

#include <string>
#include <stdexcept>
#include <iostream>

// Domínio: Senha
// Regras:
// 1. Exatamente 5 caracteres.
// 2. Caracteres permitidos: Letras (A-Z, a-z), Dígitos (0-9), Especiais (! " # $ % & ?).
// 3. Não pode haver letras consecutivas.
// 4. Não pode haver dígitos consecutivos.
// 5. Deve conter pelo menos: 1 maiúscula, 1 minúscula, 1 dígito, 1 especial.

class Senha {
private:
    std::string valor;

    // Método auxiliar de validação
    void validar(std::string senha);

public:
    Senha(); // Construtor padrão
    Senha(std::string senha); // Construtor de inicialização
    virtual ~Senha();

    void setValor(std::string senha);
    std::string getValor() const;
};

#endif // SENHA_H