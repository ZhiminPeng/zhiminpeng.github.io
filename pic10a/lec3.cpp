#include <iostream>
#include <string>
using namespace std;


int main()
{
  // const variable
  double pi;
  const double PI = 3.14;
  pi = PI + 1;

  // basic operations
  int val = 1;
  // increment;
  cout << val<<endl;
  ++val;
  cout << val<<endl;
  val++;
  cout << val<<endl;

  val = 1;
  // decrement
  cout << val<<endl;
  --val;
  cout << val<<endl;
  val--;
  cout << val<<endl;

  // difference between pre-increment and post-increment
  int a = 1;
  int double_a;
  double_a = a*2*(a++);
  cout<<"double_a is: "<<double_a<<" a: "<< a<<endl;
  a = 1;
  double_a = 2*(++a);
  cout<<"double_a is: "<<double_a<<" a: "<< a<<endl;

  // bool operations
  bool like_math = true;
  bool like_coding = false;
  bool is_cool = !(like_math && like_coding);
  cout<<"is_cool: "<< (is_cool) <<endl;

  string name = "Jukka Virtanen";
  cout<< name.length()<<endl;
  cout<< name.size()<<endl;  
  cout<< name.at(0)<<endl;
  cout<< name.substr(0, 4)<<endl;
  return 0;
}
