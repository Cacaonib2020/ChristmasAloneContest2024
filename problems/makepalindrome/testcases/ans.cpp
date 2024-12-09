#include<iostream>
#include<string>

using namespace std;

int main(){
  int n;string s;
  cin >> n >> s;
  char list[128] = {0};
  for(int i = 0; i < n; i++){
    list[int(s[i])]++;
  }
  int onetime = 0;
  for(int i = 'a'; i <= 'z'; i++){
    if(list[i] % 2 == 1){
      onetime++;
    }
  }
  if(onetime > 1){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
  return 0;
}