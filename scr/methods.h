#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef METHODS_H
#define METHODS_H

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printGallow(int gallow)
{
    if (gallow == 0)
    {
        printf("\n--------------");
        printf("\n|            |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-\n");
    }
    else if (gallow == 1)
    {
        printf("\n--------------");
        printf("\n|            |");
        printf("\n|            O");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-\n");
    }
    else if (gallow == 2)
    {
        printf("\n--------------");
        printf("\n|            |");
        printf("\n|            O");
        printf("\n|            |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-\n");
    }
    else if (gallow == 3)
    {
        printf("\n--------------");
        printf("\n|            |");
        printf("\n|            O");
        printf("\n|           -|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-\n");
    }
    else if (gallow == 4)
    {
        printf("\n--------------");
        printf("\n|            |");
        printf("\n|            O");
        printf("\n|           -|-");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-\n");
    }
    else if (gallow == 5)
    {
        printf("\n--------------");
        printf("\n|            |");
        printf("\n|            O");
        printf("\n|           -|-");
        printf("\n|           /");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-\n");
    }
    else if (gallow == 6)
    {
        printf("\n--------------");
        printf("\n|            |");
        printf("\n|            O");
        printf("\n|           -|-");
        printf("\n|           / \\");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|       Perdeu o jogo!");
        printf("\n-\n");
    }
}

void showWord(char *word_screen, int word_length)
{
    for (int i = 0; i < word_length; i++)
    {
        printf("%c ", word_screen[i]);
    }
}

bool checkLetter(char letter, char *played_letters, int moves)
{
    for (int i = 0; i < moves; i++)
    {
        if (letter == played_letters[i])
        {
            return true;
        }
    }
    return false;
}

void init(char *word_secret, char *word_screen, int *word_length)
{

    // recebe a palavra secreta
    printf("Digite a palavra secreta: ");
    fflush(stdin);
    fgets(word_secret, 100, stdin);
    word_secret[strlen(word_secret) - 1] = '\0'; // para tirar o pulo de linha do fgets
    clearScreen();
    printf("%s", word_secret);
    printf("\n\n");
    printf("O tamanho da palavra e %d", strlen(word_secret));
    *word_length = strlen(word_secret);
    word_secret[*word_length] = '\0';
    word_screen[*word_length] = '\0';
    // word_screen recebe o tamanho da word_secret
    for (int i = 0; i < *word_length; i++)
    {
        word_screen[i] = '_';
    }
    sleep(1);

    
}



#endif