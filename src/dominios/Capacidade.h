#ifndef CAPACIDADE_H
#define CAPACIDADE_H

#include <stdexcept>

/**
 * @brief Classe responsável por validar a capacidade de acomodação.
 * Regra: Apenas 1, 2, 3 ou 4 pessoas.
 */
class Capacidade {
    private:
        int valor;
        void validar(int valor) const;

    public:
        Capacidade();
        explicit Capacidade(int valor);
        void setValor(int valor);
        int getValor() const;
};

#endif