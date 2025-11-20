#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>
#include <stdexcept>

/**
 * @brief Classe responsável por armazenar e validar um endereço.
 * Regras de validação:
 * - O texto deve conter entre 5 e 30 caracteres.
 */
class Endereco {
private:
    std::string valor; ///< Armazena o texto do endereço.

    /**
     * @brief Valida as regras de negócio do endereço.
     * Verifica se o tamanho da string está dentro do intervalo permitido [5, 30].
     * @param endereco A string a ser verificada.
     * @throw std::invalid_argument Se o tamanho for inválido.
     */
    void validarEndereco(const std::string& endereco) const;

public:
    /**
     * @brief Construtor padrão.
     * Inicializa o objeto com uma string vazia.
     */
    Endereco();

    /**
     * @brief Construtor com inicialização e validação.
     * @param endereco O endereço a ser atribuído.
     * @throw std::invalid_argument Se o endereço for inválido.
     */
    explicit Endereco(const std::string& endereco);

    /**
     * @brief Define um novo endereço.
     * Substitui o valor atual se o novo passar na validação.
     * @param endereco O novo endereço.
     * @throw std::invalid_argument Se o endereço for inválido.
     */
    void setEndereco(const std::string& endereco);

    /**
     * @brief Recupera o endereço armazenado.
     * @return std::string O texto do endereço.
     */
    std::string getEndereco() const;
};

#endif