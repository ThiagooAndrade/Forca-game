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

void init(char *word_secret, char *word_screen, char letter, char *played_letters, int gallow, int word_length, int mistake, int moves)
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
    word_length = strlen(word_secret);
    word_secret[word_length] = '\0';
    word_screen[word_length] = '\0';
    // word_screen recebe o tamanho da word_secret
    for (int i = 0; i < word_length; i++)
    {
        word_screen[i] = '_';
    }
    sleep(1);

    while (1)
    {
        // a tela é limpa
        clearScreen();
        mistake = 1;
        // só aparece depois da primeira jogada
        if (letter != ' ')
        {
            printf("letras jogadas: ");
            for (int i = 0; i < moves; i++)
            {
                printf("%c, ", played_letters[i]);
            }
        }
        // imprime o jogo
        printGallow(gallow);
        printf("\n");
        printf("Adivinhe a palavra: ");
        showWord(word_screen, word_length);
        printf("\nLetra: ");
        fflush(stdin);
        scanf("%c", &letter);

        // verifica se a letter ja foi jogada
        if (checkLetter(letter, played_letters, moves))
        {
            printf("Esta letra ja foi jogada anteriormente");
            sleep(2);
            continue;
        }
        played_letters[moves] = letter;
        // conta quantas vezes foram moves, inicia com 0
        moves++;

        for (int i = 0; i < word_length; i++)
        {
            // verifica se acertou pelo menos uma letter da word_secret
            if (letter == word_secret[i])
            {
                word_screen[i] = word_secret[i];
                mistake = 0;
            }
        }

        // verifica se nao acertou nenhuma letter da word_secret
        if (mistake == 1)
        {
            gallow++;
        }
        // se errar 6 vezes o boneco é enforcado e perde o jogo
        if (gallow == 6)
        {
            clearScreen();
            printGallow(gallow);
            printf("Adivinhe a palavra: ");
            for (int i = 0; i < word_length; i++)
            {

                printf("%c ", word_screen[i]);
            }
            printf("\n\n\nA palavra secreta era: ");
            for (int i = 0; i < word_length; i++)
            {
                word_screen[i] = word_secret[i];
                printf("%c ", word_screen[i]);
            }
            printf("\n\n");
            break;
        }
        // se a word_screen for igual a word_secret ganha o jogo
        if (strcmp(word_screen, word_secret) == 0)
        {
            clearScreen();
            if (letter != ' ')
            {
                printf("letras jogadas: ");
                for (int i = 0; i < moves; i++)
                {
                    printf("%c, ", played_letters[i]);
                }
            }
            printGallow(gallow);
            printf("\n");
            printf("Adivinhe a palavra: ");
            showWord(word_screen, word_length);
            printf("\n\nVOCE ACERTOU!!\n\n");
            sleep(3);
            break;
        }
    }
}

#endif