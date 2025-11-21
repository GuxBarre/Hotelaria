#include <iostream>
#include <stdexcept>
#include "dominios/Capacidade.h"
#include "dominios/Cartao.h"
#include "dominios/Data.h"
#include "dominios/Endereco.h"
#include "dominios/Telefone.h"
#include "dominios/Codigo.h"
#include "dominios/Dinheiro.h"
#include "dominios/Nome.h"
#include "dominios/Numero.h"
#include "dominios/Ramal.h"
#include "dominios/Email.h"
#include "dominios/Senha.h"

using namespace std;

void imprimirCabecalho(const string& titulo) {
    cout << "\n========================================" << endl;
    cout << "       TESTANDO: " << titulo << endl;
    cout << "========================================" << endl;
}

int main() {
    imprimirCabecalho("CAPACIDADE");
    

    try {
        cout << "1. Tentando definir capacidade valida (3)..." << endl;
        Capacidade c(3);
        cout << "   [SUCESSO] Objeto criado com valor: " << c.getCapacidade() << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "\n2. Tentando definir capacidade invalida (10)..." << endl;
        Capacidade c(10);
        cout << "   [FALHA] O programa nao deveria chegar aqui." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    imprimirCabecalho("CARTAO");

    try {
        cout << "1. Tentando criar cartao valido (4000000000000002)..." << endl;
        Cartao c("4000000000000002");
        cout << "   [SUCESSO] Cartao aceito: " << c.getCartao() << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "\n2. Tentando criar cartao com Luhn invalido (final 3)..." << endl;
        Codigo c("4000000000000003");
        cout << "   [FALHA] O programa aceitou cartao invalido." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    imprimirCabecalho("CODIGO");
    try{
        cout << "1. Tentando criar codigo valido (1000000000)..." << endl;
        Codigo c("1000000000");
        cout << "   [SUCESSO] Codigo aceito: " << c.getCodigo() << endl;
    }catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }
    try {
        cout << "\n2. Tentando criar codigo errado" << endl;
        Codigo c("10000000001");
        cout << "   [FALHA] O programa aceitou codigo invalido." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    imprimirCabecalho("DATA");

    try {
        cout << "1. Tentando criar data bissexta valida (29/02/2024)..." << endl;
        Data d("29/02/2024");
        cout << "   [SUCESSO] Data aceita: " << d.getData() << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "\n2. Tentando criar data invalida (31 de Abril)..." << endl;
        Data d("31/04/2024"); 
        cout << "   [FALHA] O programa aceitou 31 de abril." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    imprimirCabecalho("DINHEIRO");

    try {
        cout << "1. Tentando valor valido (150.50)..." << endl;
        Dinheiro din(150.50);
        cout << "   [SUCESSO] Dinheiro aceito: " << din.getDinheiro() << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "\n2. Tentando valor abaixo do minimo (0.00)..." << endl;
        Dinheiro din(0.00);
        cout << "   [FALHA] Aceitou valor zero." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n3. Tentando valor acima do maximo (1.000.000.01)..." << endl;
        Dinheiro din(1000000.01);
        cout << "   [FALHA] Aceitou valor excessivo." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }
  
    imprimirCabecalho("EMAIL");

    try {
        cout << "1. Tentando email valido (nome.sobrenome-123@dominio.com)..." << endl;
        Email em("nome.sobrenome-123@dominio.com");
        cout << "   [SUCESSO] Email aceito: " << em.getEmail() << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "\n2. Tentando email sem @ (teste.com)..." << endl;
        Email em("teste.com");
        cout << "   [FALHA] Aceitou email sem @." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n3. Tentando ponto no inicio (.teste@dominio.com)..." << endl;
        Email em(".teste@dominio.com");
        cout << "   [FALHA] Aceitou ponto no inicio." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n4. Tentando pontos consecutivos (te..ste@dominio.com)..." << endl;
        Email em("te..ste@dominio.com");
        cout << "   [FALHA] Aceitou pontos consecutivos." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n5. Tentando hifen no final do dominio (teste@dominio-.com)..." << endl;
        Email em("teste@dominio-.com");
        cout << "   [FALHA] Aceitou hifen no final de parte do dominio." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n6. Tentando caractere invalido (teste!@dominio.com)..." << endl;
        Email em("teste!@dominio.com");
        cout << "   [FALHA] Aceitou caractere especial (!)." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    imprimirCabecalho("ENDERECO");

    try {
        cout << "1. Tentando criar endereco valido..." << endl;
        Endereco e("Av. Brasil, 1500");
        cout << "   [SUCESSO] Endereco aceito: " << e.getEndereco() << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "\n2. Tentando endereco com erro de sintaxe (Pontos seguidos)..." << endl;
        Endereco e("Rua..Teste");
        cout << "   [FALHA] O programa aceitou pontuacao invalida." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    imprimirCabecalho("NOME");

    try {
        cout << "1. Tentando nome valido (Joao Silva)..." << endl;
        Nome n("Joao Silva");
        cout << "   [SUCESSO] Nome aceito: " << n.getNome() << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "\n2. Tentando nome curto (Ana)..." << endl;
        Nome n("Ana");
        cout << "   [FALHA] Aceitou nome curto." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n3. Tentando nome com letra minuscula no inicio (joao silva)..." << endl;
        Nome n("joao Silva");
        cout << "   [FALHA] Aceitou inicial minuscula." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n4. Tentando nome com numeros (Joao 123)..." << endl;
        Nome n("Joao 123");
        cout << "   [FALHA] Aceitou numeros." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n5. Tentando nome com espaco no final (Maria )..." << endl;
        Nome n("Maria ");
        cout << "   [FALHA] Aceitou espaco no final." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }
    imprimirCabecalho("NUMERO");

    try {
        cout << "1. Tentando numero valido (150)..." << endl;
        Numero num(150);
        cout << "   [SUCESSO] Numero aceito: " << num.getNumero() << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "2. Tentando limites validos (1 e 999)..." << endl;
        Numero n1(1);
        Numero n2(999);
        cout << "   [SUCESSO] Limites aceitos." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "\n3. Tentando numero invalido (0)..." << endl;
        Numero num(0);
        cout << "   [FALHA] Aceitou valor 0." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n4. Tentando numero invalido (1000)..." << endl;
        Numero num(1000);
        cout << "   [FALHA] Aceitou valor 1000." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }
    imprimirCabecalho("RAMAL");

    try {
        cout << "1. Tentando ramal valido (25)..." << endl;
        Ramal r(25);
        cout << "   [SUCESSO] Ramal aceito: " << r.getRamal() << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "2. Tentando limites validos (0 e 50)..." << endl;
        Ramal r1(0);
        Ramal r2(50);
        cout << "   [SUCESSO] Limites aceitos." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "\n3. Tentando ramal invalido (-1)..." << endl;
        Ramal r(-1);
        cout << "   [FALHA] Aceitou valor negativo." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n4. Tentando ramal invalido (51)..." << endl;
        Ramal r(51);
        cout << "   [FALHA] Aceitou valor 51." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    imprimirCabecalho("SENHA");

    try {
        cout << "1. Tentando senha valida (X1y%2)..." << endl;
        Senha s("X1y%2");
        cout << "   [SUCESSO] Senha aceita: " << s.getSenha() << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "\n2. Tentando senha com tamanho errado (123)..." << endl;
        Senha s("123");
        cout << "   [FALHA] Aceitou tamanho incorreto." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n3. Tentando letras consecutivas (Ab1%2)..." << endl;
        Senha s("Ab1%2");
        cout << "   [FALHA] Aceitou letras consecutivas." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n4. Tentando digitos consecutivos (X12y%)..." << endl;
        Senha s("X12y%"); 
        cout << "   [FALHA] Aceitou digitos consecutivos." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    try {
        cout << "\n5. Tentando senha sem caractere especial (A1b2C)..." << endl;
        Senha s("A1b2C");
        cout << "   [FALHA] Aceitou senha incompleta (sem especial)." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }


    try {
        cout << "\n6. Tentando caractere nao permitido (@)..." << endl;
        Senha s("A1b@2");
        cout << "   [FALHA] Aceitou caractere invalido." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    imprimirCabecalho("TELEFONE");

    try {
        cout << "1. Tentando criar telefone valido (+55219999988888)..." << endl;
        Telefone t("+55219999988888");
        cout << "   [SUCESSO] Telefone aceito: " << t.getTelefone() << endl;
    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    try {
        cout << "\n2. Tentando criar telefone curto (+5521)..." << endl;
        Telefone t("+5521");
        cout << "   [FALHA] O programa aceitou telefone curto." << endl;
    } catch (const exception& e) {
        cout << "   [ERRO CAPTURADO] " << e.what() << endl;
    }

    return 0;
}