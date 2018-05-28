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

int destroy(list* root)
{
  list thisone, t;
  thisone=*root;
  t=*root;
  while (thisone!=NULL)
  {
    t=thisone->next;
    free (thisone);
    thisone=t;
  }
  *root = NULL;
  return 1;
}
bool isEmpty(list root)
{
  if(root == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int append(list* lst, int value)
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
  list tmp = malloc(sizeof(node));
  tmp->data=value;

  tmp->prev=(*lst);
  if((*lst) == tail)
  {
    tmp->next=NULL;
    ((*lst)->next) = tmp;
    tail = (*lst)-> next;
  }
  else
  {
    tmp->next=((*lst)->next);
    ((*lst)->next)->prev=tmp;
    ((*lst)->next)=tmp;
  }
  return 1;
}

int prepend(list* lst, int value)
{
  if ((*lst) == NULL)
  {
    list tmp = (list)malloc(sizeof(node));
    tmp->next=NULL;
    tmp->data=value;
    tmp->prev=NULL;
    head=tmp;
    tail=tmp;
    return 1;
  }	

  list tmp = malloc(sizeof(node));
  tmp -> data = value;
  tmp-> next = (*lst);
  if((*lst)==head)
  {
    tmp->prev=NULL;
    (*lst)->prev=tmp;
    head=(*lst)->prev;
  }
  else
  {
    tmp->prev=(*lst)->prev;
    ((*lst)->prev)->next=tmp;
    (*lst)->prev=tmp;
  }
  return 1;
}

int removel(list *lst)
{
  list thisone = (*lst);
  if ((*lst)==head)
  {
    ((*lst)->next)->prev = NULL;
    head = ((*lst)->next);
    free((thisone));
  }
  else if ((*lst)==tail)
  {
    ((*lst)->prev)->next=NULL;
    tail=((*lst)->prev);
    free((thisone));
  }
  else
  {
    ((*lst)->next)->prev=((*lst)->prev);
    ((*lst)->prev)->next=((*lst)->next);
    free((thisone));
  }
  return 1;
}
int removeposition(list *lst, int k)
{
  list tmp, headoftry;
  int ancounter=1;
  tmp=(*lst);
  while(true)
  {
    if(ancounter==k)
    {
      removel(&tmp);
      break;
    }
    (tmp)=(tmp)->next;
    ancounter++;
  };
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
  int i,data,amount,remposition,remelt,pushelt,pushvalue;
  init(&head);
  scanf("%d", &amount);
  for (i=0; i<amount; i++)
  {
    scanf("%d", &data);
    append(&tail, data);
  }
  print(&head);
  scanf("%d", &remposition);
  removeposition(&head, remposition);
  print(&head);
  scanf("%d", &remelt);
  list dud=head;
  while(true)
  {
    if(dud->data==remelt)
    {
      removel(&dud);
      break;
    }
    dud=dud->next;
  }
  dud=NULL;
  print(&head);
  scanf("%d", &pushelt);
  scanf("%d", &pushvalue);
  dud = head;
  for (i=1; i<(pushelt); i++)
  {
    dud=(dud->next);
  }
  append(&dud,pushvalue);
  dud=NULL;
  print(&head);
  scanf("%d", &pushelt);
  scanf("%d", &pushvalue);
  dud = head;
  for (i=1; i<(pushelt); i++)
  {
    dud=(dud->next);
  }
  prepend(&dud,pushvalue);
  dud=NULL;
  print(&head);
  return 0;
}
