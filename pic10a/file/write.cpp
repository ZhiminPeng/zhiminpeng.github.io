#include<fstream> // File stream
using namespace std;
int main()
{
  ofstream fout; //Note how I can pick any name I want for the
  //object
  fout.open("MyFile.txt"); //Open file named MyFile.txt for writing.
  for (int i = 0; i < 10; ++i)
  {
    fout << i <<endl;
  }
  fout.close(); // Close the file
  return 0;
}
