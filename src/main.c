#include <stdio.h>
#include "./libs/tocar/play/play.h"

int main(int argc,char *argv[]) {
    Player meuPlayer;
    char caminho[512];
    int repetir_music = 0;

    inicializar(&meuPlayer);

    printf("Digite o caminho da musica (.mp3 ou .wav): ");
    scanf("%511s", caminho);

    printf("Vai querer repetir? (0 = nao, 1 = sim): ");
    scanf("%d", &repetir_music);

    if (!carregarMusica(&meuPlayer, caminho)) {
        printf("Nao foi possivel carregar a musica.\n");
        finalizar(&meuPlayer);
        return 1;
    }

    switch (repetir_music) {
        case 0:
            tocar(&meuPlayer);
            printf("Tocando! Pressione Enter para sair...");
            getchar(); // consome o \n do scanf
            getchar();
            break;

        case 1:
            loop(&meuPlayer,repetir_music);
            printf("Tocando em loop! Pressione Enter para sair...");
            getchar(); // consome o \n do scanf
            getchar();
            break;

        default:
            printf("Opcao invalida.\n");
            break;
    }

    finalizar(&meuPlayer);
    return 0;
}