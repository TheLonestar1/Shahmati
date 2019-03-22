#include<stdio.h>





int logic(char  tab[9][9],int a,int b, int c, int d){
	switch(tab[a][b]){
		case 'p': 
			if(((a-1 == c) || ((a-2 == c) && (a == 6))) && (b == d)){
				return 1;
			}
			else return 0;
		case 'r': 
			if(((a == c) && (d != b)) || ((d == b) && (a != c))){
				return 1;
			}
			else return 0;
		case 'n': 
			if((((a + 1) == c) && ((b + 2) == d)) || (((a + 1) == c) && ((b - 2) == d)) || (((a - 1) == c) && ((b + 2) == d)) || (((a - 1) == c) && ((b - 2) == d)) || (((a + 2) == c) && ((b + 1) == d)) || (((a + 2) == c) && ((b - 1) == d)) || (((a - 2) == c) && ((b + 1) == d)) || (((a - 2) == c) && ((b - 1) == d)) ) {
				return 1;
			}
			else return 0;
		case 'b': 
			if(((a-c) == (b-d)) && (a != c) || ((a-c) == (d-b)) && (b != d)){
				return 1;
			}
			else return 0;	
		case 'k': 
			if( (  (a == c) ||  (d == b) ) || ( ( (a-c) == (b-d)) || ((a-c) == (d-b)) ) && ((a - 2) < c < (a+2) && ((a-2) < d < (b + 2) ) ) ){
				return 1;
			}
			else return 0;	
		case 'q': 
			if( (  (a == c) ||  (d == b) ) || ( ( (a-c) == (b-d)) || ((a-c) == (d-b)) ) ){
				return 1;
			}
			else return 0;	
	}
	return 0;	
}

void Hod(char tab[9][9],int a,int b,int c,int d,int *count){
    if(logic(tab,a,b,c,d) == 1){
		char temp = tab[a][b];
    	tab[a][b] = tab[c][d];
    	tab[c][d] = temp;
	}
}
int convert(char word){
    switch(word){
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

int main(){

	int counter_all[7] = {0};
    int num,num1;
    char word,word1;
    char tab[9][9] =
    {
    {'/','A','B','C','D','F','E','G','H'},
    {'1','r','n','b','q','k','b','n','r'},
    {'2','p','p','p','p','p','p','p','p'},
    {'3',' ',' ',' ',' ',' ',' ',' ',' '},
    {'4',' ',' ',' ',' ',' ',' ',' ',' '},
    {'5',' ',' ',' ',' ',' ',' ',' ',' '},
    {'6',' ',' ',' ',' ',' ',' ',' ',' '},
    {'7','p','p','p','p','p','p','p','p'},
    {'8','r','n','b','q','k','b','n','r'}
    };
    while(1){   
     for(int i = 0; i < 9; i++){
     	printf("%c ", tab[i][0]); 
        for(int j = 0; j < 8; j++){ 
            printf("%c", tab[i][j+1]);         
        }
        printf("\n");
    }
    printf("Vvedite vash hod(A4,B6)=");
    
    scanf("%c%d,%c%d", &word, &num, &word1, &num1); 
    if((1 <= num ) && ( num <= 8) && (1 <= num1 ) && ( num1 <= 8) && ('A' <= word ) && ( word <= 'H')&& ('A' <= word1 ) && ( word1 <= 'H')){
    	Hod(tab,convert(word),num,convert(word1),num1,counter_all);
	} else {
		printf("Vvedeno nepravilno... Vvedite eshe raz\n");
	}
}
 
    return 0;
}
