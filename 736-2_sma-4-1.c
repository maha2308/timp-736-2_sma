#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
  struct node *prev;
} node;

typedef node* list;
typedef enum {false, true} bool;

list head=NULL;
list tail=NULL;

int init(list* root)
{
  *root = NULL;
  return 1;
}

bool isEmpty()
{
  if(head == NULL && tail == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int add(list* lst, int value)
{
  if ((*lst)==NULL)
  {
    list tmp = (list)malloc(sizeof(node));
    tmp->next=NULL;
    tmp->data=value;
    tmp->prev=NULL;
    head=tmp;
    tail=tmp;
    return 1;
  }
  else
  {
    list tmp = (list)malloc(sizeof(node));
    tmp->data = value;
    tmp->next = NULL;
    tmp->prev = tail;
    tail->next = tmp;
    tail = tmp;
    return 1;
  }
}

int decapitate ()
{
                if (isEmpty())
                {
                        return 0;
                }
        node *thisone = head;
        printf("%d \n", thisone->data);
        if(thisone==tail){
            head = NULL;
            tail=NULL;
            free(thisone);
            return 1;
        }
        thisone->next->prev = NULL;
        head = thisone->next;
        free(thisone);
        return 1;
}


int print (list *lst)
{
  list thisone;
  thisone= *lst;
  while (thisone!=NULL)
  {
    printf("%d", (thisone)->data);
    printf(" ");
    (thisone)=(thisone)->next;
  }
  printf("\n");
  return 1;
}

int main()
{
  int i,amount, data;
  init(&head);
  scanf("%d", &amount);
  for (i=0; i<amount; i++)
  {
    scanf("%d", &data);
    add(&tail, data);
  }
  print(&head);
  for (int i=0; i <= amount; i++)
       {
                decapitate();
                print(&head);
       }

  return 0;
}

