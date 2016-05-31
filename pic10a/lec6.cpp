#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  string word = "";
  cout<<"Give me a string: ";
  cin>> word;
  int len = word.length();
  for (int i = 0; i < len/2; i++)
  {
    if(word[i]!=word[len - i - 1])
    {
      cout<<word <<" is not a P."<<endl;
      return 0;
    }
  }
  cout<<word <<" is a P."<<endl;  
  
  return 0;
}
