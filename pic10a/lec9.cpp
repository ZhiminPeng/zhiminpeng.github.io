#include <iostream>
using namespace std;

int fib(int n)
{
  if(n==0 || n==1) return 1;
  else return fib(n-1) + fib(n-2);
}

void swap(int& x, int& y)
{
  int tmp = x;
  x = y;
  y = tmp;
}

int main()
{
  for(int i=0;i<1000000000;i++)
  {
    cout<<fib(i)<<" ";
  }
  cout<<endl;
  return 0;
}
