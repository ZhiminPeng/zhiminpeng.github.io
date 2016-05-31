#include <iostream>
#include <vector>
using namespace std;

/*
void rotate(vector<int>& nums, int k) {
  int n = nums.size();
  vector<int> tmp(n, 0);
  k = k%n;
  int i = k;
  for(i=k;i<n;i++)
  {
    tmp[i] = nums[i-k];
  }
  for(i=0;i<k;i++)
  {
    tmp[i] = nums[n-k+i];
  }
  for(i=0;i<n;i++)
    nums[i] = tmp[i];
}
*/

void right_rotate_by_one(vector<int>& nums)
{
  int n = nums.size();
  int tmp = nums[n-1];
  for (int i = n-1; i >0; --i)
  {
    nums[i] = nums[i-1];
  }
  nums[0] = tmp;
}

void rotate(vector<int>& nums, int k) {
  k = k%nums.size();
  for (int i = 0; i < k; ++i)
  {
    right_rotate_by_one(nums);
  }
}

void print(const vector<int>& nums)
{
  for (int i = 0; i < nums.size(); ++i)
    cout<<nums[i]<<" ";
  cout<<endl;
}

int main(int argc, char *argv[])
{
  int n = 10;
  int d = 12;
  vector<int> v(n, 0);
  for (int i = 0; i < n; ++i)
  {
    v[i] = i+1;
  }
  print(v);
  rotate(v, d);
  print(v);
  return 0;
}
