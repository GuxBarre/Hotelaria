#ifndef RESERVA_H
#define RESERVA_H

#include "../dominios/Codigo.h"
#include "../dominios/Data.h"
#include "../dominios/Dinheiro.h"

/**
 * @brief Entidade que representa uma Reserva.
 * * Armazena os dados referentes ao agendamento de uma estadia,
 * incluindo o identificador único (Código), o período de permanência
 * (Datas de Chegada e Partida) e o custo total calculado (Valor).
 */
class Reserva {
private:
    Codigo codigo;
    Data chegada;
    Data partida;
    Dinheiro valor;

public:
    /**
     * @brief Construtor padrão da classe Reserva.
     * Inicializa uma instância sem valores definidos.
     */
    Reserva();

    /**
     * @brief Destrutor virtual da classe Reserva.
     */
    virtual ~Reserva();

    /**
     * @brief Define o código da reserva.
     * @param codigo Objeto da classe domínio Codigo.
     */
    void setCodigo(const Codigo& codigo);

    /**
     * @brief Obtém o código da reserva.
     * @return Objeto da classe domínio Codigo.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define a data de chegada (Check-in).
     * @param chegada Objeto da classe domínio Data.
     */
    void setChegada(const Data& chegada);

    /**
     * @brief Obtém a data de chegada.
     * @return Objeto da classe domínio Data.
     */
    Data getChegada() const;

    /**
     * @brief Define a data de partida (Check-out).
     * @param partida Objeto da classe domínio Data.
     */
    void setPartida(const Data& partida);

    /**
     * @brief Obtém a data de partida.
     * @return Objeto da classe domínio Data.
     */
    Data getPartida() const;

    /**
     * @brief Define o valor total da reserva.
     * @param valor Objeto da classe domínio Dinheiro.
     */
    void setValor(const Dinheiro& valor);

    /**
     * @brief Obtém o valor total da reserva.
     * @return Objeto da classe domínio Dinheiro.
     */
    Dinheiro getValor() const;
};

#endif // RESERVA_H