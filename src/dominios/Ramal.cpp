#include "Ramal.h"
#include <string>
using namespace std;

Ramal::Ramal() {
    this->ramal = 0; 
}

Ramal::Ramal(int ramal) {
    setRamal(ramal);
}

Ramal::~Ramal() {
}

void Ramal::validar(int ramal) {
    if (ramal < 0 || ramal > 50) {
        throw invalid_argument("Ramal deve estar entre 0 e 50.");
    }
}

void Ramal::setRamal(int ramal) {
    validar(ramal);
    this->ramal = ramal;
}

int Ramal::getRamal() const {
    return ramal;
}
Ramal::operator string() const {
    return to_string(ramal);
}