#include<iostream>
#include<vector>
using namespace std;


int longest_seq(vector<long long>& list, int& len)
{
  if(len == 0)
    return 0;
  if(len == 1)
    return 1;

  vector<long long> seq;

  int max = 1;
  for(int i=0; i<len; i++){
    seq.clear();
    seq.push_back(list[i]);
    for(int j=i+1; j<i+len; j++){
      vector<long long>::iterator iter = lower_bound(seq.begin(), seq.end(), list[j]);
      if(iter == seq.end())
	seq.push_back(list[j]);
      else
	*iter = list[j];
    }
    max = seq.size() > max ? seq.size() : max;
  }
  return max;

}

int main()
{
  int n;
  cout<<"Please Enter no. of test cases "<<endl;
  cin >> n;
  cout<<"Enter no. of guests invited and their corresponding no.s separated by spaces"<<endl;
  for(int i=0; i<n; i++){
    int nums;

    cin >> nums;
    vector<long long> num_list(nums*2, 0);
    for(int i=0; i<nums; i++){
      cin >> num_list[i];
      num_list[i+nums] = num_list[i];
    }
    cout << longest_seq(num_list, nums) << endl;
  }

  return 0;

}
