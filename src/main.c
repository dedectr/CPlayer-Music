#include <stdio.h>
#include "player.h"

int main() {
    Player meuPlayer;
    char caminho[512];

    inicializar(&meuPlayer);

    printf("Digite o caminho da musica (.mp3 ou .wav): ");
    scanf("%s", caminho);

    if (carregarMusica(&meuPlayer, caminho)) {
        tocar(&meuPlayer);
        printf("Tocando! Pressione Enter para sair...");
        getchar();
        getchar();
    }

    finalizar(&meuPlayer);
    return 0;
}
