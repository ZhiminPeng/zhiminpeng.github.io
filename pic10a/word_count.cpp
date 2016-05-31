#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<iostream>
using namespace std;

int word_count(vector<string> words, string word)
{
  int count = 0;
  for (int i = 0; i < words.size(); ++i)
  {
    if(words[i] == word) ++count;
  }
  return count;
}


int main()
{
  // step 1: read data from file to a vector of strings
  string file_name;
  cout << "Enter file name to read: ";
  cin >> file_name;
  ifstream fin;
  fin.open(file_name.c_str() );
  vector<string> words;
  string x;
  while (fin >> x)
    words.push_back(x);
  fin.close( );

  // step 2: convert the vector of words to a vector of
  // unique words
  vector<string> unique_words;
  for (int i = 0; i < words.size(); ++i)
  {
    if( find( unique_words.begin(), unique_words.end(),  words[i]) == unique_words.end())
    {
      unique_words.push_back(words[i]);
    }
  }

  // step 3: frequency count
  vector<int> count(unique_words.size());
  for(int i = 0; i < unique_words.size(); i++)
  {
    count[i] = word_count(words, unique_words[i]);
  }

  // step 4: write the results to the file
  ofstream fout; //Note how I can pick any name I want for the
  //object
  fout.open("word_count.txt"); //Open file named MyFile.txt for writing.
  for (int i = 0; i < unique_words.size(); ++i)
  {
    fout<< setw(10)<< unique_words[i] <<": " << count[i] <<endl;
  }
  fout.close();
  
  return 0;
}
