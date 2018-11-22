// C program to implement selection sort

#include <stdio.h>

// function to swap two integers
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

// function for selection sort
void selectionSort(int arr[], int len)
{
  int i, j, min;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < len - 1; i++)
  {
    // Find the minimum element in unsorted array
    min = i;
    for (j = i + 1; j < len; j++)
      if (arr[j] < arr[min])
        min = j;

    // Swap the found minimum element with the first element
    swap(&arr[min], &arr[i]);
  }
}

int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90, 0, -22, 999};
  int len = sizeof(arr) / sizeof(arr[0]);
  int i;

  printf("\nOriginal array: ");
  for (i = 0; i < len; i++)
    printf("%d  ", arr[i]);
  printf("\n");

  selectionSort(arr, len);

  printf("Sorted array: ");
  for (i = 0; i < len; i++)
    printf("%d  ", arr[i]);
  printf("\n\n");

  return 0;
}