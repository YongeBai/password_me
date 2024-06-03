#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int num_uppercase = 1, num_lowercase = 3, num_digits = 3, num_special = 1;

    char uppercase[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                        'U', 'V', 'W', 'X', 'Y', 'Z'};
    char lowercase[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                        'u', 'v', 'w', 'x', 'y', 'z'};
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char special[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                      '-', '_', '+', '=', '{', '}', '[', ']', '|', '\\',
                      ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/'};
    int opt;

    while ((opt = getopt(argc, argv, "u:l:d:s:")) != -1)
    {
        switch (opt)
        {
        case 'u':
            num_uppercase = atoi(optarg);
            break;
        case 'l':
            num_lowercase = atoi(optarg);
            break;
        case 'd':
            num_digits = atoi(optarg);
            break;
        case 's':
            num_special = atoi(optarg);
            break;
        default:
            fprintf(stderr, "Usage: %s [-u uppercase] [-l lowercase] [-d digits] [-s special]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    int password_length = num_uppercase + num_lowercase + num_digits + num_special;
    char password[password_length];
    int filled[password_length];

    for (int i = 0; i < password_length; i++)
    {
        int randomIdx = rand() % password_length;
        if (filled[randomIdx] == 1)
        {
            i--;
            continue;
        }
        filled[randomIdx] = 1;

        if (num_uppercase > 0)
        {
            password[randomIdx] = uppercase[rand() % 26];
            num_uppercase--;
        }
        else if (num_lowercase > 0)
        {
            password[randomIdx] = lowercase[rand() % 26];
            num_lowercase--;
        }
        else if (num_digits > 0)
        {
            password[randomIdx] = digits[rand() % 10];
            num_digits--;
        }
        else if (num_special > 0)
        {
            password[randomIdx] = special[rand() % 30];
            num_special--;
        }
    }
    printf("%s\n", password);

    return 0;
}
