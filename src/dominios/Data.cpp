#include "Data.h"
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

const vector<string> Data::MESES = {
    "JAN", "FEV", "MAR", "ABR", "MAI", "JUN", 
    "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
};

Data::Data() {
    this->dia = 0;
    this->mes = 0;
    this->ano = 0;
}


Data::Data(const string& dataStr) {
    setData(dataStr);
}


void Data::setData(const string& dataStr) {
    stringstream ss(dataStr);
    char barra1, barra2;
    int d, m, a;

    ss >> d >> barra1 >> m >> barra2 >> a;

    if (ss.fail() || barra1 != '/' || barra2 != '/') {
        throw invalid_argument("Formato de data invalido. Use DD/MM/AAAA.");
    }

    validarData(d, m, a);

    this->dia = d;
    this->mes = m;
    this->ano = a;
}

string Data::getData() const {
    stringstream ss;
    ss << setw(2) << setfill('0') << dia << "/"
       << setw(2) << setfill('0') << mes << "/"
       << ano;
    return ss.str();
}

void Data::validarData(int dia, int mes, int ano) const {
    if (mes < 1 || mes > 12) {
        throw invalid_argument("Mes invalido (1-12).");
    }

    if (ano < 2000 || ano > 2999) {
        throw invalid_argument("Ano fora do intervalo permitido (2000 a 2999).");
    }

    int diasNoMes = 31; 

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        diasNoMes = 30;
    } else if (mes == 2) {
        diasNoMes = Bissexto(ano) ? 29 : 28;
    }

    if (dia < 1 || dia > diasNoMes) {
        throw invalid_argument("Dia invalido para o mes informado.");
    }
}

bool Data::Bissexto(int ano) const {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int Data::converterMes(const string& mesStr) const {
    for (size_t i = 0; i < MESES.size(); i++) {
        if (MESES[i] == mesStr) {
            return i + 1;
        }
    }
    throw invalid_argument("Mes invalido.");
}

string Data::converterMes(int mesInt) const {
    if (mesInt < 1 || mesInt > 12) {
        throw runtime_error("Mes invalido.");
    }
    return MESES[mesInt - 1];
}

Data::operator string() const {
    return getData();
}