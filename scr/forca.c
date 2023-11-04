#include "methods.h"

char word_secret[100], word_screen[100], letter = ' ', played_letters[100];
int gallow = 0;
int word_length;
int mistake = 1;
int moves = 0;
char playAgain = '1';

int main()
{
    do
    {

        init(word_secret, word_screen, &word_length);

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
                fflush(stdin);
                printf("Digite 1 para jogar novamente e qualquer tecla para parar de jogar: ");
                scanf("%c", &playAgain);
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
                fflush(stdin);
                printf("Digite 1 para jogar novamente e qualquer tecla para parar de jogar: ");
                scanf("%c", &playAgain);
                break;
            }
        }

        for (int i = 0; i < 99; i++)
        {
            word_secret[i] = ' ';
            word_screen[i] = ' ';
            played_letters[i] = ' ';
        }
        gallow = 0;
        word_length = 0;
        moves = 0;
        letter = ' ';

        clearScreen();

    } while (playAgain == '1');

    return 0;
}
