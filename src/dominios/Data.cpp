#include "Data.h"
#include <sstream>
#include <iomanip>
#include <iostream>

const std::vector<std::string> Data::MESES = {
    "JAN", "FEV", "MAR", "ABR", "MAI", "JUN", 
    "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
};

Data::Data() {
    this->dia = 0;
    this->mes = 0;
    this->ano = 0;
}


Data::Data(const std::string& dataStr) {
    setData(dataStr);
}


void Data::setData(const std::string& dataStr) {
    std::stringstream ss(dataStr);
    char barra1, barra2;
    int d, m, a;

    ss >> d >> barra1 >> m >> barra2 >> a;

    if (ss.fail() || barra1 != '/' || barra2 != '/') {
        throw std::invalid_argument("Formato de data invalido. Use DD/MM/AAAA.");
    }

    validarData(d, m, a);

    this->dia = d;
    this->mes = m;
    this->ano = a;
}

std::string Data::getData() const {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << dia << "/"
       << std::setw(2) << std::setfill('0') << mes << "/"
       << ano;
    return ss.str();
}

void Data::validarData(int dia, int mes, int ano) const {
    if (mes < 1 || mes > 12) {
        throw std::invalid_argument("Mes invalido (1-12).");
    }

    if (ano < 2000 || ano > 2999) {
        throw std::invalid_argument("Ano fora do intervalo permitido (2000 a 2999).");
    }

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

bool Data::Bissexto(int ano) const {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

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