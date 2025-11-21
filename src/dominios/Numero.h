#ifndef NUMERO_H
#define NUMERO_H

#include <stdexcept>
#include <iostream>

// Domínio: Numero
// Regras: 
// 1. Valor inteiro.
// 2. Intervalo de 1 a 999 (inclusive).

class Numero {
private:
    int valor;
    
    // Método auxiliar para validar a regra do intervalo
    void validar(int valor);

public:
    Numero(); // Construtor padrão
    Numero(int valor); // Construtor de inicialização
    virtual ~Numero();

    void setValor(int valor);
    int getValor() const;
};

#endif // NUMERO_H