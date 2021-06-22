#include "inicia.h"


template <class A>
inicia<A>::inicia()
{
   allegro_init();
   install_keyboard();

   set_color_depth(32);
   set_gfx_mode(GFX_AUTODETECT,1360,768, 0, 0);
}

template <class A>
inicia<A> *inicia<A>::_instancia = NULL;

template <class A>
int inicia<A>::audio(int izquierda, int derecha, A *dato)
{
     /// incializa el audio en allegro
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }

	set_volume(izquierda, derecha);/// ajustamos el volumen


    if ( sizeof(*dato) == sizeof(MIDI)){
        MIDI *musica1  = load_midi("sonido.mid");
        play_midi(musica1,1);
        cout << sizeof(MIDI)<< endl;
    }
    else if(sizeof(*dato) == sizeof(SAMPLE)){
        SAMPLE *sonido1 = load_wav("song.wav");
        play_sample(sonido1,200,150,1000,0);
        cout << sizeof(SAMPLE);
    }




    return 0;
}

template <class A>
inicia<A>::~inicia()
{

//    destroy_sample(sonido1);
}
