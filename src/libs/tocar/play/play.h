#ifdef PLAY_H
#define PLAY_H

#include <SDL.h>
#include <SDL_mixer.h>

typedef struct {
	Mix_Music *musica;
} Player;


void incializar(Player *p)/
void finalizar(Player *p);
int carregarMusica(Player *p, const char *caminho);
void tocar(Player *p);

#endif