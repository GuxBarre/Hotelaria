#include "Codigo.h"
#include <cctype>
#include <string> 
using namespace std;

void Codigo::validar(const string& codigo) const {
    if (codigo.length() != 10) {
        throw invalid_argument("Codigo deve ter exatamente 10 caracteres.");
    }

    for (char c : codigo) {
        if (!isalnum(c)) {
            throw invalid_argument("Codigo deve conter apenas letras e numeros.");
        }
    }
}

Codigo::Codigo() {
    this->codigo = "0000000000";
}

Codigo::Codigo(const string& codigo) {
    setCodigo(codigo);
}

void Codigo::setCodigo(const string& codigo) {
    validar(codigo);
    this->codigo = codigo;
}

std::string Codigo::getCodigo() const {
    return this->codigo;
}

Codigo::operator string() const {
    return codigo; 
}