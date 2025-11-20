# Nome do compilador
CXX = g++

# Flags de compilação:
# -Wall: Mostra todos os avisos (bom para debugar)
# -g: Permite debugar o código depois
# -I src: Diz que a pasta 'src' é a base para os includes
CXXFLAGS = -Wall -g -I src

# Nome do executável final
TARGET = hotelaria

# Aqui está a mágica:
# O comando 'find' procura TODOS os arquivos .cpp dentro de src e subpastas automaticamente
SOURCES = $(shell find src -name '*.cpp')

# Regra principal: compilar o executável
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Regra para limpar arquivos antigos (opcional, rodar 'make clean')
clean:
	rm -f $(TARGET)