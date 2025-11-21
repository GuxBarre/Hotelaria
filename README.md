# Sistema de Gestão Hoteleira - Trabalho Prático 1

Este projeto consiste no desenvolvimento de um sistema de software para facilitar a gestão de pequenos hotéis. O sistema foi desenvolvido em C++ seguindo o paradigma de Orientação a Objetos e uma arquitetura em camadas, conforme especificado nos requisitos da disciplina de Técnicas de Programação 1.

## Arquitetura do Sistema

O software segue o estilo de arquitetura em camadas, dividido em:

1.  **Camada de Apresentação:** Responsável pela interface com o usuário e validação dos dados de entrada.
2.  **Camada de Serviço:** Responsável pela lógica de negócio e armazenamento de dados.

O projeto inclui a implementação de classes de Domínios, Entidades, Controladoras e Interfaces.

## Tecnologias Utilizadas

* **Linguagem:** C++ 
* **Ambiente de Desenvolvimento:** Compatível com Code::Blocks 
* **Documentação:** Doxygen (HTML)
* **Persistência:** Estrutura de dados em memória ou SQLite 
* **Modelagem:** UML (Diagramas de arquitetura)

## Estrutura de Arquivos

* src/: Código-fonte (.cpp e .h)
* src/dominios/: Implementação das classes de domínio e validações
* src/entidades/: Implementação das classes de entidade
* doc/: Documentação gerada pelo Doxygen
* bin/: Executáveis

## Compilação e Execução

O projeto possui dois modos de compilação: um para validação unitária dos domínios e outro para o sistema completo.

### 1. Teste de Unidade (Domínios)

Utilize este comando para compilar e rodar apenas os testes das regras de validação (CPF, Email, Senha, etc.) isoladamente, mantendo a função main limpa.

Compilação:
g++ src/teste_dominios.cpp src/dominios/*.cpp -I src -o teste_dominios

Execução:
./teste_dominios   (Linux/Mac)
teste_dominios.exe (Windows)

### 2. Sistema Principal

Utilize este comando para compilar o sistema completo, incluindo menus e fluxo de navegação.

Compilação:
g++ src/main.cpp src/dominios/*.cpp -I src -o sistema

Nota: Conforme novas camadas (serviços, controladoras) forem adicionadas, seus arquivos .cpp devem ser incluídos neste comando.

Execução:
./sistema   (Linux/Mac)
sistema.exe (Windows)

## Checklist de Entrega

* Código-fonte e executável.
* Documentação Doxygen (Páginas HTML).
* Modelo de Arquitetura (PDF) com descrição dos módulos.
* Vídeo de demonstração do Teste Fumaça (Smoke Test).
* Arquivo compactado no formato T1-TP1-X-Y-Z.ZIP (onde X, Y, Z são as matrículas).

## Autores

* Nome do Aluno 1 - Matrícula: X
* Nome do Aluno 2 - Matrícula: Y
* Nome do Aluno 3 - Matrícula: Z
