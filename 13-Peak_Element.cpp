#include <iostream>
#include <vector>
using namespace std;

// This code for understanding and the code below it for coding IRL. 😉
// int findPeak(vector<int> &nums)
// {
//   int start = 0;
//   int end = nums.size() - 1;

//   while (start <= end)
//   {
//     int mid = start + (end - start) / 2;
//     if (mid > 0 && mid < nums.size() - 1)
//     {
//       if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
//       {
//         return mid;
//       }
//       else if (nums[mid + 1] > nums[mid])
//       {
//         start = mid + 1;
//       }
//       else
//       {
//         end = mid - 1;
//       }
//     }
//     else if (mid == 0)
//     {
//       if (nums[0] > nums[1])
//       {
//         return 0;
//       }
//       else
//       {
//         return 1;
//       }
//     }
//     else if (mid == nums.size() - 1)
//     {
//       if (nums[nums.size() - 1] > nums[nums.size() - 2])
//       {
//         return nums.size() - 1;
//       }
//       else
//       {
//         return nums.size() - 2;
//       }
//     }
//   }

//   return -1;
// }
// int main()
// {
//   vector<int> nums = {20, 1};

//   int result = findPeak(nums);

//   cout << "The peak element is at the index : " << result
//        << ", with value : " << nums[result] << endl;
//   return 0;
// }

int findPeak(vector<int> &nums)
{
  int start = 0;
  int end = nums.size() - 1;

  while (start < end) // strictly <
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
  return start; // start == end
}
int main()
{
  vector<int> nums = {20, 100, 500, 5, 4, 3};

  int result = findPeak(nums);

  cout << "The peak element is at the index : " << result
       << ", with value : " << nums[result] << endl;
  return 0;
}
