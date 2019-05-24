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

/* show the elements inside the list */
int
walk(list lp)
{  
  if(lp == NULL)
  {
    printf("empty list\n");
    return 0;
  }

  struct no *cNode = lp; // current node

  while(cNode != NULL)
  {
    printf("node: %c\n", cNode->item);
    cNode = cNode->prox;
  } return 0;
}

/* destroy the list */
int
destroy(list *lp)
{
  printf("list pointer address: %p\n", *lp);
  struct no *current_node = *lp;
  if(current_node == NULL)
  {
    printf("empty list\n");
    return 0;
  }
  while(current_node != NULL)
  {
    printf("node pointer address: %p\n", current_node);
    *lp = current_node->prox;
    free(current_node);
    current_node = *lp;
  } printf("last pointer address: %p\n", current_node);
  printf("list pointer address: %p\n", *lp);
  return 0;
}

int
main(int argc, char *argv[])
{
  list L = NULL;

  for(int i=65; i <= 90; i++)
    insert(&L, (char)i);

  walk(L);
  destroy(&L);
  return 0;
}