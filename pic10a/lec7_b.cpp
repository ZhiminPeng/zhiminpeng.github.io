#include <iostream>
#include <climits>
using namespace std;

int main()
{
  string s = "";
  cin>> s;
  // reverse x
  cout<<"Initial value is: " << s<<endl;

  int digit = 0;
  int number = 0;
  for (int i = 0; i < s.size(); ++i)
  {
    digit = s[i] - 'A' + 1;
    number = number * 26 + digit;
  }

  cout<<"The reversed value is: " << number <<endl;
  
  return 0;
}
