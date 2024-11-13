#include "bibliotecas/hoteltrivago.h"
#include <assert.h>
#include <stdio.h>

void test_cadastrarQuarto() {
    Quarto quartos[MAX_QUARTO];
    int numQuartos = 0;
    cadastrarQuarto(quartos, &numQuartos);
    assert(numQuartos == 1); // Verifique se o número de quartos aumentou
    printf("test_cadastrarQuarto passed\n");
}

void test_listarQuarto() {
    Quarto quartos[MAX_QUARTO];
    int numQuartos = 1;
    quartos[0].numero = 101;
    listarQuarto(quartos, numQuartos);
    // Suponha que listarQuarto imprima os detalhes dos quartos
    printf("test_listarQuarto passed\n");
}

int main() {
    test_cadastrarQuarto();
    test_listarQuarto();
    // Chame outras funções de teste conforme necessário

    printf("All tests passed\n");
    return 0;
}
