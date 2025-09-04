#include <iostream>
#include <vector>
using namespace std;

int findPeak(const vector<int> &nums)
{
  int start = 0;
  int end = nums.size() - 1;
  while (start < end)
  {
    int mid = start + (end - start) / 2;

    if (nums[mid] < nums[mid + 1])
    {
      start = mid + 1;
    }
    else
    {
      end = mid;
    }
  }
  return start;
}

int findAsc(const vector<int> &nums, int start, int end, int target)
{
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return -1;
}
int findDes(const vector<int> &nums, int start, int end, int key)
{
  while (start < end)
  {
    int mid = start + (end - start) / 2;

    if (nums[mid] == key)
      return mid;
    else if (nums[mid] < key)
      end = mid - 1;
    else
      start = mid + 1;
  }
  return -1;
}

int findInBitonic(vector<int> &arr, int target)
{
  int peak_Element = findPeak(arr);

  int indexOfElement = findAsc(arr, 0, peak_Element, target);

  return indexOfElement == -1 ? findDes(arr, peak_Element + 1, arr.size() - 1, target) : indexOfElement;
}
int main()
{
  vector<int> arr = {1, 3, 8, 12, 4, 2};
  int target = 12;

  int index = findInBitonic(arr, target);
  if (index != -1)
    cout << "Element " << target << " found at index " << index << endl;
  else
    cout << "Element not found" << endl;

  return 0;
}