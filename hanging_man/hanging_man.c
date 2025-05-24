#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int w_size;
    char *word;
    char tries[26]; // guarda letras que NÃO existem na palavra
    int tries_size = 0;

    printf("Hello! This is a Hanging Man game\n");
    printf("The first player types in the word, the second tries to guess it!\n\n");

    while (1) {
        printf("Type:\n");
        printf("\t-1: exit\n");
        printf("\tthe size of the word (max 40): ");
        scanf("%d", &w_size);
        getchar();

        if (w_size == -1) break;
        else if (w_size < 1 || w_size > 40) {
            printf("Your word must have between 1 and 40 letters! Try again.\n\n");
        } else {
            word = (char *)malloc((w_size + 1) * sizeof(char)); // +1 for '\0'
            if (word == NULL) {
                printf("Memory allocation failed!\n");
                return 1;
            }

            printf("Now, type in the secret word: ");
            fgets(word, w_size + 1, stdin);
            getchar();

             tries[tries_size++] = 'z';

            printf("LETTERS USED: ");
            for (int i = 0; i < tries_size; i++) {
                printf("%c ", tries[i]);
            }

            printf("\no---------\n");
            printf("|        |\n|\n|\n|\n");
            printf("--- WORD: ");
            for (int i = 0; i < w_size; i++) {
                printf("_ ");
            }
            printf("\n");

            free(word);
            break;
        }
    }

    printf("Good bye!\n");
    return 0;
}

