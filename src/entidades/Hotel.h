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
 * Contém Nome, Endereço, Telefone, Código e sua lista de Quartos.
 */
class Hotel {
    private:
        Nome nome;
        Endereco endereco;
        Telefone telefone;
        Codigo codigo;
        std::vector<Quarto> quartos;

    public:
        Hotel();
        virtual ~Hotel();

        void setNome(const Nome& nome);
        Nome getNome() const;

        void setEndereco(const Endereco& endereco);
        Endereco getEndereco() const;

        void setTelefone(const Telefone& telefone);
        Telefone getTelefone() const;

        void setCodigo(const Codigo& codigo);
        Codigo getCodigo() const;
        void adicionarQuarto(const Quarto& quarto);
        std::vector<Quarto>& getQuartosRef();
        std::vector<Quarto> getQuartos() const;
        bool removerQuarto(const Numero& numero);
};

#endif