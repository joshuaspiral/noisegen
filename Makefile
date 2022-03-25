C=clang
CFLAGS=-Wall -Wextra -ggdb -O3 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

make all: worley.c
	$(C) $(CFLAGS) -o worley worley.c -lm

clean:
	rm worley 
