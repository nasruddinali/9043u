#include <stdio.h>
#include <stdlib.h>
 
struct MaxHeap
{
    int size;
    int *array;
};
 
void swap(int* a, int* b) 
{ 
	int t=*a; *a=*b;  *b=t; 
}
 
void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
    int largest=idx; 
    int left=(idx << 1) + 1;  
    int right=(idx + 1) << 1;
 
    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
        largest = left;
 
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
        largest = right;
 
    if (largest != idx)
    {
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        maxHeapify(maxHeap, largest);
    }
}
 
struct MaxHeap* createAndBuildHeap(int *array, int size)
{
    int i;
    struct MaxHeap* maxHeap=(struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size=size;  
    maxHeap->array=array; 
 
    for (i=(maxHeap->size - 2)/2;i >= 0;i--)
    {
        maxHeapify(maxHeap, i);
	}
	return maxHeap;
}
 
void heapSort(int* array, int size)
{
    struct MaxHeap* maxHeap=createAndBuildHeap(array, size);
 
    while (maxHeap->size > 1)
    {
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size; 
        maxHeapify(maxHeap, 0);
    }
}
 
void printArray(int* arr, int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        printf("%d ", arr[i]);
	}
}
 
int main()
{
    int arr[20],i,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
	}
    printf("Given array is \n");
    printArray(arr, n);
    heapSort(arr, n);
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}
