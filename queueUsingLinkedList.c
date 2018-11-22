// C program to implement queue using linked list

#include <stdio.h>
#include <stdlib.h>

// defining the node
typedef struct node
{
  int info;
  struct node *link;
} mynode;

mynode *start = NULL;

// display the queue
void display()
{
  if (start == NULL)
    printf("\n\nEmpty List\n");
  else
  {
    mynode *ptr = start;
    printf("\n\nRear -> %d ->", ptr->info);
    while (ptr->link != NULL)
    {
      ptr = ptr->link;
      printf(" %d ->", ptr->info);
    }
    printf(" Front\n");
  }
}

//insert a node at rear position
void insert(int info)
{
  mynode *new = (mynode *)malloc(sizeof(mynode));

  new->info = info;
  new->link = NULL;

  if (start == NULL)
    start = new;
  else
  {
    new->link = start;
    start = new;
  }
}

// delete at front position
void delete ()
{
  if (start == NULL)
    printf("\n\nCan't perform this operation");
  else
  {
    mynode *ptr1 = start;
    mynode *ptr2 = NULL;

    while (ptr1->link != NULL)
    {
      ptr2 = ptr1;
      ptr1 = ptr1->link;
    }

    mynode *temp = ptr1;

    // check if only one element is present
    if (ptr1 == start)
      start = NULL;
    else
      ptr2->link = NULL;
    free(temp);
  }
}

int main()
{

  int choice, info, key;

  do
  {
    printf("\n\n\nEnter Choice : \n");
    printf("1.Insert\t2.Delete\t3.Exit\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("\nEnter value :");
      scanf("%d", &info);
      system("@cls||clear");
      insert(info);
      display();
      break;
    case 2:
      system("@cls||clear");
      delete ();
      display();
      break;
    case 3:
      system("@cls||clear");
      return 0;
    default:
      system("@cls||clear");
      printf("\nWrong Choice\n");
    }
  } while (1);

  return 0;
}
