#include <stdio.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <wchar.h>
typedef struct {
	Mix_Music *musica;
} Player;

void inicializar(Player *p) {
    SDL_Init(SDL_INIT_AUDIO);
    // Abre o dispositivo de áudio (44.1kHz, 2 canais)
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("Erro ao abrir áudio: %s\n", Mix_GetError());
    }
}

int main(int argc,char* argv[]){
	Player meuPlayer;
	meuPlayer.musica = NULL;
	char caminho[512];

	inicializar(&meuPlayer);
	printf("Digite o caminho da musica (.mp3 ou .wav): ");
    scanf("%s", caminho);
    meuPlayer.musica = Mix_LoadMUS(caminho);
    if (meuPlayer.musica == NULL) {
        printf("Erro ao carregar: %s\n", Mix_GetError());
    } else {
        Mix_PlayMusic(meuPlayer.musica, 1); 
        printf("Tocando! Pressione Enter para sair...");
        
        getchar(); // Limpa o buffer do scanf
        getchar(); // Espera o usuário apertar Enter
    }

    if (meuPlayer.musica) Mix_FreeMusic(meuPlayer.musica);
    Mix_CloseAudio();
    SDL_Quit();

	return 0;
}