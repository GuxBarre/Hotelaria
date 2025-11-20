#include "Data.h"
#include <sstream>
#include <iomanip>
#include <iostream>

// Inicialização do vetor estático
const std::vector<std::string> Data::MESES = {
    "JAN", "FEV", "MAR", "ABR", "MAI", "JUN", 
    "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
};

/**
 * @brief Construtor padrão.
 */
Data::Data() {
    this->dia = 0;
    this->mes = 0;
    this->ano = 0;
}

/**
 * @brief Construtor via string.
 */
Data::Data(const std::string& dataStr) {
    setData(dataStr);
}

/**
 * @brief Setter principal.
 * Faz o parsing da string "DD/MM/AAAA" e valida.
 */
void Data::setData(const std::string& dataStr) {
    // Formato esperado: DD/MM/AAAA
    std::stringstream ss(dataStr);
    char barra1, barra2;
    int d, m, a;

    // Tenta ler: int -> char -> int -> char -> int
    ss >> d >> barra1 >> m >> barra2 >> a;

    // Verifica se a leitura foi bem sucedida e se os separadores são '/'
    if (ss.fail() || barra1 != '/' || barra2 != '/') {
        throw std::invalid_argument("Formato de data invalido. Use DD/MM/AAAA.");
    }

    validarData(d, m, a);

    // Se passou na validação, atribui aos atributos
    this->dia = d;
    this->mes = m;
    this->ano = a;
}

/**
 * @brief Getter formatado.
 */
std::string Data::getData() const {
    std::stringstream ss;
    // Formata com zero à esquerda (ex: 5 vira 05)
    ss << std::setw(2) << std::setfill('0') << dia << "/"
       << std::setw(2) << std::setfill('0') << mes << "/"
       << ano;
    return ss.str();
}

/**
 * @brief Validação lógica de calendário.
 */
void Data::validarData(int dia, int mes, int ano) const {
    // Valida Mês
    if (mes < 1 || mes > 12) {
        throw std::invalid_argument("Mes invalido (1-12).");
    }

    // Valida Ano (Requisito da imagem: 2000 a 2999)
    if (ano < 2000 || ano > 2999) {
        throw std::invalid_argument("Ano fora do intervalo permitido (2000 a 2999).");
    }

    // Valida Dias do Mês
    int diasNoMes = 31; 

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        diasNoMes = 30;
    } else if (mes == 2) {
        diasNoMes = Bissexto(ano) ? 29 : 28;
    }

    if (dia < 1 || dia > diasNoMes) {
        throw std::invalid_argument("Dia invalido para o mes informado.");
    }
}

/**
 * @brief Verifica ano bissexto (Regra Gregoriana).
 */
bool Data::Bissexto(int ano) const {
    // É bissexto se divisível por 4, exceto se divisível por 100 (a não ser que seja por 400)
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// -- Métodos auxiliares de conversão (mantidos do seu código original) --

int Data::converterMes(const std::string& mesStr) const {
    for (size_t i = 0; i < MESES.size(); i++) {
        if (MESES[i] == mesStr) {
            return i + 1;
        }
    }
    throw std::invalid_argument("Mes invalido.");
}

std::string Data::converterMes(int mesInt) const {
    if (mesInt < 1 || mesInt > 12) {
        throw std::runtime_error("Mes invalido.");
    }
    return MESES[mesInt - 1];
}