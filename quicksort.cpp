/* 
    QUICKSORT

    file: quicksort.cpp
    by: Trevor Zabilowicz

    objective:
        - Implement a quicksort searching technique 
        - Improve upon algorithm programming
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Define the constant array size
#define ARRAY_SIZE 100

/*
    FUNCTION: void swap()
    DESCRIPTION: 
        - Accepts two integer array pointers representing a location
        in an array respectively
        - Swaps the values of the two pointers

    PARAMETERS:
        - int *a
        - int *b
    
    RETURNS:
        - Nothing
*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    FUNCTION: int partition()
    DESCRIPTION: 
        - Create a new partition of the original array

    PARAMETERS:
        - int arr[] (by reference)
        - int low
        - int high
    
    RETURNS:
        - int index (index of new partition)
*/
int partition(int arr[], int low, int high) {
    int pivot, index, i;
    index = low;          //Set the index to be the low of the array
    pivot = high;         //Set the pivot to be the high of the array

    for (i = low; i < high; i++) {           //For low to high
        if (arr[i] < arr[pivot]) {           //If current position is less than pivot position
            swap(&arr[i], &arr[index]);      //Swap the ith position and the index
            index++;                         //Increment index
        }
    }

    swap(&arr[pivot], &arr[index]);          //Swap the index and the position
    return index;                            //return the index
}

/*
    FUNCTION: int random_pivot_partition()
    DESCRIPTION:
        - Create a new random partition given the low, high,
        and the array itself
        - Always moves the pivot position to the high position of 
        the array

    PARAMETERS:
        - int arr[]
        - int low 
        - int high

    RETURNS:
        - int index (index of new partition)
*/
int random_pivot_partition(int arr[], int low, int high) {
    int pvt, temp;

    pvt = low + rand()%(high - low + 1);    //Generate a random position (in the range between low and high)

    swap(&arr[high], &arr[pvt]);            //Swap the pivot position to the high position 
    return partition(arr, low, high);       //Return the partition index
}

/*
    FUNCTION: int quicksort()
    DESCRIPTION:
        - Recursively use the quicksort algorithm to sort
        an array of integers
        - Use the parititions to sort the array

    PARAMETERS:
        - int arr[]
        - int low
        - int high

    RETURNS:
        - 0 (nothing)
*/
int quicksort(int arr[], int low, int high) {
    int piv_pos;

    if (low < high) {       //If high is greater than low
        piv_pos = random_pivot_partition(arr, low, high);  //Get a random pivot position

        quicksort(arr, low, piv_pos-1);                    //Recursively sort the new low partition
        quicksort(arr, piv_pos+1, high);                   //Recursively sort the new high partition
    }

    return 0;
}

int main() {

    srand(time(NULL));

    int array[ARRAY_SIZE];

    //Initialize Array 
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    //Display original array 
    cout << "Original Array: " << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    quicksort(array, 0, ARRAY_SIZE-1);

    //_____Display_____
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}