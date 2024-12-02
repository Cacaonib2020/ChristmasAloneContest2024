レギュレーションが決まる前に作ってしまった問題なので、今のままの設定ではコンセプトに合わないかもですが、個人的に良い問題が作れたと思ったので、一応のせておきます.

# 問題文
整数 $N$ , $M$ が与えらえる。原点を通り、$xy$ 平面上の領域 $D={(x, y)|0<x≦N, 0<y≦N}$ 内の格子点をちょうど $M$ 個通るような直線の本数を求めてください.

# 制約
- $1 \leq N \leq 10^5$
- $1 \leq M \leq N$

# 入力
入力は以下の形式で与えられます
```md
$N$ $M$
```

# 出力
答えを出力せよ。

# 解答例
v v v v v


















```cpp
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define All(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    
    if(M==N) { // コーナーケース(直線x=yだけの1本)
      cout << 1 << endl;
      return;
    }
    
    auto func = [&](int n) { // 素因数分解(底だけを配列で出力)
        int m = n;
        vector<int> res;
        for(int i=2; i*i<=m; i++) {
            if(n%i==0) res.push_back(i);
            while(n%i==0) n/=i;
        }
        if(n != 1) res.push_back(n);
        return res;
    };

    ll ans = 0; // 答え
    int lower = N/(M+1)+1, upper=N/M; // for文範囲[lower, upper]
    for(int i=lower; i<=upper; i++) {
        auto res = func(i);
        int add = i;
        for(auto p : res) { // オイラーの定理
            add *= (p-1);
            add /= p;
        }
        ans += add;
    }
    ans *= 2; // 直線x=yについての対称性
    cout << ans << endl;
    return 0;
}
```
