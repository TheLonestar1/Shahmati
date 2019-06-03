#ifndef GRANDPARENT_H
#define GRANDPARENT_H
#include<stdio.h>
#include<stdlib.h>
#endif
int convert(char word);
int Hod(int tab[9][9],int a,int b,int c,int d,char hod);
int logic(int tab[9][9],int a,int b, int c, int d);
int logic_trough(int tab[9][9],int a, int b, int c,int d,char hod);
int logic_mat(int tab[9][9],int a, int b, int c,int d,char shma, int *mat);
int logic_kill(int tab[9][9],int a, int b, int c,int d,char hod);
int logic_shah(int tab[9][9],int a, int b, int c,int d,char shma);
void logic_king(int tab[9][9],int a, int b, int *mat);
