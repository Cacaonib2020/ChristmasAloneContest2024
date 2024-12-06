#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define MOD 1000000007
#define INF 2147483647
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vcsort(x) sort(all(x))
#define vcstsort(x) stable_sort(all(x))
#define rev(x) reverse(all(x))
#define vcsum(x) accumulate(all(x), 0)//llなら0を0LLに
#define vcmax(x) *max_element(all(x))
#define vcmin(x) *min_element(all(x))
int mx[4] = {0, 0, -1, 1};
int my[4]{-1, 1, 0, 0};
template <typename T> bool chmin(T &a, T b) {
  if (a > b)
    a = b;
  return true;
}
struct corr {
  int r;
  int c;
  int d;
  bool operator<(const corr &a) { return d < a.d; }
};
ll ncr(ll n, ll r, ll mod = MOD) {
  ll numerator = 1, denominator = 1;
  rng(i, 0, r) numerator = (numerator * (n - i)) % mod;
  rng(i, 0, r) denominator = (denominator * (r - i)) % mod;
  return numerator / denominator;
}
bool xyok(int r, int c, int h, int w) {
  return (r >= 0 && r < h && c >= 0 && c < w);
}
void fix(int a) { cout << fixed << setprecision(a); }
void outYN(bool a) { cout << (a ? "Yes" : "No") << endl; }
/*---------------------------------------------------------------------------------------------------------*/
int main() { 
  ll n;
  cin >> n;
  map<ll,ll> mp;
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    mp[a]++;
    mp[b]--;
  }
  map<ll,ll> num;
  ll now = 0;
  num[0] = 0;
  for(auto v:mp){
    now += v.second;
    num[v.first] = now;
  }
  vector<ll> numlist;
  for(auto v:num)numlist.push_back(v.first);
  ll q;
  cin >> q;
  rep(i,q){
    ll t;
    cin >> t;
    ll cur = lower_bound(all(numlist),t)-numlist.begin();
    cout << num[numlist[cur]] << endl;
  }
  return 0;
}