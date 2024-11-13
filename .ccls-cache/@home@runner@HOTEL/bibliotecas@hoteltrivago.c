#include "hoteltrivago.h"
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarQuarto(Quarto quarto[], int *numQuarto) {
  if (*numQuarto >= MAX_QUARTO) {
    printf("Limite de quartos atingido.\n");
    return;
  }

  Quarto novoQuarto;
  novoQuarto.numero = *numQuarto + 1;

  printf("Numero: ");
  scanf("%d", &novoQuarto.numero);

  printf("Valor da diaria: ");
  scanf("%f", &novoQuarto.valorDiaria);

  printf("Quantidade de Hospedes: ");
  scanf("%d", &novoQuarto.qtdHospede);

  novoQuarto.status = 0; // Inicialmente vago
  quarto[*numQuarto] = novoQuarto;

  FILE *file = fopen("quartos.dat", "ab");
  if (file) {
    fwrite(&novoQuarto, sizeof(Quarto), 1, file);
    fclose(file);
  } else {
    printf("Erro ao abrir o arquivo de quartos.\n");
  }

  (*numQuarto)++;
  printf("Quarto cadastrado com sucesso.\n");
}

void listarQuarto(Quarto quarto[], int numQuarto) {
  FILE *file = fopen("quartos.dat", "rb");
  if (!file) {
    printf("Nenhum quarto cadastrado.\n");
    return;
  }

  Quarto q;
  while (fread(&q, sizeof(Quarto), 1, file)) {
    printf("Número: %d\nQuantidade de Hospedes: %d\nValor Diária: "
           "%.2f\nStatus: %d\n",
           q.numero, q.qtdHospede, q.valorDiaria, q.status);
  }

  fclose(file);
}

// CADASTRAR FUNCIONARIO

void cadastrarFuncionario(Funcionario funcionario[], int *numFuncionario) {
  if (*numFuncionario >= MAX_FUNCIONARIO) {
    printf("Limite de funcionarios atingido.\n");
    return;
  }

  Funcionario novoFuncionario;
  novoFuncionario.codigo = *numFuncionario + 1;

  printf("Nome: ");
  scanf(" %[^\n]", novoFuncionario.nome);

  printf("Telefone: ");
  scanf(" %[^\n]", novoFuncionario.telefone);

  printf("Cargo: ");
  scanf(" %[^\n]", novoFuncionario.cargo);

  printf("Salario: ");
  scanf("%f", &novoFuncionario.salario);

  funcionario[*numFuncionario] = novoFuncionario;

  FILE *file = fopen("funcionarios.dat", "ab");
  if (file) {
    fwrite(&novoFuncionario, sizeof(Funcionario), 1, file);
    fclose(file);
  } else {
    printf("Erro ao abrir o arquivo de funcionarios.\n");
  }

  (*numFuncionario)++;
  printf("Funcionario cadastrado com sucesso.\n");
}

void listarFuncionario(Funcionario funcionario[], int numFuncionario) {
  FILE *file = fopen("funcionarios.dat", "rb");
  if (!file) {
    printf("Nenhum funcionario cadastrado.\n");
    return;
  }

  Funcionario f;
  while (fread(&f, sizeof(Funcionario), 1, file)) {
    printf("Codigo: %d\nNome: %s\nTelefone: %s\nSalario: %.2f\nCargo: %s\n",
           f.codigo, f.nome, f.telefone, f.salario, f.cargo);
  }

  fclose(file);
}

// CADASTRAR CLIENTE

void cadastrarCliente(Cliente clientes[], int *numClientes) {
  if (*numClientes >= MAX_CLIENTES) {
    printf("Limite de clientes atingido.\n");
    return;
  }

  Cliente novoCliente;
  novoCliente.codigo = *numClientes + 1;

  printf("Nome: ");
  scanf(" %[^\n]", novoCliente.nome);

  printf("Telefone: ");
  scanf(" %[^\n]", novoCliente.telefone);

  printf("Cidade: ");
  scanf(" %[^\n]", novoCliente.cidade);

  printf("Estado: ");
  scanf(" %[^\n]", novoCliente.estado);

  clientes[*numClientes] = novoCliente;

  FILE *file = fopen("clientes.dat", "ab");
  if (file) {
    fwrite(&novoCliente, sizeof(Cliente), 1, file);
    fclose(file);
  } else {
    printf("Erro ao abrir o arquivo de clientes.\n");
  }

  (*numClientes)++;
  printf("Cliente cadastrado com sucesso.\n");
}

void listarClientes(Cliente clientes[], int numClientes) {
  FILE *file = fopen("clientes.dat", "rb");
  if (!file) {
    printf("Nenhum cliente cadastrado.\n");
    return;
  }

  Cliente c;
  while (fread(&c, sizeof(Cliente), 1, file)) {
    printf("\nCodigo: %d\nNome: %s\nTelefone: %s\nCidade: %s\nEstado: %s\n",
           c.codigo, c.nome, c.telefone, c.cidade, c.estado);
  }

  fclose(file);
}

// CASDASTRAR ESTADIA

void cadastrarEstadia(Estadia estadia[], int *numEstadias) {
  if (*numEstadias >= MAX_QUARTO) {
    printf("Limite de estadias atingido.\n");
    return;
  }
  int calculodiaria = 0;
  int codigoCliente;

  Estadia novaEstadia;
  novaEstadia.codigoEstadia = *numEstadias + 1;

  printf("Codigo do Cliente: ");
  scanf("%d", &codigoCliente);
  novaEstadia.codigoCliente = codigoCliente;

  // Verificar se o código do cliente existe
  FILE *fileClientes = fopen("clientes.dat", "rb");
  if (!fileClientes) {
    printf("Erro ao abrir o arquivo de clientes.\n");
    return;
  }

  Cliente cliente;
  int clienteEncontrado = 0;
  while (fread(&cliente, sizeof(Cliente), 1, fileClientes)) {
    if (cliente.codigo == codigoCliente) {
      clienteEncontrado = 1;
      break;
    }
  }
  fclose(fileClientes);

  if (!clienteEncontrado) {
    printf("Código do Cliente não encontrado.\n");
    return;
  }

  printf("Código do Cliente encontrado.\n");

  printf("Dia da entrada: ");
  scanf("%d", &novaEstadia.dataEntrada.dia);

  printf("Hora da entrada: ");
  scanf("%d", &novaEstadia.dataEntrada.hora);

  printf("Dia da Saida: ");
  scanf("%d", &novaEstadia.dataSaida.dia);

  printf("Hora da Saida: ");
  scanf("%d", &novaEstadia.dataSaida.hora);

  printf("A quantidade de hóspedes: ");
  scanf("%d", &novaEstadia.qntHospedes);

  // Calcular diária
  if (novaEstadia.dataSaida.hora <= 12) {
    calculodiaria = novaEstadia.dataSaida.dia - novaEstadia.dataEntrada.dia;
    novaEstadia.qntDiarias = calculodiaria;
  } else {
    calculodiaria =
        (novaEstadia.dataSaida.dia - novaEstadia.dataEntrada.dia) + 1;
    novaEstadia.qntDiarias = calculodiaria;
  }

  // Verificação do quarto
  FILE *fileQuartos = fopen("quartos.dat", "rb+");
  if (!fileQuartos) {
    printf("Erro ao abrir o arquivo de quartos.\n");
    return;
  }
  Quarto quarto;
  int quartoEncontrado = 0;
  while (fread(&quarto, sizeof(Quarto), 1, fileQuartos)) {
    if (quarto.status == 0 && quarto.qtdHospede >= novaEstadia.qntHospedes) {
      quarto.status = 1; // (ocupado)
      fseek(fileQuartos, -sizeof(Quarto), SEEK_CUR);
      fwrite(&quarto, sizeof(Quarto), 1, fileQuartos);
      quartoEncontrado = 1;
      break;
    }
  }
  fclose(fileQuartos);

  if (!quartoEncontrado) {
    printf("Quarto adequado não encontrado.\n");
    printf("Procure outra data para sua estadia.\n");
    return;
  } else {
    printf("O seu quarto foi registrado com sucesso\nNumero do quarto: %d \n",
           quarto.numero);
  }

  novaEstadia.numQuarto = quarto.numero;

  estadia[*numEstadias] = novaEstadia;
  FILE *fileEstadias = fopen("estadias.dat", "ab");
  if (fileEstadias) {
    fwrite(&novaEstadia, sizeof(Estadia), 1, fileEstadias);
    fclose(fileEstadias);
  } else {
    printf("Erro ao abrir o arquivo de estadias.\n");
    return;
  }

  (*numEstadias)++;
  printf("\nEstadia cadastrada com sucesso.\n");
}

void listarEstadia(Estadia estadia[], int numEstadias) {
  FILE *file = fopen("estadias.dat", "rb");
  if (!file) {
    printf("Nenhuma estadia cadastrado.\n");
    return;
  }

  Estadia f;
  while (fread(&f, sizeof(Estadia), 1, file)) {
    printf("\n\nCodigo da Estadia: %d\nData de entrada: %d\nData de Saida: %d\nA "
           "quantidade de hóspedes: %d\nNumero do quarto: %d \nQuantidade de "
           "Diárias: %d\nCodigo do Cliente: %d\n\n",
           f.codigoEstadia, f.dataEntrada.dia, f.dataSaida.dia, f.qntHospedes,
           f.numQuarto, f.qntDiarias, f.codigoCliente);
  }

  fclose(file);
}

// BAIXA NA ESTADIA

void baixaEstadia() {
  int codigoBaixa;
  printf("Qual codigo da estadia que dará baixa? \n");
  scanf("%d", &codigoBaixa);

  FILE *arquivoEstadias = fopen("estadias.dat", "rb");
  if (!arquivoEstadias) {
    printf("Nenhuma estadia encontrada.\n");
    return;
  }

  float valorTotal = 0;
  Estadia e;
  int estadiaEncontrada = 0;

  // Procurar a estadia
  while (fread(&e, sizeof(Estadia), 1, arquivoEstadias) > 0) {
    if (e.codigoEstadia == codigoBaixa) {
      estadiaEncontrada = 1;
      break;
    }
  }

  if (!estadiaEncontrada) {
    printf("Estadia com o código %d não encontrada.\n", codigoBaixa);
    fclose(arquivoEstadias);
    return;
  }

  // Atualizar status do quarto
  FILE *arquivoQuartos = fopen("quartos.dat", "rb+");
  if (!arquivoQuartos) {
    printf("Erro ao abrir o arquivo de quartos.\n");
    fclose(arquivoEstadias);
    return;
  }

  Quarto quartoAtualizado;
  int quartoEncontrado = 0;

  while (fread(&quartoAtualizado, sizeof(Quarto), 1, arquivoQuartos) > 0) {
    if (quartoAtualizado.numero == e.numQuarto) {
      valorTotal = quartoAtualizado.valorDiaria * e.qntDiarias;
      quartoAtualizado.status = 0; // Quarto disponível
      fseek(arquivoQuartos, -sizeof(Quarto), SEEK_CUR);
      fwrite(&quartoAtualizado, sizeof(Quarto), 1, arquivoQuartos);
      quartoEncontrado = 1;
      break;
    }
  }

  fclose(arquivoQuartos);

  if (!quartoEncontrado) {
    printf("Erro ao atualizar o status do quarto.\n");
    fclose(arquivoEstadias);
    return;
  }

  fseek(arquivoEstadias, 0, SEEK_SET);
  FILE *arquivoEstadiasTemp = fopen("estadias.dat.tmp", "wb");
  if (!arquivoEstadiasTemp) {
    printf("Erro ao criar arquivo temporário.\n");
    fclose(arquivoEstadias);
    return;
  }

  Estadia estadiaTemp;
  while (fread(&estadiaTemp, sizeof(Estadia), 1, arquivoEstadias) > 0) {
    if (estadiaTemp.codigoEstadia != codigoBaixa) {
      fwrite(&estadiaTemp, sizeof(Estadia), 1, arquivoEstadiasTemp);
    }
  }

  fclose(arquivoEstadias);
  fclose(arquivoEstadiasTemp);

  remove("estadias.dat");
  rename("estadias.dat.tmp", "estadias.dat");

  printf("O preço a se pagar pela sua estadia no hotel trivago é de R$%.2f\n",
         valorTotal);
  printf("\nBaixa da estadia %d realizada com sucesso!\n", codigoBaixa);
}

// PROCURAR CLIENTE POR  ID
void procurarCliente() {
  int codigoCliente;
  printf("Digite o codigo do cliente que deseja procurar: \n");
  scanf("%d", &codigoCliente);

  // Verificar se o código do cliente existe
  FILE *file = fopen("clientes.dat", "rb");
  if (!file) {
    printf("Erro ao abrir o arquivo de clientes.\n");
    return;
  }

  Cliente cliente;
  int clienteEncontrado = 0;
  while (fread(&cliente, sizeof(Cliente), 1, file)) {
    if (cliente.codigo == codigoCliente) {
      clienteEncontrado = 1;
      break;
    }
  }
  fclose(file);

  if (!clienteEncontrado) {
    printf("O cliente não foi encontrado!");
  } else {
    printf("\nCodigo: %d\nNome: %s\nCidade: %s\nEstado: %s\nTelefone:%s\n",
           cliente.codigo, cliente.nome, cliente.cidade, cliente.estado,
           cliente.telefone);
  }
}

// PROCURAR FUNCIONARIO POR ID

void procuraFuncionario() {
  int codigoFuncionario;
  printf("Digite o codigo do funcionario que deseja procurar: \n");
  scanf("%d", &codigoFuncionario);

  FILE *funcionarioFile = fopen("funcionarios.dat", "rb");
  if (!funcionarioFile) {
    printf("Nenhuma funcionario encontrado.\n");
    return;
  }

  Funcionario funcionario;
  int funcionarioEncontrado;
  while (fread(&funcionario, sizeof(Funcionario), 1, funcionarioFile)) {
    if (funcionario.codigo == codigoFuncionario) {
      funcionarioEncontrado = 1;
      break;
    }
  }
  fclose(funcionarioFile);
  if (!funcionarioEncontrado) {
    printf("Funcionario não encontrado.\n");
  } else {
    printf("\nCodigo: %d\nNome: %s\nCargo: %s\nSalario: %.2f\nTelefone: %s",
           funcionario.codigo, funcionario.nome, funcionario.cargo,
           funcionario.salario, funcionario.telefone);
  }
}

// MOSTRAR ESTADIA DO CLIENTE

void mostrarEstadiasCliente() {
  Cliente cliente;
  Estadia estadia;
  int estadiaEncontrada = 0;
  int codigoCliente;
  printf("Digite o codigo do cliente que deseja visualizar a estadia: \n");
  scanf("%d", &codigoCliente);

  // Verificar se o código do cliente existe
  FILE *fileClientes = fopen("clientes.dat", "rb");
  if (!fileClientes) {
    printf("Erro ao abrir o arquivo de clientes.\n");
    return;
  }

  int clienteEncontrado = 0;
  while (fread(&cliente, sizeof(Cliente), 1, fileClientes)) {
    if (cliente.codigo == codigoCliente) {
      clienteEncontrado = 1;
      break;
    }
  }
  fclose(fileClientes);

  if (!clienteEncontrado) {
    printf("Cliente com o código %d não encontrado.\n", codigoCliente);
    return;
  }

  // Abrir arquivo de estadias e procurar todas as estadias do cliente
  FILE *fileEstadias = fopen("estadias.dat", "rb");
  if (!fileEstadias) {
    printf("Erro ao abrir o arquivo de estadias.\n");
    return;
  }

  printf("-------ESTADIAS DO CLIENTE--------\n\n");
  while (fread(&estadia, sizeof(Estadia), 1, fileEstadias)) {
    if (estadia.codigoCliente == codigoCliente) {
      estadiaEncontrada = 1;
      printf("Codigo da Estadia: %d\nData de entrada: %d\nData de Saida: %d\nA "
             "quantidade de hóspedes: %d\nNumero do quarto: %d \nQuantidade de "
             "Diárias: %d\nCodigo do Cliente: %d\n\n",
             estadia.codigoEstadia, estadia.dataEntrada.dia,
             estadia.dataSaida.dia, estadia.qntHospedes, estadia.numQuarto,
             estadia.qntDiarias, estadia.codigoCliente);
    }
  }
  fclose(fileEstadias);

  if (!estadiaEncontrada) {
    printf("Nenhuma estadia encontrada para o cliente com código %d.\n",
           codigoCliente);
  }
}
// CALCULAR PONTOS DE FIDELIDADE

void programaFidelidade() {
  Cliente cliente;
  Estadia estadia;
  int codigoCliente;
  printf("Digite o codigo do cliente que deseja procurar: \n");
  scanf("%d", &codigoCliente);

  int somaFidelidade = 0;

  // Verificar se o código do cliente existe
  FILE *fileClientes = fopen("clientes.dat", "rb");
  if (!fileClientes) {
    printf("Erro ao abrir o arquivo de clientes.\n");
    return;
  }

  int clienteEncontrado = 0;
  while (fread(&cliente, sizeof(Cliente), 1, fileClientes)) {
    if (cliente.codigo == codigoCliente) {
      clienteEncontrado = 1;
      break;
    }
  }
  fclose(fileClientes);

  if (!clienteEncontrado) {
    printf("Cliente com o código %d não encontrado.\n", codigoCliente);
    return;
  }

  // Calcular pontos de fidelidade
  FILE *fileEstadias = fopen("estadias.dat", "rb");
  if (!fileEstadias) {
    printf("Erro ao abrir o arquivo de estadias.\n");
    return;
  }

  while (fread(&estadia, sizeof(Estadia), 1, fileEstadias)) {
    if (estadia.codigoCliente == codigoCliente) {
      somaFidelidade += (estadia.qntDiarias * 10);
    }
  }
  fclose(fileEstadias);

  printf("O cliente %d tem %d pontos de fidelidade.\n", codigoCliente,
         somaFidelidade);
}
