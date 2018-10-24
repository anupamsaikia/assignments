#include<stdio.h>

void insertion_sort(int *arr, int len){
  int i, j, temp;

  for(i = 1; i< len; i++){
    temp = arr[i];
    for(j = i; j > 0 && temp < arr[j-1]; j--)
      arr[j] = arr[j-1];
    arr[j] = temp;
  }
}

main()
{
  int arr[] = {1,4,2,3,-5,7,9,7,-54,5,7,6,435,463,-67,6};
  int len = sizeof(arr)/sizeof(arr[0]);
  int i;

  printf("\nOriginal array: ");
  for(i = 0; i < len; i++)
    printf("%d  ", arr[i]);
  printf("\n");

  insertion_sort(arr, len);

  printf("Sorted array: ");
  for(i = 0; i < len; i++)
    printf("%d  ", arr[i]);
  printf("\n\n");

  return 0;
}
