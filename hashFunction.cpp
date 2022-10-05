#include <iostream>
#include <cmath>
#include <cstring>

bool foo(const char* pat, const char* txt, int pos)
{
  int m = std::strlen(pat);
  int n = std::strlen(txt);
  for (int i = 0; i < m; ++i)
  {
    if (pat[i] != txt[pos]) { return false; }
    pos++;
  }
  return true;
}

// Rabin-Karp Algorithm
int search(const char* pat, const char* txt)
{
  int m = std::strlen(pat);
  int n = std::strlen(txt);
  int pos = 0;
  int hashPat = 0;
  int hashTxt = 0;
  int count = 0;

  for (int i = 0; i < m; ++i)
  {
    hashPat = (hashPat * 10 + int(pat[i])) % (m + n);
  }

  pos = 0;
  for (int i = 0; i < m; ++i)
  {
    hashTxt = (hashTxt * 10 + int(txt[i])) % (m + n);
  }
  int q = 1;
  for (int i = 0; i < m - 1; ++i)
  {
    q = (q * 10) % (n + m);
  }
  if (hashTxt == hashPat)
  {
    if (foo(pat, txt, pos)) { count++; }
  }
  
  for (int j = 0; j < n; ++j)
  {
    pos = j + 1;
    hashTxt = ((hashTxt - (int(txt[j]) * q)) * 10 + int(txt[j + m])) % (n + m);
    if (hashTxt < 0) { hashTxt += (n + m); }
    if (hashTxt == hashPat)
    {
      if (foo(pat, txt, pos)) { count++; }
    }
  }
  return count;
}

int main()
{
  char txt[] = "dbdbaa*dbadbadbadbadba";
  char pat[] = "a*db";
  int m = std::strlen(pat);
  int n = std::strlen(txt);
  if (m > n) { std::cout << "Error!!!\n"; }
  std::cout << "Result is " << search(pat, txt) << std::endl;

  return 0;
}
