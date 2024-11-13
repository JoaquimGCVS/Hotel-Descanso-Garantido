#ifndef HOTELTRIVAGO_H
#define HOTELTRIVAGO_H

#include <stdio.h>

// Definições de constantes
#define MAX_QUARTO 5
#define MAX_CLIENTES 10
#define MAX_FUNCIONARIO 20

// Estrutura Cliente
typedef struct {
  int codigo;
  char nome[100];
  char cidade[50];
  char estado[3];
  char telefone[20];
  int fidelidade;
} Cliente;

// Estrutura Funcionario
typedef struct {
  int codigo;
  char nome[100];
  char cargo[50];
  float salario;
  char telefone[20];
} Funcionario;

// Estrutura Quarto
typedef struct {
  int numero;
  int qtdHospede;
  float valorDiaria;
  int status; // 0 = vago / 1 = ocupado
} Quarto;

// Estrutura Estadia
typedef struct {
  int dia;
  int hora;
} Entrada;

typedef struct {
  int dia;
  int hora;
} Saida;

typedef struct {
  int codigoEstadia;
  Entrada dataEntrada;
  Saida dataSaida;
  int qntHospedes;
  int qntDiarias;
  int numQuarto;
  int codigoCliente;
} Estadia;

// Funções
void cadastrarQuarto(Quarto quarto[], int *numQuarto);
void listarQuarto(Quarto quarto[], int numQuarto);
void cadastrarFuncionario(Funcionario funcionario[], int *numFuncionario);
void listarFuncionario(Funcionario funcionario[], int numFuncionario);
void cadastrarCliente(Cliente clientes[], int *numClientes);
void listarClientes(Cliente clientes[], int numClientes);
void cadastrarEstadia(Estadia estadia[], int *numEstadias);
void listarEstadia(Estadia estadia[], int numEstadias);
void baixaEstadia();
void procurarCliente();
void procuraFuncionario();
void mostrarEstadiasCliente();
void programaFidelidade();

#endif // HOTELTRIVAGO_H
