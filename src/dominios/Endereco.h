#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>
#include <stdexcept>
using namespace std;
/**
 * @brief Classe responsável por armazenar e validar um endereço.
 * Regras de validação:
 * - O texto deve conter entre 5 e 30 caracteres.
 */
class Endereco {
private:
    string endereco; ///< Armazena o texto do endereço.

    /**
     * @brief Valida as regras de negócio do endereço.
     * Verifica se o tamanho da string está dentro do intervalo permitido [5, 30].
     * @param endereco A string a ser verificada.
     * @throw invalid_argument Se o tamanho for inválido.
     */
    void validarEndereco(const string& endereco) const;

public:
    /**
     * @brief Construtor padrão.
     * Inicializa o objeto com uma string vazia.
     */
    Endereco();

    /**
     * @brief Sobrecarga do operador de conversão para string.
     * * Permite que o objeto seja convertido implicitamente para uma string,
     * retornando o endereco armazenado internamente.
     * * @return string O endereco do atributo armazenado.
     */
    operator string() const;

    /**
     * @brief Construtor com inicialização e validação.
     * @param endereco O endereço a ser atribuído.
     * @throw invalid_argument Se o endereço for inválido.
     */
    explicit Endereco(const string& endereco);

    /**
     * @brief Define um novo endereço.
     * Substitui o endereco atual se o novo passar na validação.
     * @param endereco O novo endereço.
     * @throw invalid_argument Se o endereço for inválido.
     */
    void setEndereco(const string& endereco);

    /**
     * @brief Recupera o endereço armazenado.
     * @return string O texto do endereço.
     */
    string getEndereco() const;
};

#endif