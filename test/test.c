#include "ctest.h"
#include "board_print_plain.h"
#include "chess.h"


CTEST(get_out_table,chess_test){
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
	word = 'G';
	num = 1;
	hod = '-';
	word1 = 'Z';
	num1 = 9;
	ASSERT_EQUAL(1,Hod(tab,convert(word),num,convert(word1),num1,hod));
}
CTEST(Hod_peshki,chess_test){

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
	word = 'A';
	num = 7;
	hod = '-';
	word1 = 'A';
	num1 = 6;
	ASSERT_EQUAL(0,Hod(tab,convert(word),num,convert(word1),num1,hod));
}
CTEST(Hod_rook,chess_test){
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
	word = 'A';
	num = 8;
	hod = '-';
	word1 = 'A';
	num1 = 4;
	ASSERT_EQUAL(0,Hod(tab,convert(word),num,convert(word1),num1,hod));
}
CTEST(Hod_clon,chess_test){
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
	word = 'C';
	num = 8;
	hod = '-';
	word1 = 'F';
	num1 = 6;
	ASSERT_EQUAL(0,Hod(tab,convert(word),num,convert(word1),num1,hod));
}
CTEST(Hod_Knigt,chess_test){
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
	word = 'B';
	num = 8;
	hod = '-';
	word1 = 'C';
	num1 = 6;
	ASSERT_EQUAL(0,Hod(tab,convert(word),num,convert(word1),num1,hod));
}
CTEST(Hod_qeen,chess_test){
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
	word = 'F';
	num = 8;
	hod = '-';
	word1 = 'F';
	num1 = 3;
	ASSERT_EQUAL(0,Hod(tab,convert(word),num,convert(word1),num1,hod));
}
CTEST(Hod_king,chess_test){
	int num,num1;
    char word,word1,hod;
	int tab[9][9] = 
   {
 {'/','1','2','3','4','5','6','7','8'},
 {'A',7,12,9,10,11,9,12,7},
 {'B',6,6,6,6,6,6,6,6},
 {'C',8,8,8,8,8,8,8,8},
 {'D',8,8,8,8,8,8,8,8},
 {'F',8,8,8,3,8,8,8,8},
 {'E',8,8,8,8,8,8,8,8},
 {'G',0,0,0,0,0,0,0,0},
 {'H',1,5,2,8,4,2,5,1},
};
	word = 'D';
	num = 5;
	hod = '-';
	word1 = 'F';
	num1 = 5;
	ASSERT_EQUAL(0,Hod(tab,convert(word),num,convert(word1),num1,hod));
}

