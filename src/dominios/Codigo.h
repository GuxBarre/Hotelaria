#ifndef CODIGO_H
#define CODIGO_H

#include <string>
#include <stdexcept>

/**
 * @brief Classe responsável por validar o Código de identificação.
 * Regras:
 * 1. Deve ter exatamente 10 caracteres.
 * 2. Cada caractere deve ser letra ou dígito.
 */
class Codigo {
    private:
        std::string valor; ///< Armazena o código.
        
        /**
         * @brief Valida as regras do código.
         * @param codigo String a ser validada.
         * @throw std::invalid_argument Se o tamanho for diferente de 10 ou contiver caracteres especiais.
         */
        void validar(const std::string& codigo) const;

    public:
        Codigo();
        explicit Codigo(const std::string& codigo);
        
        void setValor(const std::string& codigo);
        std::string getValor() const;
};

#endif