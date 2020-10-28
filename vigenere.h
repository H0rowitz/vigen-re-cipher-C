#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LENGTH_ALPHA 26

char* cesar_code(char*, int); 
char** table_vigenere();
char* generate_key(int);
char* chiffrer(char*, char**, char*); 
char* dechiffrer(char*, char**, char*); 
void output_table_vigenere(char**);
void free_matrix_memo(char**);
