/* 
C program to implement single linked list and its various operations
Operations : 
  1. Display
  2. Insert at first
  3. Insert at last
  4. Insert after key
  5. Delete at first
  6. Delete at Last
  7. Delete element with given key info
  8. Search for given key info
*/

#include <stdio.h>
#include <stdlib.h>

// defining the node
typedef struct node
{
  int info;
  struct node *link;
} mynode;

mynode *start = NULL;

// display the linked list
void display()
{
  if (start == NULL)
    printf("\n\nEmpty List\n");
  else
  {
    mynode *ptr = start;
    printf("\n\nStart -> %d ->", ptr->info);
    while (ptr->link != NULL)
    {
      ptr = ptr->link;
      printf(" %d ->", ptr->info);
    }
    printf(" end\n");
  }
}

//insert a node at first position
void insertAtFirst(int info)
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

//insert a node at last position
void insertAtLast(int info)
{
  mynode *new = (mynode *)malloc(sizeof(mynode));

  new->info = info;
  new->link = NULL;

  if (start == NULL)
    start = new;
  else
  {
    mynode *ptr = start;
    while (ptr->link != NULL)
      ptr = ptr->link;
    ptr->link = new;
  }
}

//insert after given key
void insertAfterKey(int info, int key)
{
  mynode *new = (mynode *)malloc(sizeof(mynode));

  new->info = info;
  new->link = NULL;

  if (start == NULL)
    printf("\n\nCan't perform this operation");
  else
  {
    mynode *ptr = start;
    while (ptr->info != key && ptr->link != NULL)
      ptr = ptr->link;

    //If key not found
    if (ptr->info != key)
      printf("\n\nKey not Found\n");
    else
    {
      new->link = ptr->link;
      ptr->link = new;
    }
  }
}

// delete at first position
void deleteAtFirst()
{
  if (start == NULL)
    printf("\n\nCan't perform this operation");
  else
  {
    mynode *temp = start;
    start = start->link;
    free(temp);
  }
}

// delete at last position
void deleteAtLast()
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

// delete whose key info is given
void deleteKey(int key)
{
  if (start == NULL)
    printf("\n\nCan't perform this operation");
  else
  {
    mynode *ptr1 = start;
    mynode *ptr2 = NULL;

    while (ptr1->info != key && ptr1->link != NULL)
    {
      ptr2 = ptr1;
      ptr1 = ptr1->link;
    }

    //If key not found
    if (ptr1->info != key)
      printf("\n\nKey not Found");
    else
    {
      mynode *temp = ptr1;

      // check if element is in first position
      if (ptr2 == NULL)
        start = ptr1->link;
      else
        ptr2->link = ptr1->link;
      free(temp);
    }
  }
}

// search an element and show its position
void search()
{
  if (start == NULL)
    printf("\n\nEmpty List");
  else
  {
    int item;
    printf("Enter element to search : ");
    scanf("%d", &item);
    int pos = 1;
    mynode *ptr = start;
    while (ptr->info != item && ptr->link != NULL)
    {
      ptr = ptr->link;
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

  int choice, info, key;

  do
  {
    printf("\n\n\nEnter Choice : \n");
    printf("1.Insert at first\t2.Insert at last\t3.Insert after key\n");
    printf("4.Delete at first\t5.Delete at last\t6.Delete key\n");
    printf("7.Search for a key\t8.Display the List\t9.Exit\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("\nEnter value :");
      scanf("%d", &info);
      system("@cls||clear");
      insertAtFirst(info);
      display();
      break;
    case 2:
      printf("\nEnter value :");
      scanf("%d", &info);
      system("@cls||clear");
      insertAtLast(info);
      display();
      break;
    case 3:
      printf("\nEnter key :");
      scanf("%d", &key);
      printf("Enter value :");
      scanf("%d", &info);
      system("@cls||clear");
      insertAfterKey(info, key);
      display();
      break;
    case 4:
      system("@cls||clear");
      deleteAtFirst();
      display();
      break;
    case 5:
      system("@cls||clear");
      deleteAtLast();
      display();
      break;
    case 6:
      printf("\nEnter key :");
      scanf("%d", &key);
      system("@cls||clear");
      deleteKey(key);
      display();
      break;
    case 7:
      system("@cls||clear");
      search();
      break;
    case 8:
      system("@cls||clear");
      display();
      break;
    case 9:
      return 0;
    default:
      system("@cls||clear");
      printf("\nWrong Choice\n");
    }
  } while (1);

  return 0;
}
