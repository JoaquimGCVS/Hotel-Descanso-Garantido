#include "../include/hoteltrivago.h"
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  Quarto quarto[MAX_QUARTO];
  Cliente clientes[MAX_CLIENTES];
  Funcionario funcionario[MAX_FUNCIONARIO];
  Estadia estadia[MAX_QUARTO];
  int numClientes = 0;
  int numFuncionario = 0;
  int numQuarto = 0;
  int numEstadias = 0;
  int opcao;
  printf("---------BEM VINDO AO HOTELTRIVAGO---------");
  do {
    printf("\nSoftware de gestão do Hotel Descanso Garantido:\n");
    printf("\n1. Cadastrar Cliente\n");
    // printf("2. Listar Clientes\n");
    printf("2. Cadastrar Funcionario\n");
    // printf("4. Listar Funcionarios\n");
    printf("3. Cadastrar Quarto\n");
    // printf("6. Listar Quartos\n");
    printf("4. Cadastar estadia\n");
    // printf("8. Listar estadia\n");
    printf("5. Baixa em estadia\n");
    printf("6. Procurar Cliente por ID\n");
    printf("7. Procurar Funcionario por ID\n");
    printf("8. Pontos de Fidelidade\n");
    printf("9. Mostrar estadias do cliente\n");
    printf("10. Sair\n");
    printf("\nEscolha uma opcao:[1-10] ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      cadastrarCliente(clientes, &numClientes);
      break;
    case 2:
      cadastrarFuncionario(funcionario, &numFuncionario);
      break;
    case 3:
      cadastrarQuarto(quarto, &numQuarto);
      break;
    case 4:
      cadastrarEstadia(estadia, &numEstadias);
      break;
    case 5:
      baixaEstadia();
      break;
    case 6:
      procurarCliente();
      break;
    case 7:
      procuraFuncionario();
      break;
    case 8:
      programaFidelidade();
      break;
    case 9:
      mostrarEstadiasCliente();
      break;
    case 10:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 10);

  return 0;
}
