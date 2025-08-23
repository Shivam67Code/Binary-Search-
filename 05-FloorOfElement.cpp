#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<int> nums, int target)
{
  int start = 0;
  int end = nums.size() - 1;
  int res = -1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (nums[mid] == target)
    {
      return nums[mid];
    }
    else if (nums[mid] < target)
    {
      res = nums[mid];
      start = mid + 1;
    }
    else if (nums[mid] > target)
    {
      end = mid - 1;
    }
  }
  return res;
}
int main()
{
  vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 9};

  int target = 8;
  int answer = findFloor(nums, target);

  cout << answer;
  return 0;
}