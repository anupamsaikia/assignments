#include <stdio.h>
#include <stdlib.h>

const int max = 10;
int queue[10];
int front = -1;
int rear = -1;

void insert(int value)
{
  if ((front == 0 && rear == max-1) || (front == rear + 1))
  {
    printf("Overflow");
  }

  else
  {
    if (front == -1)
    {
      front = rear = 0;
    }
    else if (rear = max-1)
    {
      rear = 0;
    }
    else
    {
      rear = rear + 1;
    }

    queue[rear] = value;
  }
}

void delete ()
{
  if (front == -1)
  {
    printf("Empty Queue");
  }
  else if (front == rear)
  {
    front = -1;
  }
  else
  {
    front--;
  }
}

void display()
{
  int i;
  for (i = 0; i < max; i++)
    printf("%d ", queue[i]);
}

int main()
{
  insert(5);
  insert(6);
  insert(5);
  insert(6);
  display();
}