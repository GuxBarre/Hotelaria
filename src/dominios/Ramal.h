#ifndef RAMAL_H
#define RAMAL_H

#include <stdexcept>
#include <iostream>

/**
 * @class Ramal
 * @brief Representa o domínio de Ramal telefônico.
 * * @details
 * Regras de formato válido conforme especificação:
 * - Deve ser um número inteiro.
 * - Intervalo permitido: 0 a 50 (inclusive).
 */
class Ramal {
private:
    int valor;
    
    /**
     * @brief Valida se o ramal está dentro do intervalo permitido.
     * * @param valor O inteiro a ser validado.
     * @throw std::invalid_argument Se o valor for menor que 0 ou maior que 50.
     */
    void validar(int valor);

public:
    /**
     * @brief Construtor padrão.
     * Inicializa o objeto com um estado padrão.
     */
    Ramal(); 

    /**
     * @brief Construtor de inicialização.
     * * @param valor Inteiro representando o ramal.
     * @throw std::invalid_argument Se o valor estiver fora do intervalo de 0 a 50.
     */
    Ramal(int valor); 
    
    virtual ~Ramal();

    /**
     * @brief Define o número do ramal.
     * * @param valor Inteiro entre 0 e 50.
     * @throw std::invalid_argument Se o valor violar a regra de intervalo.
     */
    void setRamal(int valor);

    /**
     * @brief Recupera o número do ramal.
     * * @return int O valor do ramal.
     */
    int getRamal() const;
};

#endif 