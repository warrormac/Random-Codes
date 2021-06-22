#ifndef SERPIENTE_H
#define SERPIENTE_H


class serpiente
{
public:
    char tecla;
    int dif;
    int n=1;//se agrega al tam
    int tam = 2;//es el tamaño inicial del cuerpo
    int x=4, y=4;//cordenada del inicio
    int dir=3;//esto es para uasr las flechas
    int xc=10, yc=4;//comida  óscision x para la comida
    int Puntos=0;//contador del puntaje
    int xxc= 14, yyc=4;//pocision y para la comida
    double tiempo;//contador del tiempo
    int cuerpo[200][20];//tablero
public:

    serpiente();//constructor
    virtual ~serpiente();//destructo
    void gotoxy(int x, int y);
    void comida();
    bool gameover();
    void puntosx();
    void pintar();
    void dibujarcuerpo();
    void guardarposicion();
    void borrarcuerpo();
    void proceso();
    void Teclear();


};

#endif // SERPIENTE_H
