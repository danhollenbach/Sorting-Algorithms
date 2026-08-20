// Brief Explanation: 
// Order a array by swapping a element and its next element over and over again.
// This is the most common, and easiest, approach to a sorting array problem. 

// It gets sorted as the i index get incremented, here's a example to see it:
// Ex.
// pos. 0  1  2  3  4
//---------------------
// Arr: 5, 4, 3, 2, 1 | i = 0 and j = 0 -> array in a worse case scenario
//      -     
// Arr: 4, 5, 3, 2, 1 | i = 0 and j = 1
//         -
// Arr: 4, 3, 5, 2, 1 | i = 0 and j = 2
//            - 
// Arr: 4, 3, 2, 5, 1 | i = 0 and j = 3
//               - 
// Arr: 4, 3, 2, 1, 5 | i = 0 and j = 4 -> 5 is in its right place
//                  -
// Arr: 4, 3, 2, 1, 5 | i = 1 and j = 0
//      -           - 
// Arr: 3, 4, 2, 1, 5 | i = 1 and j = 0
//         -        - 
//  ...
// Arr: 3, 2, 1, 4, 5 | i = 1 and j = 0
//               -  -
//  ...
// Sorted Arr: 1, 2, 3, 4, 5 | i = 4 and j = 0 -> the last element to be sorted will already be in its right place
//             -  -  -  -  -

vector<int> bubbleSort(vector<int>& nums) {
  int l = nums.size();    // -> a variable to describe the length of the array
  for (int i = 0; i < l; i++) {   // -> an outter loop to do the same procedure to each and every array element
      for (int j = 0; j < l - 1 - i; j++) {   // -> a inner loop that will only run for disorganized array elements 
          if (nums[j] > nums[j+1]) {    // if a predecessor is greater than its successor, do this:
              int temp = nums[j];   // save the predecessor in a temporary variable, so it doesn't get lost -> Arr: ..., num1, num2, ...
              nums[j] = nums[j + 1];    // set the predecessor value to the successor value, a lesser number -> Arr: ..., num2, num2, ...
              nums[j + 1] = temp;       // set the original value of the predecessor to the successor -> Arr: ..., num2, num1, ...
          }
      }
  }
  return nums;    // return the sorted array after all the processing
}

// Observation.
// It is helpful to notice that this algorithm consist in swapping elements and there is
//  a lot of ways to do that, such as: the cpp std::swap function,the bitwise xor swapping method 
// or the arithmetic swap method.