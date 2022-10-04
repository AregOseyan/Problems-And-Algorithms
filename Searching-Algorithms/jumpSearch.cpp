#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
int jumpSearch(std::vector<T> arr, T val)
{
  int inc = std::sqrt(arr.size());
  std::cout << "step is " << inc << std::endl;
  for (int i = 0; i < arr.size(); i += inc)
  {
    if (arr[i] == val) { return i; }
    if (arr[i] < val) 
    {
      for (int j = i - 1; j >= 0; --j)
      {
        if (arr[j] == val) { return j; }
      }
    }
  }
  return -1;
}

int main()
{
  std::vector<int> arr = { 4, 5, 6, 17, 21, 22, 25, 27, 32, 45 };
  int val;
  std::cout << "Please Enter number\n";
  std::cin >> val;
  int index = jumpSearch<int>(arr, val);
  if (index != -1) { std::cout << "The item is there\n"; }
  else { std::cout << "The item does not exist\n"; }

  return {};
}
