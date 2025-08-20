/*  This program will not give output for target = 2 because

The problem is with mixing size_t (unsigned) and int (signed) types. Here's what's happening:
Here declare start and end as size_t (unsigned)
When end = mid - 1 and mid is 0, you get end = 0 - 1
Since size_t is unsigned, this wraps around to a very large positive number (underflow)
The condition start <= end becomes true when it should be false, causing an infinite loop


 IT'S FIX IS BELOW THIS PROGRAM */

/* #include <iostream>
using namespace std;

int firstOccurrence(int arr[], size_t size, int target)
{
  size_t start = 0, end = size - 1;
  int res = -1;

  while (start <= end)
  {
    size_t mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
      res = mid;
      end = mid - 1;
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

int lastOccurrence(int arr[], size_t size, int target)
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
  int target = 2;

  int first = firstOccurrence(arr, size, target);
  int last = lastOccurrence(arr, size, target);

  if (first == -1)
  {
    cout << "Oops! The requested element is not in the array!" << endl;
  }
  else
  {
    cout << "First occurrence is at index: " << first << endl;
    cout << "Last occurrence is at index: " << last << endl;
    cout << "Total occurrences of the element in the array is: " << (last - first + 1) << endl;
  }
  return 0;
}
 */
#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int size, int target)
{
  int start = 0, end = size - 1; // Changed to int
  int res = -1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2; // Changed to int

    if (arr[mid] == target)
    {
      res = mid;
      end = mid - 1;
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

int lastOccurrence(int arr[], int size, int target)
{
  int start = 0, end = size - 1; // Changed to int
  int res = -1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2; // Changed to int

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
  int size = sizeof(arr) / sizeof(arr[0]); // Changed to int
  int target = 10;

  int first = firstOccurrence(arr, size, target);
  int last = lastOccurrence(arr, size, target);

  if (first == -1)
  {
    cout << "Oops! The requested element is not in the array!" << endl;
  }
  else
  {
    cout << "First occurrence is at index: " << first << endl;
    cout << "Last occurrence is at index: " << last << endl;
    cout << "Total occurrences of the element in the array is: " << (last - first + 1) << endl;
  }
  return 0;
}
