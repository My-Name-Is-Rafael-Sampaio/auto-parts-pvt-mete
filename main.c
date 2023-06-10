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

void insert(Node **head, void *new_data, size_t data_size)
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

int main(void)
{
  printf("Hello World\n");
  return 0;
}