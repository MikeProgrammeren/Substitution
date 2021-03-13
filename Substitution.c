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
char* GetString(void);
char* Decrypt(char* CipherText, char* Key);
bool ContainsLetterMoreThanOnce(char* String);
bool ContainsOnlyLowerLetters(char* String);
bool ValidateCommandLineArguments(int argc, char* argv);

int main(int argc, char *argv[]){
    //key: qwertyuiopasdfghjklzxcvbnm
    if(ValidateCommandLineArguments(argc, argv[1]) == false)
        return 1; 

    char* Key = argv[1];
    char* PlainText = GetString();

    char* CipherText = Encrypt(PlainText, Key );
 
    printf("Ciphertext: %s\n", CipherText);
    
    free(PlainText);
    free(CipherText);
    return 0;
}

bool ValidateCommandLineArguments(int argc, char* argv){

    if (argc != 2){
        printf("Function requires one argument. You entered: %i.\n", argc - 1); 
        return false; 
    }     
    else if(strlen(argv) != 26){
        printf("Key has to be 26 letters long. You the length you entered was: %i.\n", strlen(argv));
        return false; 
    }    
    else if(ContainsOnlyLowerLetters(argv) == false){
        printf("Key contained none alfabetical character.");
        return false; 
    }
    else if(ContainsLetterMoreThanOnce(argv)){
        printf("Key contained the same character more than once.");
        return false; 
    }

    return true;  
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
    char * CipherText = malloc(strlen(PlainText) + 1);
    
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

bool ContainsOnlyLowerLetters(char* String){
    for(int i = 0, n = strlen(String); i < n; i++){
        if(String[i] < 97 || String[i] > 122)
            return false;
    }
    return true; 
}

bool ContainsLetterMoreThanOnce(char* String){
   int LetterCount = 0;

   for(int i = 0, k = 97; i < 27; i++, k++){
      for(int j = 0, n = strlen(String); j < n; j++){
         if(String[j] == k){
            LetterCount++;
         }
      }
      if(LetterCount > 1)
         return true;
      else 
         LetterCount = 0;   
   }
   return false;
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

char* GetString(void){
    char str[MAXCHAR]; 

    printf("Enter plaintext: ", str);
    fgets(str, MAXCHAR, stdin); 
    
    char* conv = malloc(strlen(str)+1);
    strcpy (conv, str);
    return conv;
}
