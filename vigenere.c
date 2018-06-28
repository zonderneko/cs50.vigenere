#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char key[100], input[100];
    int swch;
    do
    {
        swch = 0;
        printf("Enter key string\n");
        gets(key);
        for (int i = 0; i < strlen(key); i++)
        {
            key[i] = tolower(key[i]);
            if (isalpha(key[i]) == 0)
            {
                swch = 1;
                printf("Please enter only alphabet characters\n");
                break;
            }
        }
    }
    while (swch == 1); // ^ checking key string for only abc chars
//   puts(key);
    printf("Enter string:\n");
    gets(input); //input string
    printf("Cyphered string:\n");
    for (int i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]))
        {
            if (islower(input[i]))
                printf("%c", (input[i] - 97 + key[i % strlen(key)] - 97) % 26 + 97); //shift lowercase
            else
                printf("%c", (input[i] - 65 + key[i % strlen(key)] - 65) % 26 + 65); //shift uppercase
        }
        else
            printf("%c", input[i]);
    }
}

