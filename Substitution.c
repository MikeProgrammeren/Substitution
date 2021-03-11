#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXCHAR 2000

char* Encrypt(char* PlainText, char* Key);
bool IsUpperCase(char c);
bool IsLowerCase(char c);
char* ConvertStringToLower(char* String);
void PrintString(char* String);
char* GetString(void);
char* Decrypt(char* CipherText, char* Key);

int main(void){
    char PlainText[] = "Hoi computer ik hou van jou <3.";
    char* Key = "qw#rtyuiop%sdfghjklzxcvbnm";
   
    char* CipherText = Encrypt(PlainText, Key);
    char* DecipheredText = Decrypt(CipherText, Key);
 
    PrintString(CipherText);
    PrintString(DecipheredText);
}

char* Decrypt(char* CipherText, char* Key){
    char * DecipheredText =  malloc(strlen(CipherText) + 1); 

    for(int i = 0, n = strlen(CipherText); i <= n; i++){
        for(int j = 0, m = strlen(Key); j < m; j++){
            if(IsLowerCase(CipherText[i])){
                if(CipherText[i] == Key[j]){ 
                    DecipheredText[i] = 97 + j;
                    break;
                }    
            } 
            else if(IsUpperCase(CipherText[i])){
                if(CipherText[i] == Key[j] - 32){
                    DecipheredText[i] = 65 + j;  
                    break;
                }    
            }
            else 
                DecipheredText[i] = CipherText[i];
        } 
    }
    return DecipheredText;
}

char* Encrypt(char* PlainText, char* Key){
    char * CipherText = calloc(strlen(PlainText) + 1, sizeof(char));
    
    for(int i = 0, n = strlen(PlainText); i <= n; i++){
        if(IsLowerCase(PlainText[i])){
            for (int j = 0, k = 97; j < 27; j++, k++){
                if (PlainText[i] == k){
                    CipherText[i] = Key[j];  
                    break;  
                }       
            } 
        }
        else if(IsUpperCase(PlainText[i])){
            for (int j = 0, k = 65; j < 27; j++, k++){
                if (PlainText[i] == k){
                    CipherText[i] = Key[j] - 32;  
                    break;
                }
            }
        }
        else   
            CipherText[i] = PlainText[i]; 
    } 
    return CipherText;      
}

bool IsUpperCase(char c){
    if((c >= 65  && c < 91)) 
        return true;
    else 
        return false; 
}

bool IsLowerCase(char c){
    if(c >= 97   && c < 123) 
        return true; 
    else 
        return false;
}

char* ConvertStringToLower(char* String){
    for(int i = 0, n = strlen(String); i < n; i++){
        if(String[i] >= 65 && String[i] < 91){
            String[i] += 32;
        }  
    }
    return String;
}

void PrintString(char* String){
    printf("%s\n", String);  
}

char* GetString(void){
    char str[MAXCHAR]; 

    printf("Enter plaintext: ", str);
    fgets(str, MAXCHAR, stdin); 
    
    char* conv = malloc(strlen(str)+1);
    strcpy (conv, str);
    return conv;
}