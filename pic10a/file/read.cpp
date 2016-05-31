#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int word_count(vector<string> words, string word)
{
  int count = 0;
  for (int i = 0; i < words.size(); ++i)
    if(words[i] == word) ++count;
  return count;
}

int main()
{
  string file_name;
  cout << "Enter file name to read: ";
  cin >> file_name;
  ifstream fin;
  fin.open(file_name.c_str( ));
  vector<string> list;
  string x;
  while (fin >> x)
    list.push_back(x);
  fin.close( );
  /*
  for (int i = 0; i < 10; ++i)
  {
    cout<<list[i]<<endl;
  }
  */
  vector<int>::iterator it;

  vector<string> unique_list;
  for (int i = 0; i < list.size(); ++i)
  {
    if(!find(unique_list.begin(), unique_list.end(), list[i]))
      unique_list.push_back(list[i]);
  }
  /*
  string word;
  cout<<"Enter the word to count: ";
  cin>>word;
  cout<<word << " occured " << word_count(list, word) << " times"<<endl;
  */
  return 0;
}
