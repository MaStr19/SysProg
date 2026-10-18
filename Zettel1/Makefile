# Variablen
SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)

CFLAGS  := -g -Wall -Wextra -fsanitize=address,undefined
LDFLAGS := -g -Wall -Wextra -fsanitize=address,undefined

# Name der ausführbaren Datei
TARGET := demo

# Standardziel
all: $(TARGET)

# Kompilieren: jede .c-Datei zu einer .o-Datei
%.o: %.c
	clang $(CFLAGS) -c $< -o $@

# Linken: alle .o-Dateien zu einer ausführbaren Datei
$(TARGET): $(OBJECTS)
	clang $(LDFLAGS) -o $@ $^

# Aufräumen
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean