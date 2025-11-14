#ifndef CARTAO_H
#define CARTAO_H

#include <string>
#include <stdexcept>

/*  - Deve possuir 16 digitos
    - Presença do verificador do algorítmo de Luhn
*/

class Cartao {
    private:
        std::string numero;
        void validar (const std::string& numero) const;
        bool validarLuhn(const std::string& numero) const;

    public:
        Cartao();
        explicit Cartao(const std::string& numero);

        void setValor(const std::string& numero)
        std::string getValor() const;
}
#endif