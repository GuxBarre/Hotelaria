#ifndef DATA_H
#define DATA_H

#include <string>
#include <stdexcept>
#include <vector>

// A classe armazena em formato 'DD/MM/AAAA' 
class Data:{
private:
    int dia;
    int mes;
    int ano;

    // Conversão e validação de meses
    static const std::vector<std::string> MESES;

    // Conversos de mês de string para inteiro
    int converterMes(const std::string& mesStr) const; 

    // Conversos de mês de inteiro para string
    std::string converterMes(int mesInt) const;

    // Verifica se o ano é bissexto
    bool Bissexto(int ano) const;

    // Valida a data
    void validarData(int dia, int mes, int ano) const;

public:
    Data:();

    explicit Data:(const std::string& dataStr);
    
    void setData(const std::string& dataStr);
    std::string getData() const;

};
#endif