#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int size, char test_type, int test_num);
void printArray(int arr[], int size);
void positiveCase();
void negativeCase();
void performanceCase();
void boundaryCase();
void idempotencyCase();

int main(int argc, char const *argv[])
{
    positiveCase();
    negativeCase();
    performanceCase();
    boundaryCase();
    idempotencyCase();
    return 0;
}

//sorts positive integers up to max int value on machine
void bubbleSort(int arr[], int size, char test_type, int test_num)
{
    clock_t start, end;
    double time_taken;
    start = clock();
    if(size == 0){
        printf("Cannot sort empty array\n");
        return;
    }
    if(size == 1){
        printf("Array is already sorted\n");
        return;
    }

    for (int i = 0; i < size - 1; ++i)
    {
        if(arr[i] < 0){
            printf("Value in array is negative.\n");
            break;
        }
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();
    time_taken = ((double)end-start)/CLOCKS_PER_SEC*1000;
    if(test_type == '+')
    {
        for(int i = 0; i < size; ++i)
        {
            printf( "%d, ", arr[i]);
        }
        printf("\n");
    }
    else if(test_type == 'p'){
        printf("Time taken = %f for performace test on array of size %d\n", time_taken, size);
    }
    else if(test_type == 'i'){
        printf("Time taken for Idempotency case #%d = %f\n", test_num, time_taken);
    }
    return;
}


//shows that the array is sorted as intended
void positiveCase(){
    int arr1[200] = {};
    for(int i = 0; i < 200; ++i){
        arr1[i] = (rand() % (1000 - 1 + 1)) + 1;
    }
    bubbleSort(arr1, 200, '+', 0);
    return;
}

//does not allow sorting of negative integers
void negativeCase(){
    int arr[200] = {};
    for(int i = 0; i < 200; ++i){
        arr[i] = (rand() % (1000 - (-1000) + 1)) + (-1000);
    }
    bubbleSort(arr, 200, '-', 0);
    return;
}

//shows O(n^2) time complexity for bubbleSort as expected
void performanceCase(){
    int arr1[200] = {};
    for(int i = 0; i < 200; ++i){
        arr1[i] = (rand() % (1000 - 1 + 1)) + 1;
    }
    bubbleSort(arr1, 200, 'p', 0);

    int arr2[2000] = {};
    for(int i = 0; i < 2000; ++i){
        arr2[i] = (rand() % (1000 - 1 + 1)) + 1;
    }
    bubbleSort(arr2, 2000, 'p', 0);

    int arr3[20000] = {};
    for(int i = 0; i < 20000; ++i){
        arr3[i] = (rand() % (1000 - 1 + 1)) + 1;
    }
    bubbleSort(arr3, 20000, 'p', 0);
    return;
}

void boundaryCase(){
    int arr1[0] = {};
    bubbleSort(arr1, 0, 'b', 0);

    int arr2[1] = {10};
    bubbleSort(arr2, 1, 'b', 0);
    return;
}

void idempotencyCase(){
    int arr1[2000] = {};
    for(int i = 0; i < 2000; ++i){
        arr1[i] = (rand() % (1000 - 1 + 1)) + 1;
    }
    bubbleSort(arr1, 200, 'i', 1);
    bubbleSort(arr1, 200, 'i', 2);
    bubbleSort(arr1, 200, 'i', 3);
    bubbleSort(arr1, 200, 'i', 4);
    return;
}