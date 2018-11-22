// C program to insert and delete an element from a given array.

#include <stdio.h>
#include <stdlib.h>

const int max = 20;
int arr[20];
int i, size = 0;

// display function
void display()
{
  printf("\n");
  if (size == 0)
    printf("Empty !");
  else
    for (i = 0; i < size; i++)
      printf("%d  ", arr[i]);
  printf("\n");
}

// insert function
void insert()
{
  if (size == max)
    printf("\nOverflow");
  else
  {
    int value, pos;
    printf("Enter position (0 means first): ");
    scanf("%d", &pos);
    printf("\nEnter value : ");
    scanf("%d", &value);

    if (pos < 0 || pos > size)
      printf("\nInvalid position");
    else
    {
      for (i = size; i > pos; i--)
        arr[i] = arr[i - 1];
      arr[pos] = value;
      size++;
    }
  }
}

// delete function
void del()
{
  if (size == 0)
    printf("\nEmpty");
  else
  {
    int pos;
    printf("Enter position to delete (0 means first): ");
    scanf("%d", &pos);
    if (pos < 0 || pos >= size)
      printf("\nInvalid position");
    else
    {
      for (i = pos; i < size - 1; i++)
      {
        arr[i] = arr[i + 1];
      }
      size--;
    }
  }
}

int main()
{
  int choice;

  do
  {
    printf("\n\nEnter Choice : \n");
    printf("1.Insert\t2.Delete\t3.Display\t4.Exit\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      system("@cls||clear");
      insert();
      display();
      break;
    case 2:
      system("@cls||clear");
      del();
      display();
      break;
    case 3:
      system("@cls||clear");
      display();
      break;
    case 4:
      system("@cls||clear");
      return 0;
    default:
      system("@cls||clear");
      printf("\nWrong Choice\n");
    }
  } while (1);

  return 0;
}
