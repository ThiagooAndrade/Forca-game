#include "methods.h"

char word_secret[100], word_screen[100], letter = ' ', played_letters[100];
int gallow = 0;
int word_length;
int mistake = 1;
int moves = 0;

int main()
{

    init(word_secret, word_screen, letter, played_letters, gallow, word_length, mistake, moves);

    return 0;
}
