#ifndef GERENTE_H
#define GERENTE_H

#include "Pessoa.h" 
#include "../dominios/Ramal.h"
#include "../dominios/Senha.h"

/**
 * @brief Entidade que representa o Gerente do hotel.
 * Herda de Pessoa (que já contém Nome e Email).
 * Adiciona os atributos específicos: Ramal e Senha.
 */
class Gerente : public Pessoa {
    private:
        Ramal ramal;
        Senha senha;

    public:
        /**
         * @brief Construtor padrão.
         * Necessário para instanciar o objeto antes de definir os valores.
         */
        Gerente();

        /**
         * @brief Destrutor virtual.
         * Garante a destruição correta dos objetos herdados.
         */
        virtual ~Gerente();

        // Setters e Getters específicos de Gerente
        void setRamal(const Ramal& ramal);
        Ramal getRamal() const;

        void setSenha(const Senha& senha);
        Senha getSenha() const;
};

#endif // GERENTE_H