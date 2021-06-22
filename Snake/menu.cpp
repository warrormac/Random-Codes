#include "menu.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;
menu::menu()
{
    //ctor
}

menu::~menu()
{
    //dtor
}

void menu::gotoxy(int x,int y){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;

	SetConsoleCursorPosition(hCon,dwPos);
}
void menu::menu_inicial(){
    for(int i = 0 ; i< 17 ; i++){
        for(int j = 0 ; j < 71 ; j++){
            if(inicio[i][j] == 'A'){
                gotoxy(j+1,i+1); cout<<("*");
            }
        }
    }

    tecla = getch();

    for(int i = 0 ; i< 17 ; i++){
        for(int j = 0 ; j < 71 ; j++){
            if(inicio[i][j] == 'A'){
                gotoxy(j+3,i+3);
            }
        }
    }
}
