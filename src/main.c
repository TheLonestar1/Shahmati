#include"chess.h"
#include"board_print_plain.h"

int main(){


    int num,num1;
    char word,word1,hod;
	int tab[9][9] = 
   {
 {'/','1','2','3','4','5','6','7','8'},
 {'A',7,12,9,10,11,9,12,7},
 {'B',6,6,6,6,6,6,6,6},
 {'C',8,8,8,8,8,8,8,8},
 {'D',8,8,8,8,8,8,8,8},
 {'F',8,8,8,8,8,8,8,8},
 {'E',8,8,8,8,8,8,8,8},
 {'G',0,0,0,0,0,0,0,0},
 {'H',1,5,2,3,4,2,5,1},
};
    while(1){   
    system("clear");
    printTab(tab);
    printf("Vvedite vash hod(A4,B6)=");
    
    scanf("%c%d%c%c%d", &word, &num,&hod, &word1, &num1); 
    if((1 <= num ) && ( num <= 8) && (1 <= num1 ) && ( num1 <= 8) && ('A' <= word ) && ( word <= 'H')&& ('A' <= word1 ) && ( word1 <= 'H')){
    	Hod(tab,convert(word),num,convert(word1),num1,hod);
	} else {
		printf("Vvedeno nepravilno... Vvedite eshe raz\n");
	}
	
}
 
    return 0;
}
