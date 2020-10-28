#include "vigenere.h"

char* cesar_code(char* input_str, int key) {
    int input_str_length = strlen(input_str); 
    char* encode_str = (char*)malloc(sizeof(char)*input_str_length); 
    for(int i = 0; i < input_str_length; i++){
        char * current_char_to_encode = strchr(ALPHABET, input_str[i]); 
        int index_char = (int)(current_char_to_encode-ALPHABET);
        encode_str[i] = ALPHABET[(index_char+key)%LENGTH_ALPHA];  
        printf("Char %c at index %d in ALPHA => %c\n", input_str[i], index_char, encode_str[i]);
    }
    return encode_str; 
}

char** table_vigenere(){
    char** table = malloc(sizeof(char*)*LENGTH_ALPHA); 
    for(int i = 0; i < LENGTH_ALPHA; i++){
        table[i] = malloc(sizeof(char)*LENGTH_ALPHA);  
        for (int j = 0; j < LENGTH_ALPHA; j++){
            table[i][j] = ALPHABET[(j+i)%LENGTH_ALPHA]; 
        }
    } 
    return table; 
}

char* generate_key(int length){
    char* key = malloc(sizeof(char)*length+1); 
    for(int i = 0; i < length; i++){
        key[i] = ALPHABET[rand()%LENGTH_ALPHA]; 
    }
    return key; 
}

char* chiffrer(char* to_encode, char** t_v, char* key){
    char* output = malloc(sizeof(char)*(int)strlen(to_encode)); 
    for(int i = 0; i < (int)strlen(to_encode); i++){
        char* current_char_key = strchr(ALPHABET, key[i]);
        char* current_char_to_encode = strchr(ALPHABET, to_encode[i]);
        int index_char_key = (int)(current_char_key-ALPHABET);
        int index_char_encode = (int)(current_char_to_encode-ALPHABET); 
        output[i] = t_v[index_char_key][index_char_encode]; 
    }
    return output; 
}

char* dechiffrer(char* to_decode, char** t_v, char* key){ 
    char* output = malloc(sizeof(char)*strlen(to_decode)); 

    for(int i = 0; i < (int)strlen(to_decode); i++){ 
        for (int j = 0; j < LENGTH_ALPHA; j++){
            char* char_key = strchr(ALPHABET, key[i]);
            int index_key = (int)(char_key-ALPHABET);
            if (t_v[index_key][j] == to_decode[i]){
                output[i] = ALPHABET[j]; 
            }
        }  
    }
    return output; 
}

void output_table_vigenere(char** table) {
    for(int row = 0; row < LENGTH_ALPHA; row++){
        for(int column = 0; column < LENGTH_ALPHA; column++){
            printf("%c\t", table[row][column]); 
        }
        printf("\n"); 
    }
}

void free_matrix_memo(char** m){
    for(int i = 0; i < (sizeof(m)/sizeof(m[0])); i++){
        free(m[i]); 
    }
    free(m); 
}
