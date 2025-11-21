#include "Dinheiro.h"
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;
Dinheiro::Dinheiro() {
    this->valorCentavos = 1;
}

Dinheiro::Dinheiro(double valor) {
    setDinheiro(valor);
}

Dinheiro::~Dinheiro() {
}

void Dinheiro::validar(long long valor) {
    if (valor < 1 || valor > 100000000) {
        throw invalid_argument("Valor monetario deve estar entre 0,01 e 1.000.000,00.");
    }
}

void Dinheiro::setDinheiro(double valor) {
    long long centavos = llround(valor * 100);
    
    validar(centavos);
    
    this->valorCentavos = centavos;
}

double Dinheiro::getDinheiro() const {
    return valorCentavos / 100.0;
}
Dinheiro::operator string() const {
    stringstream ss;
    ss << fixed << setprecision(2) << getDinheiro();
    return ss.str();
}