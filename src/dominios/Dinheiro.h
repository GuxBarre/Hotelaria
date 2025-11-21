#ifndef DINHEIRO_H
#define DINHEIRO_H

#include <stdexcept>
#include <iostream>

// Domínio: Dinheiro
// Regras: 
// 1. Valor entre 0,01 e 1.000.000,00
// 2. Armazenamento interno em INTEIRO (centavos)

class Dinheiro {
private:
    long long valorCentavos; // Usamos long long para garantir espaço, embora int servisse.
    
    // Método auxiliar para validar as regras
    void validar(long long valor);

public:
    Dinheiro(); // Construtor padrão
    Dinheiro(double valor); // Construtor de inicialização
    virtual ~Dinheiro();

    void setValor(double valor);
    double getValor() const; // Retorna double para uso externo, mas converte do inteiro interno
};

#endif // DINHEIRO_H