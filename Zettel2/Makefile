NASM  = nasm -f elf64 -g -F dwarf
LD    = ld

SRC   = $(wildcard *.S)
OBJ   = $(SRC:.S=.o)
PROGS = $(SRC:.S=)

all: $(PROGS)

$(PROGS): %: %.o
	$(LD) -o $@ $<

$(OBJ): %.o: %.S
	$(NASM) -o $@ $<

clean:
	rm -f $(OBJ) $(PROGS)
