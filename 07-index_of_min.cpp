#include <iostream>
#include <vector>
using namespace std;

class Test
{
public:
  static int indexOfMin(vector<int> &nums)
  {
    int start = 0;
    int end = nums.size() - 1;
    int mid;
    while (start < end)
    {
      mid = start + (end - start) / 2;
      if (nums[mid] > nums[end])
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
  static void showAns(vector<int> &nums)
  {
    int minIndex = indexOfMin(nums);
    cout << "The minimum term in the array is : " << nums[minIndex] << " and is at the index : " << minIndex << endl;
  }
};

int main()
{
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

  Test::showAns(nums);
  return 0;
}