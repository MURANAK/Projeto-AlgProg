CC = gcc
CFLAGS = -Wall -std=c99 -O2
INCLUDES = -Iinclude
TARGET = main
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Busca automaticamente todos os arquivos .c dentro da pasta src/
SRCS = $(wildcard src/*.c)

all: $(TARGET)

# Compila todos os arquivos encontrados juntos
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)
