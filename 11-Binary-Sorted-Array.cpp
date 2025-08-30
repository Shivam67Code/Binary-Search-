/*This program finds the first occurrence of a target in a binary sorted array,
   simulating infinite array search using binary search.
   -> A Binary sorted array is an array where elements are sorted in non-decreasing order and may contain only two distinct values (typically 0s and 1s).
*/

#include <iostream>
#include <vector>
using namespace std;

// Binary search for first occurrence in [low, high]
int firstOccurence(vector<int> &nums, int target, int low, int high)
{
  int res = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
    {
      res = mid;
      high = mid - 1;
    }
    else if (nums[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return res;
}

int findInInfinity(vector<int> &nums, int target)
{
  int low = 0;
  int high = 1;

  while (high < nums.size() && nums[high] < target)
  {
    low = high;
    high *= 2;
  }

  // Clamp high to array size
  if (high >= nums.size())
    high = nums.size() - 1;

  // Binary search in the found range
  return firstOccurence(nums, target, low, high);
}

int main()
{
  vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int target = 1;

  int result = findInInfinity(nums, target);
  cout << "First occurrence is at index: " << result << endl;

  return 0;
}
