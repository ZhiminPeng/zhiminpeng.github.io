#include <iostream>
#include <string>
using namespace std;

double add(double, double);
string add(string, string);

int main()
{
  string x = "abc";
  string y = "def";
  string z = add(x, y);
  cout<<z<<endl;
  return 0;
}


double add(double x, double y)
{
  return x + y;
}


string add(string x, string y)
{
  return x + y;
}


