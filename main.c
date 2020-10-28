#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vigenere.h"

int main(int argc, char* argv[]) {

    char* code_cesar = cesar_code("BONJOUR", 25); 
    printf("Cesar output: %s\n\n", code_cesar); 

    char** t_v = table_vigenere();
    output_table_vigenere(t_v); 
    
    char* input = malloc(sizeof(char));  
    printf("Mot à encrypter: ");
    scanf("%s", input);  

    char* key = generate_key((int)strlen(input)); 
    char* output = chiffrer(input, t_v, key); 
    printf("key: %s\n", key); 
    printf("Input: %s\n", input); 
    printf("Output: %s\n", output); 

    char* out_decoded = dechiffrer(output, t_v, key); 
    printf("Reverse outpout: %s\n", out_decoded); 

    free_matrix_memo(t_v); 
    free(key);
    free(output); 
    free(out_decoded); 

    return 0; 
}
