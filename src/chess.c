#include "chess.h"

int logic(int tab[9][9], int a, int b, int c, int d)
{
    switch (tab[a][b]) {
    case 0:
        if (((a - 1 == c) || ((a - 2 == c) && (a == 6))) && (b == d)) {
            return 1;
        } else
            return 0;
    case 1:
        if (((a == c) && (d != b)) || ((d == b) && (a != c))) {
            return 1;
        } else
            return 0;
    case 5:
        if ((((a + 1) == c) && ((b + 2) == d))
            || (((a + 1) == c) && ((b - 2) == d))
            || (((a - 1) == c) && ((b + 2) == d))
            || (((a - 1) == c) && ((b - 2) == d))
            || (((a + 2) == c) && ((b + 1) == d))
            || (((a + 2) == c) && ((b - 1) == d))
            || (((a - 2) == c) && ((b + 1) == d))
            || (((a - 2) == c) && ((b - 1) == d))) {
            return 1;
        } else
            return 0;
    case 2:
        if ((((a - c) == (b - d)) && (a != c))
            || (((a - c) == (d - b)) && (b != d))) {
            return 1;
        } else
            return 0;
    case 3:
        if (((a == c) || (d == b))
            || (((a - c) == (b - d))
                || ((((a - c) == (d - b))) && (((a - 2) < c))
                    && ((((c < (a + 2)))) && (((a - 2) < d)))
                    && (((d < (b + 2))))))) {
            return 1;
        } else
            return 0;
    case 4:
        if (((a == c) || (d == b))
            || (((a - c) == (b - d)) || ((a - c) == (d - b)))) {
            return 1;
        } else
            return 0;
    }
    return 0;
}

int Hod(int tab[9][9], int a, int b, int c, int d, char hod)
{
    if ((logic(tab, b, a, d, c) == 1)
        && (logic_trough(tab, b, a, d, c, hod) == 1)
        && ((logic_kill(tab, b, a, d, c, hod) == 1) || (hod != 'x'))
        && ((hod == '-') || (hod == 'x'))) {
        int temp = tab[b][a];
        tab[b][a] = tab[d][c];
        tab[d][c] = temp;
        return 0;
    }
    return 1;
}

int logic_trough(int tab[9][9], int a, int b, int c, int d, char hod)
{
    if ((tab[c][d] == 8) || ((tab[c][d] > 5) && (hod == 'x'))) {
        return 1;
    } else
        return 0;
}

int convert(char word)
{
    switch (word) {
    case 'A':
        return 1;
    case 'B':
        return 2;
    case 'C':
        return 3;
    case 'D':
        return 4;
    case 'F':
        return 5;
    case 'E':
        return 6;
    case 'G':
        return 7;
    case 'H':
        return 8;
    }
    return 0;
}

int logic_kill(int tab[9][9], int a, int b, int c, int d, char hod)
{
    if (hod != 'x')
        return 0;
    if (tab[c][d] > 5) {
        tab[c][d] = 8;
        return 1;
    }
    return 0;
}

