#include <ctime>
#include <vector>
#include <cstdlib>

vector<int> sortArray(vector<int>& nums) {    // main function
int l = nums.size();    // var to store the array's length

if(l <= 1) return nums;   // a length of 0 or 1 means that the array is already sorted

quickSort(nums, l);   // calls the quisck sort main function

return nums;    // return the sorted array
}
void quickSort(vector<int>& arr, int length) {    // initialize the quick sort algorithm 
  int low, high;    // set two variables

  low = 0;    // low to track the start of the sorting array 
  high = length - 1;    // high to track the end of the sorting array

  srand(time(NULL));    // function to assert that for each execution there will be a different random pivot

  quickSort_recursion(arr, low, high);    // the recurison of the algorithm itself
}

void quickSort_recursion(vector<int>& arr, int low, int high) {   // set a random pivot for the following arrays and repite the algorithm until it reaches the end case
  if (low >= high) return;    // end case, when both high and low index are pointing to the same element or when high points to a previous element of low

  int pivot_idx = partition(arr, low, high);    // calls the function that sets the pivot and organize the array around the pivot

  quickSort_recursion(arr, low, pivot_idx - 1);   // sort the left side of the pivot
  quickSort_recursion(arr, pivot_idx + 1, high);    // sort the right side of the pivot
}

int partition(vector<int>& arr, int low, int high) {    // set the index of the pivot and organize the array around it

  int pivot_idx = low + (rand() % (high - low + 1));   // assure that the index is between low and high

  if (pivot_idx != high) {    // swap the last element with the element in the pivot idx
    int temp = arr[pivot_idx];
    arr[pivot_idx] = arr[high];
    arr[high] = temp;
  }

  int pivot = arr[high];    // set the pivot to the element that was the previous arr[pivot_idx]
  int i = low;    // variable to track where the lesser element must be put

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {   // Bring lesser elements to the left side of the pivot
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      ++i;
    }
  }
  int temp = arr[i];    // Puts the element in the middle of lesser and greater elements
  arr[i] = arr[high];
  arr[high] = temp;

return i;   // return the idx of the pivot's position
}
