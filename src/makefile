NOME_SAIDA=../aluguel

IDIR =../include
CC=g++
EXT = cpp
CFLAGS=-Wall -g -I $(IDIR) -std=c++11

ODIR=obj

LIBS=-lm

_DEPS = comandos.h containers.h controladoras.h dominios.h entidades.h interfaces.h stubs.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o comandos.o containers.o controladoras.o dominios.o entidades.o stubs.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.$(EXT) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NOME_SAIDA): $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(CFLAGS)

.PHONY: all
all: $(NOME_SAIDA)

.PHONY: clean
clean:
	rm -f $(ODIR)/* *~ core $(INCDIR)/*~
