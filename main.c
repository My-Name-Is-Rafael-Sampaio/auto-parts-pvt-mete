#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FULL_NAME_SIZE 30
#define MAX_DATE_FORMAT_SIZE 10
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
    printf("Erro ao alocar memória para collaborator/colaborador!\n");
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
    printf("Erro ao alocar memória para supplie/fornecedor!\n");
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
    printf("Erro ao alocar memória para part/peça!\n");
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
    printf("Erro ao alocar memória para consumer/cliente!\n");
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
  printf("\n%d° Collaborator/Colaborador:\n", (index + 1));
  printf("ID -> %d\nCPF -> %d\nNome Completo -> %s\nData de Nascimento -> %s\nE-mail -> %s\nTelefone de Contato -> %s\nEndereço Residencial -> %s\nCargo -> %s\nSalário -> %.2f\nTotal de Vendas -> %d\n", collaborator->id, collaborator->cpf, collaborator->full_name, collaborator->date_birth, collaborator->email_address, collaborator->phone_number, collaborator->home_address, collaborator->office, collaborator->salary, collaborator->total_sales_made);
}

void print_supplier_details(const Supplier *supplier, int index)
{
  printf("\n%d° Supplier/Fornecedor:\n", (index + 1));
  printf("ID -> %d\nCNPJ -> %d\nNome Completo -> %s\nCategoria da Peça -> %s\nE-mail -> %s\nTelefone de Contato -> %s\nEndereço Comercial -> %s\nData de Contrato -> %s\nPreço do Contrato -> %.2f\n", supplier->id, supplier->cnpj, supplier->full_name, supplier->part_category, supplier->email_address, supplier->phone_number, supplier->business_address, supplier->contract_date, supplier->contract_price);
}

void print_part_details(const Part *part, int index)
{
  printf("\n%d° Part/Peça:\n", (index + 1));
  printf("ID -> %d\nID do Fornecedor -> %d\nNome Completo -> %s\nModelo do Carro -> %s\nQuantidade -> %d\nPreço -> %.2f\n", part->id, part->supplier_id, part->full_name, part->car_model, part->amount, part->price);
}

void print_consumer_details(const Consumer *consumer, int index)
{
  printf("\n%d° Consumer/Cliente:\n", (index + 1));
  printf("ID -> %d\nCPF -> %d\nNome Completo -> %s\nData de Nascimento -> %s\nE-mail -> %s\nTelefone de Contato -> %s\nEndereço Residencial -> %s\n", consumer->id, consumer->cpf, consumer->full_name, consumer->date_birth, consumer->email_address, consumer->phone_number, consumer->home_address);
}

void list_all_collaborators(const Collaborator *head)
{
  if (head == NULL)
  {
    printf("\nO arquivo está vazio e/ou nenhum collaborator/colaborador foi cadastrado.\n");
    return;
  }

  int index = 0;
  const Collaborator *current = head;
  printf("\n----- DADOS DOS COLLABORATORS/COLABORADORES -----\n");
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
    printf("\nO arquivo está vazio e/ou nenhum supplier/fornecedor foi cadastrado.\n");
    return;
  }
  int index = 0;
  const Supplier *current = head;
  printf("\n----- DADOS DOS SUPPLIERS/FORNECEDORES -----\n");
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
    printf("\nO arquivo está vazio e/ou nenhum part/peça foi cadastrado.\n");
    return;
  }
  int index = 0;
  const Part *current = head;
  printf("\n----- DADOS DOS PARTS/PEÇAS -----\n");
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
    printf("\nO arquivo está vazio e/ou nenhum consumer/cliente foi cadastrado.\n");
    return;
  }
  int index = 0;
  const Consumer *current = head;
  printf("\n----- DADOS DOS CONSUMERS/CLIENTES -----\n");
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
  fprintf(file, "%d, %d,\"%s\",\"%s\",\"%s\", \"%s\", \"%s\", \"%s\",%.2f, %d\n", collaborator->id, collaborator->cpf, collaborator->full_name, collaborator->date_birth, collaborator->email_address, collaborator->phone_number, collaborator->home_address, collaborator->office, collaborator->salary, collaborator->total_sales_made);
}

void save_supplier_data(FILE *file, const Supplier *supplier)
{
  fprintf(file, "%d, %d,\"%s\",\"%s\",\"%s\", \"%s\", \"%s\", \"%s\",%.2f\n", supplier->id, supplier->cnpj, supplier->full_name, supplier->part_category, supplier->email_address, supplier->phone_number, supplier->business_address, supplier->contract_date, supplier->contract_price);
}

void save_part_data(FILE *file, const Part *part)
{
  fprintf(file, "%d, %d,\"%s\",\"%s\", %d, %.2f\n", part->id, part->supplier_id, part->full_name, part->car_model, part->amount, part->price);
}

void save_consumer_data(FILE *file, const Consumer *consumer)
{
  fprintf(file, "%d, %d,\"%s\",\"%s\",\"%s\", \"%s\", \"%s\"\n", consumer->id, consumer->cpf, consumer->full_name, consumer->date_birth, consumer->email_address, consumer->phone_number, consumer->home_address);
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
    printf("\nDados dos collaborators/colaboradores salvos com sucesso no arquivo!\n");
  }
  else
  {
    printf("Erro ao abrir o arquivo para salvar os dados dos collaborators/colaboradores.\n\n");
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
    printf("\nDados dos suppliers/fornecedores salvos com sucesso no arquivo!\n");
  }
  else
  {
    printf("Erro ao abrir o arquivo para salvar os dados dos suppliers/fornecedores.\n\n");
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
    printf("\nDados dos parts/peças salvos com sucesso no arquivo!\n");
  }
  else
  {
    printf("Erro ao abrir o arquivo para salvar os dados dos parts/peças.\n\n");
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
    printf("\nDados dos consumers/clientes salvos com sucesso no arquivo!\n");
  }
  else
  {
    printf("Erro ao abrir o arquivo para salvar os dados dos consumers/clientes.\n\n");
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

int read_integer_input_cpf(const char *prompt, int min_value, int max_value)
{
  char input[12];
  int value;

  while (true)
  {
    printf("%s", prompt);
    scanf("%11s", input);

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
    collaborator->cpf = read_integer_input_cpf("\nCPF do collaborator/colaborador: ", 0, 99999999999);
    printf("CPF modificado com sucesso!\n");
  case 2:
    read_string_input("\nNome completo do collaborator/colaborador: ", collaborator->full_name,
                      MAX_FULL_NAME_SIZE);
    printf("Nome modificado com sucesso!\n");
    break;
  case 3:
    read_string_input("\nData de nascimento do collaborator/colaborador: ", collaborator->date_birth,
                      MAX_DATE_FORMAT_SIZE);
    printf("Data de nascimento modificada com sucesso!\n");
    break;
  case 4:
    read_string_input("\nE-mail do collaborator/colaborador: ", collaborator->email_address,
                      MAX_EMAIL_ADDRESS_SIZE);
    printf("E-mail modificado com sucesso!\n");
    break;
  case 5:
    read_string_input("\nTelefone de contato do collaborator/colaborador: ", collaborator->phone_number,
                      MAX_PHONE_NUMBER_SIZE);
    printf("Telefone de contato modificado com sucesso!\n");
    break;
  case 6:
    read_string_input("\nEndereço residencial do collaborator/colaborador: ", collaborator->home_address,
                      MAX_HOME_ADDRESS_SIZE);
    printf("Endereço residencial modificado com sucesso!\n");
    break;
  case 7:
    read_string_input("\nCargo do collaborator/colaborador: ", collaborator->home_address,
                      MAX_OFFICE_SIZE);
    printf("Cargo modificado com sucesso!\n");
    break;
  case 8:
    collaborator->salary = read_double_input("\nSalário do collaborator/colaborador: ", 0.0, 99999.99);
    printf("Salário modificado com sucesso!\n");
    break;
  case 9:
    collaborator->total_sales_made = read_integer_input("Total de vendas do collaborator/colaborador: ", 0, 99999);
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
    supplier->cnpj = read_integer_input_cnpj("\nCNPJ do supplier/fornecedor: ", 0, 99999999999999);
    printf("CNPJ modificado com sucesso!\n");
  case 2:
    read_string_input("\nNome completo do supplier/fornecedor: ", supplier->full_name,
                      MAX_FULL_NAME_SIZE);
    printf("Nome modificado com sucesso!\n");
    break;
  case 3:
    read_string_input("\nCategoria da peça: ", supplier->part_category,
                      MAX_PART_CATEGORY_SIZE);
    printf("Categoria da peça modificada com sucesso!\n");
    break;
  case 4:
    read_string_input("\nE-mail do supplier/fornecedor: ", supplier->email_address,
                      MAX_EMAIL_ADDRESS_SIZE);
    printf("E-mail modificado com sucesso!\n");
    break;
  case 5:
    read_string_input("\nTelefone de contato do supplier/fornecedor: ", supplier->phone_number,
                      MAX_PHONE_NUMBER_SIZE);
    printf("Telefone de contato modificado com sucesso!\n");
    break;
  case 6:
    read_string_input("\nEndereço comercial do supplier/fornecedor: ", supplier->business_address,
                      MAX_BUSINESS_ADDRESS_SIZE);
    printf("Endereço comercial modificado com sucesso!\n");
    break;
  case 7:
    read_string_input("\nData do contrato do supplier/fornecedor: ", supplier->contract_date,
                      MAX_DATE_FORMAT_SIZE);
    printf("Data do contrato modificada com sucesso!\n");
    break;
  case 8:
    supplier->contract_price = read_double_input("\nPreço do contrato do supplier/fornecedor: ", 0.0, 99999.99);
    printf("Preço do contrato modificado com sucesso!\n");
    break;
  default:
    printf("Opção inválida. Nenhuma modificação realizada.\n");
    break;
  }
}

void modify_part_data(Part *part, Supplier *supplier_head)
{
  printf("\nOpções de modificação:\n");
  printf("1 - ID do Supplier/Fornecedor\n");
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
    int supplier_id;
    Supplier *existing_supplier;

    do
    {
      supplier_id = read_integer_input("\nID do supplier/fornecedor: ", 0, 999);
      existing_supplier = find_supplier_by_id(supplier_head, supplier_id);

      if (existing_supplier != NULL)
      {
        part->supplier_id = supplier_id;
        printf("ID do supplier/fornecedor modificado com sucesso!\n");
      }
      else
      {
        printf("\nID do supplier/fornecedor informado não existe. A lista de supplier/fornecedor está vazia ou o arquivo supplier.txt não foi carregado. Insira um ID existente ou cadastre um supplier/fornecedor\n");
      }
    } while (existing_supplier == NULL);
    break;
  case 2:
    read_string_input("\nNome da part/peça: ", part->full_name,
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
    consumer->cpf = read_integer_input_cpf("\nCPF do consumer/cliente: ", 0, 99999999999);
    printf("CPF modificado com sucesso!\n");
    break;
  case 2:
    read_string_input("\nNome do consumer/cliente: ", consumer->full_name,
                      MAX_FULL_NAME_SIZE);
    printf("Nome modificado com sucesso!\n");
    break;
  case 3:
    read_string_input("\nData de nascimento do consumer/cliente: ", consumer->date_birth,
                      MAX_DATE_FORMAT_SIZE);
    printf("Data de nascimento modificada com sucesso!\n");
    break;
  case 4:
    read_string_input("\nE-mail do consumer/cliente: ", consumer->email_address,
                      MAX_EMAIL_ADDRESS_SIZE);
    printf("E-mail modificado com sucesso!\n");
    break;
  case 5:
    read_string_input("\nTelefone de contato do consumer/cliente: ", consumer->phone_number,
                      MAX_PHONE_NUMBER_SIZE);
    printf("Telefone de contato modificado com sucesso!\n");
    break;
  case 6:
    read_string_input("\nEndereço residencial do consumer/cliente: ", consumer->home_address,
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
    strncpy(new_collaborator->full_name, token, MAX_FULL_NAME_SIZE - 1);
    if (new_collaborator->full_name[0] == '"')
    {
      memmove(new_collaborator->full_name, new_collaborator->full_name + 1,
              strlen(new_collaborator->full_name));
      new_collaborator->full_name[strlen(new_collaborator->full_name) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_collaborator->date_birth, token, MAX_DATE_FORMAT_SIZE - 1);
    if (new_collaborator->date_birth[0] == '"')
    {
      memmove(new_collaborator->date_birth, new_collaborator->date_birth + 1,
              strlen(new_collaborator->date_birth));
      new_collaborator->date_birth[strlen(new_collaborator->date_birth) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_collaborator->email_address, token, MAX_EMAIL_ADDRESS_SIZE - 1);
    if (new_collaborator->email_address[0] == '"')
    {
      memmove(new_collaborator->email_address, new_collaborator->email_address + 1,
              strlen(new_collaborator->email_address));
      new_collaborator->email_address[strlen(new_collaborator->email_address) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_collaborator->phone_number, token, MAX_PHONE_NUMBER_SIZE - 1);
    if (new_collaborator->phone_number[0] == '"')
    {
      memmove(new_collaborator->phone_number, new_collaborator->phone_number + 1,
              strlen(new_collaborator->phone_number));
      new_collaborator->phone_number[strlen(new_collaborator->phone_number) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_collaborator->home_address, token, MAX_HOME_ADDRESS_SIZE - 1);
    if (new_collaborator->home_address[0] == '"')
    {
      memmove(new_collaborator->home_address, new_collaborator->home_address + 1,
              strlen(new_collaborator->home_address));
      new_collaborator->home_address[strlen(new_collaborator->home_address) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_collaborator->office, token, MAX_OFFICE_SIZE - 1);
    if (new_collaborator->office[0] == '"')
    {
      memmove(new_collaborator->office, new_collaborator->office + 1,
              strlen(new_collaborator->office));
      new_collaborator->office[strlen(new_collaborator->office) - 1] = '\0';
    }

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
    strncpy(new_supplier->full_name, token, MAX_FULL_NAME_SIZE - 1);
    if (new_supplier->full_name[0] == '"')
    {
      memmove(new_supplier->full_name, new_supplier->full_name + 1,
              strlen(new_supplier->full_name));
      new_supplier->full_name[strlen(new_supplier->full_name) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_supplier->part_category, token, MAX_PART_CATEGORY_SIZE - 1);
    if (new_supplier->part_category[0] == '"')
    {
      memmove(new_supplier->part_category, new_supplier->part_category + 1,
              strlen(new_supplier->part_category));
      new_supplier->part_category[strlen(new_supplier->part_category) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_supplier->email_address, token, MAX_EMAIL_ADDRESS_SIZE - 1);
    if (new_supplier->email_address[0] == '"')
    {
      memmove(new_supplier->email_address, new_supplier->email_address + 1,
              strlen(new_supplier->email_address));
      new_supplier->email_address[strlen(new_supplier->email_address) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_supplier->phone_number, token, MAX_PHONE_NUMBER_SIZE - 1);
    if (new_supplier->phone_number[0] == '"')
    {
      memmove(new_supplier->phone_number, new_supplier->phone_number + 1,
              strlen(new_supplier->phone_number));
      new_supplier->phone_number[strlen(new_supplier->phone_number) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_supplier->business_address, token, MAX_BUSINESS_ADDRESS_SIZE - 1);
    if (new_supplier->business_address[0] == '"')
    {
      memmove(new_supplier->business_address, new_supplier->business_address + 1,
              strlen(new_supplier->business_address));
      new_supplier->business_address[strlen(new_supplier->business_address) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_supplier->contract_date, token, MAX_DATE_FORMAT_SIZE - 1);
    if (new_supplier->contract_date[0] == '"')
    {
      memmove(new_supplier->contract_date, new_supplier->contract_date + 1,
              strlen(new_supplier->contract_date));
      new_supplier->contract_date[strlen(new_supplier->contract_date) - 1] = '\0';
    }

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
    strncpy(new_part->full_name, token, MAX_FULL_NAME_SIZE - 1);
    if (new_part->full_name[0] == '"')
    {
      memmove(new_part->full_name, new_part->full_name + 1,
              strlen(new_part->full_name));
      new_part->full_name[strlen(new_part->full_name) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_part->car_model, token, MAX_CAR_MODEL_SIZE - 1);
    if (new_part->car_model[0] == '"')
    {
      memmove(new_part->car_model, new_part->car_model + 1,
              strlen(new_part->car_model));
      new_part->car_model[strlen(new_part->car_model) - 1] = '\0';
    }

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
    strncpy(new_consumer->full_name, token, MAX_FULL_NAME_SIZE - 1);
    if (new_consumer->full_name[0] == '"')
    {
      memmove(new_consumer->full_name, new_consumer->full_name + 1,
              strlen(new_consumer->full_name));
      new_consumer->full_name[strlen(new_consumer->full_name) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_consumer->date_birth, token, MAX_DATE_FORMAT_SIZE - 1);
    if (new_consumer->date_birth[0] == '"')
    {
      memmove(new_consumer->date_birth, new_consumer->date_birth + 1,
              strlen(new_consumer->date_birth));
      new_consumer->date_birth[strlen(new_consumer->date_birth) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_consumer->email_address, token, MAX_EMAIL_ADDRESS_SIZE - 1);
    if (new_consumer->email_address[0] == '"')
    {
      memmove(new_consumer->email_address, new_consumer->email_address + 1,
              strlen(new_consumer->email_address));
      new_consumer->email_address[strlen(new_consumer->email_address) - 1] = '\0';
    }

    token = strtok(NULL, ",");
    strncpy(new_consumer->phone_number, token, MAX_PHONE_NUMBER_SIZE - 1);
    if (new_consumer->phone_number[0] == '"')
    {
      memmove(new_consumer->phone_number, new_consumer->phone_number + 1,
              strlen(new_consumer->phone_number));
      new_consumer->phone_number[strlen(new_consumer->phone_number) - 1] = '\0';
    }

    token = strtok(NULL, ",");

    strncpy(new_consumer->home_address, token, MAX_HOME_ADDRESS_SIZE - 1);
    if (new_consumer->home_address[0] == '"')
    {
      memmove(new_consumer->home_address, new_consumer->home_address + 1,
              strlen(new_consumer->home_address));
      new_consumer->home_address[strlen(new_consumer->home_address) - 1] = '\0';
    }

    insert_consumer_in_list(head, new_consumer);
  }
}

void print_menu()
{
  int choice;

  printf("\n----- MENU -----\n");
  printf("1 - Adicionar collaborator/colaborador | supplier/funcionário | part/peça | consumer/cliente\n");
  printf("2 - Remover collaborator/colaborador | supplier/funcionário | part/peça | consumer/cliente\n");
  printf("3 - Listar collaborator/colaborador | supplier/funcionário | part/peça | consumer/cliente\n");
  printf("4 - Buscar collaborator/colaborador | supplier/funcionário | part/peça | consumer/cliente\n");
  printf("5 - Salvar dados dos collaborator/colaborador | supplier/funcionário | part/peça | consumer/cliente em arquivos\n");
  printf("0 - Sair\n");

  choice = ("\nEscolha uma opção de modificação: ", 0, 5);

  switch (choice)
  {
  case 0:
    printf("\nEncerrando o programa...\n");
    break;
  case 1:
    printf("\n----- MENU-ADICIONAR -----\n");
    printf("1 - Collaborator/colaborador");
    printf("2 - Supplier/funcionário");
    printf("3 - Part/peça");
    printf("4 - Consumer/cliente");
    break;
  case 2:
    printf("\n----- MENU-REMOVER -----\n");
    printf("1 - Collaborator/colaborador");
    printf("2 - Supplier/funcionário");
    printf("3 - Part/peça");
    printf("4 - Consumer/cliente");
    break;
  case 3:
    printf("\n----- MENU-LISTAR -----\n");
    printf("1 - Collaborator/colaborador");
    printf("2 - Supplier/funcionário");
    printf("3 - Part/peça");
    printf("4 - Consumer/cliente");
    break;
  case 4:
    printf("\n----- MENU-BUSCAR -----\n");
    printf("1 - Collaborator/colaborador");
    printf("2 - Supplier/funcionário");
    printf("3 - Part/peça");
    printf("4 - Consumer/cliente");
    break;
  case 5:
    printf("\n----- MENU-SALVAR -----\n");
    printf("1 - Collaborator/colaborador");
    printf("2 - Supplier/funcionário");
    printf("3 - Part/peça");
    printf("4 - Consumer/cliente");
    break;
  default:
    printf("Opção inválida. Nenhuma ação foi feita!.\n");
    break;
  }
}

int main(void)
{
  Node *head = NULL;

  int choice;
  char user_response[2];
  char choice_file_type[15];

  char file_relative_paths[4][MAX_RELATIVE_PATH_SIZE] = {
      "", // collaborators
      "", // suppliers
      "", // parts
      ""  // consumers
  };

  printf("\n----- BEM-VINDO AO SISTEMA AUTO PEÇAS PVT METE! -----\n");
  printf("\nVocê pode informar o caminho relativo dos seguintes arquivos: collaborators.txt | suppliers.txt | parts.txt | consumers.txt\n");

  do
  {
    read_string_input("\nDeseja informar o caminho relativo do arquivo? (s/n): ", user_response, sizeof(user_response));

    if (tolower(user_response[0]) != 's' && tolower(user_response[0]) != 'n')
    {
      printf("\nOpção inválida. Por favor, escolha uma opção válida (s/n).\n");
    }
    else if (tolower(user_response[0]) == 's')
    {
      read_string_input("\nDeseja informar o caminho relativo de qual arquivo? ", choice_file_type, sizeof(choice_file_type));

      int struct_type = -1;

      if (strcmp(choice_file_type, "collaborators") == 0 || strcmp(choice_file_type, "colaboradores") == 0)
      {
        struct_type = 1;
      }
      else if (strcmp(choice_file_type, "suppliers") == 0 || strcmp(choice_file_type, "fornecedores") == 0)
      {
        struct_type = 2;
      }
      else if (strcmp(choice_file_type, "parts") == 0 || strcmp(choice_file_type, "peças") == 0)
      {
        struct_type = 3;
      }
      else if (strcmp(choice_file_type, "consumers") == 0 || strcmp(choice_file_type, "consumidores") == 0)
      {
        struct_type = 4;
      }

      if (struct_type != -1)
      {
        char relative_path[MAX_RELATIVE_PATH_SIZE];
        read_string_input("\nCaminho relativo do arquivo de dados: ", relative_path, sizeof(relative_path));
        strcpy(file_relative_paths[struct_type], relative_path);

        FILE *file = fopen(relative_path, "r");
        if (file != NULL)
        {
          read_data_from_file(file, &head, struct_type);
          fclose(file);
        }
      }
      else
      {
        printf("\nTipo de arquivo inválido. Por favor, escolha uma opção válida.\n");
      }
    }
  } while (tolower(user_response[0]) != 's' && tolower(user_response[0]) != 'n');

  return 0;
}