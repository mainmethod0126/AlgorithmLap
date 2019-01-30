#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  char op;
  int cum_add;
  int cum_minus;
  int cum_multifly;
  int cum_divide;
  struct node *child_add;
  struct node *child_minus;
  struct node *child_multifly;
  struct node *child_divide;
  struct node *parent_node;
}Node;

Node *make_node(Node *parent, char op, int cum_add, int cum_minus, int cum_multifly, int cum_divide){
  Node *node = (Node *)malloc(sizeof(Node));
  node->op = op;
  node->cum_add = cum_add;
  node->cum_minus = cum_minus;
  node->cum_multifly = cum_multifly;
  node->cum_divide = cum_divide;
  node->child_add = NULL;
  node->child_minus = NULL;
  node->child_multifly = NULL;
  node->child_divide = NULL;
  node->parent_node = parent;

  return node;
}
void init_nodes(Node *head, int N, int add, int minus, int multifly, int divide){
  if ( head->cum_add + head->cum_minus + head->cum_multifly + head->cum_divide > N ){
    return;
  }
  if ( head->cum_add < add ){
    head->child_add = make_node(head, '+', head->cum_add + 1, head->cum_minus, head->cum_multifly, head->cum_divide);
    init_nodes(head->child_add, N, add, minus, multifly, divide);
  }
  if ( head->cum_minus < minus ){
    head->child_minus = make_node(head, '-', head->cum_add, head->cum_minus + 1, head->cum_multifly, head->cum_divide);
    init_nodes(head->child_minus, N, add, minus, multifly, divide);
  }
  if ( head->cum_multifly < multifly ){
    head->child_multifly = make_node(head, '*', head->cum_add, head->cum_minus, head->cum_multifly + 1, head->cum_divide);
    init_nodes(head->child_multifly, N, add, minus, multifly, divide);
  }
  if ( head->cum_divide < divide ){
    head->child_divide = make_node(head, '/', head->cum_add, head->cum_minus, head->cum_multifly, head->cum_divide + 1);
    init_nodes(head->child_divide, N, add, minus, multifly, divide);
  }

}

int max = -1000000000;
int min = 1000000000;
char operator[10];

void calc_max(Node *head, int N, int number[11], int data){
  int idx = head->cum_add + head->cum_minus + head->cum_multifly + head->cum_divide;
  if ( idx > 0 ){
    operator[idx-1] = head->op;
  }
  if ( idx == N-1 ){
    int i = 0;
    int sum = number[0];
    for( i = 0; i < N-1; i++){
      switch (operator[i]) {
        case '+':
          sum += number[i+1];
          break;
        case '-':
          sum -= number[i+1];
          break;
        case '*':
          sum *= number[i+1];
          break;
        case '/':
          sum /= number[i+1];
          break;
        default:
          break;
      }
    }
    if ( max < sum ){
      max = sum;
    }
    if ( min > sum ){
      min = sum;
    }
    return;
  }

  if ( head->child_add != NULL ){
    calc_max(head->child_add, N, number, data + number[idx+1]);
  }
  if ( head->child_minus != NULL ){
    calc_max(head->child_minus, N, number, data - number[idx+1]);
  }
  if ( head->child_multifly != NULL ){
    calc_max(head->child_multifly, N, number, data * number[idx+1]);
  }
  if ( head->child_divide != NULL ){
    calc_max(head->child_divide, N, number, data / number[idx+1]);
  }
}

int main(){
  int N;
  int number[11];
  int add;
  int minus;
  int multifly;
  int divide;

  scanf("%d", &N);

  int i;
  for ( i = 0; i < N; i++){
    scanf("%d", &number[i]);
  }

  Node *head = make_node(NULL, '0', 0, 0, 0, 0);

  scanf("%d %d %d %d", &add, &minus, &multifly, &divide);
  init_nodes(head, N, add, minus, multifly, divide);
  calc_max(head, N, number, number[0]);

  printf("%d\n%d\n", max, min);

  return 0;
}
