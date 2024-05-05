OUT = pacman.o
OBJECTS = $(wildcard src/*.c */src/*.c)
HEADERS = $(wildcard include/*.h */include/*.h)

all: $(OUT) 
	
$(OUT): clean
	gcc $(OBJECTS) $(HEADERS) -o $@
	./$@
	
clean:
	-rm -f $(OUT)
