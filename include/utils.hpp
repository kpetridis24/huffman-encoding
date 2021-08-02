#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <cstdlib>
#include <cstdbool>
#include <time.h>
#include <vector>

struct node{

    node *left;
    node *right;
    int frequency;
    int code;
};

namespace util{

    void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }


    void printVectorParam(std::vector <node*> vec){

        for (const auto& i: vec)
            std::cout << i->frequency << ' ';
    }

    void printVector(std::vector <int> vec){

        for (const auto& i: vec)
            std::cout << i << ' ';
    }
 
    /* This function takes last element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right
    of pivot */
    int partition (int *arr, int low, int high)
    {
        int pivot = arr[high]; // pivot
        int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    
        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than the pivot
            if (arr[j] < pivot)
            {
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
 
    /* The main function that implements QuickSort
    arr[] --> Array to be sorted,
    low --> Starting index,
    high --> Ending index */
    void quickSort(int *arr, int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
            at right place */
            int pi = partition(arr, low, high);
    
            // Separately sort elements before
            // partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }


    int linearSearch(std::vector <node*> arr, int target){
        //std::cout<<"Target="<<target<<std::endl;
        for (int i = 0; i < arr.size(); i++){
            //std::cout<<"i="<<i<<std::endl;
            if(target <= arr.at(i)->frequency) return i;
        }
        return arr.size();
    }


    int binarySearch(std::vector <node*> arr, int low, int high, int key)
    {   
        //if(key > arr[arr.size()]->frequency){ std::cout<<"ENTER\n";return arr.size() - 1;}
        if (high < low)
            return -1;
        int mid = (low + high) / 2; /*low + (high - low)/2;*/
        if (key == arr[mid]->frequency)
            return mid;
        if (key > arr[mid]->frequency)
            return binarySearch(arr, (mid + 1), high, key);
        return binarySearch(arr, low, (mid - 1), key);
    }

/*
    int binarySearch(std::vector <node*> arr, int l, int r, int x)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;
    
            // If the element is present at the middle
            // itself
            if (arr.at(mid)->frequency == x)
                return mid;
    
            // If element is smaller than mid, then
            // it can only be present in left subarray
            if (arr.at(mid)->frequency > x)
                return binarySearch(arr, l, mid - 1, x);
    
            // Else the element can only be present
            // in right subarray
            return binarySearch(arr, mid + 1, r, x);
        }
    
        // We reach here when element is not
        // present in array
        return -1;
    }
*/

    int *randomFrequencies(int len, int rangeBound)
    {
        srand(time(NULL));
        int *freq = new int[len];
        for(int i = 0; i < len; i++) freq[i] = rand() % rangeBound; 
        return freq;
    }
}


#endif