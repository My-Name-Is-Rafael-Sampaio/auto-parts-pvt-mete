#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FULL_NAME_SIZE 30
#define MAX_DATE_FORMAT_SIZE 13
#define MAX_EMAIL_ADDRESS_SIZE 50
#define MAX_PHONE_NUMBER_SIZE 14
#define MAX_HOME_ADDRESS_SIZE 30
#define MAX_OFFICE_SIZE 20
#define MAX_PART_CATEGORY_SIZE 20
#define MAX_BUSINESS_ADDRESS_SIZE 30
#define MAX_CAR_MODEL_SIZE 30

#define MAX_RELATIVE_PATH_SIZE 100
#define MAX_FILE_LINE_SIZE 100

typedef struct Collaborator
{
  int id;
  int cpf;
  char full_name[MAX_FULL_NAME_SIZE];
  char date_birth[MAX_DATE_FORMAT_SIZE];
  char email_address[MAX_EMAIL_ADDRESS_SIZE];
  char phone_number[MAX_PHONE_NUMBER_SIZE];
  char home_address[MAX_HOME_ADDRESS_SIZE];
  char office[MAX_OFFICE_SIZE];
  double salary;
  int total_sales_made;
  struct Collaborator *next;
} Collaborator;

typedef struct Supplier
{
  int id;
  int cnpj;
  char full_name[MAX_FULL_NAME_SIZE];
  char part_category[MAX_PART_CATEGORY_SIZE];
  char email_address[MAX_EMAIL_ADDRESS_SIZE];
  char phone_number[MAX_PHONE_NUMBER_SIZE];
  char business_address[MAX_BUSINESS_ADDRESS_SIZE];
  char contract_date[MAX_DATE_FORMAT_SIZE];
  double contract_price;
  struct Supplier *next;
} Supplier;

typedef struct Part
{
  int id;
  int supplier_id;
  char full_name[MAX_FULL_NAME_SIZE];
  char car_model[MAX_CAR_MODEL_SIZE];
  int amount;
  double price;
  struct Part *next;
} Part;

typedef struct Consumer
{
  int id;
  int cpf;
  char full_name[MAX_FULL_NAME_SIZE];
  char date_birth[MAX_DATE_FORMAT_SIZE];
  char email_address[MAX_EMAIL_ADDRESS_SIZE];
  char phone_number[MAX_PHONE_NUMBER_SIZE];
  char home_address[MAX_HOME_ADDRESS_SIZE];
  struct Consumer *next;
} Consumer;

Collaborator *create_collaborator_node()
{
  Collaborator *node = (Collaborator *)malloc(sizeof(Collaborator));
  if (node == NULL)
  {
    printf("Erro ao alocar memória para colaborador!\n");
    exit(1);
  }
  node->next = NULL;
  return node;
}

Supplier *create_supplier_node()
{
  Supplier *node = (Supplier *)malloc(sizeof(Supplier));
  if (node == NULL)
  {
    printf("Erro ao alocar memória para fornecedor!\n");
    exit(1);
  }
  node->next = NULL;
  return node;
}

Part *create_part_node()
{
  Part *node = (Part *)malloc(sizeof(Part));
  if (node == NULL)
  {
    printf("Erro ao alocar memória para peça!\n");
    exit(1);
  }
  node->next = NULL;
  return node;
}

Consumer *create_consumer_node()
{
  Consumer *node = (Consumer *)malloc(sizeof(Consumer));
  if (node == NULL)
  {
    printf("Erro ao alocar memória para cliente!\n");
    exit(1);
  }
  node->next = NULL;
  return node;
}

void insert_collaborator_in_list(Collaborator **head, Collaborator *new_collaborator)
{
  if (*head == NULL)
  {
    *head = new_collaborator;
  }
  else
  {
    Collaborator *current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = new_collaborator;
  }
}

void insert_supplier_in_list(Supplier **head, Supplier *new_supplier)
{
  if (*head == NULL)
  {
    *head = new_supplier;
  }
  else
  {
    Supplier *current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = new_supplier;
  }
}

void insert_part_in_list(Part **head, Part *new_part)
{
  if (*head == NULL)
  {
    *head = new_part;
  }
  else
  {
    Part *current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = new_part;
  }
}

void insert_consumer_in_list(Consumer **head, Consumer *new_consumer)
{
  if (*head == NULL)
  {
    *head = new_consumer;
  }
  else
  {
    Consumer *current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = new_consumer;
  }
}

void print_collaborator_details(const Collaborator *collaborator, int index)
{
  printf("\n%d° Colaborador:\n", (index + 1));
  printf("ID -> %d\nCPF -> %d\nNome Completo -> %s\nData de Nascimento -> %s\nE-mail -> %s\nTelefone de Contato -> %s\nEndereço Residencial -> %s\nCargo -> %s\nSalário -> %.2f\nTotal de Vendas -> %d\n", collaborator->id, collaborator->cpf, collaborator->full_name, collaborator->date_birth, collaborator->email_address, collaborator->phone_number, collaborator->home_address, collaborator->office, collaborator->salary, collaborator->total_sales_made);
}

void print_supplier_details(const Supplier *supplier, int index)
{
  printf("\n%d° Fornecedor:\n", (index + 1));
  printf("ID -> %d\nCNPJ -> %d\nNome Completo -> %s\nCategoria da Peça -> %s\nE-mail -> %s\nTelefone de Contato -> %s\nEndereço Comercial -> %s\nData de Contrato -> %s\nPreço do Contrato -> %.2f\n", supplier->id, supplier->cnpj, supplier->full_name, supplier->part_category, supplier->email_address, supplier->phone_number, supplier->business_address, supplier->contract_date, supplier->contract_price);
}

void print_part_details(const Part *part, int index)
{
  printf("\n%d° Peça:\n", (index + 1));
  printf("ID -> %d\nID do Fornecedor -> %d\nNome Completo -> %s\nModelo do Carro -> %s\nQuantidade -> %d\nPreço -> %.2f\n", part->id, part->supplier_id, part->full_name, part->car_model, part->amount, part->price);
}

void print_consumer_details(const Consumer *consumer, int index)
{
  printf("\n%d° Cliente:\n", (index + 1));
  printf("ID -> %d\nCPF -> %d\nNome Completo -> %s\nData de Nascimento -> %s\nE-mail -> %s\nTelefone de Contato -> %s\nEndereço Residencial -> %s\n", consumer->id, consumer->cpf, consumer->full_name, consumer->date_birth, consumer->email_address, consumer->phone_number, consumer->home_address);
}

void list_all_collaborators(const Collaborator *head)
{
  if (head == NULL)
  {
    printf("\nO arquivo está vazio e/ou nenhum colaborador foi cadastrado.\n");
    return;
  }

  int index = 0;
  const Collaborator *current = head;
  printf("\n----- DADOS DOS COLABORADORES -----\n");
  while (current != NULL)
  {
    print_collaborator_details(current, index);
    current = current->next;
    index++;
  }
}

void list_all_suppliers(const Supplier *head)
{
  if (head == NULL)
  {
    printf("\nO arquivo está vazio e/ou nenhum fornecedor foi cadastrado.\n");
    return;
  }
  int index = 0;
  const Supplier *current = head;
  printf("\n----- DADOS DOS FORNECEDORES -----\n");
  while (current != NULL)
  {
    print_supplier_details(current, index);
    current = current->next;
    index++;
  }
}

void list_all_parts(const Part *head)
{
  if (head == NULL)
  {
    printf("\nO arquivo está vazio e/ou nenhum peça foi cadastrado.\n");
    return;
  }
  int index = 0;
  const Part *current = head;
  printf("\n----- DADOS DOS PEÇAS -----\n");
  while (current != NULL)
  {
    print_part_details(current, index);
    current = current->next;
    index++;
  }
}

void list_all_consumers(const Consumer *head)
{
  if (head == NULL)
  {
    printf("\nO arquivo está vazio e/ou nenhum cliente foi cadastrado.\n");
    return;
  }
  int index = 0;
  const Consumer *current = head;
  printf("\n----- DADOS DOS CLIENTES -----\n");
  while (current != NULL)
  {
    print_consumer_details(current, index);
    current = current->next;
    index++;
  }
}

Collaborator *find_collaborator_by_id(Collaborator *head, int id)
{
  Collaborator *current = head;
  while (current != NULL)
  {
    if (current->id == id)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

Supplier *find_supplier_by_id(Supplier *head, int id)
{
  Supplier *current = head;
  while (current != NULL)
  {
    if (current->id == id)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

Part *find_part_by_id(Part *head, int id)
{
  Part *current = head;
  while (current != NULL)
  {
    if (current->id == id)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

Consumer *find_consumer_by_id(Consumer *head, int id)
{
  Consumer *current = head;
  while (current != NULL)
  {
    if (current->id == id)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void save_collaborator_data(FILE *file, const Collaborator *collaborator)
{
  fprintf(file, "%d,%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",%.2f,%d\n", collaborator->id, collaborator->cpf, collaborator->full_name, collaborator->date_birth, collaborator->email_address, collaborator->phone_number, collaborator->home_address, collaborator->office, collaborator->salary, collaborator->total_sales_made);
}

void save_supplier_data(FILE *file, const Supplier *supplier)
{
  fprintf(file, "%d,%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",%.2f\n", supplier->id, supplier->cnpj, supplier->full_name, supplier->part_category, supplier->email_address, supplier->phone_number, supplier->business_address, supplier->contract_date, supplier->contract_price);
}

void save_part_data(FILE *file, const Part *part)
{
  fprintf(file, "%d,%d,\"%s\",\"%s\",%d,%.2f\n", part->id, part->supplier_id, part->full_name, part->car_model, part->amount, part->price);
}

void save_consumer_data(FILE *file, const Consumer *consumer)
{
  fprintf(file, "%d,%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n", consumer->id, consumer->cpf, consumer->full_name, consumer->date_birth, consumer->email_address, consumer->phone_number, consumer->home_address);
}

void save_collaborator_data_to_file(const char *file_path, const Collaborator *head)
{
  FILE *output_file = fopen(file_path, "w");
  if (output_file != NULL)
  {
    Collaborator *current = head;
    while (current != NULL)
    {
      save_collaborator_data(output_file, current);
      current = current->next;
    }
    fclose(output_file);
    printf("\nDados dos colaboradores salvos com sucesso no arquivo!\n");
  }
  else
  {
    printf("Erro ao abrir o arquivo para salvar os dados dos colaboradores.\n\n");
  }
}

void save_supplier_data_to_file(const char *file_path, const Supplier *head)
{
  FILE *output_file = fopen(file_path, "w");
  if (output_file != NULL)
  {
    Supplier *current = head;
    while (current != NULL)
    {
      save_supplier_data(output_file, current);
      current = current->next;
    }
    fclose(output_file);
    printf("\nDados dos fornecedores salvos com sucesso no arquivo!\n");
  }
  else
  {
    printf("Erro ao abrir o arquivo para salvar os dados dos fornecedores.\n\n");
  }
}

void save_part_data_to_file(const char *file_path, const Part *head)
{
  FILE *output_file = fopen(file_path, "w");
  if (output_file != NULL)
  {
    Part *current = head;
    while (current != NULL)
    {
      save_part_data(output_file, current);
      current = current->next;
    }
    fclose(output_file);
    printf("\nDados dos peças salvos com sucesso no arquivo!\n");
  }
  else
  {
    printf("Erro ao abrir o arquivo para salvar os dados dos peças.\n\n");
  }
}

void save_consumer_data_to_file(const char *file_path, const Consumer *head)
{
  FILE *output_file = fopen(file_path, "w");
  if (output_file != NULL)
  {
    Consumer *current = head;
    while (current != NULL)
    {
      save_consumer_data(output_file, current);
      current = current->next;
    }
    fclose(output_file);
    printf("\nDados dos clientes salvos com sucesso no arquivo!\n");
  }
  else
  {
    printf("Erro ao abrir o arquivo para salvar os dados dos clientes.\n\n");
  }
}

void read_string_input(const char *prompt, char *buffer, int max_length)
{
  printf("%s", prompt);
  fgets(buffer, max_length, stdin);
  size_t length = strlen(buffer);
  if (length > 0 && buffer[length - 1] == '\n')
  {
    buffer[length - 1] = '\0';
  }
  else
  {
    buffer[0] = '\0';
    while (getchar() != '\n')
    {
    }
  }
}

int read_integer_input(const char *prompt, int min_value, int max_value)
{
  int value;
  while (true)
  {
    printf("%s", prompt);
    scanf("%d", &value);
    while (getchar() != '\n')
    {
    }
    if (value >= min_value && value <= max_value)
    {
      break;
    }
    printf("\nValor inválido. Insira um número entre %d e %d.\n", min_value,
           max_value);
  }
  return value;
}

long long read_integer_input_cpf(const char *prompt, long long min_value, long long max_value)
{
  char input[12];
  long long value;

  while (true)
  {
    printf("%s", prompt);
    scanf("%11s", input);

    if (strlen(input) != 11)
    {
      printf("\nValor inválido. O CPF deve ter exatamente 11 dígitos.\n");

      int c;
      while ((c = getchar()) != '\n' && c != EOF)
      {
      }

      continue;
    }

    bool valid = true;
    for (int i = 0; i < 11; i++)
    {
      if (input[i] < '0' || input[i] > '9')
      {
        valid = false;
        break;
      }
    }

    if (valid)
    {
      value = atoll(input);
      if (value >= min_value && value <= max_value)
      {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
        break;
      }
    }

    printf("\nValor inválido. Insira um número entre %lld e %lld.\n", min_value, max_value);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
  }

  return value;
}

int read_integer_input_cnpj(const char *prompt, int min_value, int max_value)
{
  char input[12];
  int value;

  while (true)
  {
    printf("%s", prompt);
    scanf("%14s", input);

    bool valid = true;
    for (int i = 0; i < 11; i++)
    {
      if (input[i] < '0' || input[i] > '9')
      {
        valid = false;
        break;
      }
    }

    if (valid)
    {
      value = atoi(input);
      if (value >= min_value && value <= max_value)
      {
        break;
      }
    }

    printf("\nValor inválido. Insira um número entre %d e %d.\n", min_value, max_value);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
  }

  return value;
}

double read_double_input(const char *prompt, double min_value, double max_value)
{
  double value;
  while (true)
  {
    printf("%s", prompt);
    scanf("%lf", &value);
    while (getchar() != '\n')
    {
    }
    if (value >= min_value && value <= max_value)
    {
      break;
    }
    printf("\nValor inválido. Insira um número entre %.2f e %.2f.\n\n",
           min_value, max_value);
  }
  return value;
}

void modify_collaborator_data(Collaborator *collaborator)
{
  printf("\nOpções de modificação:\n");
  printf("1 - CPF\n");
  printf("2 - Nome Completo\n");
  printf("3 - Data de Nascimento\n");
  printf("4 - E-mail\n");
  printf("5 - Telefone de Contato\n");
  printf("6 - Endereço Residencial\n");
  printf("7 - Cargo\n");
  printf("8 - Salário\n");
  printf("9 - Total de Vendas\n");
  printf("0 - Cancelar\n");

  int choice = read_integer_input("\nEscolha uma opção de modificação: ", 0, 9);

  switch (choice)
  {
  case 0:
    printf("\nModificação cancelada.\n");
    break;
  case 1:
    collaborator->cpf = read_integer_input_cpf("\nCPF do colaborador: ", 0, 99999999999);
    printf("CPF modificado com sucesso!\n");
  case 2:
    read_string_input("\nNome completo do colaborador: ", collaborator->full_name,
                      MAX_FULL_NAME_SIZE);
    printf("Nome modificado com sucesso!\n");
    break;
  case 3:
    read_string_input("\nData de nascimento do colaborador: ", collaborator->date_birth,
                      MAX_DATE_FORMAT_SIZE);
    printf("Data de nascimento modificada com sucesso!\n");
    break;
  case 4:
    read_string_input("\nE-mail do colaborador: ", collaborator->email_address,
                      MAX_EMAIL_ADDRESS_SIZE);
    printf("E-mail modificado com sucesso!\n");
    break;
  case 5:
    read_string_input("\nTelefone de contato do colaborador: ", collaborator->phone_number,
                      MAX_PHONE_NUMBER_SIZE);
    printf("Telefone de contato modificado com sucesso!\n");
    break;
  case 6:
    read_string_input("\nEndereço residencial do colaborador: ", collaborator->home_address,
                      MAX_HOME_ADDRESS_SIZE);
    printf("Endereço residencial modificado com sucesso!\n");
    break;
  case 7:
    read_string_input("\nCargo do colaborador: ", collaborator->home_address,
                      MAX_OFFICE_SIZE);
    printf("Cargo modificado com sucesso!\n");
    break;
  case 8:
    collaborator->salary = read_double_input("\nSalário do colaborador: ", 0.0, 99999.99);
    printf("Salário modificado com sucesso!\n");
    break;
  case 9:
    collaborator->total_sales_made = read_integer_input("Total de vendas do colaborador: ", 0, 99999);
    printf("Total de vendas modificada com sucesso!\n");
    break;
  default:
    printf("Opção inválida. Nenhuma modificação realizada.\n");
    break;
  }
}

void modify_supplier_data(Supplier *supplier)
{
  printf("\nOpções de modificação:\n");
  printf("1 - CNPJ\n");
  printf("2 - Nome Completo\n");
  printf("3 - Categoria da Peça\n");
  printf("4 - E-mail\n");
  printf("5 - Telefone de Contato\n");
  printf("6 - Endereço Comercial\n");
  printf("7 - Data do Contrato\n");
  printf("8 - Preço do Contrato\n");
  printf("0 - Cancelar\n");

  int choice = read_integer_input("\nEscolha uma opção de modificação: ", 0, 8);

  switch (choice)
  {
  case 0:
    printf("\nModificação cancelada.\n");
    break;
  case 1:
    supplier->cnpj = read_integer_input_cnpj("\nCNPJ do fornecedor: ", 0, 99999999999999);
    printf("CNPJ modificado com sucesso!\n");
  case 2:
    read_string_input("\nNome completo do fornecedor: ", supplier->full_name,
                      MAX_FULL_NAME_SIZE);
    printf("Nome modificado com sucesso!\n");
    break;
  case 3:
    read_string_input("\nCategoria da peça: ", supplier->part_category,
                      MAX_PART_CATEGORY_SIZE);
    printf("Categoria da peça modificada com sucesso!\n");
    break;
  case 4:
    read_string_input("\nE-mail do fornecedor: ", supplier->email_address,
                      MAX_EMAIL_ADDRESS_SIZE);
    printf("E-mail modificado com sucesso!\n");
    break;
  case 5:
    read_string_input("\nTelefone de contato do fornecedor: ", supplier->phone_number,
                      MAX_PHONE_NUMBER_SIZE);
    printf("Telefone de contato modificado com sucesso!\n");
    break;
  case 6:
    read_string_input("\nEndereço comercial do fornecedor: ", supplier->business_address,
                      MAX_BUSINESS_ADDRESS_SIZE);
    printf("Endereço comercial modificado com sucesso!\n");
    break;
  case 7:
    read_string_input("\nData do contrato do fornecedor: ", supplier->contract_date,
                      MAX_DATE_FORMAT_SIZE);
    printf("Data do contrato modificada com sucesso!\n");
    break;
  case 8:
    supplier->contract_price = read_double_input("\nPreço do contrato do fornecedor: ", 0.0, 99999.99);
    printf("Preço do contrato modificado com sucesso!\n");
    break;
  default:
    printf("Opção inválida. Nenhuma modificação realizada.\n");
    break;
  }
}

void modify_part_data(Part *part, Supplier *supplier_head)
{
  Supplier *existing_supplier;

  int supplier_id;

  printf("\nOpções de modificação:\n");
  printf("1 - ID do fornecedor\n");
  printf("2 - Nome\n");
  printf("3 - Modelo do Carro\n");
  printf("4 - Quantidade\n");
  printf("5 - Preço\n");
  printf("0 - Cancelar\n");

  int choice = read_integer_input("\nEscolha uma opção de modificação: ", 0, 5);

  switch (choice)
  {
  case 0:
    printf("\nModificação cancelada.\n");
    break;
  case 1:
    do
    {
      supplier_id = read_integer_input("\nID do fornecedor: ", 0, 999);
      existing_supplier = find_supplier_by_id(supplier_head, supplier_id);

      if (existing_supplier != NULL)
      {
        part->supplier_id = supplier_id;
        printf("ID do fornecedor modificado com sucesso!\n");
      }
      else
      {
        printf("\nID do fornecedor informado não existe. A lista de fornecedor está vazia ou o arquivo supplier.txt não foi carregado. Insira um ID existente ou cadastre um fornecedor\n");
      }
    } while (existing_supplier == NULL);
    break;
  case 2:
    read_string_input("\nNome da peça: ", part->full_name,
                      MAX_FULL_NAME_SIZE);
    printf("Nome modificado com sucesso!\n");
    break;
  case 3:
    read_string_input("\nModelo do carro: ", part->car_model,
                      MAX_CAR_MODEL_SIZE);
    printf("Modelo do carro modificado com sucesso!\n");
    break;
  case 4:
    part->amount = read_integer_input("\nQuantidade: ", 1, 99999);
    printf("Quantidade modificada com sucesso!\n");
    break;
  case 5:
    part->price = read_double_input("Preço: ", 0.0, 99999.99);
    printf("Preço modificado com sucesso!\n");
    break;
  default:
    printf("Opção inválida. Nenhuma modificação realizada.\n");
    break;
  }
}

void modify_consumer_data(Consumer *consumer)
{
  printf("\nOpções de modificação:\n");
  printf("1 - CPF\n");
  printf("2 - Nome Completo\n");
  printf("3 - Data de Nascimento\n");
  printf("4 - E-mail\n");
  printf("5 - Telefone de Contato\n");
  printf("6 - Endereço Residencial\n");
  printf("0 - Cancelar\n");

  int choice = read_integer_input("\nEscolha uma opção de modificação: ", 0, 6);

  switch (choice)
  {
  case 0:
    printf("\nModificação cancelada.\n");
    break;
  case 1:
    consumer->cpf = read_integer_input_cpf("\nCPF do cliente: ", 0, 99999999999);
    printf("CPF modificado com sucesso!\n");
    break;
  case 2:
    read_string_input("\nNome do cliente: ", consumer->full_name,
                      MAX_FULL_NAME_SIZE);
    printf("Nome modificado com sucesso!\n");
    break;
  case 3:
    read_string_input("\nData de nascimento do cliente: ", consumer->date_birth,
                      MAX_DATE_FORMAT_SIZE);
    printf("Data de nascimento modificada com sucesso!\n");
    break;
  case 4:
    read_string_input("\nE-mail do cliente: ", consumer->email_address,
                      MAX_EMAIL_ADDRESS_SIZE);
    printf("E-mail modificado com sucesso!\n");
    break;
  case 5:
    read_string_input("\nTelefone de contato do cliente: ", consumer->phone_number,
                      MAX_PHONE_NUMBER_SIZE);
    printf("Telefone de contato modificado com sucesso!\n");
    break;
  case 6:
    read_string_input("\nEndereço residencial do cliente: ", consumer->home_address,
                      MAX_HOME_ADDRESS_SIZE);
    printf("Endereço residencial modificado com sucesso!\n");
    break;
  default:
    printf("Opção inválida. Nenhuma modificação realizada.\n");
    break;
  }
}

void remove_collaborator(Collaborator **head, Collaborator *collaborator)
{
  if (*head == collaborator)
  {
    *head = collaborator->next;
  }
  else
  {
    Collaborator *current = *head;
    while (current != NULL && current->next != collaborator)
    {
      current = current->next;
    }
    if (current != NULL)
    {
      current->next = collaborator->next;
    }
  }
  free(collaborator);
}

void remove_supplier(Supplier **head, Supplier *supplier)
{
  if (*head == supplier)
  {
    *head = supplier->next;
  }
  else
  {
    Supplier *current = *head;
    while (current != NULL && current->next != supplier)
    {
      current = current->next;
    }
    if (current != NULL)
    {
      current->next = supplier->next;
    }
  }
  free(supplier);
}

void remove_part(Part **head, Part *part)
{
  if (*head == part)
  {
    *head = part->next;
  }
  else
  {
    Part *current = *head;
    while (current != NULL && current->next != part)
    {
      current = current->next;
    }
    if (current != NULL)
    {
      current->next = part->next;
    }
  }
  free(part);
}

void remove_consumer(Consumer **head, Consumer *consumer)
{
  if (*head == consumer)
  {
    *head = consumer->next;
  }
  else
  {
    Consumer *current = *head;
    while (current != NULL && current->next != consumer)
    {
      current = current->next;
    }
    if (current != NULL)
    {
      current->next = consumer->next;
    }
  }
  free(consumer);
}

int is_file_empty(const char *file_path)
{
  FILE *file = fopen(file_path, "r");
  if (file == NULL)
  {
    return 1;
  }

  int is_empty = 1;

  char line[2];
  if (fgets(line, sizeof(line), file) != NULL)
  {
    is_empty = 0;
  }

  fclose(file);
  return is_empty;
}

void remove_quotes(char *str)
{
  if (str[0] == '"')
  {
    memmove(str, str + 1, strlen(str));
    str[strlen(str) - 1] = '\0';
  }
}

void read_data_collaborators_file(FILE *file, Collaborator **head)
{
  char line[MAX_FILE_LINE_SIZE + 100];
  while (fgets(line, sizeof(line), file) != NULL)
  {
    Collaborator *new_collaborator = create_collaborator_node();

    char *token = strtok(line, ",");

    new_collaborator->id = atoi(token);

    token = strtok(NULL, ",");
    new_collaborator->cpf = atoi(token);

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_collaborator->full_name, token, MAX_FULL_NAME_SIZE - 1);
    new_collaborator->full_name[MAX_FULL_NAME_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_collaborator->date_birth, token, MAX_DATE_FORMAT_SIZE - 1);
    new_collaborator->date_birth[MAX_DATE_FORMAT_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_collaborator->email_address, token, MAX_EMAIL_ADDRESS_SIZE - 1);
    new_collaborator->email_address[MAX_EMAIL_ADDRESS_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_collaborator->phone_number, token, MAX_PHONE_NUMBER_SIZE - 1);
    new_collaborator->phone_number[MAX_PHONE_NUMBER_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_collaborator->home_address, token, MAX_HOME_ADDRESS_SIZE - 1);
    new_collaborator->home_address[MAX_HOME_ADDRESS_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_collaborator->office, token, MAX_OFFICE_SIZE - 1);
    new_collaborator->office[MAX_OFFICE_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    new_collaborator->salary = atof(token);

    token = strtok(NULL, ",");
    new_collaborator->total_sales_made = atoi(token);

    insert_collaborator_in_list(head, new_collaborator);
  }
}

void read_data_suppliers_file(FILE *file, Supplier **head)
{
  char line[MAX_FILE_LINE_SIZE + 100];
  while (fgets(line, sizeof(line), file) != NULL)
  {
    Supplier *new_supplier = create_supplier_node();

    char *token = strtok(line, ",");

    new_supplier->id = atoi(token);

    token = strtok(NULL, ",");
    new_supplier->cnpj = atoi(token);

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_supplier->full_name, token, MAX_FULL_NAME_SIZE - 1);
    new_supplier->full_name[MAX_FULL_NAME_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_supplier->part_category, token, MAX_PART_CATEGORY_SIZE - 1);
    new_supplier->part_category[MAX_PART_CATEGORY_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_supplier->email_address, token, MAX_EMAIL_ADDRESS_SIZE - 1);
    new_supplier->email_address[MAX_EMAIL_ADDRESS_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_supplier->phone_number, token, MAX_PHONE_NUMBER_SIZE - 1);
    new_supplier->phone_number[MAX_PHONE_NUMBER_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_supplier->business_address, token, MAX_BUSINESS_ADDRESS_SIZE - 1);
    new_supplier->business_address[MAX_BUSINESS_ADDRESS_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_supplier->contract_date, token, MAX_DATE_FORMAT_SIZE - 1);
    new_supplier->contract_date[MAX_DATE_FORMAT_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    new_supplier->contract_price = atof(token);

    insert_supplier_in_list(head, new_supplier);
  }
}

void read_data_parts_file(FILE *file, Part **head)
{
  char line[MAX_FILE_LINE_SIZE + 100];
  while (fgets(line, sizeof(line), file) != NULL)
  {
    Part *new_part = create_part_node();

    char *token = strtok(line, ",");

    new_part->id = atoi(token);

    token = strtok(NULL, ",");
    new_part->supplier_id = atoi(token);

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_part->full_name, token, MAX_FULL_NAME_SIZE - 1);
    new_part->full_name[MAX_FULL_NAME_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_part->car_model, token, MAX_CAR_MODEL_SIZE - 1);
    new_part->car_model[MAX_CAR_MODEL_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    new_part->amount = atoi(token);

    token = strtok(NULL, ",");
    new_part->price = atof(token);

    insert_part_in_list(head, new_part);
  }
}

void read_data_consumers_file(FILE *file, Consumer **head)
{
  char line[MAX_FILE_LINE_SIZE + 100];
  while (fgets(line, sizeof(line), file) != NULL)
  {
    Consumer *new_consumer = create_consumer_node();

    char *token = strtok(line, ",");

    new_consumer->id = atoi(token);

    token = strtok(NULL, ",");
    new_consumer->cpf = atoi(token);

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_consumer->full_name, token, MAX_FULL_NAME_SIZE - 1);
    new_consumer->full_name[MAX_FULL_NAME_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_consumer->date_birth, token, MAX_DATE_FORMAT_SIZE - 1);
    new_consumer->date_birth[MAX_DATE_FORMAT_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_consumer->email_address, token, MAX_EMAIL_ADDRESS_SIZE - 1);
    new_consumer->email_address[MAX_EMAIL_ADDRESS_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_consumer->phone_number, token, MAX_PHONE_NUMBER_SIZE - 1);
    new_consumer->phone_number[MAX_PHONE_NUMBER_SIZE - 1] = '\0';

    token = strtok(NULL, ",");
    remove_quotes(token);
    strncpy(new_consumer->home_address, token, MAX_HOME_ADDRESS_SIZE - 1);
    new_consumer->home_address[MAX_HOME_ADDRESS_SIZE - 1] = '\0';

    insert_consumer_in_list(head, new_consumer);
  }
}

void print_default_menu()
{
  printf("\n--------------------------------------------------------------------------------\n");
  printf("\n----- MENU -----\n");
  printf("1 - Listar colaborador | fornecedor | peça | cliente\n");
  printf("2 - Buscar colaborador | fornecedor | peça | cliente\n");
  printf("3 - Adicionar colaborador | fornecedor | peça | cliente\n");
  printf("4 - Remover colaborador | fornecedor | peça | cliente\n");
  printf("5 - Salvar dados dos colaboradores | fornecedores | peças | clientes em arquivos\n");
  printf("\n6 - Sair\n");
}

void secondary_menu_options()
{
  printf("1 - Colaborador\n");
  printf("2 - Fornecedor\n");
  printf("3 - Peça\n");
  printf("4 - Cliente\n");
  printf("\n0 - Voltar\n");
}

void print_secondary_menu(int choice)
{
  switch (choice)
  {
  case 1:
    printf("\n--------------------------------------------------------------------------------\n");
    printf("\n----- MENU LISTAR -----\n");
    secondary_menu_options();
    break;
  case 2:
    printf("\n--------------------------------------------------------------------------------\n");
    printf("\n----- MENU BUSCAR -----\n");
    secondary_menu_options();
    break;
  case 3:
    printf("\n--------------------------------------------------------------------------------\n");
    printf("\n----- MENU ADICIONAR -----\n");
    secondary_menu_options();
    break;
  case 4:
    printf("\n--------------------------------------------------------------------------------\n");
    printf("\n----- MENU REMOVER -----\n");
    secondary_menu_options();
    break;
  case 5:
    printf("\n--------------------------------------------------------------------------------\n");
    printf("\n----- MENU SALVAR -----\n");
    secondary_menu_options();
    break;
  default:
    printf("Opção inválida. Nenhuma ação foi realizada!\n");
    break;
  }
}

int main(void)
{
  Collaborator *collaborator_head = NULL;
  Supplier *supplier_head = NULL;
  Part *part_head = NULL;
  Consumer *consumer_head = NULL;

  char user_response[3];

  char file_relative_path_type[20];

  char collaborators_file_relative_path[MAX_RELATIVE_PATH_SIZE];
  char suppliers_file_relative_path[MAX_RELATIVE_PATH_SIZE];
  char parts_file_relative_path[MAX_RELATIVE_PATH_SIZE];
  char consumers_file_relative_path[MAX_RELATIVE_PATH_SIZE];

  int choice_default_menu;
  int choice_secondary_menu;

  int collaborator_id;
  Collaborator *existing_collaborator;
  Collaborator *collaborator_to_remove;

  int supplier_id;
  Supplier *existing_supplier;
  Supplier *supplier_to_remove;

  int part_id;
  Part *existing_part;
  Part *part_to_remove;

  int consumer_id;
  Consumer *existing_consumer;
  Consumer *consumer_to_remove;

  int modify_choice;

  printf("\n----- BEM-VINDO AO SISTEMA AUTO PEÇAS PVT METE! -----\n");

  do
  {
    read_string_input("\nDeseja informar o caminho relativo do arquivo? (s/n): ", user_response, 3);

    if (tolower(user_response[0]) != 's' && tolower(user_response[0]) != 'n')
    {
      printf("\nOpção inválida. Por favor, escolha uma opção válida (s/n).\n");
    }
    else
    {
      if (tolower(user_response[0]) == 's')
      {
        read_string_input("\nEscolha uma das opções (colaboradores | fornecedores | peças | clientes | todos): ", file_relative_path_type, 20);

        if (strcmp(file_relative_path_type, "colaboradores") == 0)
        {
          read_string_input("\nInforme o caminho relativo do arquivo de dados dos colaboradores: ", collaborators_file_relative_path, MAX_RELATIVE_PATH_SIZE);

          FILE *collaborators_file = fopen(collaborators_file_relative_path, "r");
          if (collaborators_file != NULL)
          {
            read_data_collaborators_file(collaborators_file, &collaborator_head);
            fclose(collaborators_file);
          }
        }
        else if (strcmp(file_relative_path_type, "fornecedores") == 0)
        {
          read_string_input("\nInforme o caminho relativo do arquivo de dados dos fornecedores: ", suppliers_file_relative_path, MAX_RELATIVE_PATH_SIZE);

          FILE *suppliers_file = fopen(suppliers_file_relative_path, "r");
          if (suppliers_file != NULL)
          {
            read_data_suppliers_file(suppliers_file, &supplier_head);
            fclose(suppliers_file);
          }
        }
        else if (strcmp(file_relative_path_type, "peças") == 0)
        {
          read_string_input("\nInforme o caminho relativo do arquivo de dados das peças: ", parts_file_relative_path, MAX_RELATIVE_PATH_SIZE);

          FILE *parts_file = fopen(parts_file_relative_path, "r");
          if (parts_file != NULL)
          {
            read_data_parts_file(parts_file, &part_head);
            fclose(parts_file);
          }
        }
        else if (strcmp(file_relative_path_type, "clientes") == 0)
        {
          read_string_input("\nInforme o caminho relativo do arquivo de dados dos clientes: ", consumers_file_relative_path, MAX_RELATIVE_PATH_SIZE);

          FILE *consumers_file = fopen(consumers_file_relative_path, "r");
          if (consumers_file != NULL)
          {
            read_data_consumers_file(consumers_file, &consumer_head);
            fclose(consumers_file);
          }
        }
        else if (strcmp(file_relative_path_type, "todos") == 0)
        {
          read_string_input("\nInforme o caminho relativo do arquivo de dados dos colaboradores: ", collaborators_file_relative_path, MAX_RELATIVE_PATH_SIZE);
          read_string_input("\nInforme o caminho relativo do arquivo de dados dos fornecedores: ", suppliers_file_relative_path, MAX_RELATIVE_PATH_SIZE);
          read_string_input("\nInforme o caminho relativo do arquivo de dados das peças: ", parts_file_relative_path, MAX_RELATIVE_PATH_SIZE);
          read_string_input("\nInforme o caminho relativo do arquivo de dados dos clientes: ", consumers_file_relative_path, MAX_RELATIVE_PATH_SIZE);

          FILE *collaborators_file = fopen(collaborators_file_relative_path, "r");
          if (collaborators_file != NULL)
          {
            read_data_collaborators_file(collaborators_file, &collaborator_head);
            fclose(collaborators_file);
          }

          FILE *suppliers_file = fopen(suppliers_file_relative_path, "r");
          if (suppliers_file != NULL)
          {
            read_data_suppliers_file(suppliers_file, &supplier_head);
            fclose(suppliers_file);
          }

          FILE *parts_file = fopen(parts_file_relative_path, "r");
          if (parts_file != NULL)
          {
            read_data_parts_file(parts_file, &part_head);
            fclose(parts_file);
          }

          FILE *consumers_file = fopen(consumers_file_relative_path, "r");
          if (consumers_file != NULL)
          {
            read_data_consumers_file(consumers_file, &consumer_head);
            fclose(consumers_file);
          }
        }
      }
    }
  } while (tolower(user_response[0]) != 's' && tolower(user_response[0]) != 'n');

  do
  {
    print_default_menu();
    choice_default_menu = read_integer_input("\nEscolha uma opção: ", 1, 6);

    switch (choice_default_menu)
    {
    case 1:
      print_secondary_menu(choice_default_menu);
      choice_secondary_menu = read_integer_input("\nEscolha uma opção: ", 0, 4);

      switch (choice_secondary_menu)
      {
      case 0:
        printf("\nRetornando...\n");
        break;
      case 1:
        if (is_file_empty(collaborators_file_relative_path) || collaborator_head != NULL)
        {
          list_all_collaborators(collaborator_head);
        }
        else
        {
          printf("\nO arquivo/lista está vazia e/ou não esxiste.\n");
        }

        sleep(2);
        break;
      case 2:
        if (is_file_empty(suppliers_file_relative_path) || supplier_head != NULL)
        {
          list_all_suppliers(supplier_head);
        }
        else
        {
          printf("\nO arquivo/lista está vazia e/ou não esxiste.\n");
        }

        sleep(2);
        break;
      case 3:
        if (is_file_empty(parts_file_relative_path) || part_head != NULL)
        {
          list_all_parts(part_head);
        }
        else
        {
          printf("\nO arquivo/lista está vazia e/ou não esxiste.\n");
        }

        sleep(2);
        break;
      case 4:
        if (is_file_empty(consumers_file_relative_path) || consumer_head != NULL)
        {
          list_all_consumers(consumer_head);
        }
        else
        {
          printf("\nO arquivo/lista está vazia e/ou não esxiste.\n");
        }

        sleep(2);
        break;
      default:
        printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        break;
      }
      break;
    case 2:
      print_secondary_menu(choice_default_menu);
      choice_secondary_menu = read_integer_input("\nEscolha uma opção: ", 0, 4);

      switch (choice_secondary_menu)
      {
      case 0:
        printf("\nRetornando...\n");
        break;
      case 1:
        collaborator_id = read_integer_input("\nInforme o ID do colaborador: ", 0, 999);
        existing_collaborator = find_collaborator_by_id(collaborator_head, collaborator_id);
        if (existing_collaborator != NULL)
        {
          print_collaborator_details(existing_collaborator, 0);

          modify_choice = read_integer_input("\nDeseja modificar os dados deste colaborador? (1 - Sim, 2 - Não): ", 1, 2);

          if (modify_choice == 1)
          {
            modify_collaborator_data(existing_collaborator);
          }
        }
        else
        {
          printf("\nNenhum colaborador encontrado com o ID informada.\n");
        }

        sleep(2);
        break;
      case 2:
        supplier_id = read_integer_input("\nInforme o ID do fornecedor: ", 0, 999);
        existing_supplier = find_supplier_by_id(supplier_head, supplier_id);
        if (existing_supplier != NULL)
        {
          print_supplier_details(existing_supplier, 0);

          modify_choice = read_integer_input("\nDeseja modificar os dados deste fornecedor? (1 - Sim, 2 - Não): ", 1, 2);

          if (modify_choice == 1)
          {
            modify_supplier_data(existing_supplier);
          }
        }
        else
        {
          printf("\nNenhum fornecedor encontrado com o ID informada.\n");
        }

        sleep(2);
        break;
      case 3:
        part_id = read_integer_input("\nInforme o ID da peça: ", 0, 999);
        existing_part = find_part_by_id(part_head, part_id);
        if (existing_part != NULL)
        {
          print_part_details(existing_part, 0);

          modify_choice = read_integer_input("\nDeseja modificar os dados desta peça? (1 - Sim, 2 - Não): ", 1, 2);

          if (modify_choice == 1)
          {
            modify_part_data(existing_part, supplier_head);
          }
        }
        else
        {
          printf("\nNenhum peça encontrado com o ID informada.\n");
        }

        sleep(2);
        break;
      case 4:
        consumer_id = read_integer_input("\nInforme o ID do cliente: ", 0, 999);
        existing_consumer = find_consumer_by_id(consumer_head, consumer_id);
        if (existing_part != NULL)
        {
          print_consumer_details(existing_part, 0);

          modify_choice = read_integer_input("\nDeseja modificar os dados desta peça? (1 - Sim, 2 - Não): ", 1, 2);

          if (modify_choice == 1)
          {
            modify_consumer_data(existing_part);
          }
        }
        else
        {
          printf("\nNenhum peça encontrado com o ID informada.\n");
        }

        sleep(2);
        break;
      default:
        printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        break;
      }
      break;
    case 3:
      print_secondary_menu(choice_default_menu);
      choice_secondary_menu = read_integer_input("\nEscolha uma opção: ", 0, 4);

      switch (choice_secondary_menu)
      {
      case 0:
        printf("\nRetornando...\n");
        break;
      case 1:
        printf("\n----- ENTRADA DE DADOS -----\n");

        do
        {
          collaborator_id = read_integer_input("\nInforme o ID do colaborador: ", 0, 999);
          existing_collaborator = find_collaborator_by_id(collaborator_head, collaborator_id);

          if (existing_collaborator != NULL)
          {
            printf("\nO ID informado já existe. Insira um ID válido!\n");
          }
        } while (existing_collaborator != NULL);

        Collaborator *new_collaborator = create_collaborator_node();

        new_collaborator->id = collaborator_id;
        new_collaborator->cpf = read_integer_input_cpf("\nInforme o CPF do colaborador: ", 0, 99999999999);
        read_string_input("\nInforme o nome completo do colaborador: ", new_collaborator->full_name, MAX_FULL_NAME_SIZE);
        read_string_input("\nInforme a data de nascimento do colaborador: ", new_collaborator->date_birth, MAX_DATE_FORMAT_SIZE);
        read_string_input("\nInforme o e-mail do colaborador: ", new_collaborator->email_address, MAX_EMAIL_ADDRESS_SIZE);
        read_string_input("\nInforme o telefone de contato do colaborador: ", new_collaborator->phone_number, MAX_PHONE_NUMBER_SIZE);
        read_string_input("\nInforme o endereço residencial do colaborador: ", new_collaborator->home_address, MAX_HOME_ADDRESS_SIZE);
        read_string_input("\nInforme o cargo do colaborador: ", new_collaborator->office, MAX_OFFICE_SIZE);
        new_collaborator->salary = read_double_input("\nInforme o salário do colaborador: ", 0.0, 99999.99);
        new_collaborator->total_sales_made = read_integer_input("\nInfome a quantidade de vendas do colaborador: ", 0, 99999);

        insert_collaborator_in_list(&collaborator_head, new_collaborator);

        printf("\nColaborador adicionado com sucesso!\n");

        sleep(2);
        break;
      case 2:
        printf("\n----- ENTRADA DE DADOS -----\n");

        do
        {
          supplier_id = read_integer_input("\nInforme o ID do fornecedor: ", 0, 999);
          existing_supplier = find_supplier_by_id(supplier_head, supplier_id);

          if (existing_supplier != NULL)
          {
            printf("\nO ID informado já existe. Insira um ID válido!\n");
          }
        } while (existing_supplier != NULL);

        Supplier *new_supplier = create_supplier_node();

        new_supplier->id = supplier_id;
        new_supplier->cnpj = read_integer_input_cnpj("\nInforme o CNPJ do fornecedor: ", 0, 99999999999999);
        read_string_input("\nInforme o nome completo do fornecedor: ", new_supplier->full_name, MAX_FULL_NAME_SIZE);
        read_string_input("\nInforme a categotia da peça: ", new_supplier->part_category, MAX_PART_CATEGORY_SIZE);
        read_string_input("\nInforme o e-mail do fornecedor: ", new_supplier->email_address, MAX_EMAIL_ADDRESS_SIZE);
        read_string_input("\nInforme o telefone de contato do fornecedor: ", new_supplier->phone_number, MAX_PHONE_NUMBER_SIZE);
        read_string_input("\nInforme o endereço comercial do fornecedor: ", new_supplier->business_address, MAX_BUSINESS_ADDRESS_SIZE);
        read_string_input("\nInforme a data da assinatura do contrato: ", new_supplier->contract_date, MAX_DATE_FORMAT_SIZE);
        new_supplier->contract_price = read_double_input("\nInforme o valor do contrato: ", 0.0, 99999.99);

        insert_supplier_in_list(&supplier_head, new_supplier);

        printf("\nFornecedor adicionado com sucesso!\n");

        sleep(2);
        break;
      case 3:
        printf("\n----- ENTRADA DE DADOS -----\n");

        do
        {
          part_id = read_integer_input("\nInforme o ID da peça: ", 0, 999);
          existing_part = find_part_by_id(part_head, part_id);

          if (existing_part != NULL)
          {
            printf("\nO ID informado já existe. Insira um ID válido!\n");
          }
        } while (existing_part != NULL);

        Part *new_part = create_part_node();

        new_part->id = part_id;

        int count = 0;

        do
        {
          supplier_id = read_integer_input("\nInforme o ID do fornecedor: ", 0, 999);
          existing_supplier = find_supplier_by_id(supplier_head, supplier_id);

          if (existing_supplier == NULL)
          {
            printf("\nNão existe fornecedor com esse ID. Adicione um ou insira um ID válido!\n");
          }

          count++;

          if (count == 10)
          {
            printf("\nNúmero de tentativas inválidas atingidas!\n");
            sleep(2);
            break;
          }

        } while (existing_supplier == NULL);

        new_part->supplier_id = supplier_id;
        read_string_input("\nInforme o nome da peça: ", new_part->full_name, MAX_FULL_NAME_SIZE);
        read_string_input("\nInforme o modelo do carro: ", new_part->car_model, MAX_CAR_MODEL_SIZE);
        new_part->amount = read_integer_input("\nInforme a quantidade: ", 1, 99999);
        new_part->price = read_double_input("\nInforme o valor da peça: ", 1.1, 99999.99);

        insert_part_in_list(&part_head, new_part);

        printf("\nPeça adicionada com sucesso!\n");

        sleep(2);
        break;
      case 4:
        printf("\n----- ENTRADA DE DADOS -----\n");

        do
        {
          consumer_id = read_integer_input("\nInforme o ID do cliente: ", 0, 999);
          existing_consumer = find_consumer_by_id(consumer_head, consumer_id);

          if (existing_consumer != NULL)
          {
            printf("\nO ID informado já existe. Insira um ID válido!\n");
          }
        } while (existing_consumer != NULL);

        Consumer *new_consumer = create_consumer_node();

        new_consumer->id = consumer_id;
        new_consumer->cpf = read_integer_input_cpf("\nInforme o CPF do cliente: ", 0, 99999999999);
        read_string_input("\nInforme o nome completo do cliente: ", new_consumer->full_name, MAX_FULL_NAME_SIZE);
        read_string_input("\nInforme a data de nascimento do cliente: ", new_consumer->date_birth, MAX_DATE_FORMAT_SIZE);
        read_string_input("\nInforme o e-mail do cliente: ", new_consumer->email_address, MAX_EMAIL_ADDRESS_SIZE);
        read_string_input("\nInforme o telefone de contato do cliente: ", new_consumer->phone_number, MAX_PHONE_NUMBER_SIZE);
        read_string_input("\nInforme o endereço residencial do cliente: ", new_consumer->home_address, MAX_HOME_ADDRESS_SIZE);

        insert_consumer_in_list(&consumer_head, new_consumer);

        printf("\nCliente adicionado com sucesso!\n");

        sleep(2);
        break;
      default:
        printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        break;
      }
      break;
    case 4:
      print_secondary_menu(choice_default_menu);
      choice_secondary_menu = read_integer_input("\nEscolha uma opção: ", 0, 4);

      switch (choice_secondary_menu)
      {
      case 0:
        printf("\nRetornando...\n");
        break;
      case 1:
        collaborator_id = read_integer_input("\nInforme o ID do colaborador a ser removido: ", 0, 999);
        collaborator_to_remove = find_collaborator_by_id(collaborator_head, collaborator_id);

        if (collaborator_to_remove != NULL)
        {
          remove_collaborator(&collaborator_head, collaborator_to_remove);
          printf("\nColaborador removido com sucesso!\n");
        }
        else
        {
          printf("\nNenhum colaborador encontrado com o ID informado.\n");
        }

        sleep(2);
        break;
      case 2:
        supplier_id = read_integer_input("\nInforme o ID do fornecedor a ser removido: ", 0, 999);
        supplier_to_remove = find_supplier_by_id(supplier_head, supplier_id);

        if (supplier_to_remove != NULL)
        {
          remove_supplier(&supplier_head, supplier_to_remove);
          printf("\nFornecedor removido com sucesso!\n");
        }
        else
        {
          printf("\nNenhum fornecedor encontrado com o ID informado.\n");
        }

        sleep(2);
        break;
      case 3:
        part_id = read_integer_input("\nInforme o ID da peça a ser removida: ", 0, 999);
        part_to_remove = find_part_by_id(part_head, part_id);

        if (part_to_remove != NULL)
        {
          remove_part(&part_head, part_to_remove);
          printf("\nPeça removida com sucesso!\n");
        }
        else
        {
          printf("\nNenhuma peça encontrada com o ID informado.\n");
        }

        sleep(2);
        break;
      case 4:
        consumer_id = read_integer_input("\nInforme o ID do cliente a ser removido: ", 0, 999);
        consumer_to_remove = find_consumer_by_id(consumer_head, consumer_id);

        if (consumer_to_remove != NULL)
        {
          remove_consumer(&consumer_head, consumer_to_remove);
          printf("\nCliente removido com sucesso!\n");
        }
        else
        {
          printf("\nNenhum cliente encontrado com o ID informado.\n");
        }

        sleep(2);
        break;
      default:
        printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        break;
      }
      break;
    case 5:
      print_secondary_menu(choice_default_menu);
      choice_secondary_menu = read_integer_input("\nEscolha uma opção: ", 0, 4);

      switch (choice_secondary_menu)
      {
      case 0:
        printf("\nRetornando...\n");
        break;
      case 1:
        if (collaborator_head != NULL)
        {
          read_string_input("\nInforme o caminho relativo no qual o arquivo com os dados dos colaboradores será salvo: ", collaborators_file_relative_path, MAX_RELATIVE_PATH_SIZE);

          save_collaborator_data_to_file(collaborators_file_relative_path, collaborator_head);
        }
        else
        {
          printf("\nErro! Nenhum colaborador foi cadastrado e/ou carregado.\n");
        }

        sleep(2);
        break;
      case 2:
        if (supplier_head != NULL)
        {
          read_string_input("\nInforme o caminho relativo no qual o arquivo com os dados dos fornecedores será salvo: ", suppliers_file_relative_path, MAX_RELATIVE_PATH_SIZE);

          save_supplier_data_to_file(suppliers_file_relative_path, supplier_head);
        }
        else
        {
          printf("\nErro! Nenhum fornecedor foi cadastrado e/ou carregado.\n");
        }

        sleep(2);
        break;
      case 3:
        if (part_head != NULL)
        {
          read_string_input("\nInforme o caminho relativo no qual o arquivo com os dados das peças será salvo: ", parts_file_relative_path, MAX_RELATIVE_PATH_SIZE);

          save_part_data_to_file(parts_file_relative_path, part_head);
        }
        else
        {
          printf("\nErro! Nenhuma peça foi cadastrado e/ou carregado.\n");
        }

        sleep(2);
        break;
      case 4:
        if (consumer_head != NULL)
        {
          read_string_input("\nInforme o caminho relativo no qual o arquivo com os dados dos clientes será salvo: ", consumers_file_relative_path, MAX_RELATIVE_PATH_SIZE);

          save_consumer_data_to_file(consumers_file_relative_path, consumer_head);
        }
        else
        {
          printf("\nErro! Nenhum cliente foi cadastrado e/ou carregado.\n");
        }

        sleep(2);
        break;
      default:
        printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        break;
      }
      break;
    case 6:
      printf("\nEncerrando o programa...\n");
      break;
    default:
      printf("Opção inválida. Por favor, escolha uma opção válida.\n");
      break;
    }
  } while (choice_default_menu != 6);

  Collaborator *current_Collaborator = collaborator_head;
  while (current_Collaborator != NULL)
  {
    Collaborator *temp_Collaborator = current_Collaborator;
    current_Collaborator = current_Collaborator->next;
    free(temp_Collaborator);
  }

  Supplier *current_supplier = supplier_head;
  while (current_supplier != NULL)
  {
    Supplier *temp_supplier = current_supplier;
    current_supplier = current_supplier->next;
    free(temp_supplier);
  }

  Part *current_part = part_head;
  while (current_part != NULL)
  {
    Part *temp_part = current_part;
    current_part = current_part->next;
    free(temp_part);
  }

  Consumer *current_consumer = consumer_head;
  while (current_consumer != NULL)
  {
    Consumer *temp_consumer = current_consumer;
    current_consumer = current_consumer->next;
    free(temp_consumer);
  }

  return 0;
}