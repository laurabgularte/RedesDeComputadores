#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo, *destino;
    char buffer[100]; // Buffer para armazenar os dados lidos
    size_t bytesLidos, elementos_escritos;;

    // Abre o arquivo binario para leitura
    arquivo = fopen("flutter.pdf", "rb");
    destino = fopen("flutter_dest.pdf", "wb");

    // Verifica se o arquivo de ORIGEM foi aberto com sucesso
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Verifica se o arquivo de DESTINO foi aberto com sucesso
    if (destino == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }


    // Le os dados do arquivo em blocos
    while ((bytesLidos = fread(buffer, 1, sizeof(buffer), arquivo)) > 0) {
        // Processa os dados lidos (Salva no arquivo destino)
            fwrite(buffer, sizeof(buffer),1, destino);
    }

    // Verifica se ocorreu algum erro durante a leitura
    if (ferror(arquivo)) {
        perror("Erro ao ler o arquivo");
        fclose(arquivo);
        return 1;
    }

    // Fecha o arquivo
    fclose(arquivo);
    fclose(destino);
    return 0;
}
