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
bool ContainsLetterMoreThanOnce(char* String)

int main( int argc, char *argv[] ){
    
    
    
    char PlainText[] = "Hoi computer ik hou van jou <3.";
    char* Key = "qw#rtyuiop%sdfghjklzxcvbnm";
   
    char* CipherText = Encrypt(PlainText, Key);
    char* DecipheredText = Decrypt(CipherText, Key);
 
    PrintString(CipherText);
    PrintString(DecipheredText);
    free(CipherText);
    free(DecipheredText);

}

bool ValidateCommandLineArguments(int argc, char* argv){
    int ErrorCount = 0;
    int KeyLength = strlen(argv);

    
    if (argc > 1){
            printf("Function requires one command line argument. You entered: %i\n", argc); 
            ErrorCount++; 
        }     
    if (KeyLength != 26 ){
            printf("Key has to be 26 letters. You entered: %i\n", KeyLength);
            ErrorCount++; 
        }    
  //  if( )

   


}
//If your program is executed without any command-line arguments or with more than one command-line argument
//, your program should print an error message of your choice (with printf) 
//and return from main a value of 1 (which tends to signify an error) immediately.

//If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not ..//containing each letter exactly once), your program should print an error message of your choice (with printf) and return from //..//main a value of 1 immediately.


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

bool ContainsLetterMoreThanOnce(char* String){
    int LetterCount = 0;

    for(int i = 0, n = strlen(String); i <= String; i++){
        for(int j = 0,  k = 97; j < 27; k++){
            if(String[i] == k){
                LetterCount++;
            }
        }
    if(LetterCount > 1)
        return false;
    }
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
