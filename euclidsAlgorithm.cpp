#include <iostream>

int euclidsIter(int num1, int num2)
{
  if (num1 == 0 || num2 == 0) { throw "Invalid arguments!!!"; }
  int rem;
  int den;
  int num;
  if (num1 > num2)
  {
    num = num1;
    den = num2;
  }
  else
  {
    num = num2;
    den = num1;
  }
  rem = num % den;
  while (rem != 0)
  {
    rem = num % den;
    num = den;
    den = rem;
  }
  return num;
}

int euclidsRec(int num, int den)
{
  int rem = num % den;
  num = den;
  den = rem;
  if (rem == 0) { return num; }
  return euclidsRec(num, den); 
}

int main()
{
  int num1;
  int num2;
  std::cout << "Please Enter 2 number\n";
  std::cin >> num1;
  std::cin >> num2;
  int gcd = euclidsIter(num1, num2);
  std::cout << "gcd is " << gcd << std::endl;

  int gcd1;
  if (num1 == 0 || num2 == 0) 
  { 
    std::cout << "Invalid arguments!!!\n";
    return {};
  }
  if (num1 > num2) { gcd1 = euclidsRec(num1, num2); }
  else { gcd1 = euclidsRec(num2, num1); }
  std::cout << "gcd is " << gcd1 << std::endl;
  
  return {};
}
