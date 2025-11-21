#ifndef RAMAL_H
#define RAMAL_H

#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
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
    int ramal;
    
    /**
     * @brief Valida se o ramal está dentro do intervalo permitido.
     * * @param ramal O inteiro a ser validado.
     * @throw invalid_argument Se o ramal for menor que 0 ou maior que 50.
     */
    void validar(int ramal);

public:
    /**
     * @brief Construtor padrão.
     * Inicializa o objeto com um estado padrão.
     */
    Ramal(); 

    /**
     * @brief Sobrecarga do operador de conversão para string.
     * * Permite que o objeto seja convertido implicitamente para uma string,
     * retornando o ramal armazenado internamente.
     * * @return string O ramal do atributo armazenado.
     */
    operator string() const;

    /**
     * @brief Construtor de inicialização.
     * * @param ramal Inteiro representando o ramal.
     * @throw invalid_argument Se o ramal estiver fora do intervalo de 0 a 50.
     */
    Ramal(int ramal); 
    
    virtual ~Ramal();

    /**
     * @brief Define o número do ramal.
     * * @param ramal Inteiro entre 0 e 50.
     * @throw invalid_argument Se o ramal violar a regra de intervalo.
     */
    void setRamal(int ramal);

    /**
     * @brief Recupera o número do ramal.
     * * @return int O ramal do ramal.
     */
    int getRamal() const;
};

#endif 