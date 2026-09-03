#include <ctime>
#include <cstdlib>

vector<int> sortArray(vector<int>& nums) {
int l = nums.size();

if(l <= 1) return nums;

quickSort(nums, l);

return nums;
}
void quickSort(vector<int>& arr, int length) {
  int low, high;

  low = 0;
  high = length - 1;

  srand(time(NULL));

  quickSort_recursion(arr, low, high);
}

void quickSort_recursion(vector<int>& arr, int low, int high) {
  if (low >= high) return;

  int pivot_idx = partion(arr, low, high);

  quickSort_recursion(arr, low, pivot_idx - 1);
  quickSort_recursion(arr, pivot_idx + 1, high);
}

int partion(vector<int>& arr, int low, int high) {

  int pivot_idx = low + (rand() % (high - low + 1))

  if (pivot_idx != high) {
    int temp = arr[pivot_idx];
    arr[pivot_idx] = arr[high];
    arr[high] = temp;
  }

  int pivot = arr[high];
  int i = low;

  for (int j = low; j < high; j++) {
      if (arr[j] < pivot) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      ++i;
    }
  }
  int temp = arr[i];
  arr[i] = arr[high];
  arr[high] = temp;

return i;
}
