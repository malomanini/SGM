all: tp3/producteur.c
	gcc -g -Wall -o producteur tp3/producteur.c

clean:
	$(RM) producteur
