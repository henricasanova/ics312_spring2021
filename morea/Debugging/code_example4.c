#include <stdio.h>
#include <stdlib.h>

struct dllist {
 int value;
 struct dllist *next;
 struct dllist *prev;
};

struct dllist *head, *tail;

void print_list(struct dllist *head);
void append_node(struct dllist *lnode);
void insert_node(struct dllist *lnode, struct dllist *after);
void remove_node(struct dllist *lnode);

int main(void) {
 struct dllist *lnode;
 int i = 0;
 struct  dllist *node_three;

 printf("---- Testing Double-Linked List Implementation ----\n");
 /* add some values to the double linked list */
 printf("Node insertions...\n");
 for(i = 0; i <= 5; i++) {
  printf("\tAppending a node with value '%d'\n",i);
  lnode = (struct dllist *)malloc(sizeof(struct dllist));
  lnode->value = i;
  append_node(lnode);
  // Remember node 3
  if (i == 3) { 
    node_three = lnode;
    printf("\tKeeping a pointer to the node that contains value '%d'\n",i);
  }
 }

 printf("Printing the content of the list...\n");
 /* print the dll list */
 print_list(head);

  printf("Inserting a node with value 12 after the node with value 3...\n");
  lnode = (struct dllist *)malloc(sizeof(struct dllist));
  lnode->value = 12;
  insert_node(lnode, node_three);
  print_list(head);


 printf("Removing the node that contains value 3...\n");
 remove_node(node_three);
 print_list(head);

 /* destroy the dll list */
 printf("Destroying the list one node at a time...\n");
 while(head != NULL) {
   remove_node(head);
   print_list(head);
 }

 return 0;
}

void print_list(struct dllist *head) {
 struct dllist *lnode;
 printf("\t list: ");
 for(lnode = head; lnode != NULL; lnode = lnode->next) {
  printf("%d ", lnode->value);
 }
 printf("\n");
 return;
}

void append_node(struct dllist *lnode) {
 if(head == NULL) {
  head = lnode;
  lnode->prev = NULL;
 } else {
  tail->next = lnode;
  lnode->prev = tail;
 }

 lnode->next = NULL;
}

void insert_node(struct dllist *lnode, struct dllist *after) {
 lnode->next = after->next;
 lnode->prev = after;

 if(after->next != NULL)
   after->next->prev = lnode;
 else
   tail = lnode;
}

void remove_node(struct dllist *lnode) {
 if(lnode->prev == NULL)
   head = lnode->next;
 else
   lnode->prev->next = lnode->next;

 if(lnode->next == NULL)
  tail = lnode->prev;
 else
  lnode->next->prev = lnode->prev;
}

