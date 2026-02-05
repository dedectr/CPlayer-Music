#ifndef PLAY_H
#define PLAY_H

#include <SDL.h>
#include <SDL_mixer.h>

typedef struct {
    Mix_Music *musica;
} Player;

void inicializar(Player *p);
int  carregarMusica(Player *p, const char *caminho);
void tocar(Player *p);
void loop(Player *p, int quantos_loops);
void finalizar(Player *p);

#endif