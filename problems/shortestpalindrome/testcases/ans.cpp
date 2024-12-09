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
  for(int i = 0; i < n; i++){
    string t;
    t = s.substr(0,i);
    reverse(t.begin(),t.end());
    if(palindrome(s+t)){
      cout << s+t << endl;
      return 0;
    }
  }
  return 0;
}