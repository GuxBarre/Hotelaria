#include "Telefone.h"
#include <cctype>
#include <string> 
using namespace std;
void Telefone::validarTelefone(const string& telefone) const {
    if (telefone.length() != 14){
        throw invalid_argument("O telefone deve ter exatamente 14 caracteres (Formato: +DDDDDDDDDDDDDD).");
    }

    if (telefone[0] != '+'){
        throw invalid_argument("O telefone deve começar com '+'");
    }

    for (size_t i = 1; i < telefone.length(); i++) {
        if(!isdigit(telefone[i])) {
            throw invalid_argument("O telefone deve conter apenas dígitos após o '+'");
        }
    }
}

Telefone::Telefone(){
    this->telefone = "+0000000000000";
}

Telefone::Telefone(const string& telefone){
    setTelefone(telefone);
}

void Telefone::setTelefone(const string& telefone){
    validarTelefone(telefone); 
    this->telefone = telefone;
}

string Telefone::getTelefone() const {
    return this->telefone;
}

Telefone::operator string() const {
    return telefone;
}