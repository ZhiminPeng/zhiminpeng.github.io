#include <iostream>
#include <climits>
using namespace std;

int main()
{
  int x = 0;
  cin>> x;
  // reverse x
  cout<<"Initial value is: " << x<<endl;
  long long y = 0;
  int digit = 0;
  while(x!=0)
  {
    digit = x % 10;
    x /= 10;
    y = y*10 + digit;
  }
  if(y > INT_MAX || y < INT_MIN)
    y = 0;

  cout<<"The reversed value is: " << (int) y<<endl;
  
  return 0;
}
