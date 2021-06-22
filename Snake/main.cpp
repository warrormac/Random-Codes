#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include "menu.h"
#include "serpiente.h"
#include "dificultad.h"
#include "menu.h"
using namespace std;

#define ARRIBA 72//para jugar con las flechas
#define IZQUIERDA 75
#define ABAJO 80
#define DERECHA 77
#define ESC 27






int main(){
serpiente a;
menu m;
dificultad p;
m.menu_inicial();
p.difi();
a.pintar();
a.gotoxy(50,2);cout<<a.Puntos;
a.gotoxy(a.xc,a.yc);cout<<"*";
while(a.tecla != ESC && a.gameover() ){
    a.proceso();
}
if ( !a.gameover()){
        system("cls");
        cout<<"Has perdido\n";
        cout<<"Creadores:Andre Alvarez   Jean Pierre Mejia";

}
	system("pause>NULL");
	return 0;


}

