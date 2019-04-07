#include"chess.h"


int logic(int tab[9][9],int a,int b, int c, int d){
	switch(tab[a][b]){
		case 0: 
			if(((a-1 == c) || ((a-2 == c) && (a == 6))) && (b == d)){
				return 1;
			}
			else return 0;
		case 1: 
			if(((a == c) && (d != b)) || ((d == b) && (a != c))){
				return 1;
			}
			else return 0;
		case 5: 
			if((((a + 1) == c) && ((b + 2) == d)) || (((a + 1) == c) && ((b - 2) == d)) || (((a - 1) == c) && ((b + 2) == d)) || (((a - 1) == c) && ((b - 2) == d)) || (((a + 2) == c) && ((b + 1) == d)) || (((a + 2) == c) && ((b - 1) == d)) || (((a - 2) == c) && ((b + 1) == d)) || (((a - 2) == c) && ((b - 1) == d)) ) {
				return 1;
			}
			else return 0;
		case 2: 
			if(((a-c) == (b-d)) && (a != c) || ((a-c) == (d-b)) && (b != d)){
				return 1;
			}
			else return 0;	
		case 3: 
			if( (  (a == c) ||  (d == b) ) || ( ( (a-c) == (b-d)) || ((a-c) == (d-b)) ) && ((a - 2) < c < (a+2) && ((a-2) < d < (b + 2) ) ) ){
				return 1;
			}
			else return 0;	
		case 4: 
			if( (  (a == c) ||  (d == b) ) || ( ( (a-c) == (b-d)) || ((a-c) == (d-b)) ) ){
				return 1;
			}
			else return 0;	
	}
}

void Hod(int tab[9][9],int a,int b,int c,int d,char hod,char shma,int *mat){
    if((logic(tab,b,a,d,c) == 1) && (logic_trough(tab,b,a,d,c,hod) == 1) && ((logic_mat(tab,b,a,d,c,shma,mat) == 1) || (shma != '+'))&& ((logic_kill(tab,b,a,d,c,hod) == 1) || (hod != 'x') )&& ((logic_shah(tab,b,a,d,c,shma) == 1) || (shma != '#')) && ((hod == '-') || (hod == 'x'))){
		int temp = tab[b][a];
    	tab[b][a] = tab[d][c];
    	tab[d][c] = temp;
	}
	else printf("Vvedeno nepravilno... Vvedite eshe raz\n");
}

int logic_trough(int tab[9][9],int a, int b, int c,int d, char hod) {
	if((tab[c][d] == 8) || ((tab[c][d] > 5) && (hod == 'x'))){
		return 1;
	}
	else return 0;
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
int logic_mat(int tab[9][9],int a, int b, int c,int d,char shma,int *mat){
	if(shma != '+') return 0;
		switch(tab[a][b]){
		case 0: 
			if((tab[c+1][d-1] == 10) || (tab[c+1][d+1]) == 10) {
				logic_king(tab, c+1,d-1,mat);
				logic_king(tab, c+1,d+1,mat);
				return 1;
			}
			else return 0;
		case 1:
			for(int i = 1; i < 9; i++){
				if(tab[c][i] == 10) {
					logic_king(tab,c , i, mat);
					return 1;
				}
				if(tab[i][d] == 10) {
					logic_king(tab,i , d, mat);
					return 1;
				}
			}
			return 0;
		case 2:
				for(int i = 0; i < 9 - c; i++){
				if(tab[c+i][d+i] == 10) {
					logic_king(tab,c+i,d+i,mat);
					return 1;
				}
			}
			for(int i = 0; i <  c + 1; i++){
				if(tab[c-i][d-i] == 10) {
					logic_king(tab,c-i,d-i,mat);
					return 1;
				}
			}
			for(int i = 0; i < 9 - d; i++){
				if(tab[c-i][d+i] == 10) {
					logic_king(tab,c-i,d+i,mat);
					return 1;
				}
			}
			for(int i = 0; i < d; i++){
				if(tab[c+i][d-i] == 10) {
					logic_king(tab,c+i,d-i,mat);
					return 1;
				}
			}
		case 5: 
			if((tab[c+1][d+2] == 10) || (tab[c+1][d-2] == 10) || (tab[c-1][b+2] == 10) || (tab[c-1][b-2] == 10) || (tab[c+2][d+1] == 10) || (tab[c+2][d-1] == 10) || (tab[c-2][d+1]) || (tab[c-2][d-1] == 10)) {
				logic_king(tab, c+1,d+2,mat);
				logic_king(tab, c+1,d-2,mat);
				logic_king(tab, c-1,d+2,mat);
				logic_king(tab, c-1,d-2,mat);
				logic_king(tab, c+2,d+1,mat);
				logic_king(tab, c+2,d-1,mat);
				logic_king(tab, c-2,d+1,mat);
				logic_king(tab, c-2,d-1,mat);
				return 1;
			}
			else return 0;	
		case 3:
			return 0;
		case 4:
			for(int i = 0; i < 9 - c; i++){
				if(tab[c+i][d+i] == 10) {
					logic_king(tab,c+i,d+i,mat);
					return 1;
				}
			}
			for(int i = 0; i <  c + 1; i++){
				if(tab[c-i][d-i] == 10) {
					logic_king(tab,c-i,d-i,mat);
					return 1;
				}
			}
			for(int i = 0; i < 9 - d; i++){
				if(tab[c-i][d+i] == 10) {
					logic_king(tab,c-i,d+i,mat);
					return 1;
				}
			}
			for(int i = 0; i < d; i++){
				if(tab[c+i][d-i] == 10) {
					logic_king(tab,c+i,d-i,mat);
					return 1;
				}
			}
			for(int i = 1; i < 9; i++){
				if(tab[c][i] == 10) {
					logic_king(tab,c , i, mat);
					return 1;
				}
				if(tab[i][d] == 10) {
					logic_king(tab,i , d, mat);
					return 1;
				}
			}
			
	}
	
}
int logic_kill(int tab[9][9],int a, int b, int c,int d, char hod){
	if(hod != 'x') return 0;
	if(tab[c][d] > 5) {
		tab[c][d] = 8;
		return 1;
	}
	
}
int logic_shah(int tab[9][9],int a, int b, int c,int d,char shma){
	
	if(shma != '#') return 0;
	switch(tab[a][b]){
		case 0: 
			if((tab[c+1][d-1] == 10) || (tab[c+1][d+1]) == 10) return 1;
			else return 0;
		case 1:
			for(int i = 1; i < 9; i++){
				if(tab[c][i] == 10) return 1;
				if(tab[i][d] == 10) return 1;
			}
			return 0;
		case 2:
			for(int i = 0; i < 9 - c; i++){
				if(tab[c+i][d+i] == 10) return 1;
			}
			for(int i = 0; i <  c + 1; i++){
				if(tab[c-i][d-i] == 10) return 1;
			}
			for(int i = 0; i < 9 - d; i++){
				if(tab[c-i][d+i] == 10) return 1;
			}
			for(int i = 0; i < d; i++){
				if(tab[c+i][d-i] == 10) return 1;
			}
		case 5: 
			if((tab[c+1][d+2] == 10) || (tab[c+1][d-2] == 10) || (tab[c-1][b+2] == 10) || (tab[c-1][b-2] == 10) || (tab[c+2][d+1] == 10) || (tab[c+2][d-1] == 10) || (tab[c-2][d+1]) || (tab[c-2][d-1] == 10)) {
				return 1;
			}
			else return 0;	
		case 3:
			return 0;
		case 4:
			for(int i = 0; i < 9 - c; i++){
				if(tab[c+i][d+i] == 10) return 1;
			}
			for(int i = 0; i <  c + 1; i++){
				if(tab[c-i][d-i] == 10) return 1;
			}
			for(int i = 0; i < 9 - d; i++){
				if(tab[c-i][d+i] == 10) return 1;
			}
			for(int i = 0; i < d; i++){
				if(tab[c+i][d-i] == 10) return 1;
			}
			for(int i = 1; i < 9; i++){
				if(tab[c][i] == 10) return 1;
				if(tab[i][d] == 10) return 1;
			}
			
	}
}

void logic_king(int tab[9][9],int a, int b, int *mat){
	
	if((tab[a+1][b+1] != 8) || (tab[a][b+1] != 8) || (tab[a+1][b] != 8) || (tab[a-1][b+1] != 8) || (tab[a+1][b-1] != 8) || (tab[a][b-1] != 8) || (tab[a-1][b] != 8) || (tab[a-1][b-1] != 8) && (tab[a][b] == 10)){
		mat = 1;	
	}
}
	
	
