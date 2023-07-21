// This program encrypts a message using Caesar’s cipher

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Checks for correct number of arguments.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Checks that each character in given argument is numeric

    for (int i = 0, len = strlen(argv[1]); i < len ; i++)
    {
        if (isdigit(argv[1][i]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Prompt user for text
    string text = get_string("plaintext: ");


    int K = atoi(argv[1]);
    int len = strlen(text);
    char cipher[len];

    // Encrypts the text using provided key.

    for (int i = 0; i < len ; i++)
    {
        if islower(text[i])
        {
            int P = text[i] - 'a';  // converts to alpabetical index
            char C = ((P + K) % 26) + 'a';
            cipher[i] = C;
        }

        else if isupper(text[i])
        {
            int P = text[i] - 'A';  // converts to alpabetical index
            char C = ((P + K) % 26) + 'A';
            cipher[i] = C;
        }

        else
        {
            cipher[i] = text[i];
        }
    }
    cipher[len] = '\0';
    printf("ciphertext: %s\n", cipher);
    return 0;


}
