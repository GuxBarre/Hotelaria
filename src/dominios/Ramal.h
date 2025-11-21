#ifndef RAMAL_H
#define RAMAL_H

#include <stdexcept>
#include <iostream>

// Domínio: Ramal
// Regras:
// 1. Valor inteiro.
// 2. Intervalo de 0 a 50 (inclusive).

class Ramal {
private:
    int valor;
    
    // Método auxiliar de validação
    void validar(int valor);

public:
    Ramal(); // Construtor padrão
    Ramal(int valor); // Construtor de inicialização
    virtual ~Ramal();

    void setValor(int valor);
    int getValor() const;
};

#endif // RAMAL_H