#include "board_print_plain.h"

void printTab(int tab[9][9])
{
    for (int i = 0; i < 9; i++) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            if (i == 0) {
                printf("A B C D F E G H");
                break;
            } else {
                printf("%c ", converts(tab, i, j + 1));
            }
        }
        printf("\n");
    }
}

char converts(int tab[9][9], int i, int j)
{
    switch (tab[i][j]) {
    case 0:
        return 'p';
    case 1:
        return 'r';
    case 2:
        return 'b';
    case 3:
        return 'k';
    case 4:
        return 'q';
    case 5:
        return 'n';
    case 6:
        return 'p';
    case 7:
        return 'r';
    case 9:
        return 'b';
    case 10:
        return 'k';
    case 11:
        return 'q';
    case 12:
        return 'n';
    case 8:
        return ' ';
    }
    return 0;
}
