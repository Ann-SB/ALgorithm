/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.
The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
*/


#include<stdio.h>

void main()
{  int a[100],n,i,j,temp;		//'a' is an integer array of size 100
   printf("Enter no. of elements: ");
   scanf("%d",&n);			//'n' stores the number of elements in the array
   printf("Enter array:");
   for(i=0;i<n;i++)			//for loop to input elements of the array
       scanf("%d",&a[i]);
   
   //Sorting
   
   for(i=0;i<n-1;i++)
    {  for(j=i+1;j<n;j++)
          {   if(a[i]>a[j])
                {   temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                 }
           }
    }

    printf("Sorted array :");
   for(i=0;i<n;i++)			//for loop to print sorted array
     printf("%d ",a[i]);
   printf("\n");
}