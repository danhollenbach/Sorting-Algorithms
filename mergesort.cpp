void merge(vector<int>& arr, int low_pos, int mid_pos, int high_pos);   // Gather two sorted arrays in a unique sorted one
void mergeSort(vector<int>& nums, int low_pos, int high_pos);   // Continually divides a array in halves until it only last a single element (it'll be already sorted) 

vector<int> sortArray(vector<int>& nums) {    // A function to initialize important variables and call the mergeSort function
  int l = nums.size();    // Length of the array

  if (l <= 1) return nums;    // If there is only one or none elements in the array it's already sorted, just return the array

  int low_pos = 0;    // An index to track the beginning of the array
  int high_pos = l - 1;   // An index to track the ending of the array

  mergeSort(nums, low_pos, high_pos);   // Call the mergeSort function with the array, its first position and its last position

  return nums;    // After all the processing, return the sorted array
}

void mergeSort(vector<int>& nums, int low_pos, int high_pos) {    // A function to recursively divide the  array in halves, until the array is already sorted (just one element)
  // This is the heart of merge sort, like every recursively algorithm it needs a stop condition, and here it's when the array is already sorted (one element)
  if (low_pos >= high_pos) return;    // The more common approach is just the '==' operator, but this prevents an error if a array with zero elements reaches here (low = 0 and high = -1)

  int mid_pos = (high_pos + low_pos) / 2;   // A index to truncates the middle of the original array

  // Ex.

  //      lp      mp       hp
  //       |       |       |
  // Arr: 10, 20, 30, 40, 50   -> Arr1: 10, 20, 30 + Arr2: 40, 50
  //      --      --      --
  // obs: int division in C++ trunk the number, so it will work for both even and odd arrays 
  // -> for a array with 6 elements (low_p = 0 and high_p = 5) the mid_p will be int(5/2) = 2. 
  
  mergeSort(nums, low_pos, mid_pos);    // This applies the same rule over and over again to Arr1 until it reaches a sorted array and return to ...
  mergeSort(nums, mid_pos + 1, high_pos);   // another sorted array

  merge(nums, low_pos, mid_pos, high_pos);    // and then it'll merge these two arrays into one sorted array

}

void merge(vector<int>& arr, int low_pos, int mid_pos, int high_pos) {    // This function will do the hard work of gathering both arrays in a sorted way
  // Here for every call of the merge function we assign a temporary array, this could be just a single temporary array declared in the sortArray function and passed by reference
  vector<int> temp_arr;   // This array is needed for us to save the combination of the arrays in a sorted manner

  int left_idx = low_pos;   // Index to tracks how many elements from the first array were copied to the combined array
  int right_idx = mid_pos + 1;    // Index to tracks how many elements from the second array were copied to the combined array

  while (left_idx <= mid_pos && right_idx <= high_pos) {    // While the left index is not over the end of the first array and, in the same, the right index is not over the end of the second array, do this:
    // Compare one element from to first array to the second array, and add the lesser one in order in the temporary array
    if (arr[left_idx] <= arr[right_idx]){
      temp_arr.push_back(arr[left_idx]);
      left_idx++;   // increase this index to track how many elements from the first array have been added to the final array
    } else {
      temp_arr.push_back(arr[right_idx]);
      right_idx++;    // increase this index to track how many elements from the second array have been added to the final array
    }
  }

 // Everytime one of the arrays will have leftovers because we only increment one index at a time, so:  
  while (left_idx <= mid_pos) {   // if the first array still has leftovers, ...
    temp_arr.push_back(arr[left_idx]);    // ... they'll just be added in the end of the array cause they are already sorted
    ++left_idx;
  }

  while (right_idx <= high_pos) {   // if the second array still has leftovers, ...
    temp_arr.push_back(arr[right_idx]);   // ... they'll just be added in the end of the array cause they are already sorted
    ++right_idx;
  }

  for (int idx = 0; idx < temp_arr.size(); idx++) {   // And finally the sorted array will be copied into the original array
    arr[low_pos] = temp_arr[idx];
    low_pos++;
  }
}
