#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool palindrome(string s){
  int n = s.size();
  for(int i = 0; i < n/2; i++){
    if(s[i] != s[n-i-1]) return false;
  }
  return true;
}


int main(){
  int n;string s;
  cin >> n >> s;
  string t = s.substr(0,n-1);
  reverse(t.begin(),t.end());
  cout << s+t << endl;

  return 0;
}