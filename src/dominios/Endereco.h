#ifndef ENDERECO_H
#define ENDERECO_H

class Endereco{
private:
    std::strinf valor;
    void validarEndereco(const std::string& endereco) const;

public:
    Endereco();
    explicit Endereco(const std::string& endereco);

    void setEndereco(const std::string& endereco);
    std::string getEndereco() const;
};
#endif
