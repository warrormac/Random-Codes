#include "dificultad.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

using namespace std;
dificultad::dificultad()
{
    //ctor
}

dificultad::~dificultad()
{
    //dtor
}
void dificultad::difi(){
    cout<<" \n";
	cout<<"elija una dificultad para alterar la velocidad\n";
	cout<<"1: facil\n";
	cout<<"2: media\n";
	cout<<"3: dificil\n";
	cin>>d;
	switch(d){
		case 1:
			dif=100;//la dificultad
			break;
		case 2:
		    dif=80;
			break;
		case 3:
		    dif=40;
			break;
	}
	system("cls");//limpia la pantalla
}
