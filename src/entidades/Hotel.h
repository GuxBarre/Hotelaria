#ifndef HOTEL_H
#define HOTEL_H

#include "../dominios/Nome.h"
#include "../dominios/Endereco.h"
#include "../dominios/Telefone.h"
#include "../dominios/Codigo.h"

class Hotel {
    private:
        Nome nome;
        Endereco endereco;
        Telefone telefone;
        Codigo codigo;

    public:
        Hotel(const Nome& nome, const Endereco& endereco, const Telefone& telefone, const Codigo& codigo);

        void setNome(const Nome& nome);
        Nome getNome() const;

        void setEndereco(const Endereco& endereco);
        Endereco getEndereco() const;

        void setTelefone(const Telefone& telefone);
        Telefone getTelefone() const;

        void setCodigo(const Codigo& codigo);
        Codigo getCodigo() const;
}
#endif
