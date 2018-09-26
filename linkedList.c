#include <stdio.h>
#include <stdlib.h>

// defining the node
typedef struct node
{
  int info;
  struct node *link;
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
    while (ptr->link != NULL)
    {
      ptr = ptr->link;
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
    printf("\n\nEmpty List\n");
  else {
    mynode *ptr = start;
    while (ptr->info != key && ptr->link != NULL)
      ptr = ptr->link;
    
    //If key not found
    if(ptr->info != key)
      printf("\n\nKey not Found\n");
    else {
      new->link = ptr->link;
      ptr->link =new;
    }
  }

}


// delete at last position
void del()
{
  if (start == NULL)
    printf("\n\nEmpty List\n");
  else
  {
    mynode *ptr1 = start;
    mynode *ptr2 = NULL;

    while (ptr1->link != NULL) {
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
void delKey(key)
{
  if (start == NULL)
    printf("\n\nEmpty List\n");
  else
  {
    mynode *ptr1 = start;
    mynode *ptr2 = NULL;

    while (ptr1->info != key && ptr1->link != NULL) {
      ptr2 = ptr1;
      ptr1 = ptr1->link;
    }

    //If key not found
    if(ptr1->info != key)
      printf("\n\nKey not Found\n");
    else {
      mynode *temp = ptr1;

      // check if only one element is present
      if (ptr1 == start && ptr1->link == NULL)
        start = NULL;
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
    printf("\n\nEmpty List\n");
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
    printf("\n\n\nEnter Choice : \n1.Insert\n2.Insert after key\n3.Display\n4.Delete last\n5.Delete key\n6.Search\n7.Exit\n");
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
      printf("\nEnter key :");
      scanf("%d", &key);
      printf("Enter value :");
      scanf("%d", &info);
      system("@cls||clear");
      insertAfterKey(info, key);
      display();
      break;
    case 3:
      system("@cls||clear");
      display();
      break;
    case 4:
      system("@cls||clear");
      del();
      system("@cls||clear");
      display();
      break;
    case 5:
    printf("\nEnter key :");
      scanf("%d", &key);
      delKey(key);
      system("@cls||clear");
      display();
      break;
    case 6:
      system("@cls||clear");
      search();
      break;
    case 7:
      return 0;
    default:
      printf("\nWrong Choice\n");
    }

  } while (1);

  return 0;
}


