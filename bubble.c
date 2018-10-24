#include <stdio.h> 
  
void swap(int *x, int *y) 
{ 
  int temp = *x; 
  *x = *y; 
  *y = temp; 
}
  
void bubbleSort(int arr[], int len) 
{ 
  int i, j; 
  for (i = 0; i < len-1; i++)       
    for (j = 0; j < len-i-1; j++)  
      if (arr[j] > arr[j+1]) 
        swap(&arr[j], &arr[j+1]); 
}


int main() 
{ 
  int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
  int len = sizeof(arr)/sizeof(arr[0]);
  int i;

  
  printf("\nOriginal array: ");
  for(i = 0; i < len; i++)
    printf("%d  ", arr[i]);
  printf("\n");

  bubbleSort(arr, len);

  printf("Sorted array: ");
  for(i = 0; i < len; i++)
    printf("%d  ", arr[i]);
  printf("\n\n");

  return 0;
} 