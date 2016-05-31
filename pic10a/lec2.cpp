/************************************
 * This is sample code for lecture 2
 *
 * copyright: Zhimin Peng
 ************************************/


#include<iostream>
#include <climits>
using namespace std;

int main()
{

  /****************************
   * Demo different data types*
   ****************************/

  // character types
  char my_char1 ='a';
  char my_char2 ='1';
  char my_char3 ='&';

  cout<<"character my_char1 is: "<< my_char1 <<endl;
  cout<<"character my_char2 is: "<< my_char2 <<endl;
  cout<<"character my_char3 is: "<< my_char3 <<endl;

  // int types
  int year  = 2015;
  int month = 4;
  int day   = 2;

  cout<<"Today is: "<< month <<"/" << day << "/" << year <<endl;
  cout<<"The largest int is: " << INT_MAX<<endl;
  cout<<"The smallest int is: " << INT_MIN<<endl;

  // long long type
  long long my_big_int = 99999999999999999;
  cout<<"I have a big int: "<< my_big_int<<endl;
  cout<<"The largest long long is: " << LLONG_MAX<<endl;
  cout<<"The smallest long long is: " << LLONG_MIN<<endl;

  // boolean type
  bool state = true;
  cout<<state<<endl;


  // basic calculations
  int num_minutes = 4;
  int num_seconds = num_minutes * 60;
  cout << num_minutes <<" minutes = " << num_seconds <<" seconds." <<endl;

  // double arithmetic
  double a = 2.;
  double b = 0.3;
  double c = a/b;
  cout<<c<<endl;
  
  return 0;
}
