#ifndef NOME_H
#define NOME_H

#include <string>
#include <stdexcept>
#include <iostream>

// Domínio: Nome
// Regras:
// 1. 5 a 20 caracteres.
// 2. Apenas letras (A-Z, a-z) ou espaço.
// 3. Primeira letra de cada termo deve ser Maiúscula.
// 4. Não pode haver espaços seguidos.
// 5. Não pode terminar com espaço.

class Nome {
private:
    std::string nome;
    
    // Método auxiliar de validação
    void validar(std::string nome);

public:
    Nome();
    Nome(std::string nome);
    virtual ~Nome();

    void setNome(std::string nome);
    std::string getNome() const;
};

#endif // NOME_H