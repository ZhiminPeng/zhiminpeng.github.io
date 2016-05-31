#include <iostream>
#include <string>
using namespace std;

int count_syllables(string);

bool is_vowel(char);

int count_words(string);

int count_sentences(string);

bool is_punctuation(char);

double comp_index(string);


int main()
{
  string str;
  while(true)
  {
    cin>>str;
    cout<<count_syllables(str);
    cout<<endl;
  }
  return 0;
}

// count the number of syllables in a word
int count_syllables(string word)
{
  int num_syl = 0;
  int i = 0;
  for (i = 0; i < word.size()-1; ++i)
  {
    if(is_vowel(word[i]) && !is_vowel(word[i+1]))
      ++num_syl;
  }
  // take care of the last character
  if(word[i]=='e' && is_vowel(word[i-1]) || 
     (is_vowel(word[i]) && word[i]!='e') )
    ++num_syl;

  if(num_syl == 0) num_syl = 1;
  
  return num_syl;
}

int count_words(string str)
{
  int num_words = 1;
  for (int i = 0; i < str.size(); ++i)
  {
    if(str[i]==' ') ++num_words;
  }
  return num_words;
}

bool is_vowel(char c)
{
  return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y')?true:false;
}

bool is_punctuation(char c)
{
  return (c==':' || c=='.' || c==';' || c=='?' || c=='!')?true:false;  
}


