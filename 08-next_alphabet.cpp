#include <iostream>
#include <vector>
using namespace std;

char findNextAlphabet(vector<char> &letters, char target)
{
  int start = 0;
  int end = letters.size() - 1;
  char res = '#';

  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (letters[mid] == target)
    {
      start = mid + 1;
    }
    else if (letters[mid] > target)
    {
      res = letters[mid];
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
  }
  return res;
}

int main()
{
  vector<char> letters = {'a', 'c', 'f', 'h'};

  char target = 'f';
  char result = findNextAlphabet(letters, target);
  cout << "The letter which comes after " << target << " in the given array is : " << result << endl;

  return 0;
}