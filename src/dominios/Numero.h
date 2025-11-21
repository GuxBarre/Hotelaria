#ifndef NUMERO_H
#define NUMERO_H

#include <stdexcept>
#include <iostream>

/**
 * @class Numero
 * @brief Representa o domínio de número de quarto.
 * * @details
 * Regras de formato válido conforme especificação:
 * - Deve ser um valor inteiro.
 * - Intervalo permitido: 1 a 999 (inclusive).
 */
class Numero {
private:
    int valor;
    
    /**
     * @brief Valida se o número está dentro do intervalo permitido.
     * * @param valor O inteiro a ser validado.
     * @throw std::invalid_argument Se o valor for menor que 1 ou maior que 999.
     */
    void validar(int valor);

public:
    /**
     * @brief Construtor padrão.
     * Inicializa o objeto com um estado padrão.
     */
    Numero(); 

    /**
     * @brief Construtor de inicialização.
     * * Já instancia o objeto validando o número fornecido.
     * * @param valor Inteiro representando o número do quarto.
     * @throw std::invalid_argument Se o valor estiver fora do intervalo de 1 a 999.
     */
    Numero(int valor); 
    
    virtual ~Numero();

    /**
     * @brief Define o número do quarto.
     * * @param valor Inteiro entre 1 e 999.
     * @throw std::invalid_argument Se o valor violar a regra de intervalo.
     */
    void setValor(int valor);

    /**
     * @brief Recupera o número armazenado.
     * * @return int O número do quarto.
     */
    int getValor() const;
};

#endif // NUMERO_H