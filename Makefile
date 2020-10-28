# compilateur
CC := gcc
# options de compilation
CFLAGS := -std=c99 -Wall -Wextra -pedantic -ggdb 

# règle de compilation --- exécutables
all : vigenere 

vigenere : crypto.o main.o 
	$(CC) $(CFLAGS) -o $@ $^	

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

# options de compilation
memoire : vigenere
	valgrind --track-origins=yes --leak-check=full ./vigenere

clean:
	rm *.o vigenere
