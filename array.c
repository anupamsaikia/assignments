#include <stdio.h>
#include <stdlib.h>

int max = 20;
int arr[20];
int i;

//to get length of the array
int getLength(){
  for(i = 0; arr[i] != NULL; i++);
  return i;
}

//to display the array
void display(){
  printf("\n");
  for(i = 0; arr[i] != NULL; i++)
    printf("%d  ", arr[i]);
  printf("\n");
}

//insert
void insert(){
  if(getLength() == max)
    printf("\nOverflow");
  else{
    int value, pos;
    printf("\nEnter value : ");
    scanf("%d", &value);
    printf("Enter position : ");
    scanf("%d", &pos);
    if(pos <= 0 || pos-1>getLength())
      printf("\nInvalid position");
    else{
      for(i = getLength(); i>pos-1; i--)
        arr[i] = arr[i-1];
      arr[pos-1] = value;
    }
  }
}

void del(){
  if(getLength() == 0)
    printf("\nEmpty");
  else{
    int pos;
    printf("Enter position : ");
    scanf("%d", &pos);
    if(pos <= 0 || pos>getLength())
      printf("\nInvalid position");
    else{
      for(i = pos - 1; i<getLength(); i++){
        printf("test");
        arr[i] = arr[i+1];
      }
        
    }
  }
}


int main(){
  int choice;

  do
  {
    printf("\n\nEnter Choice : \n");
    printf("1.Insert\t2.Delete\t3.Exit\n");
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
      return 0;
    default:
      system("@cls||clear");
      printf("\nWrong Choice\n");
    }
  } while (1);

  return 0;
}
