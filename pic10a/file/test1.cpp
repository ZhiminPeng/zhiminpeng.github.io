#include <fstream>
#include <vector>
using namespace std;


int main()
{
  vector<int> v;
  for (int i = 0; i < 10; ++i)
  {
    v.push_back(i);
  }
  ofstream fout;
  fout.open("MyFile.txt");
  for(int i=0; i<v.size();i++)
    fout<<v[i]<<endl;
  
  return 0;
}
