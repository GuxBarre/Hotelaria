#ifndef TELEDONE_H
#define TELEFONE_H

#include <string>
#include <stdexcept>

// Formato: +XX (XX) XXXX-XXXX
class Telefone{
    private:
        std::string valor;
        void validarTelefone(const std::string& telefone) const;
    public:
        Telefone();
        explicit Telefone(const std::string& telefone);

        void setValor(const std::string& telefone);
        std::string getValor() const;
};
#endif
