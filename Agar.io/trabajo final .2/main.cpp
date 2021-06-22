#include "inicia.h"
#include "global.h"


int main ()
{

    ///inicia<MIDI> *p;
    inicia<SAMPLE> *p;
    p->instancia();   /// llamada a contructor private

    //MIDI *musica1  = load_midi("sonido.mid");
    SAMPLE *musica1 = load_wav("song.wav");
    p->audio(200,200, musica1);

    mainmenu();
    gameloop();

    return 0;
}
END_OF_MAIN ();
