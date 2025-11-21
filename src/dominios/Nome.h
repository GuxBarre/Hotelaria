#ifndef NOME_H
#define NOME_H

#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
/**
 * @class Nome
 * @brief Representa o domínio de nome de pessoa ou hotel.
 * * @details
 * Regras de formato válido conforme especificação:
 * - Tamanho: 5 a 20 caracteres.
 * - Caracteres permitidos: Apenas letras (A-Z, a-z) ou espaço em branco.
 * - Formatação: O primeiro caractere de cada termo deve ser letra maiúscula (A-Z).
 * - Espaços: Espaço em branco deve ser seguido por letra (não permite espaços consecutivos).
 * - O último caractere não pode ser um espaço em branco.
 */
class Nome {
private:
    string nome;
    
    /**
     * @brief Valida se o nome obedece às regras de formatação e tamanho.
     * * @param nome A string a ser validada.
     * @throw invalid_argument Se o nome for muito curto/longo, contiver caracteres inválidos, termos minúsculos ou espaços mal posicionados.
     */
    void validar(string nome);

public:
    /**
     * @brief Construtor padrão.
     * Inicializa o objeto com estado vazio.
     */
    Nome();

    /**
     * @brief Construtor de inicialização.
     * * Já realiza a validação do nome fornecido.
     * * @param nome String representando o nome.
     * @throw invalid_argument Se o formato for inválido.
     */
    Nome(string nome);

    /**
     * @brief Sobrecarga do operador de conversão para string.
     * * Permite que o objeto seja convertido implicitamente para uma string,
     * retornando o valor armazenado internamente.
     * * @return string O valor do atributo armazenado.
     */
    operator string() const; 

    virtual ~Nome();

    /**
     * @brief Define o nome.
     * * Verifica todas as regras (tamanho, capitalização e espaços) antes de armazenar.
     * * @param nome String do nome (ex: "Hotel California").
     * @throw invalid_argument Se o nome não atender às regras de negócio.
     */
    void setNome(string nome);

    /**
     * @brief Recupera o nome armazenado.
     * * @return string O nome atual.
     */
    string getNome() const;
};

#endif