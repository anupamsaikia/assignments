// C pogram to implement queue using array

#include <stdio.h>
#include <stdlib.h>

const int max = 10;
int queue[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int front = -1;
int rear = -1;

void insert(int value)
{
  if ((front == 0 && rear == max - 1) || (front == rear + 1))
    printf("Overflow");
  else
  {
    if (front == -1)
      front = rear = 0;
    else if (rear == max - 1)
      rear = 0;
    else
      rear++;
    queue[rear] = value;
  }
}

void delete ()
{
  if (front == -1)
    printf("Empty Queue");
  else if (front == rear)
    front = rear = -1;
  else if (front == max-1)
    front = 0;
  else
    front++;
}

void display()
{
  int i;
  if (front == -1)
    printf("\n\nEmpty Queue\n");
  else if (rear < front)
  {
    for (i = front; i < max; i++)
      printf("%d ", queue[i]);
    for (i = 0; i <= rear; i++)
      printf("%d ", queue[i]);
  }
  else
  {
    for (i = front; i <= rear; i++)
      printf("%d ", queue[i]);
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