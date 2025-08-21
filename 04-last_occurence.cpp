// Program to find the last occurence of an element in the sorted array.
#include <iostream>
using namespace std;
int binarySearch(int arr[], size_t size, int target)
{
  size_t start = 0, end = size - 1;
  int res = -1;

  while (start <= end)
  {
    size_t mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
      res = mid;
      start = mid + 1;
    }
    else if (arr[mid] < target)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return res;
}

int main()
{
  int arr[] = {2, 4, 10, 10, 10, 18, 20};

  size_t size = sizeof(arr) / sizeof(arr[0]);

  int target = 10;

  int index = binarySearch(arr, size, target);

  if (index != -1)
  {
    cout << "Last occurence is at : " << index << endl;
  }
  else
  {
    cout << "Oopss! The requested element is not in the array ! " << endl;
  }
  return 0;
}