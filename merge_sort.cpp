// Problem: Merge Sort
// Approach: Divide and Conquer
// Time: O(n log n)
// Space: O(n)


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void merge(vector<int> &nums, int st, int end, int mid){
        vector<int> arr;
        int i = st;
        int j = mid+1;

        while(i <= mid && j <= end){
            if(nums[i] < nums[j]) {
                arr.push_back(nums[i]);
                i++;
            }
            else{
                arr.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            arr.push_back(nums[i]);
            i++;
        }

        while(j <= end){
            arr.push_back(nums[j]);
            j++;
        }

        for(int i=0; i<arr.size(); i++){
            nums[st + i] = arr[i];
        }
    }


    void mergeSort(vector<int>& nums, int st, int end) {
        if(st >= end) return;
        int mid = (end - st)/2 + st;

        mergeSort(nums, st, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, st, end, mid);

    }

    vector<int> sortArray(vector<int>& nums){
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }