#include <stdio.h>
#include <stdlib.h>

// defining the node
typedef struct node
{
  int info;
  struct node *llink;
  struct node *rlink;
} mynode;

mynode *start = NULL;

// display the list
void display()
{
  if (start == NULL)
    printf("\n\nEmpty List\n");
  else
  {
    mynode *ptr = start;
    printf("\n\nStart -> %d ->", ptr->info);
    while (ptr->rlink != NULL)
    {
      ptr = ptr->rlink;
      printf(" %d ->", ptr->info);
    }
    printf(" end\n");
  }
}

//insert at last position
void insert(int info)
{
  mynode *new = (mynode *)malloc(sizeof(mynode));

  new->info = info;
  new->rlink = NULL;
  new->llink = NULL;

  if (start == NULL)
    start = new;
  else
  {
    mynode *ptr = start;
    while (ptr->rlink != NULL)
      ptr = ptr->rlink;
    new->llink = ptr;
    ptr->rlink = new;
  }
}

// delete at last position
void del()
{
  if (start == NULL)
    printf("\n\nEmpty List\n");
  else
  {
    mynode *ptr = start;
    while (ptr->rlink != NULL)
      ptr = ptr->rlink;
    mynode *temp = ptr;

    // check if only one element is present
    if (ptr->llink == NULL)
    {
      start = NULL;
    }
    else
    {
      ptr = ptr->llink;
      ptr->rlink = NULL;
    }
    free(temp);
  }
}

// search an element and show its position
void search()
{
  if (start == NULL)
    printf("\n\nEmpty List\n");
  else
  {
    int item;
    printf("Enter element to search : ");
    scanf("%d", &item);
    int pos = 1;
    mynode *ptr = start;
    while (ptr->info != item && ptr->rlink != NULL)
    {
      ptr = ptr->rlink;
      pos++;
    }

    if (ptr->info == item)
    {
      //item found
      display();
      printf("\n\nElement found at position : %d\n", pos);
    }
    else
    {
      //item not found
      display();
      printf("\n\nElement not found\n");
    }
  }
}

int main()
{

  int choice, info;

  do
  {
    printf("\n\n\nEnter Choice : \n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit\n");
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
      display();
      break;
    case 3:
      system("@cls||clear");
      del();
      system("@cls||clear");
      display();
      break;
    case 4:
      system("@cls||clear");
      search();
      break;
    case 5:
      return 0;
    default:
      printf("\nWrong Choice\n");
    }

  } while (1);

  return 0;
}
