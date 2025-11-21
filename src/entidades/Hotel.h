#ifndef HOTEL_H
#define HOTEL_H

#include "../dominios/Nome.h"
#include "../dominios/Endereco.h"
#include "../dominios/Telefone.h"
#include "../dominios/Codigo.h"

/**
 * @brief Entidade que representa um Hotel.
 * Contém Nome, Endereço, Telefone e Código (Identificador).
 */
class Hotel {
    private:
        Nome nome;
        Endereco endereco;
        Telefone telefone;
        Codigo codigo;

    public:
        /**
         * @brief Construtor padrão.
         */
        Hotel();

        /**
         * @brief Destrutor virtual.
         */
        virtual ~Hotel();

        void setNome(const Nome& nome);
        Nome getNome() const;

        void setEndereco(const Endereco& endereco);
        Endereco getEndereco() const;

        void setTelefone(const Telefone& telefone);
        Telefone getTelefone() const;

        void setCodigo(const Codigo& codigo);
        Codigo getCodigo() const;
}; // <--- Faltava esse ponto e vírgula

#endif // HOTEL_H