#include <iostream>
#include <vector>
using namespace std;

int findInSort(vector<int> &nums, int target)
{
  int start = 0;
  int end = nums.size() - 1;
  int mid;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }

    // left side of array is sorted
    if (nums[start] <= nums[mid])
    {
      if (target >= nums[start] && target < nums[mid])
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }
    // right side of array is sorted
    else
    {
      if (target > nums[mid] && target <= nums[end])
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }
  }
  return -1;
}

int main()
{
  vector<int> nums = {6, 7, 2, 3, 4, 5};
  int target = 4;
  int index = findInSort(nums, target);

  if (index != -1)
  {
    cout << "The target is at : " << index << " Index ! " << endl;
  }
  else
  {
    cout << "There is no such number in the array !!!" << endl;
  }
  return 0;
}
