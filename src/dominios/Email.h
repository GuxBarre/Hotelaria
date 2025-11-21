#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <stdexcept>
#include <iostream>

// Domínio: Email
// Regras:
// 1. Formato parte-local@dominio.
// 2. Parte local: até 64 chars, letras(a-z), digitos(0-9), ponto(.) ou hifen(-).
//    - Não pode iniciar/terminar com ponto ou hifen.
//    - Ponto ou hifen deve ser seguido por letra ou digito.
// 3. Dominio: até 255 chars, partes separadas por ponto.
//    - Partes: letras(a-z), digitos(0-9) ou hifen(-).
//    - Não pode iniciar/terminar com hifen.

class Email {
private:
    std::string valor;

    void validar(std::string email);

public:
    Email(); 
    Email(std::string email);
    virtual ~Email();

    void setValor(std::string email);
    std::string getValor() const;
};

#endif // EMAIL_H