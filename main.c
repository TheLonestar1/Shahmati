#include<stdio.h>

void Hod(char tab[][],int a,int b,int c,int d){
    char temp = tab[a][b];
    tab[a][b] = tab[c][d];
    tab[c][d] = temp;
}
int convert(char word){
    switch(word){
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
        case 'D':
            return 3;
        case 'F':
            return 4;
        case 'E':
            return 5;
        case 'G':
            return 6;
        case 'H':
            return 7;
       }
    return 0;
}

int main(){
    int num,num1;
    char word,word1;
    char table[8][8] =
    {
    {'r','n','b','q','k','b','n','r'},
    {'p','p','p','p','p','p','p','p'},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {'p','p','p','p','p','p','p','p'},
    {'r','n','b','q','k','b','n','r'},
    };
    while(1){   
     for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){ 
            printf("%c", table[i][j]);         
        }
        printf("\n");
    }
    printf("Vvedite vash hod(A4,B6)=");
    scanf("%c%d,%c%d", &word, &num, &word1, &num1); 
    Hod(*table,convert(word),num,convert(word1),num1);
} 
    return 0;   
}
