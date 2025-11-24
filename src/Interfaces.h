#ifndef INTERFACES_H
#define INTERFACES_H

#include "entidades/Gerente.h"
#include "entidades/Hotel.h"
#include "entidades/Quarto.h"
#include "entidades/Hospede.h"
#include "entidades/Reserva.h"

#include <vector>
#include <string>

/**
 * @brief Interface para o Serviço de Autenticação.
 * * Define o contrato para validação de credenciais de usuários (Login).
 */
class IServicoAutenticacao {
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~IServicoAutenticacao() {}

    /**
     * @brief Valida as credenciais de um usuário.
     * @param email O email fornecido.
     * @param senha A senha fornecida.
     * @return true se as credenciais forem válidas e existirem no banco.
     * @return false caso contrário.
     */
    virtual bool autenticar(const Email& email, const Senha& senha) = 0;
};

/**
 * @brief Interface para o Serviço de Gestão Pessoal.
 * * Define as operações CRUD (Criar, Ler, Atualizar, Excluir) para
 * as entidades Gerente e Hóspede.
 */
class IServicoPessoal {
public:
    virtual ~IServicoPessoal() {}
    /**
     * @brief Cadastra um novo gerente no sistema.
     * @param gerente Objeto com os dados do gerente.
     * @return true se o cadastro for realizado com sucesso.
     */
    virtual bool criarGerente(const Gerente& gerente) = 0;

    /**
     * @brief Recupera os dados de um gerente através do email.
     * @param email Email do gerente a ser buscado (Chave de busca).
     * @param gerente Ponteiro onde os dados recuperados serão armazenados.
     * @return true se o gerente for encontrado.
     */
    virtual bool lerGerente(const Email& email, Gerente* gerente) = 0;

    /**
     * @brief Atualiza os dados de um gerente existente.
     * @param gerente Objeto com os novos dados (Email deve corresponder a um existente).
     * @return true se a atualização for bem-sucedida.
     */
    virtual bool atualizarGerente(const Gerente& gerente) = 0;

    /**
     * @brief Remove um gerente do sistema.
     * @param email Email do gerente a ser excluído.
     * @return true se a exclusão for realizada.
     */
    virtual bool excluirGerente(const Email& email) = 0;
    /**
     * @brief Cadastra um novo hóspede no sistema.
     * @param hospede Objeto com os dados do hóspede.
     * @return true se o cadastro for realizado com sucesso.
     */
    virtual bool criarHospede(const Hospede& hospede) = 0;

    /**
     * @brief Recupera os dados de um hóspede através do email.
     * @param email Email do hóspede a ser buscado.
     * @param hospede Ponteiro onde os dados recuperados serão armazenados.
     * @return true se o hóspede for encontrado.
     */
    virtual bool lerHospede(const Email& email, Hospede* hospede) = 0;

    /**
     * @brief Atualiza os dados de um hóspede existente.
     * @param hospede Objeto com os novos dados.
     * @return true se a atualização for bem-sucedida.
     */
    virtual bool atualizarHospede(const Hospede& hospede) = 0;

    /**
     * @brief Remove um hóspede do sistema.
     * @param email Email do hóspede a ser excluído.
     * @return true se a exclusão for realizada.
     */
    virtual bool excluirHospede(const Email& email) = 0;

    // --- Listagem ---

    /**
     * @brief Lista todos os hóspedes cadastrados.
     * @return Um vetor contendo todos os objetos Hospede encontrados.
     */
    virtual std::vector<Hospede> listarHospedes() = 0;
};

/**
 * @brief Interface para o Serviço de Hotelaria.
 * * Define as operações de gerenciamento de Hotéis e Quartos.
 * * As operações de Quartos dependem da identificação do Hotel (Composição).
 */
class IServicoHotelaria {
public:
    virtual ~IServicoHotelaria() {}
    /**
     * @brief Cria um novo hotel.
     * @param hotel Objeto contendo os dados do hotel.
     * @return true se criado com sucesso.
     */
    virtual bool criarHotel(const Hotel& hotel) = 0;

    /**
     * @brief Lê os dados de um hotel.
     * @param codigo Código identificador do hotel.
     * @param hotel Ponteiro para armazenar os dados recuperados.
     * @return true se o hotel for encontrado.
     */
    virtual bool lerHotel(const Codigo& codigo, Hotel* hotel) = 0;

    /**
     * @brief Atualiza os dados de um hotel.
     * @param hotel Objeto com os dados atualizados.
     * @return true se a atualização for bem-sucedida.
     */
    virtual bool atualizarHotel(const Hotel& hotel) = 0;

    /**
     * @brief Exclui um hotel do sistema.
     * @param codigo Código do hotel a ser excluído.
     * @return true se a exclusão for bem-sucedida.
     */
    virtual bool excluirHotel(const Codigo& codigo) = 0;
    /**
     * @brief Adiciona um quarto a um hotel específico.
     * @param quarto Objeto com os dados do quarto.
     * @param codigoHotel Código do hotel ao qual o quarto pertence.
     * @return true se o quarto for criado com sucesso.
     */
    virtual bool criarQuarto(const Quarto& quarto, const Codigo& codigoHotel) = 0;

    /**
     * @brief Lê os dados de um quarto específico de um hotel.
     * @param numero Número do quarto.
     * @param codigoHotel Código do hotel onde o quarto está localizado.
     * @param quarto Ponteiro para armazenar os dados recuperados.
     * @return true se o quarto for encontrado.
     */
    virtual bool lerQuarto(const Numero& numero, const Codigo& codigoHotel, Quarto* quarto) = 0;

    /**
     * @brief Atualiza os dados de um quarto.
     * @param quarto Objeto com os dados atualizados.
     * @param codigoHotel Código do hotel onde o quarto está localizado.
     * @return true se a atualização for bem-sucedida.
     */
    virtual bool atualizarQuarto(const Quarto& quarto, const Codigo& codigoHotel) = 0;

    /**
     * @brief Remove um quarto de um hotel.
     * @param numero Número do quarto a ser removido.
     * @param codigoHotel Código do hotel.
     * @return true se a exclusão for bem-sucedida.
     */
    virtual bool excluirQuarto(const Numero& numero, const Codigo& codigoHotel) = 0;

    // --- Listagens ---

    /**
     * @brief Lista todos os hotéis cadastrados.
     * @return Vetor com os hotéis.
     */
    virtual std::vector<Hotel> listarHoteis() = 0;

    /**
     * @brief Lista todos os quartos de um hotel específico.
     * @param codigoHotel Código do hotel.
     * @return Vetor com os quartos pertencentes àquele hotel.
     */
    virtual std::vector<Quarto> listarQuartos(const Codigo& codigoHotel) = 0;
};

/**
 * @brief Interface para o Serviço de Reservas.
 * * Define as operações CRUD para gerenciamento de reservas de estadias.
 */
class IServicoReservas {
public:
    virtual ~IServicoReservas() {}

    /**
     * @brief Cria uma nova reserva.
     * @param reserva Objeto com os dados da reserva.
     * @return true se criada com sucesso (sem conflito de datas).
     */
    virtual bool criarReserva(const Reserva& reserva) = 0;

    /**
     * @brief Recupera os dados de uma reserva.
     * @param codigo Código identificador da reserva.
     * @param reserva Ponteiro para armazenar os dados recuperados.
     * @return true se a reserva for encontrada.
     */
    virtual bool lerReserva(const Codigo& codigo, Reserva* reserva) = 0;

    /**
     * @brief Atualiza os dados de uma reserva existente.
     * @param reserva Objeto com os novos dados.
     * @return true se a atualização for bem-sucedida.
     */
    virtual bool atualizarReserva(const Reserva& reserva) = 0;

    /**
     * @brief Cancela/Exclui uma reserva.
     * @param codigo Código da reserva a ser excluída.
     * @return true se a exclusão for realizada.
     */
    virtual bool excluirReserva(const Codigo& codigo) = 0;

    // --- Listagem ---

    /**
     * @brief Lista todas as reservas cadastradas.
     * @return Vetor com todas as reservas.
     */
    virtual std::vector<Reserva> listarReservas() = 0;
};

#endif // INTERFACES_H