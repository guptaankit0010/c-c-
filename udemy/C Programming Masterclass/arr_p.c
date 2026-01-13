#include <stdio.h>

#define SIZE 5
int sumArray(int arr[], int size);

int sumArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void searchArray(int arr[], int size, int target);

void searchArray(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            printf("Element %d found at index %d\n", target, i);
            return;
        }
    }
    printf("Element %d not found in the array\n", target);
}

int findMax(int arr[], int size);

int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

double avgArray(int arr[], int size);

double avgArray(int arr[], int size)
{
    int sum = sumArray(arr, size);
    return sum / size;
}

void minmaxArray(int arr[], int size, int *min, int *max);

void minmaxArray(int arr[], int size, int *min, int *max)
{
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
    }
}

int findNeighbour(int arr[], int size);

int findNeighbour(int arr[], int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        if ((arr[i - 1] ? arr[i - 1] : 0) + (arr[i + 1] ? arr[i + 1] : 0) == arr[i])
        {
            return arr[i];
        }
    }
    return 0;
}

int isArraySoted(int arr[], int size);

int isArraySorted(int arr[], int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i] >= arr[i + 1])
        {
            return 0; // Array is not sorted
        }
    }
    return 1; // Array is sorted
}

int isArraySortedRecursive(int arr[], int size);

int isArraySortedRecursive(int arr[], int size)
{
    if (size == 1)
    {
        return 1; // Base case: single element is sorted
    }

    if (arr[size - 1] < arr[size - 2])
    {
        return 0; // Not sorted
    }

    return isArraySortedRecursive(arr, size - 1);

    // [34, 78, 12, 45, 67]
}

void reverseArr(int arr[], int size);
void reverseArr(int arr[], int size)
{
    // function body
    // arr = [34, 78, 12, 45, 67, 89,  90];
    if (size <= 1)
    {
        return; // Base case: nothing to reverse
    }

    int temp = arr[size - 1];
    arr[size - 1] = arr[0];
    arr[0] = temp;

    reverseArr(arr + 1, size - 2); // 0:7,1:5,2:3,4:1
}

void printFrequency(int arr[], int size);
void printFrequency(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        int j;
        int count = 1;
        int alreadyCounted = 0;
        for (j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                alreadyCounted = 1;
                break;
            }
        }

        if (alreadyCounted)
        {
            continue;
        }
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        printf("Element %d occurs %d times\n", arr[i], count);
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    int total = sumArray(ptr, SIZE);
    printf("Sum of array elements: %d\n", total);

    searchArray(ptr, SIZE, 3);
    searchArray(ptr, SIZE, 6);

    double average = avgArray(ptr, SIZE);
    printf("Average of array elements: %.2f\n", average);

    int min, max;
    minmaxArray(ptr, SIZE, &min, &max);
    printf("Minimum element in the array: %d\n", min);
    printf("Maximum element in the array: %d\n", max);

    int max2 = findMax(ptr, SIZE);
    printf("Maximum element in the array: %d\n", max2);

    int arr2[5] = {2, 8, 6, 10, 16};
    int hasNeighbour = findNeighbour(arr2, 5);
    if (hasNeighbour)
    {
        printf("Element with neighbours summing to it: %d\n", hasNeighbour);
    }
    else
    {
        printf("No element found with neighbours summing to it.\n");
    }

    int arr3[5] = {1, 2, 3, 4, 4};
    if (isArraySorted(arr3, 5))
    {
        printf("Array is sorted in ascending order.\n");
    }
    else
    {
        printf("Array is not sorted in ascending order.\n");
    }

    int arr4[5] = {32, 45, 67, 89, 90};
    if (isArraySortedRecursive(arr4, 5))
    {
        printf("Array is sorted in ascending order (checked recursively).\n");
    }
    else
    {
        printf("Array is not sorted in ascending order (checked recursively).\n");
    }

    int arr5[5] = {34, 78, 12, 45, 67};
    if (isArraySortedRecursive(arr5, 5))
    {
        printf("Array is sorted in ascending order (checked recursively).\n");
    }
    else
    {
        printf("Array is not sorted in ascending order (checked recursively).\n");
    }

    int arr6[7] = {34, 78, 12, 45, 67, 89, 90};
    reverseArr(arr6, 7);
    printf("Reversed array: ");
    for (int i = 0; i < 7; i++)
    {
        printf("%d \n", arr6[i]);
    }

    int arr7[5] = {1, 2, 2, 3, 4};
    printFrequency(arr7, 5);
    return 0;
}