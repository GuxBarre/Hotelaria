#ifndef DATA_H
#define DATA_H

#include <string>
#include <stdexcept>
#include <vector>
using namespace std;
/**
 * @brief Classe para representação e validação de datas.
 * * Armazena internamente a data em inteiros (dia, mês, ano), mas permite
 * a manipulação via string (geralmente no formato DD/MM/AAAA ou similar).
 */
class Data {
private:
    int dia; ///< Representa o dia do mês.
    int mes; ///< Representa o mês (1-12).
    int ano; ///< Representa o ano.

    /**
     * @brief Lista estática com os nomes ou siglas dos meses.
     * Útil para conversão de string para int e vice-versa.
     */
    static const vector<string> MESES;

    /**
     * @brief Converte o nome/sigla do mês para seu número correspondente.
     * @param mesStr String contendo o mês (ex: "Jan", "Fev").
     * @return int Número do mês (1 a 12).
     */
    int converterMes(const string& mesStr) const; 

    /**
     * @brief Converte o número do mês para sua representação em string.
     * @param mesInt Número do mês (1 a 12).
     * @return string Nome ou sigla do mês.
     */
    string converterMes(int mesInt) const;

    /**
     * @brief Verifica se um ano é bissexto.
     * @param ano O ano a ser verificado.
     * @return true Se for bissexto.
     * @return false Se não for bissexto.
     */
    bool Bissexto(int ano) const;

    /**
     * @brief Valida se os componentes da data formam uma data gregoriana válida.
     * @param dia Dia a validar.
     * @param mes Mês a validar.
     * @param ano Ano a validar.
     * @throw invalid_argument Se a data for inválida.
     */
    void validarData(int dia, int mes, int ano) const;

public:
    /**
     * @brief Construtor padrão.
     * Inicializa a data com valores padrão (ex: data atual ou vazia).
     */
    Data();

    /**
     * @brief Sobrecarga do operador de conversão para string.
     * * Permite que o objeto seja convertido implicitamente para uma string,
     * retornando o valor armazenado internamente.
     * * @return string O valor do atributo armazenado.
     */
    operator string() const;

    /**
     * @brief Construtor que inicializa a data a partir de uma string.
     * @param dataStr String contendo a data formatada.
     * @throw invalid_argument Se o formato for inválido.
     */
    explicit Data(const string& dataStr);
    
    /**
     * @brief Define uma nova data a partir de uma string.
     * Valida e atualiza os campos internos.
     * @param dataStr String contendo a nova data.
     * @throw invalid_argument Se a data for inválida.
     */
    void setData(const string& dataStr);

    /**
     * @brief Retorna a data formatada como string.
     * @return string A data no formato padrão da classe (ex: "DD/MM/AAAA").
     */
    string getData() const;

};
#endif