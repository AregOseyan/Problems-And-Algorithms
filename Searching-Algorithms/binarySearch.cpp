#include <iostream>
#include <vector>

template <typename T>
T binarySearch(std::vector<T> arr, T val, int start, int end)
{
  if (start < end)
  {
    int mid = (start - end) / 2;
    if (arr[mid] == val) { return mid; }
    if (arr[mid] < val) { return binarySearch(arr, val, mid + 1, end); }
    if (arr[mid] > val) { return binarySearch(arr, val, start, mid - 1); }
  }
  return -1;
}

int main()
{
  std::vector<int> arr = { 4, 5, 6, 17, 21, 22, 25, 27, 32, 45 };
  int val;
  std::cout << "Please Enter number\n";
  std::cin >> val;
  int index = binarySearch<int>(arr, val, 0, arr.size() - 1);
  if (index != -1) { std::cout << "The item is there\n"; }
  else { std::cout << "The item does not exist\n"; }

  return {};
}
