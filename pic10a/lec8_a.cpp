#include <iostream>
#include <string>
#include <climits>
using namespace std;

int string_to_int(string str) {
  int i = 0; // counter
  while(str[i]==' ')
  {
    ++i;
  }
  bool is_positive = true;
  if(str[i]=='-')
  {
    is_positive = false;
    ++i;
  }else if(str[i]=='+')
  {
    is_positive = true;
    ++i;
  }
  
  long long num = 0;

  int digit = 0; //
  
  while(i<str.size())
  {
    digit = str[i] - '0';
    if(digit>=0 && digit <=9)
      num = num * 10 + digit;
    else
    {
      cout<<"Invalid input" <<endl;
      return 0;
    }
    ++i;
  }
  num = (is_positive==true)?num:-num;
  if(num > INT_MAX) num = INT_MAX;
  if(num <INT_MIN) num = INT_MIN;
  return (int)num;
}

int main(int argc, char *argv[])
{
  string s;
  while(true)
  {
    cin>>s;
    cout<<s <<" = "<< string_to_int(s)<<endl;
  }
  return 0;
}
