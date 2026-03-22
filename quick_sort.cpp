// Problem: quick Sort
// Approach: Divide and Conquer
// Time: O(n log n)
// Space: O(n)
// worst case time complexity O(n^2)


#include<iostream>
#include<algorithm>
using namespace std;

    int partition(int arr[], int si, int ei){
        int i = si - 1;
        int pivot = arr[ei];
        
        for(int j=si; j<ei; j++){
            if(arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        i++;
        swap(arr[i], arr[ei]);

        // pivotIdx = i
        return i;
    }

    void quickSort(int arr[], int si, int ei){

        if(si >= ei) return;
        int pivotIdx = partition(arr, si, ei);

        quickSort(arr, si, pivotIdx-1);
        quickSort(arr, pivotIdx+1, ei);
    }

