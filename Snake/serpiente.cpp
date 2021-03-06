#include "serpiente.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

using namespace std;

#define ARRIBA 72//para jugar con las flechas
#define IZQUIERDA 75
#define ABAJO 80
#define DERECHA 77
#define ESC 27


serpiente::serpiente()
{
    //ctor
}

serpiente::~serpiente()
{
    //dtor
}

void serpiente::gotoxy(int x,int y){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;

	SetConsoleCursorPosition(hCon,dwPos);
}

void serpiente::pintar(){
	for(int i=2; i<78;i++){
		gotoxy(i,3);cout<<"-";
		gotoxy(i,23);cout<<"-";
	}
	for(int i=4;i<23;i++){
		gotoxy(2,i); cout<<"|";
		gotoxy(77,i); cout<<"|";
	}
	gotoxy(2,3);cout<<"|";
	gotoxy(2,23);cout<<"|";
	gotoxy(77,3);cout<<"|";
	gotoxy(77,23);cout<<"|";

}

void serpiente::dibujarcuerpo(){
	for(int i=1; i<tam;i++){
		gotoxy(cuerpo[i][0],cuerpo[i][1]); cout<<"O";
	}
}

void serpiente::guardarposicion(){
	cuerpo[n][0]=x;
	cuerpo[n][1]=y;
	n++;
	if (n==tam){n=1;}
	dibujarcuerpo();
}


void serpiente::borrarcuerpo(){
		gotoxy(cuerpo[n][0],cuerpo[n][1]); cout<<" ";
		guardarposicion();
	}

void serpiente::Teclear(){//esto es la uncion para usar las flechas
	if (kbhit()){
		tecla=getch();
		switch(tecla){
			case ARRIBA:
			if (dir !=2){dir=1;}
			break;
			case ABAJO:
			if(dir != 1 ){dir=2;}
			break;
			case IZQUIERDA:
			if (dir != 3){dir=4;}
			break;
			case DERECHA:
			if (dir != 4){dir=3;}
			break;
		}
	}

}

void serpiente::comida(){
	if (x==xc && y==yc) {
		srand((unsigned)time(NULL));
		xc=(rand()% 73)+4;
		srand((unsigned)time(NULL));
		yc=(rand()% 19)+4;
		tam++;
		gotoxy(xc,yc); cout<<(char)4;
		Puntos++;
		gotoxy(50,2);cout<<Puntos;
	}

}

bool serpiente::gameover(){
	if (y==3 || y== 23 || x==2 || x==77){return false; }
	for (int j=tam-1; j>0;j--){
		if(cuerpo[j][0]==x && cuerpo [j][1]==y) {return false; }
	}
	return true;
}

void serpiente::puntosx(){
	tiempo=tiempo+0.05;
	int tiempo2=tiempo;
	gotoxy(35,2);cout<<tiempo;
	if (x==xxc && y== yyc){
		srand((unsigned)time(NULL));
		xxc=(rand()%73)+4;
		srand((unsigned)time(NULL));
		yyc=(rand()%19)+4;
		Puntos=Puntos+5;
        gotoxy(50,2);cout<<Puntos;
	}
	if (tiempo2 %10==0){
	   gotoxy(xxc,yyc); cout<<(char)6;
	} else if (tiempo2 %15==0){
		gotoxy(xxc,yyc); cout<<" ";
		srand((unsigned)time(NULL));
		xxc=(rand()%73)+4;
		srand((unsigned)time(NULL));
		yyc=(rand()%19)+4;
	}
}

void serpiente::proceso(){//esto llama a las funciones
	borrarcuerpo();
	comida();
	puntosx();
	Teclear();
	Teclear();
	if (dir==1){y--;}
	if (dir==2){y++;}
	if (dir==3){x++;}
	if (dir==4){x--;}
	Sleep(100);
}
