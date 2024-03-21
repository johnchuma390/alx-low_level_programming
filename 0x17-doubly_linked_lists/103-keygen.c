#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 100

/**
 * generate_key - Generates key for given username
 * @username: The username for which key is generated
 * @key: Buffer to store generated key
 */
void generate_key(const char *username, char *key)
{
    int i, len;
    char reversed_username[MAX_KEY_LENGTH];
    strcpy(reversed_username, username);
    strrev(reversed_username);
    len = strlen(reversed_username);

    for (i = 0; i < len; i++)
    {
        key[i] = reversed_username[i] + i;
    }
    key[len] = '\0';
}

/**
 * main - Entry point, generates key for given username
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s username\n", argv[0]);
        return 1;
    }

    char key[MAX_KEY_LENGTH];
    generate_key(argv[1], key);
    printf("%s\n", key);

    return 0;
}

