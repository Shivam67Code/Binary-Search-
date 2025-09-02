#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findMinimumDiff(vector<int> &nums, int target)
{
  int start = 0;
  int end = nums.size() - 1;
  int floor = -1, ceil = -1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (nums[mid] == target)
    {
      return nums[mid];
    }
    else if (nums[mid] < target)
    {
      floor = nums[mid];
      start = mid + 1;
    }
    else
    {
      ceil = nums[mid];
      end = mid - 1;
    }
  }
  // Check if any of of them (floor,ceil)is not present.
  if (floor == -1)
    return ceil;
  if (ceil == -1)
    return floor;

  return abs(floor - target) <= abs(ceil - target) ? floor : ceil;
}
int main()
{
  vector<int> nums = {1, 3, 5, 10, 15};
  int target = 12;

  int result = findMinimumDiff(nums, target);

  cout << "The required element which gives minimum difference with the target : "
       << target << " is : " << result << endl;

  return 0;
}
