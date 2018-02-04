# Tässä Makefile ohjelman rakentamiseen

SRCDIR = ./sources
INCDIR = ./headers
OBJDIR = ./objects


# Muuttuja kääntäjän valitsemiseen
CC = gcc
# Tähän kaikki halutut lipukkeet kääntämiseen.
FLAGS = -Wall -Wextra -pedantic -std=c99 -g 
# Tänne kaikki ohjelman tarvitsevat objektikoodit.
SOURCES = main.c tietorakenteet.c apufunktiot.c tiedosto.c
OBJECTS = $(addprefix $(OBJDIR)/,$(SOURCES:.c=.o))
# Ottaa mukaan kaikki ohjelmien headerit tässä kansiossa.
INCLUDES = -I $(INCDIR) 
# Tuotettavan ohjelman nimi.
OUTPUT = ohjelma
.PHONY: all clean

all: $(OUTPUT) $(SRCDIR) $(INCDIR) $(OBJDIR)

$(SRCDIR): 
	@mkdir -p $(SOURCES) 
	@mv $(SOURCES) $@

$(INCDIR): $(wildcard *.h) 
	@mkdir -p $@
	@mv $^ $@
$(OBJDIR):
	@mkdir -p $@

# Lopullisen suoritettavan ohjelman kääntäminen, riippuu objektikoodeista.
$(OUTPUT) : $(OBJECTS)
	${CC} ${FLAGS} ${INCLUDES} $^ -o ${OUTPUT} 

# Objektikoodien kääntäminen, riippuu lähdekoodeista
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	${CC} ${FLAGS} -c $^ ${INCLUDES} -o $@

# Make clean poistaa kaikki hakemiston objektikoodit ja suoritettavan ohjelma tiedoston.
clean:
	-rm -rf *.o
	-rm ${OUTPUT} 
