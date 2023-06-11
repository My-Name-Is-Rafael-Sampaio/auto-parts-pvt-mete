#include <stdio.h>
#include <stdlib.h>

#define MAX_FULL_NAME_SIZE 30
#define MAX_DATE_FORMAT_SIZE 10
#define MAX_EMAIL_ADDRESS_SIZE 50
#define MAX_PHONE_NUMBER_SIZE 14
#define MAX_HOME_ADDRESS_SIZE 30
#define MAX_OFFICE_SIZE 20
#define MAX_PART_CATEGORY_SIZE 20
#define MAX_BUSINESS_ADDRESS_SIZE 30
#define MAX_CAR_MODEL_SIZE 30

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

typedef struct Node
{
  void *data;
  struct Node *next;
} Node;

Node *create_node(size_t size)
{
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL)
  {
    printf("Erro ao alocar memória para o nó!\n");
    exit(1);
  }
  node->data = malloc(size);
  if (node->data == NULL)
  {
    printf("Erro ao alocar memória para o dado do nó!\n");
    exit(1);
  }
  node->next = NULL;
  return node;
}

Node *create_collaborator_node() { return create_node(sizeof(Collaborator)); }

Node *create_supplier_node() { return create_node(sizeof(Supplier)); }

Node *create_part_node() { return create_node(sizeof(Part)); }

Node *create_consumer_node() { return create_node(sizeof(Consumer)); }

int is_file_empty(const char *file_path)
{
  FILE *file = fopen(file_path, "r");
  if (file == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  int is_empty = 1;

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);

  if (file_size > 0)
  {
    is_empty = 0;
  }

  fclose(file);
  return is_empty;
}

void insert_data_into_list(Node **head, void *new_data, size_t data_size)
{
  Node *new_node = create_node(data_size);
  memcpy(new_node->data, new_data, data_size);

  if (*head == NULL)
  {
    *head = new_node;
  }
  else
  {
    Node *current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = new_node;
  }
}

void *find_entity_by_id(void *head, int id, size_t struct_size)
{
  char *current = (char *)head;
  while (current != NULL)
  {
    int current_id = *(int *)current;
    if (current_id == id)
    {
      return (void *)current;
    }
    current += struct_size;
  }
  return NULL;
}

void remove_entity(void **head, void *node)
{
  if (*head == node)
  {
    *head = ((struct Node *)node)->next;
  }
  else
  {
    struct Node *current = *head;
    while (current != NULL && current->next != node)
    {
      current = current->next;
    }
    if (current != NULL)
    {
      current->next = ((struct Node *)node)->next;
    }
  }
  free(node);
}

void print_entity_details(void *data, int index, const char *data_type)
{
  if (strcmp(data_type, "collaborator") == 0)
  {
    Collaborator *collaborator = (Collaborator *)data;
    printf("\n%d° Colaborador:\n", (index + 1));
    printf("ID -> %d\nCPF -> %d\nNome -> %s\nData de Nascimento -> %s\nEndereço de Email -> %s\nNúmero de Telefone -> %s\nEndereço Residencial -> %s\nCargo -> %s\nSalário -> %.2f\nTotal de Vendas -> %d\n",
           collaborator->id, collaborator->cpf, collaborator->full_name, collaborator->date_birth,
           collaborator->email_address, collaborator->phone_number, collaborator->home_address,
           collaborator->office, collaborator->salary, collaborator->total_sales_made);
  }
  else if (strcmp(data_type, "supplier") == 0)
  {
    Supplier *supplier = (Supplier *)data;
    printf("\n%d° Fornecedor:\n", (index + 1));
    printf("ID -> %d\nCNPJ -> %d\nNome -> %s\nCategoria da Peça -> %s\nEndereço de Email -> %s\nNúmero de Telefone -> %s\nEndereço Comercial -> %s\nData do Contrato -> %s\nPreço do Contrato -> %.2f\n",
           supplier->id, supplier->cnpj, supplier->full_name, supplier->part_category,
           supplier->email_address, supplier->phone_number, supplier->business_address,
           supplier->contract_date, supplier->contract_price);
  }
  else if (strcmp(data_type, "part") == 0)
  {
    Part *part = (Part *)data;
    printf("\n%d° Peça:\n", (index + 1));
    printf("ID -> %d\nID do Fornecedor -> %d\nNome -> %s\nModelo do Carro -> %s\nQuantidade -> %d\nPreço -> %.2f\n",
           part->id, part->supplier_id, part->full_name, part->car_model, part->amount, part->price);
  }
  else if (strcmp(data_type, "consumer") == 0)
  {
    Consumer *consumer = (Consumer *)data;
    printf("\n%d° Consumidor:\n", (index + 1));
    printf("ID -> %d\nCPF -> %d\nNome -> %s\nData de Nascimento -> %s\nEndereço de Email -> %s\nNúmero de Telefone -> %s\nEndereço Residencial -> %s\n",
           consumer->id, consumer->cpf, consumer->full_name, consumer->date_birth,
           consumer->email_address, consumer->phone_number, consumer->home_address);
  }
  else
  {
    printf("Tipo de dados não suportado.\n");
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

double read_double_input(const char *prompt, double min_value,
                         double max_value)
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

void read_field_with_quotes(char *token, char *dest, size_t dest_size)
{
  if (token[0] == '"')
  {
    memmove(dest, token + 1, strlen(token));
    dest[strlen(dest) - 1] = '\0';
  }
  else
  {
    strncpy(dest, token, dest_size - 1);
  }
}

void read_field_with_quotes(char *token, char *dest, size_t dest_size)
{
  if (token[0] == '"')
  {
    memmove(dest, token + 1, strlen(token));
    dest[strlen(dest) - 1] = '\0';
  }
  else
  {
    strlcpy(dest, token, dest_size);
  }
}

void read_common_data(char *token, void *node)
{
  read_field_with_quotes(token, node->full_name, MAX_FULL_NAME_SIZE);
  token = strtok(NULL, ",");
  read_field_with_quotes(token, node->date_birth, MAX_DATE_FORMAT_SIZE);
  token = strtok(NULL, ",");
  strncpy(node->email_address, token, MAX_EMAIL_ADDRESS_SIZE - 1);
  token = strtok(NULL, ",");
  strncpy(node->phone_number, token, MAX_PHONE_NUMBER_SIZE - 1);
}

void read_collaborator_data(char *token, Collaborator *new_node)
{
  new_node->id = atoi(token);
  token = strtok(NULL, ",");
  new_node->cpf = atoi(token);
  token = strtok(NULL, ",");
  read_common_data(token, new_node);
  token = strtok(NULL, ",");
  strncpy(new_node->home_address, token, MAX_HOME_ADDRESS_SIZE - 1);
  token = strtok(NULL, ",");
  strncpy(new_node->office, token, MAX_OFFICE_SIZE - 1);
  token = strtok(NULL, ",");
  new_node->salary = atof(token);
  token = strtok(NULL, ",");
  new_node->total_sales_made = atoi(token);
}

void read_supplier_data(char *token, Supplier *new_node)
{
  new_node->id = atoi(token);
  token = strtok(NULL, ",");
  new_node->cnpj = atoi(token);
  token = strtok(NULL, ",");
  read_common_data(token, new_node);
  token = strtok(NULL, ",");
  read_field_with_quotes(token, new_node->part_category, MAX_PART_CATEGORY_SIZE);
  token = strtok(NULL, ",");
  read_field_with_quotes(token, new_node->business_address, MAX_BUSINESS_ADDRESS_SIZE);
  token = strtok(NULL, ",");
  read_field_with_quotes(token, new_node->contract_date, MAX_DATE_FORMAT_SIZE);
  token = strtok(NULL, ",");
  new_node->contract_price = atof(token);
}

void read_part_data(char *token, Part *new_node)
{
  new_node->id = atoi(token);
  token = strtok(NULL, ",");
  new_node->supplier_id = atoi(token);
  token = strtok(NULL, ",");
  read_common_data(token, new_node);
  token = strtok(NULL, ",");
  read_field_with_quotes(token, new_node->car_model, MAX_CAR_MODEL_SIZE);
  token = strtok(NULL, ",");
  new_node->amount = atoi(token);
  token = strtok(NULL, ",");
  new_node->price = atof(token);
}

void read_consumer_data(char *token, Consumer *new_node)
{
  new_node->id = atoi(token);
  token = strtok(NULL, ",");
  new_node->cpf = atoi(token);
  token = strtok(NULL, ",");
  read_common_data(token, new_node);
  token = strtok(NULL, ",");
  strncpy(new_node->home_address, token, MAX_HOME_ADDRESS_SIZE - 1);
}

void read_data_from_file(FILE *file, void **head, int struct_type)
{
  char line[MAX_FULL_NAME_SIZE + 100];
  while (fgets(line, sizeof(line), file) != NULL)
  {
    void *new_node = NULL;
    char *token = strtok(line, ",");

    switch (struct_type)
    {
    case 1:
      new_node = create_collaborator_node();
      if (new_node != NULL)
      {
        read_collaborator_data(token, new_node);
      }
      break;
    case 2:
      new_node = create_supplier_node();
      if (new_node != NULL)
      {
        read_supplier_data(token, new_node);
      }
      break;
    case 3:
      new_node = create_part_node();
      if (new_node != NULL)
      {
        read_part_data(token, new_node);
      }
      break;
    case 4:
      new_node = create_consumer_node();
      if (new_node != NULL)
      {
        read_consumer_data(token, new_node);
      }
      break;
    }

    if (new_node != NULL)
    {
      insert_node(head, new_node, struct_type);
    }
  }
}

void save_collaborator_data(FILE *file, const Collaborator *collaborator)
{
  fprintf(file, "%d,%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",%.2f,%d\n",
          collaborator->id, collaborator->cpf, collaborator->full_name,
          collaborator->date_birth, collaborator->email_address,
          collaborator->phone_number, collaborator->home_address,
          collaborator->office, collaborator->salary,
          collaborator->total_sales_made);
}

void save_supplier_data(FILE *file, const Supplier *supplier)
{
  fprintf(file, "%d,%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",%.2f\n",
          supplier->id, supplier->cnpj, supplier->full_name,
          supplier->part_category, supplier->email_address,
          supplier->phone_number, supplier->business_address,
          supplier->contract_date, supplier->contract_price);
}

void save_part_data(FILE *file, const Part *part)
{
  fprintf(file, "%d,%d,\"%s\",\"%s\",%d,%.2f\n",
          part->id, part->supplier_id, part->full_name,
          part->car_model, part->amount, part->price);
}

void save_consumer_data(FILE *file, const Consumer *consumer)
{
  fprintf(file, "%d,%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
          consumer->id, consumer->cpf, consumer->full_name,
          consumer->date_birth, consumer->email_address,
          consumer->phone_number, consumer->home_address);
}

// function save_entity_data_to_file here

int main(void)
{
  printf("Hello World\n");
  return 0;
}