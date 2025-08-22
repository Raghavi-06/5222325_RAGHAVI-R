#include <stdio.h>
#include <string.h>
#include <ctype.h>

//function to encrypt a single character
char encryptChar(char c, int k) 
{
    //check if the character is a lowercase letter
    if (islower(c)) 
    {
    //'a' is the starting point, so we normalize the character to be 0-25
 //we add k and take the modulo 26 to handle wrap-around
    //then we add 'a' back to get the new character
        return 'a' + (c - 'a' + k) % 26;
    }
    //check if the character is an uppercase letter
    else if (isupper(c)) 
    {
 //'A' is the starting point, so we normalize the character to be 0-25
    //we add k and take the modulo 26 to handle wrap-around
    //then we add 'A' back to get the new character
        return 'A' + (c - 'A' + k) % 26;
    }
//if the character is not a letter, return it unchanged
    else {
        return c;
    }
}

//function to perform the Caesar Cipher on a string
void caesarCipher(char* s, int k) 
{
    //iterate through each character of the string
    for (int i = 0; s[i] != '\0'; i++) 
    {
  //encrypt the current character and update the string
        s[i] = encryptChar(s[i], k);
    }
}

int main()
 {
    int n, k;
    char s[101]; // Max string length is 100 + 1 for null terminator
    
    //read the length of the string (though not strictly necessary for this C implementation)
    scanf("%d", &n);
    
    //read the string
    scanf("%s", s);
    
    // Read the rotation factor
    scanf("%d", &k);
    
    //call the caesarCipher function to modify the string in place
    caesarCipher(s, k);
    
    //print the encrypted string
    printf("%s\n", s);
    
    return 0;
}
