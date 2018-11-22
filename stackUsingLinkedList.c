// C program to implement stack using array

#include <stdio.h>
#include <stdlib.h>

// defining the node
typedef struct node
{
  int info;
  struct node *link;
} mynode;

mynode *top = NULL;

void push(int info)
{
  mynode *new = (mynode *)malloc(sizeof(mynode));

  new->info = info;
  new->link = NULL;

  if (top == NULL)
    top = new;
  else
  {
    new->link = top;
    top = new;
  }
}

void pop()
{
  if (top == NULL)
    printf("\n\nCan't perform this operation");
  else
  {
    mynode *temp = top;
    top = top->link;
    free(temp);
  }
}

void display()
{
  if (top == NULL)
    printf("\n\nEmpty Stack\n");
  else
  {
    mynode *ptr = top;
    printf("\n\nTop -> %d |", ptr->info);
    while (ptr->link != NULL)
    {
      ptr = ptr->link;
      printf(" %d |", ptr->info);
    }
  }
}

int main()
{
  int choice, info;
  do
  {
    printf("\n\n\nEnter Choice : \n");
    printf("1.Push to stack\t\t2.Pop from stack\t3.Exit\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("\nEnter value :");
      scanf("%d", &info);
      system("@cls||clear");
      push(info);
      display();
      break;
    case 2:
      system("@cls||clear");
      pop();
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
}