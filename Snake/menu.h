#ifndef MENU_H
#define MENU_H


class menu
{
private:
    char tecla;
    char inicio[50][100] =
    {
    "           AAAA AA   A AAAA A A   AAAA",
    "           A    A A  A A  A AAA   A   ",
    "           A    A  A A AAAA A  A  AAA ",
    "           A    A   AA A  A A   A A   ",
    "       AAAAA    A   AA A  A A   A AAAA",
    };

public:
    menu();
    virtual ~menu();
    void menu_inicial();
    void gotoxy(int x, int y);
    void dificultad();
};

#endif // MENU_H
