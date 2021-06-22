#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#include "comida.h"


int SCREENW = 1360;
int SCREENH = 768;

int jugadores = 10;
int players[10];
double max_delta = 2;


BITMAP* buffer = NULL;


int player_colors[10][2] =
{
    27648,37648,
    168,178,
    8521476,8521476,
    8421476,8421476,

    10007083,10007073,//2970685,2970685,///9830500,9830500
    2980685,2980685,
    9870550,9870550,
    3999985,3999985,
    2960685,2960685,
    89421476,89421476
};


int humanplayer[10] =
{
   /// 1,1,1,1,1,1,1,1,1,1
   1,0,0,0,0,0,0,0,0,0
};


vector <base *> blobs;
vector <base *> blobs2;

int player_key[11][5] =
{
  // up, down, left, right
    {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE},
    {KEY_W, KEY_S, KEY_A, KEY_D, KEY_F},
    {KEY_I, KEY_K, KEY_J, KEY_L, KEY_P},
    {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE},
    {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE},
    {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE},

    {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE},
    {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE},
    {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE},
    {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE},
    {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE}
};

int players_start[10][2] =
{
    {rand()% SCREENW , rand() % SCREENH},
    {rand()% SCREENW , rand() % SCREENH},
    {rand()% SCREENW , rand() % SCREENH},
    {rand()% SCREENW , rand() % SCREENH},
    {rand()% SCREENW , rand() % SCREENH},
    {rand()% SCREENW , rand() % SCREENH},
    {rand()% SCREENW , rand() % SCREENH},
    {rand()% SCREENW , rand() % SCREENH},
    {rand()% SCREENW , rand() % SCREENH},
    {rand()% SCREENW , rand() % SCREENH}
};


void movecomputer(unsigned int c)
{
    unsigned int closest = c;


    double distance = SCREENW * SCREENW + SCREENH * SCREENH;
    for (unsigned int d = 0; d < blobs.size(); d++)
    {
        if (d == c) continue;
        int xx = abs(blobs[c]->getx() - blobs[d]->getx());
        int yy = abs(blobs[c]->gety() - blobs[d]->gety());
        double p = xx * xx + yy * yy;
        if (p < distance)
        {
            distance = p;
            closest = d;
        }
    }

    int dx = (blobs[closest]->getx() > blobs[c]->getx()) ? 1 : -1;
    int dy = (blobs[closest]->gety() > blobs[c]->gety()) ? 1 : -1;
    if (blobs[closest]->radius < blobs[c]->radius)
    {
        blobs[c]->setdx( blobs[c]->getdx() + dx );/// += dx;
        blobs[c]->setdy( blobs[c]->getdy() + dy );
    }
    else
    {
        blobs[c]->setdx( blobs[c]->getdx() - dx );
        blobs[c]->setdy( blobs[c]->getdy() - dy );
    }

    ///controlar el velocidad
    if (blobs[c]->getdx() > max_delta/2.0) blobs[c]->setdx( max_delta/2.0 );
    if (blobs[c]->getdy() > max_delta/2.0) blobs[c]->setdy( max_delta/2.0 );
    if (blobs[c]->getdx() < -max_delta/2.0) blobs[c]->setdx( -max_delta/2.0 );
    if (blobs[c]->getdy() < -max_delta/2.0) blobs[c]->setdy( -max_delta/2.0 );
}


void doble()
{
    if (key[player_key[0][4]])
    {
        base *temp2 = blobs[0];
        base *temp = new base();

        (*temp) = (*temp)/(*temp2);
        ///temp->setradius(blobs[0]->getradius()/2);

        temp->cal_area();
        temp->setplayerid(1);
        temp->setx(blobs[0]->getx() + blobs[0]->getdx() + blobs[0]->getradius() );
        temp->sety(blobs[0]->gety() + blobs[0]->getdy() +blobs[0]->getradius() );
        temp->setdx(blobs[0]->getdx());
        temp->setdy(blobs[0]->getdy());
        blobs.insert(blobs.begin(),temp);

        ///temp2->setradius(temp->getradius()/2);
        (*temp2) = (*temp2)/(*temp);
    }
}

int moveplayers()
{
    int numplayers = 0;
    int players2[50000];

    for (int c = 0; c < jugadores+4; c++)
        players[c] = -1;
    for (int c = 0; c < 2500; c++)
        players2[c] = -1;

    for (unsigned int c = 0; c < jugadores+4; c++)
    {
        if ((blobs.size() > c) && (blobs[c]->getplayerid() ))
        {
            players[blobs[c]->getplayerid() - 1] = c;
            numplayers++;
        }
    }



  /***
  if (key[KEY_F10]) {
    facenum ++;
    if (faces[facenum][0] == 0) facenum = 0;
    int i = 0;
    do {
      face[i] = faces[facenum][i];
    } while (faces[facenum][i++] != '\0');
  }
******
*/



    for (int p = 0; p < jugadores+4; p++)
    {
        if (players[p] >= 0)
        {
            if (humanplayer[p] || (players[10] == 10) )
            {
                if (key[player_key[p][0]])
                {
                    blobs[players[p]]->setdy( blobs[players[p]]->getdy()-1);
                    doble();
                }
                else if (key[player_key[p][1]])
                {
                    blobs[players[p]]->setdy( blobs[players[p]]->getdy()+1);
                    doble();
                }
                else
                {

                    if (blobs[players[p]]->getdy() > 0){
                        blobs[players[p]]->setdy( blobs[players[p]]->getdy()-1);
                        doble();}
                    if (blobs[players[p]]->getdy() < 0){
                        blobs[players[p]]->setdy( blobs[players[p]]->getdy()+1);
                        doble();}
                    //doble();
                }

                if (key[player_key[p][2]])
                {
                    blobs[players[p]]->setdx( blobs[players[p]]->getdx()-1);
                    doble();
                }
                else if (key[player_key[p][3]])
                {
                    blobs[players[p]]->setdx( blobs[players[p]]->getdx()+1);
                    doble();
                }
                else
                {
                    if (blobs[players[p]]->getdx() > 0){
                        blobs[players[p]]->setdx( blobs[players[p]]->getdx()-1);
                        doble();}
                    if (blobs[players[p]]->getdx() < 0)
                        blobs[players[p]]->setdx( blobs[players[p]]->getdx()+1);
                }
            }

            else
                    movecomputer (players[p]);


        ///controlar cada vez que se mueve no se excesa max_delta

        if (blobs[players[p]]->getdx() > max_delta/2.0) blobs[players[p]]->setdx( max_delta/2.0 );    ///blobs[c].dx = max_delta/2 ;
        if (blobs[players[p]]->getdy() > max_delta/2.0) blobs[players[p]]->setdy( max_delta/2.0 );
        if (blobs[players[p]]->getdx() < -max_delta/2.0) blobs[players[p]]->setdx( -max_delta/2.0 );
        if (blobs[players[p]]->getdy() < -max_delta/2.0) blobs[players[p]]->setdy( -max_delta/2.0 );

        blobs[ players[p] ]->setx( blobs[ players[p] ]->getx() + blobs[players[p]]->getdx() );
        blobs[ players[p] ]->sety( blobs[ players[p] ]->gety() + blobs[players[p]]->getdy() );

        }
    }
    return numplayers;
}


void mainmenu()
{
    while (!key[KEY_ENTER])/// && !key[KEY_ENTER]&& !key[KEY_ESC])
    {
        clear_to_color(screen, makecol(0, 0, 0));
        for (int p = 0; p < jugadores; p++)
        {
            /// player_colors[p]            SCREENH / 2 - 30 + 20 * p
            textprintf_centre_ex(screen, font, SCREENW / 2, SCREENH / 2 -200 + 20 * p,  player_colors[p][1],
            makecol(0,0,0),"(%d) Player %d - %s", p + 1, p + 1, humanplayer[p] ? "human   " : "computer");
        }

    textprintf_centre_ex(screen, font, SCREENW / 2, 60, makecol(255,255,255), makecol(0,0,0), "Agario Battle");
    textprintf_centre_ex(screen, font, SCREENW / 2, 75, makecol(255,255,255), makecol(0,0,0), "++AAA");
    textprintf_centre_ex(screen, font, SCREENW / 2, 90, makecol(255,255,255), makecol(0,0,0), "Developers Abel, Adriana, Andre");
    textprintf_centre_ex(screen, font, SCREENW / 2, SCREENH / 2 - 20 + 20 * jugadores, makecol(255,255,255), makecol(0,0,0), "Press ENTER to begin");
    textprintf_centre_ex(screen, font, SCREENW / 4, SCREENH - 300, player_colors[0][1], makecol(0,0,0), "Arrow");
    textprintf_centre_ex(screen, font, SCREENW / 4, SCREENH - 280, player_colors[0][1], makecol(0,0,0), "Keys");
    textprintf_centre_ex(screen, font, SCREENW / 4, SCREENH - 260, player_colors[0][1], makecol(0,0,0), "PLAYER 1");
    textprintf_centre_ex(screen, font, SCREENW / 2, SCREENH - 300, player_colors[1][1], makecol(0,0,0), "W");
    textprintf_centre_ex(screen, font, SCREENW / 2, SCREENH - 280, player_colors[1][1], makecol(0,0,0), "ASD");
    textprintf_centre_ex(screen, font, SCREENW / 2, SCREENH - 260, player_colors[1][1], makecol(0,0,0), "PLAYER 2");
    textprintf_centre_ex(screen, font, 3 * SCREENW / 4, SCREENH - 300, player_colors[2][1], makecol(0,0,0), "I");
    textprintf_centre_ex(screen, font, 3 * SCREENW / 4, SCREENH - 280, player_colors[2][1], makecol(0,0,0), "JKL");
    textprintf_centre_ex(screen, font, 3 * SCREENW / 4, SCREENH - 260, player_colors[2][1], makecol(0,0,0), "PLAYER 3");
    textprintf_centre_ex(screen, font, SCREENW / 2, SCREENH - 80, makecol(255,255,255), makecol(0,0,0), "F1 to return to this menu   ESC to quit");


    }
/*
    int in = readkey() & 0xff;

    if ((in >= '1') && (in <= '1'+jugadores))
        humanplayer[in - '1'] = !humanplayer[in - '1'];
*/


}





int gameloop()
{

    //mainmenu();

    buffer = create_bitmap(SCREENW, SCREENH);

    blobs.clear();
    blobs2.clear();

    for (int p = 0; p < jugadores; p++)
    {
        blobs.push_back( new base(players_start[p][0], players_start[p][1], 8) );
        blobs.back()->setplayerid(p+1);
        //blobs.back()->setplayerid(p+1);
    }


    for(int i=0; i<3000; i++)
    {

        base* newblob2 = new comida(rand() % SCREENW , rand() % SCREENH ,rand() %15);
        newblob2->cal_area();
        blobs2.push_back(newblob2);
        //blobs2.back()->setplayerid(1);
    }


    for (int num = 0; num < 115; num++)
    {


        base* newblob = new comida();
        //newblob->cal_area();
        newblob->setx( rand() % SCREENW );
        newblob->sety( rand() % SCREENH );
        newblob->setdx( rand() % 2 );
        newblob->setdy( rand() % 2 );

        blobs.push_back(newblob);
    }

    int numplayers = jugadores;



        while (!key[KEY_ESC] && (numplayers>1) )///(tick)
        {


            //rest(1);
            numplayers = moveplayers();

            for (unsigned int c = 0; c < blobs.size(); c++)
            {

                blobs[c]->setx( blobs[c]->getx() + blobs[c]->getdx() );
                blobs[c]->sety( blobs[c]->gety() + blobs[c]->getdy() );
///
                if ((blobs[c]->getx() - blobs[c]->radius) < 0)
                {
                    blobs[c]->setx( blobs[c]->radius + 15 );
                    blobs[c]->setdx( -blobs[c]->getdx() );
                }
                if ((blobs[c]->gety() - blobs[c]->radius) < 0)
                {
                    blobs[c]->sety( blobs[c]->radius + 15);
                    blobs[c]->setdy( -blobs[c]->getdy() );
                }

                if ((blobs[c]->getx() + blobs[c]->radius) > SCREENW-270)
                {
                    blobs[c]->setx( SCREENW-280-blobs[c]->radius );
                    blobs[c]->setdx( -blobs[c]->getdx() );
                }

                if ((blobs[c]->gety() + blobs[c]->radius) > SCREENH-150)
                {
                    blobs[c]->sety( SCREENH-160-blobs[c]->radius );
                    blobs[c]->setdy( -blobs[c]->getdy() );
                }


///
                for (unsigned int d = c+1 ; d < blobs.size(); d++)
                {
                    if (blobs[c]->radius < 0.6){
                        blobs.erase(blobs.begin() + c);

                     blobs.push_back(new comida(rand() % SCREENW , rand() % SCREENH ,rand() %5));

                    }
                    if (blobs2[c]->radius < 0.6){
                        blobs2.erase(blobs2.begin() + c);
                        blobs2.push_back(new comida(rand() % SCREENW , rand() % SCREENH ,rand() %5));


                    }

                    blobs[c]->collides_with( blobs[d] );
                        ///blobs.push_back(new comida(rand() % SCREENW , rand() % SCREENH ,rand() %5));


                    blobs2[d-1]->collides_with( blobs2[c] );
                    ///blobs.push_back(new comida(rand() % SCREENW , rand() % SCREENH ,rand() %5));


                }

                for (unsigned int d = 0; d < blobs.size(); d++)
                {

                   /// blobs2.push_back(new comida(rand() % SCREENW , rand() % SCREENH ,rand() %5));

                    if (blobs2[c]->radius < 0.6)
                    blobs2.erase(blobs2.begin() + c);

                    blobs2[c]->collides_with( blobs[d] );
                    blobs2[c]->collides_with( blobs2[d] );
                }


                if (blobs2[c]->radius < 0.6){
                        blobs2.erase(blobs2.begin() + c);
                    blobs2.push_back(new comida(rand() % SCREENW , rand() % SCREENH ,rand() %5));

                }
                if (blobs[c]->radius < 0.6)
                {
                    blobs.erase(blobs.begin() + c);

                    blobs.push_back(new comida(rand() % SCREENW , rand() % SCREENH ,rand() %5));

                }



            } ///end for

            /// draw screen
            int col;

            for (unsigned int c = 0; c < blobs.size() && c<200; c++)
            {
                col =  makecol (120,100, 00);///makecol (170, 180, 170);

                ///col = player_colors[1];
                for (int p = 0; p < jugadores; p++)
                {
                    if (blobs[c]->getplayerid() == p + 1)
                        col = player_colors[p][0];
                }

                //circle(buffer, blobs2[c]->getx(), blobs2[c]->gety(), blobs2[c]->radius, makecol (120,100, 00));

                ///circle(buffer, blobs[c]->getx(), blobs[c]->gety(), 1.2*blobs[c]->radius, col);
                circle(buffer, blobs[c]->getx(), blobs[c]->gety(), blobs[c]->radius, col);


                circlefill(buffer, blobs2[c]->getx(), blobs2[c]->gety(), blobs2[c]->radius, makecol (120,100, 00));


                //circle(buffer, blobs2[c]->getx(), blobs2[c]->gety(), blobs2[c]->radius, makecol (120,100, 00));

                for (int p = 0; p < jugadores; p++)
                {
                    if (blobs[c]->getplayerid() == p + 1)
                        col = player_colors[p][1];
                }
                //circle(buffer, blobs2[c]->getx(), blobs2[c]->gety(), blobs2[c]->radius, makecol (120,100, 00));

                circlefill(buffer, blobs[c]->getx() + (blobs[c]->radius / 3), blobs[c]->gety() - (blobs[c]->radius / 3), (int)(3 * blobs[c]->radius / 17), col);

            }


            blit(buffer, screen, 0, 0, 0, 0, SCREENW, SCREENH);
            clear_to_color(buffer, makecol(0, 0, 0));
        }/// end while tick



   /// }/// end while esc



    textout_centre_ex(screen, font, "GAME OVER", SCREENW / 2, SCREENH / 2 - 20, makecol(255, 255, 255), -1);
    if (numplayers == 0)
        textout_centre_ex(screen, font, "No winner", SCREENW / 2, SCREENH / 2 + 20, makecol(255, 255, 255), -1);

    else if (blobs[0]->getplayerid())
        textprintf_centre_ex(screen, font, SCREENW / 2, SCREENH / 2, player_colors[blobs[0]->getplayerid() - 1][0], -1, "Playser %d wins", blobs[0]->getplayerid());

    textout_centre_ex(screen, font, "Press ENTER", SCREENW / 2, SCREENH / 2 + 20, makecol(255, 255, 255), -1);

    while(!key[KEY_ENTER] && !key[KEY_ESC] )
        rest(1);

    blobs.clear();
    blobs2.clear();

    destroy_bitmap(buffer);
    return 1;
}///end gameloop


/*

int gameloop()
{

    //mainmenu();

    buffer = create_bitmap(SCREENW, SCREENH);

    blobs.clear();
    blobs2.clear();

    for (int p = 0; p < jugadores; p++)
    {
        blobs.push_back( new base(players_start[p][0], players_start[p][1], 8) );
        blobs.back()->setplayerid(p+1);
        //blobs.back()->setplayerid(p+1);
    }


    for(int i=0; i<500; i++)
    {

        base* newblob2 = new comida(rand() % SCREENW , rand() % SCREENH ,rand() %15);
        newblob2->cal_area();
        blobs2.push_back(newblob2);
        //blobs2.back()->setplayerid(1);
    }


    for (int num = 0; num < 400; num++)
    {


        base* newblob = new comida();
        //newblob->setradius(6);
        newblob->cal_area();
        newblob->setx( rand() % SCREENW );
        newblob->sety( rand() % SCREENH );
        newblob->setdx( rand() % 2 );
        newblob->setdy( rand() % 2 );

        blobs.push_back(newblob);




    }



///


    int numplayers = jugadores;

//    tick = 0;
   /// while ( (!key[KEY_ESC]) && (!key[KEY_F1]) && (numplayers>=1) )
    ///{

        while (!key[KEY_ESC])///(tick)
        {
            ///tick--;

            numplayers = moveplayers();

            for (unsigned int c = 0; c < blobs.size(); c++)
            {

                blobs[c]->setx( blobs[c]->getx() + blobs[c]->getdx() );
                blobs[c]->sety( blobs[c]->gety() + blobs[c]->getdy() );
///
                if ((blobs[c]->getx() - blobs[c]->radius) < 0)
                {
                    blobs[c]->setx( blobs[c]->radius );
                    blobs[c]->setdx( -blobs[c]->getdx() );
                }
                if ((blobs[c]->gety() - blobs[c]->radius) < 0)
                {
                    blobs[c]->sety( blobs[c]->radius );
                    blobs[c]->setdy( -blobs[c]->getdy() );
                }

                if ((blobs[c]->getx() + blobs[c]->radius) > SCREENW-280)
                {
                    blobs[c]->setx( SCREENW-280-blobs[c]->radius );
                    blobs[c]->setdx( -blobs[c]->getdx() );
                }

                if ((blobs[c]->gety() + blobs[c]->radius) > SCREENH-160)
                {
                    blobs[c]->sety( SCREENH-160-blobs[c]->radius );
                    blobs[c]->setdy( -blobs[c]->getdy() );
                }


///
                for (unsigned int d = c+1 ; d < blobs.size(); d++)
                {
                    if (blobs[c]->radius < 0.5)
                        blobs.erase(blobs.begin() + c);

                    if (blobs2[c]->radius < 0.8)
                        blobs2.erase(blobs2.begin() + c);


                    blobs[c]->collides_with( blobs[d] );
                    blobs2[d-1]->collides_with( blobs2[c] );
                }

                for (unsigned int d = 0; d < blobs.size(); d++)
                {

                    //base* newblob2 = new comida(rand() % SCREENW , rand() % SCREENH ,rand() %15);
                    //newblob2->cal_area();
                    blobs2.push_back(new comida(rand() % SCREENW , rand() % SCREENH ,rand() %5));
                    //blobs.push_back(new comida(rand() % SCREENW , rand() % SCREENH ,rand() %15));
                    if (blobs2[c]->radius < 1.2)
                    blobs2.erase(blobs2.begin() + c);

                    blobs2[c]->collides_with( blobs[d] );
                    blobs2[c]->collides_with( blobs2[d] );
                }


                if (blobs2[c]->radius < 1.2)
                        {blobs2.erase(blobs2.begin() + c);}

                if (blobs[c]->radius < 1.2)
                {
                    blobs.erase(blobs.begin() + c);

                    //blobs2.push_back(new comida(rand() % SCREENW , rand() % SCREENH ,rand() %15));
                    blobs.push_back(new comida(rand() % SCREENW , rand() % SCREENH ,rand() %5));

/*
                    base* newblob = new comida();
                    //newblob->radius = 2 * rand() % 6;
                    newblob->cal_area();
                    newblob->setx( rand() % SCREENW );
                    newblob->sety( rand() % SCREENH );
                    newblob->setdx( rand() % 2 );
                    newblob->setdy( rand() % 2 );


                    blobs.push_back(newblob);
&********************************


                }



            } ///end for

            /// draw screen
            int col;

            for (unsigned int c = 0; c < blobs.size() && c<200; c++)
            {
                col = makecol (170, 180, 170);
                ///col = player_colors[1];
                for (int p = 0; p < jugadores; p++)
                {
                    if (blobs[c]->getplayerid() == p + 1)
                        col = player_colors[p][0];
                }

                //circle(buffer, blobs2[c]->getx(), blobs2[c]->gety(), blobs2[c]->radius, makecol (120,100, 00));

                circle(buffer, blobs[c]->getx(), blobs[c]->gety(), 1.2*blobs[c]->radius, col);
                //while( !blobs2.empty() )
                  //  circle(buffer, blobs2[c]->getx(), blobs2[c]->gety(), blobs2[c]->radius, makecol (120,100, 00));

                for (int p = 0; p < jugadores; p++)
                {
                    if (blobs[c]->getplayerid() == p + 1)
                        col = player_colors[p][1];
                }
                circle(buffer, blobs2[c]->getx(), blobs2[c]->gety(), blobs2[c]->radius, makecol (120,100, 00));

                circlefill(buffer, blobs[c]->getx() + (blobs[c]->radius / 3), blobs[c]->gety() - (blobs[c]->radius / 3), (int)(3 * blobs[c]->radius / 17), col);

            }


            //for(int i=0; i<50 ; i++)
              //  circle(buffer, blobs2[i]->getx(), blobs2[i]->gety(), blobs2[i]->radius, makecol (120,100, 00));
                //circle(buffer, blobs2[1]->getx(), blobs2[1]->gety(), blobs2[1]->radius, makecol (120,100, 00));



            blit(buffer, screen, 0, 0, 0, 0, SCREENW, SCREENH);
            clear_to_color(buffer, makecol(0, 0, 0));
        }/// end while tick



   /// }/// end while esc

    if (numplayers == 1)
        return 1;

    textout_centre_ex(screen, font, "GAME OVER", SCREENW / 2, SCREENH / 2 - 20, makecol(255, 255, 255), -1);
    if (numplayers == 0)
        textout_centre_ex(screen, font, "No winner", SCREENW / 2, SCREENH / 2 + 20, makecol(255, 255, 255), -1);

    else if (blobs[0]->getplayerid())
        textprintf_centre_ex(screen, font, SCREENW / 2, SCREENH / 2, player_colors[blobs[0]->getplayerid() - 1][0], -1, "Playser %d wins", blobs[0]->getplayerid());

    textout_centre_ex(screen, font, "Press ENTER", SCREENW / 2, SCREENH / 2 + 20, makecol(255, 255, 255), -1);

    while(!key[KEY_ENTER] && !key[KEY_SPACE] && !key[KEY_ESC]&& !key[KEY_F1])
        rest(1);

    blobs.clear();
    blobs2.clear();

    destroy_bitmap(buffer);
    return 1;
}///end gameloop

*/

#endif // GLOBAL_H_INCLUDED
