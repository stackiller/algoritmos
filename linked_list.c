#include <stdio.h>
#include <stdlib.h>

/*

Because it is, is not the best example because in this case it would be better
to use an array because it is a logical sequence (the alphabet).

The key to using stringed list is that we can work with sequential values without
following a sequence and with sequences of varying sizes, other than the array it is
not necessary to make the declaration of a predefined size, even in the case of pointers.

Using linked lists besides offering more flexibility helps a lot when working with asynchronous
data that need to be arranged in a sequential xD list.

Author: aSynKronus

*/

/* struct node of linked list */
typedef struct no {
  char item; // node data.
  struct no *prox; // pointer to other node.
} *list; // pointer to linked list.

/* insert node at the top of the list */
void
insert(list *lp, char node_item)
{
  struct no *new_node = (struct no*) malloc(sizeof(struct no)); // allocates a new node.
  new_node->item = node_item; // assigns value to new node.
  new_node->prox = *lp; // saves the contents of the previous node into the current node.
  *lp = new_node; // assigns the value of the new node to the index of the beginning of the list ;
}

/* show the elements inside the list */
int
walk(list lp)
{  
  /* check if the current node is equal to null */
  if(lp == NULL)
  {
    printf("empty list\n");
    return 0;
  }

  struct no *cNode = lp; // current node.

  /* continue the loop while the current
  node is diffent from null */
  while(cNode != NULL)
  {
    printf("node: %c\n", cNode->item); // print the node item.
    cNode = cNode->prox; // assigns the next node to the current node.
  } return 0;
}

/* destroy the list */
int
destroy(list *lp)
{
  printf("list pointer address: %p\n", *lp); // print the current index pointer.
  struct no *current_node = *lp; // assign the contents of the start of the list to the current node.
  
  /* check if the current node is equal to null */
  if(current_node == NULL)
  {
    printf("empty list\n");
    return 0;
  }

  /* continue the loop while the current node is different from null */
  while(current_node != NULL)
  {
    printf("node pointer address: %p\n", current_node); // print the current index pointer.
    *lp = current_node->prox; // defines the contents of the initial index pointer of the list with the netx node.
    free(current_node); // release the current node.
    current_node = *lp; // assign the initial index pointer to the current node.
  } printf("last pointer address: %p\n", current_node); // print the last node pointer address.
  printf("list pointer address: %p\n", *lp); // and print the last list index pointer address. 
  return 0;
}

int
main(int argc, char *argv[])
{
  list L = NULL;

  for(int i=65; i <= 90; i++)
    insert(&L, (char)i); // inserts the alphabet into the linked list ().

  walk(L); // walk the list
  destroy(&L); // destroy the list
  return 0;
}