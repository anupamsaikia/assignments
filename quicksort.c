// C program to implement quick sort taking first element as pivot

#include<stdio.h>

// function to swap two integers
void swap(int *x, int *y) 
{ 
  int temp = *x; 
  *x = *y; 
  *y = temp; 
}

// function for quick sort
quickSort(int data[], int first, int last){
  int lower = first + 1;
  int upper = last;
  int pivot = data[first];

  while(lower <= upper){
    while(data[lower] < pivot)
      lower++;
    while(pivot < data[upper])
      upper--;
    if(lower < upper)
      swap(&data[lower++], &data[upper--]);
    else
      lower++;
  }

  swap(&data[upper], &data[first]);

  if(first < upper -1)
    quickSort(data, first, upper -1);
  if(upper + 1 < last)
    quickSort(data, upper+1, last);

}




void main(){

  int arr[] = {12,23,45,12,2,1,3,54,67,8,3321,4};
  int len = sizeof(arr)/sizeof(arr[0]);

  int i;

  printf("\nOriginal array: ");
  for(i = 0; i < len; i++)
    printf("%d  ", arr[i]);
  printf("\n");

  quickSort(arr, 0, len -1);

  printf("Sorted array: ");
  for(i = 0; i < len; i++)
    printf("%d  ", arr[i]);
  printf("\n\n");
}
