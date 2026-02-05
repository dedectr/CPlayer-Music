#include <stdio.h>
#include "play.h"

void inicializar(Player *p) {
    p->musica = NULL;

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("Erro SDL: %s\n", SDL_GetError());
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("Erro Mix: %s\n", Mix_GetError());
    }
}

int carregarMusica(Player *p, const char *caminho) {
    if (p->musica) {
        Mix_FreeMusic(p->musica);
        p->musica = NULL;
    }

    p->musica = Mix_LoadMUS(caminho);
    if (!p->musica) {
        printf("Erro ao carregar: %s\n", Mix_GetError());
        return 0;
    }
    return 1;
}

void tocar(Player *p) {
    if (p->musica) {
        Mix_PlayMusic(p->musica, 0); // 0 = toca 1 vez
    }
}

void loop(Player *p, int quantos_loops) {
    if (!p->musica) return;

    if (quantos_loops < 0) {
        Mix_PlayMusic(p->musica, -1); // loop infinito
    } else {
        Mix_PlayMusic(p->musica, quantos_loops); // repete N+1 vezes
    }
}

void finalizar(Player *p) {
    if (p->musica) {
        Mix_FreeMusic(p->musica);
        p->musica = NULL;
    }
    Mix_CloseAudio();
    SDL_Quit();
}