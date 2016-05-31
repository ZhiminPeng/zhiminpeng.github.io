#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guess_number()
{
  srand(time(NULL));
  int magic_number = rand()%20 + 1;
  int guess = 0;
  cin>> guess;
  while(guess != magic_number)
  {
    if(guess < magic_number)
    {
      cout<<"The guess is too low, guess again: "<<endl;
      cin >> guess;
    }else if(guess > magic_number)
    {
      cout<<"The guess is too high, guess again: "<<endl;
      cin >> guess;
    }

  }
  cout<<"Cong!"<<endl;

}


int main(int argc, char *argv[])
{
  guess_number();
  return 0;
}
