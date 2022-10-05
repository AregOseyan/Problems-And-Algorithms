#include <iostream>
#include <vector>

void sum(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& res, std::vector<int>& r, int idx)
{
  if (target == 0)
  {
    res.push_back(r);
    return;
  }
  while (idx < candidates.size() && target - candidates[idx] >= 0)
  {
    r.push_back(candidates[idx]);
    sum(candidates, target - candidates[idx], res, r, idx);
    ++idx;

    r.pop_back();
  }
}

void combinationSum(int target)
{
  std::vector<int> candidates;
  for (int i = 1; i <= target; ++i) { candidates.push_back(i); }

  std::vector<int> r;
  std::vector<std::vector<int>> res;
  sum(candidates, target, res, r, 0);

  for (auto& x : res)
  {
    for (auto& y : x) { std::cout << y << " "; }
    std::cout << std::endl;
  }
}

int main()
{
  int n = 5;
  combinationSum(n);

  return {};
}
