#include <iostream>
using namespace std;
// Normal binary search.
int binarySearch(int arr[], size_t size, int target)
{
  size_t start = 0;
  size_t end = size - 1;

  while (start <= end)
  {
    size_t mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] > target)
    {
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
  }
  return -1;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6};
  size_t size = sizeof(arr) / sizeof(arr[0]);

  int target = 5;

  int index = binarySearch(arr, size, target);

  if (index != -1)
  {
    cout << "Target found at index : " << index << endl;
  }
  else
  {
    cout << "Target not found" << endl;
  }
  return 0;
}