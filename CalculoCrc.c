#include <stdio.h>
#include <stdint.h> // Para uint32_t

// Define o polinômio gerador (CRC-32/IEEE 802.3)
#define POLYNOMIAL 0xEDB88320

// Tabela CRC pré-calculada (será gerada uma vez)
uint32_t crc_table[256];

// Função para gerar a tabela CRC
void generate_crc_table() {
    uint32_t i, j, crc;
    for (i = 0; i < 256; ++i) {
        crc = i;
        for (j = 0; j < 8; ++j) {
            crc = (crc & 1) ? (crc >> 1) ^ POLYNOMIAL : (crc >> 1);
        }
        crc_table[i] = crc;
    }
}

// Função principal para calcular o CRC32
uint32_t calculate_crc32(const unsigned char *data, size_t length) {
    uint32_t crc = 0xFFFFFFFF; // Valor inicial (inverso de todos os bits)
    size_t i;

    for (i = 0; i < length; ++i) {
        // Combina o byte de entrada com o byte menos significativo do CRC atual
        // e usa a tabela para obter o próximo valor do CRC
        crc = (crc >> 8) ^ crc_table[(crc ^ data[i]) & 0xFF];
    }

    // Finaliza o cálculo (inverte os bits e XOR com 0xFFFFFFFF)
    return crc ^ 0xFFFFFFFF;
}

int main() {
    // Gere a tabela antes de calcular o CRC
    generate_crc_table();

    // Exemplo de uso com um array de bytes
    unsigned char dados[] = "Aula de Redes I";
    size_t tamanho = sizeof(dados) - 1; // Exclui o caractere nulo '\0'

    uint32_t checksum = calculate_crc32(dados, tamanho);

    printf("CRC32: 0x%08X\n", checksum);

    return 0;
}
