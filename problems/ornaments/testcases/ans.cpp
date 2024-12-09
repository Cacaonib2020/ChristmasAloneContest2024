#include<iostream>
#include<algorithm>

using namespace std;
int main(){
  int r,c,w;
  cin >> r >> c >> w;
  cout << min({r,c,w}) << endl;
  return 0;
}