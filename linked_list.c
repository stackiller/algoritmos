#include <stdio.h>
#include <stdlib.h>

/* struct node of linked list */
typedef struct no {
  char item; // node data
  struct no *prox; // pointer to other node
} *list; // pointer to linked list

/* insert node at the top of the list */
void
insert(list *lp, char node_item)
{
  struct no *new_node = (struct no*) malloc(sizeof(struct no)); // allocates a new node
  new_node->item = node_item; // assigns value to new node
  new_node->prox = *lp; // saves the contents of the previous node into the current node;
  *lp = new_node; // ;
}

/* percorrer os elementos da minha lista */
int
walk(struct no lp)
{  

  if(lp.prox == NULL)
  {
    printf("last item: %c\n", lp.item);
    printf("lista vazia\n");
    return 0;
  }

  struct no *cNode = &lp; // node atual
  
  while(cNode->prox != NULL)
  {
    printf("node: %c\n", cNode->item);
    *cNode = *(cNode->prox);
  } return 0;
}

/* destroi a lista */
void
destroy(list *lp)
{
  struct no *current_node = *lp;
  while(current_node->prox != NULL)
  {
    free(*lp);
    *lp = current_node->prox;
    current_node = *lp;
  }
}

int
main(int argc, char *argv[])
{
  list L = NULL; // primeiro elemento armazena o valor NULL

  for(int i=64; i <= 90; i++)
    insert(&L, (char)i);

  walk(*L);
  return 0;
}