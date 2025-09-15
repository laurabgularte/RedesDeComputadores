#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char buffer[100]; // Buffer para armazenar os dados lidos
    size_t bytesLidos;

    // Abre o arquivo bin�rio para leitura
    arquivo = fopen("Coloque aqui o nome do arquivo.bin", "rb");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // L� os dados do arquivo em blocos
    while ((bytesLidos = fread(buffer, 1, sizeof(buffer), arquivo)) > 0) {
        // Processa os dados lidos (ex: imprime na tela)
        for (size_t i = 0; i < bytesLidos; i++) {
            printf("%02X ", buffer[i]); // Imprime os bytes em formato hexadecimal
        }
    }

    // Verifica se ocorreu algum erro durante a leitura
    if (ferror(arquivo)) {
        perror("Erro ao ler o arquivo");
        fclose(arquivo);
        return 1;
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
