#include <stdio.h>
#include <stdlib.h>

const int max = 10;
int top = -1;
int stack[10];

void push(int value)
{
  if(top == max - 1)
    printf("\nStack is full");
  else{
    top++;
    stack[top] = value;
  }
}

void pop()
{
  if (top == -1)
    printf("\nCan't perform this operation");
  else
    top--;
}

void display()
{
  if (top == -1)       
    printf("\nEmpty Stack\n");
  else
  {
    int i = top;
    printf("\nTop -> %d |", stack[i]);
    i--;
    while (i>=0)
    {
      printf(" %d |", stack[i]);
      i--;
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