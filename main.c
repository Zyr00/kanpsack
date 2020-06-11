#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int val; /* valore */
  int wt; /* peso */
} item;

void clean_input_buffer();
void read_int(int *, char *);
void menu(int *, item *, int, item *, int, item *, int, item *, int *);
void sub_menu(int, item *, int *);
void gen(item **, int *, int);
void print_list(item [], int);
void run(int, item *, int);
int max(int, int);
int knap_sack(int, item [], int, int *);

/**
  @brief programa principal @warging Valores
  a cima 10000 dão core dump (linha 123), se o tamanho da
  mochila (W) for 50 ou acima se for um
  numero baixo como 5 já da até um certo limit
  @return 0 sempre que chega ao fim sem erros
*/
int main (void) {
  /* Lista de Objetos para adicionar */
  item list_1[] = {
    { 10, 3 }, { 13, 13 }, { 32, 7 }, { 34, 8 }, { 92, 3 },
    { 22, 12 }, { 9, 5 }, { 32, 9 }, { 43, 9 }, { 5, 8 } };
  int size_1 = 10;
  item list_2[] = {
    { 10, 3 }, { 13, 13 }, { 32, 7 }, { 34, 8 }, { 92, 3 },
    { 22, 12 }, { 9, 5 }, { 32, 9 }, { 43, 9 }, { 5, 8 },
    { 10, 13 }, { 18, 11 }, { 27, 7 }, { 29, 9 }, { 29, 3 },
    { 9, 13 }, { 13, 7 }, { 29, 9 }, { 10, 9 }, { 15, 8 } };
  int size_2 = 20;
  item list_3[] = {
    { 10, 3 }, { 13, 13 }, { 32, 7 }, { 34, 8 }, { 92, 10 },
    { 22, 12 }, { 9, 5 }, { 32, 9 }, { 43, 9 }, { 5, 8 },
    { 10, 7 }, { 17, 8 }, { 30, 8 }, { 17, 6 }, { 12, 8 },
    { 20, 17 }, { 9, 5 }, { 32, 9 }, { 23, 9 }, { 8, 3 },
    { 10, 13 }, { 18, 11 }, { 27, 7 }, { 29, 9 }, { 29, 3 },
    { 9, 13 }, { 13, 7 }, { 29, 9 }, { 10, 9 }, { 15, 8 } };
  int size_3 = 30;
  item *list_4 = NULL;
  int size_4 = 0;

  /* tamanho da mochila */
  int W = 50;

  srand(time(NULL));

  menu(&W, list_1, size_1, list_2, size_2, list_3, size_3, list_4, &size_4);
  free(list_4);

  return 0;
}

/**
  * @brief Limpa o buffer de entrada de dados.
  * @warning Caso não exista nenhuma informação no buffer, o programa pode
  * ficar a aguardar que exista informação no buffer
*/
void clean_input_buffer() {
  char ch;
  while((ch = getchar()) != '\n' && ch != EOF);
}

/**
 * @brief metodo para ler uma int do stdin
 * @param r a referencia onde vai ser guardado o valor lido
 * @param m uma mensagem em caso de erro
*/
void read_int(int *r, char *m) {
    while(scanf("%d", r) != 1) {
      printf("Valor Invalido\n%s", m);
      clean_input_buffer();
    }
    clean_input_buffer();
}

/**
 * @brief metodo para o menu da aplicação
 * @param list_1 lista 1
 * @param size_1 o tamanho da lista 1
 * @param list_2 lista 2
 * @param size_2 o tamanho da lista 2
 * @param list_3 lista 3
 * @param size_3 o tamanho da lista 3
 * @param list_4 lista 4
 * @param size_4 o tamanho da lista 4
*/
void menu(int *W, item *list_1, int size_1, item *list_2, int size_2,
    item *list_3, int size_3, item *list_4, int *size_4) {
  int op;

  do {
    printf("################\n");
    printf("###   MENU   ###\n");
    printf("################\n");
    printf("1 - lista 1\n");
    printf("2 - lista 2\n");
    printf("3 - lista 3\n");
    printf("4 - Lista costumizada\n");
    printf("5 - Mudar tamanho mochila\n");
    printf("0 - Sair\n");
    printf("Escolher opção: ");

    read_int(&op, "Escolher opção: ");

    switch(op) {
      case 0: printf("\nA sair...\n"); break;
      case 1: run(*W, list_1, size_1); break;
      case 2: run(*W, list_2, size_2); break;
      case 3: run(*W, list_3, size_3); break;
      case 4:
              sub_menu(*W, list_4, size_4);
              break;
      case 5:
              printf("\nTamanho atual: %d\n", *W);
              printf("Novo tamanho: ");
              read_int(W, "Novo tamanho: ");
              printf("\n");
              break;
      default: printf("\nOpção invalida\n");
    }
  } while (op != 0);
}

/**
 * @brief um sub-menu para criar uma lista de items
 * @param W peso da mochila
 * @param *list_4 referencia para a lista
 * @param *size_4 referencia para o tamanho
*/
void sub_menu(int W, item *list_4, int *size_4) {
  int sub_op;

  do {
    printf("\n1 - Criar lista\n");
    printf("2 - Imprimir items\n");
    printf("3 - Gerar lista automaticamente\n");
    printf("4 - Currer lista\n");
    printf("0 - Sair\n");
    printf("Escolher opção: ");

    read_int(&sub_op, "Escolher opção: ");

    switch(sub_op) {
      case 0: printf("\nA sair...\n"); break;
      case 1:
              gen(&list_4, size_4, 0);
              break;
      case 2:
              if (*size_4 > 0)
                print_list(list_4, *size_4);
              else
                printf("Lista vazia\n");
              break;
      case 3:
              gen(&list_4, size_4, 1);
              break;
      case 4:
              run(W, list_4, *size_4);
              break;
      default: printf("\nOpção Invalida\n");
    }
  } while (sub_op != 0);
}

/**
 * @brief metodo que cria uma array do tipo item com valores aleatorios
 * para o valor (1-30) como para o peso (1-10)
 * @param items a lista de items
 * @param size o tamanho da lista
 * @param gen 1 ou 0 para ver se é automatico ou manual
*/
void gen(item **items, int *size, int gen) {
  int i, val, wt;

  printf("Tamanho lista: ");
  read_int(size, "Tamanho lista: ");

  *items = (item *) malloc(sizeof(item) * (*size));

  if (items != NULL) {
    for (i = 0; i < *size; i++) {
      if (gen == 1) {
        (*items)[i].val = (rand() % 30) + 1;
        (*items)[i].wt  = (rand() % 10) + 1;
      } else {
        printf("Introduza o valor: ");
        read_int(&val, "Introduza o valor: ");
        printf("Introduza o peso: ");
        read_int(&wt, "Introduza o peso: ");
        (*items)[i].val = val;
        (*items)[i].wt = wt;
      }
    }
    printf("Lista gerada\n");
  } else {
    printf("Erro ao gerar lista\n");
  }
}

/**
 * @brief metodo para imprirmir lista de items
 * @param items a lista de items para imprimir
 * @param size o tamanho da lista para imprimir
*/
void print_list(item items[], int size) {
  int i;

  printf("\nLista\n");
  for (i = 0; i < size; i++) {
    printf("[%2d] Valor: %2d, Peso: %2d\n", i + 1, items[i].val, items[i].wt);
  }
}

/**
 * @brief metodo para correr os testes
 * @param W a capacidade da mochila
 * @param items a lista de itemetos
 * @param size o tamanho da lista
*/
void run(int W, item items[], int size) {
  clock_t start, finish;
  int solution, count = 0;

  print_list(items, size);

  start = clock();
  solution = knap_sack(W, items, size, &count);
  finish = clock();

  printf("\nSolution: %d\n", solution);
  printf("Time execution: %f \n", (double) (finish - start) / CLOCKS_PER_SEC);
  printf("Operações Executadas: %d\n", count);
  printf("Big O (size * W): %d * %d = %d\n\n", size, W, size * W);
}

/**
 * @brief calcular o maximo entre dois numeros Big O(1)
 * @param a um valor para ser comparado
 * @param b um valor para ser comparado
 * @return o valor maior entre a e b
*/
int max (int a, int b) { return (a > b) ? a : b; }

/**
 * @brief Big O of (size * W)
 * @param W a capacidade da mochila
 * @param items a lista de itemetos para adicionar a mochila
 * @param size o tamanho da lista de itemetos
 * @return o valor maximo que se pode colocar na mochila com capacidade de @param W
*/
int knap_sack(int W, item items[], int n, int *count) {
  int i, j, K[n + 1][W + 1];

  if (n == 0 || W == 0) {
    (*count)++;
    return 0;
  }

  /* construir a K[][] de baixo para cima O(size * W)*/
  for (i = 0; i <= n; i++) { /* O(size) */
    (*count)++;
    for (j = 0; j <= W; j++) { /* O(W) */
      (*count)++;
      if (i == 0 || j == 0)
        K[i][j] = 0; /* O(1) */
      else if (items[i - 1].wt <= j)
        K[i][j] = max(items[i - 1].val + K[i - 1][j - items[i - 1].wt], K[i - 1][j]); /* O(1) */
      else
        K[i][j] = K[i - 1][j]; /* O(1) */
      (*count)++;
    }
    (*count)++;
  }

  (*count)++;
  return K[n][W];
}
