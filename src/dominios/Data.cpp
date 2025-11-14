#include "Data.h"
#include <sstream>  // Para std::stringstream
#include <iomanip>  // Para std::setw e std::setfill
#include <algorithm> // Para std::transform (uppercase)

// Inicializa o vetor estático de meses
const std::vector<std::string> Data::MESES = {
    "JAN", "FEV", "MAR", "ABR", "MAI", "JUN", 
    "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
};

int Data::converteMes (const std::string& mesStr) const{
    for (int i = 0; i < MESES.size(); i++) {
        if (MESES[i] == mesStr) {
            return i + 1; // Retorna o número relativo ao mês
        }
    }
    throw std::invalid_argument("Mês inválido");
}

std::string Data::converterMes(int mesInt) const{
    if mesInt < 1 || mesInt > 12 {
        throw std::runtime_error("Mês inválido");
    }
    return MESES[mesInt - 1];
}

