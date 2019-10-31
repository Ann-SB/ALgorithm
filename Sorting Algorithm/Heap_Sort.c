/*
Heap sort is a comparison based sorting technique based on Binary Heap data structure. 
It is similar to selection sort where we first find the maximum element and place the maximum element at the end.
The same process is repeated for remaining elements. 

A Binary Heap is a Complete Binary Tree where items are stored in a special order such that value in a parent node is greater(or smaller) than the values in its two children nodes. 
The former is called as max heap and the latter is called min heap. The heap can be represented by binary tree or array.

Since a Binary Heap is a Complete Binary Tree, it can be easily represented as array and array based representation is space efficient.
If the parent node is stored at index I, the left child can be calculated by 2 * I + 1 and right child by 2 * I + 2 (assuming the indexing starts at 0).

Heap Sort Algorithm for sorting in increasing order:
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of tree.
3. Repeat above steps while size of heap is greater than 1.
*/

#include <stdio.h>

void swap(int *a, int *b)                                         //function to swap 2 values
{
  int t=*b;
  *b=*a;
  *a=t;
}

void buildHeap(int a[], int curr, int size)                       //function to build heap
{
  int left = 2 * curr + 1, right = 2 * curr + 2, largest = curr;
  if(left < size)
    largest = a[largest] > a[left] ? largest : left;
  if(right < size)
    largest = a[largest] > a[right] ? largest : right;
  if( largest != curr )
  {
    swap(&a[largest], &a[curr]);
    buildHeap(a,largest,size);
  }
}

void HeapSort(int a[], int size)                                  //function to sort
{
  int i;
  for(i= size/2 - 1;i >= 0; --i)
    buildHeap(a,i,size);
  for (i = size - 1; i >= 0; i--)
  {
    swap(&a[0], &a[i]);
    buildHeap(a, 0, i);
  }
}

void main()
{
  int size, a[200],i;
  printf("Enter the size of the array :");
  scanf("%d",&size);                                                    
  printf("Enter the elements :\n");
  for(i = 0; i < size; ++i)
    scanf("%d",&a[i]);
  HeapSort(a,size);
  printf("Sorted Array : \n");
  for(i = 0; i < size; ++i)
    printf("%d ",a[i]);
}
