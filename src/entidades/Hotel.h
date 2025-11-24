#ifndef HOTEL_H
#define HOTEL_H

#include "../dominios/Nome.h"
#include "../dominios/Endereco.h"
#include "../dominios/Telefone.h"
#include "../dominios/Codigo.h"

#include "Quarto.h"
#include "../dominios/Numero.h"
#include <vector>

/**
 * @brief Entidade que representa um Hotel.
 * * A classe Hotel é composta por atributos básicos de identificação 
 * (Nome, Endereço, Telefone, Código) e gerencia uma lista de Quartos 
 * através de um relacionamento de composição.
 */
class Hotel {
    private:
        Nome nome;
        Endereco endereco;
        Telefone telefone;
        Codigo codigo;
        
        /**
         * @brief Lista de quartos pertencentes ao hotel.
         * Armazena os objetos Quarto associados a esta instância.
         */
        std::vector<Quarto> quartos;

    public:
        /**
         * @brief Construtor padrão da classe Hotel.
         * Inicializa uma instância vazia.
         */
        Hotel();

        /**
         * @brief Destrutor virtual da classe Hotel.
         */
        virtual ~Hotel();

        /**
         * @brief Define o nome do hotel.
         * @param nome Objeto da classe domínio Nome.
         */
        void setNome(const Nome& nome);

        /**
         * @brief Obtém o nome do hotel.
         * @return Objeto da classe domínio Nome.
         */
        Nome getNome() const;

        /**
         * @brief Define o endereço do hotel.
         * @param endereco Objeto da classe domínio Endereco.
         */
        void setEndereco(const Endereco& endereco);

        /**
         * @brief Obtém o endereço do hotel.
         * @return Objeto da classe domínio Endereco.
         */
        Endereco getEndereco() const;

        /**
         * @brief Define o telefone de contato do hotel.
         * @param telefone Objeto da classe domínio Telefone.
         */
        void setTelefone(const Telefone& telefone);

        /**
         * @brief Obtém o telefone do hotel.
         * @return Objeto da classe domínio Telefone.
         */
        Telefone getTelefone() const;

        /**
         * @brief Define o código identificador do hotel.
         * @param codigo Objeto da classe domínio Codigo.
         */
        void setCodigo(const Codigo& codigo);

        /**
         * @brief Obtém o código identificador do hotel.
         * @return Objeto da classe domínio Codigo.
         */
        Codigo getCodigo() const;

        // --- MÉTODOS DE GERENCIAMENTO DE QUARTOS ---

        /**
         * @brief Adiciona um novo quarto à lista do hotel.
         * @param quarto Objeto da entidade Quarto a ser incluído.
         */
        void adicionarQuarto(const Quarto& quarto);

        /**
         * @brief Obtém uma referência direta ao vetor de quartos.
         * * Este método é utilizado principalmente pela camada de persistência (Container)
         * para atualizar dados dos quartos diretamente na memória sem precisar remover e reinserir.
         * * @return Referência para std::vector<Quarto>.
         */
        std::vector<Quarto>& getQuartosRef();

        /**
         * @brief Obtém uma cópia da lista de quartos.
         * * Este método é utilizado para listagens e operações de leitura onde
         * não se deseja alterar o estado interno do objeto Hotel.
         * * @return Cópia de std::vector<Quarto>.
         */
        std::vector<Quarto> getQuartos() const;

        /**
         * @brief Remove um quarto da lista do hotel com base no número.
         * * Percorre a lista de quartos e remove o primeiro que corresponder ao número informado.
         * * @param numero Objeto domínio Numero identificador do quarto.
         * @return true se o quarto foi encontrado e removido.
         * @return false se o quarto não foi encontrado.
         */
        bool removerQuarto(const Numero& numero);
};

#endif // HOTEL_H