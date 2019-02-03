#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Prototypes:
bool isValidNumberOfArguments(int n);
bool isValidArgument(string arg);
int shift(char c);
string encryptTheWord(string word, string key);

int main(int argc, string argv[])
{
    // Check first if the key is a valid key
    if (!isValidNumberOfArguments(argc) || !isValidArgument(argv[1]))
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    string key = argv[1];

    string word = get_string("plaintext: ");
    string encryptedWord = encryptTheWord(word, key);
    printf("ciphertext: %s\n", encryptedWord);
}

bool isValidNumberOfArguments(int n)
{
    return n == 2;
}

bool isValidArgument(string arg)
{
    for (int i = 0, n = strlen(arg); i < n; i++)
    {
        if (!isalpha(arg[i]))
        {
            return false;
        }
    }
    return true;
}

int shift(char c)
{
    c = toupper(c);
    return c - 65;
}

string encryptTheWord(string word, string key)
{
    int counter = 0;
    int currentChar;
    for (int i = 0, n = strlen(word), k = strlen(key); i < n; i++)
    {
        currentChar = counter % k;
        // Lowercase:
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] -= 97;
            word[i] = (word[i] + shift(key[currentChar])) % 26;
            word[i] += 97;
            counter++;
        }
        // Uppercase:
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            word[i] -= 65;
            word[i] = (word[i] + shift(key[currentChar])) % 26;
            word[i] += 65;
            counter++;
        }
    }
    return word;
}
