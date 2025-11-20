#include <iostream>
#include <stdexcept>
#include "dominios/Cartao.h"
#include "dominios/Endereco.h"
#include "dominios/Telefone.h"
#include "dominios/Data.h"

using namespace std;

void testarCartao() {
    cout << "=== Testando Cartao ===" << endl;
    try {
        // Caso Valido (Visa Teste Calculado)
        // Explicação: 4 vira 8. Os zeros continuam 0. O final 2 soma com 8 = 10. 10%10 == 0.
        Cartao c("4000000000000002"); 
        cout << "[OK] Cartao valido aceito: " << c.getValor() << endl;
    } catch (exception& e) {
        cout << "[FALHA] Erro inesperado em cartao valido: " << e.what() << endl;
    }

    try {
        // Caso Invalido (Luhn errado)
        // Mudamos o final para 3, a soma vai dar 11, que falha.
        Cartao c("4000000000000003"); 
        cout << "[FALHA] Aceitou cartao invalido!" << endl;
    } catch (exception& e) {
        cout << "[OK] Rejeitou cartao invalido corretamente: " << e.what() << endl;
    }
    cout << endl;
}

void testarEndereco() {
    cout << "=== Testando Endereco ===" << endl;
    try {
        Endereco e("Rua das Flores, 123"); // Tam: 19
        cout << "[OK] Endereco valido aceito: " << e.getEndereco() << endl;
    } catch (exception& e) {
        cout << "[FALHA] " << e.what() << endl;
    }

    try {
        Endereco e("Rua"); // Curto demais
        cout << "[FALHA] Aceitou endereco curto!" << endl;
    } catch (exception& e) {
        cout << "[OK] Rejeitou endereco curto: " << e.what() << endl;
    }
    cout << endl;
}

void testarTelefone() {
    cout << "=== Testando Telefone ===" << endl;
    try {
        Telefone t("+55219999988888"); 
        cout << "[OK] Telefone valido aceito: " << t.getValor() << endl;
    } catch (exception& e) {
        cout << "[FALHA] " << e.what() << endl;
    }

    try {
        Telefone t("11999998888"); // Sem + e tamanho errado
        cout << "[FALHA] Aceitou telefone invalido!" << endl;
    } catch (exception& e) {
        cout << "[OK] Rejeitou telefone invalido: " << e.what() << endl;
    }
    cout << endl;
}

// Nota: Se voce ainda nao terminou o Data.cpp, comente essa funcao
// No main.cpp, substitua a funcao testarData() por esta:
void testarData() {
    cout << "=== Testando Data ===" << endl;
    try {
        Data d1("29/02/2024"); // 2024 é bissexto, OK
        cout << "[OK] Data bissexta valida: " << d1.getData() << endl;
    } catch (exception& e) {
        cout << "[FALHA] " << e.what() << endl;
    }

    try {
        Data d2("29/02/2023"); // 2023 NÃO é bissexto, deve falhar
        cout << "[FALHA] Aceitou data inexistente (29/02/23)!" << endl;
    } catch (exception& e) {
        cout << "[OK] Rejeitou data inexistente: " << e.what() << endl;
    }
    
    try {
        Data d3("31/04/2024"); // Abril só tem 30 dias
        cout << "[FALHA] Aceitou 31 de abril!" << endl;
    } catch (exception& e) {
        cout << "[OK] Rejeitou 31 de abril: " << e.what() << endl;
    }
    cout << endl;
}

int main() {
    testarCartao();
    testarEndereco();
    testarTelefone();
    testarData();
    return 0;
}