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

//insert after given position
void insertAt(int info, int pos)
{
  // pos value meanings: -1 = at last, 0 = at first, n = after nth position

  mynode *new = (mynode *)malloc(sizeof(mynode));

  new->info = info;
  new->rlink = NULL;
  new->llink = NULL;

  if(pos == 0){
    //insert at first position
    if (start == NULL)
      start = new;
    else
    {
      new->rlink = start;
      start->llink = new;
      start = new;
    }
  }
  else if(pos == -1){
    //insert at last position
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
  else{
    int i = 1;
    mynode *ptr = start;
    while(i<pos && ptr!=NULL){
      if(ptr->rlink == NULL)
        break;
      ptr = ptr->rlink;
      i++;
    }

    //check empty condition
    if(ptr == NULL)
      printf("Position not Valid");
    else if(i==pos){
      if(ptr->rlink == NULL)
      {
        //last position
        new->llink = ptr;
        new->rlink = NULL;
        ptr->rlink = new;
      }
      else
      {
        //not last position
        new->llink = ptr;
        new->rlink = ptr->rlink;
        ptr->rlink = new;
      }
    }
    else
      printf("Position not Valid");
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

  int choice, info, pos;

  do
  {
    printf("\n\n\nEnter Choice : \n1.Insert\n2.Insert at particular position\n3.Display\n4.Delete\n5.Search\n6.Exit\n");
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
      printf("\nEnter position :");
      scanf("%d", &pos);
      printf("Enter value :");
      scanf("%d", &info);
      system("@cls||clear");
      insertAt(info, pos);
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
      system("@cls||clear");
      search();
      break;
    case 6:
      return 0;
    default:
      printf("\nWrong Choice\n");
    }

  } while (1);

  return 0;
}


