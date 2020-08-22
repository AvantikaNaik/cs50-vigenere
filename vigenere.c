#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int shift(char c);
int main(int argc, string argv[])

{
    // If more than 2 arguments, ends code
    if (argc != 2) 
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }
    
    // Check if command argument promt is only letters
    int i = 0;
    while (argv[1][i] != '\0')
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./vigenere key\n");
            return 1;
        }
        i++;
    }
    
    // Shifts key to number 
    int keylength = strlen(argv[1]);
    int key[100];
    for (i = 0; i < strlen(argv[1]); i++)
    {
        key[i] = shift(argv[1][i]);
    }
    
    // Get plaintext from user
    string plaintext = get_string("plaintext:");
    
    // Start printing output 
    printf("ciphertext: ");
    
    int j = 0;
    //Loop letters and shift by key
    for (i = 0, j = 0; plaintext [i] != '\0'; i++)
    {
        if (isupper(plaintext[i]))
        {
            // Convert to ciphertext
            int letter = plaintext[i];
            int newletter = (letter - 64);
            int cipherletter = ((newletter + key[j % keylength]) % 26);
            int f_lower = (cipherletter + 64);
            char finallower = f_lower;
            printf("%c", finallower);
            j++;
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i];
            int newletter = letter - 96;
            int cipherletter = (newletter + key[j % keylength]) % 26;
            int f_upper = cipherletter + 96;
            char finalupper = f_upper;
            printf("%c", finalupper);
            j++;
        }
        else 
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

// Defining the function for letter to number convertion
int shift(char c)
{
    if (isupper(c))
    {
        // Convert to number
        int letter = c;
        int newnumber = (letter - 65);
        return newnumber;
    }
    else
    {
        int letter = c;
        int newnumber = letter - 97;
        return newnumber;
    }
}
