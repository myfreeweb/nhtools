all: dir priceid

clean:
	rm -f *.o bin/*

dir:
	mkdir -p bin

priceid: priceid.c
	gcc -o bin/priceid priceid.c

.PHONY: all clean
