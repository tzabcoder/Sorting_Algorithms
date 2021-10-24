/* 
    SORTING METODS 

    file: main.cpp
    by: Trevor Zabilowicz

    objective:
        - Improve programming skills and practice algorithm programming 
        and analysis.
        - The sorting methods were researched from various sources, but
        no source code was copied. 
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>        //For timing of each sorting method
using namespace std;

//Alias for passing the array by reference 
#define ARRAY_SIZE 20
using IntCode = int[ARRAY_SIZE];

/*
    FUNCTION: standard_sort()
    DESCRIPTION: 
        - Accepts an integer array by reference using the IntCode alias
        defined globally
        - The function sorts the array using two loops swaping the 
        largest and smallest values on each iteration (where the changes
        are recoreded in the array referenced from main)
        - Performance:
            O(N^2)

    PARAMETERS:
        - int arr[] (passed by reference)
    
    RETURNS:
        - Nothing
*/
void standard_sort(IntCode& arr) {
    int temp;     //Container variable

    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = i+1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[i];         //Store the largest value 
                arr[i] = arr[j];       //Swap the smallest value and largest value
                arr[j] = temp;         //Re-store the largest value 
            }
        }
    }
}

//Bubble Sort 
//Merge Sort 
//Quicksort 

int main() {
    srand(time(NULL));     //Seed time (new random numbers each execution)

    int array[ARRAY_SIZE];

    //Initialize array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    //Display Original Array 
    cout << "Non-Sorted Array: " << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    standard_sort(array);     //Sort the array using the standard method
    
    //__________Display__________
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
