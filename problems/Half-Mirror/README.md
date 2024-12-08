レギュレーションが決まる前に作ってしまった問題なので、今のままの設定ではコンセプトに合わないかもですが、個人的に良い問題が作れたと思ったので、一応のせておきます。
# -Half Mirror
実行制限時間: 2sec/メモリ制限:1024MB <br>
配点: $\large ---$点 <br>
想定Difficulty: 1200

### ストーリー
(読み飛ばしても構いません)  

この街は碁盤状に家が並んでいます．より正確には街を正方形で表した場合格子点にあたる位置に家が建設されています．  
このソリは**直線的に移動すること**と$M$ **個のプレゼントを積載すること**が可能です．  
このソリを使って街の家にプレゼントを配布する時，一度の移動に $M$ 個のプレゼントを配布するような移動経路は何通りあるか求めましょう．
### 問題文
整数 $N$ , $M$ が与えらえる。原点を通り、 $xy$ 平面上の領域 $`\begin{equation}D = \left\{(x, y)|0<x\leq N, 0<y\leq N\right\}\end{equation}`$ 内の格子点をちょうど $M$ 個通るような直線の本数を求めてください。 

### 制約
- $1 \leq N \leq 10^5$
- $1 \leq M \leq N$
- 入力はすべて整数
#
### 入力
入力は以下の形式で標準入力から与えられる。
```md
$N$ $M$
```

### 出力
答えを出力せよ。
#
### 入力例1
```md
60 3
```
### 出力例1
```md
112
```
#
### 入力例2
```md
10 9
```
### 出力例2
```md
0
```
#
### 入力例3
```md
100000 1
```
### 出力例3
```md
3785285600
```
32bit整数におさまらない場合に注意してください。
#

# 解答例
v v v v v
<br><br><br><br><br><br><br><br>
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
      return 0;
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

# 解説
要約: ( $x$ 軸と $y$ 軸を含まない)正方形領域において、原点を通り、その中の格子点をちょうど $M$ 個通るような直線の本数を求める問題でした。
#
### 解く前に
以下の問題を考えます。
格子点 $A(m, n)$ , $B(m+a, n+b)$ ( $a$ , $b$ は整数)に対し、次の(i), (ii)が同値であることを示せ。  
(i) a, bが共通の素因数をもつ。  
(ii) 線分AB(両端を除く)上に格子点がある。  

(i) $\Rightarrow$ (ii) について.
$a$ , $b$ が共通の素因数をもつとし、そのうち1つを $p$ ( $p\geq 2$ )とすると,  
$`\begin{equation}
a=a'p, b=b'p (0<a'<a, 0<b'<b)
\end{equation}`$
を満たす正の整数 $a\'$ , $b'$ が存在する。
よって, $C(m+a', n+b')$ とおくと $C$ は格子点であり,  
$`\begin{equation}
\binom{a'}{b'}=\cfrac{1}{p}\binom{a}{b}
\end{equation}`$
より,

とあらわされ, $`0<\cfrac{1}{p}\leq\cfrac{1}{2}`$ であるから, $C$ は線分 $AB$ (両端を除く)上の格子点.

(ii) $\Rightarrow$ (i) について.
線分 $AB$ (両端を除く)上に格子点があるとし, そのうちの1つを $C(m+q, n+r) (0<q<a, 0<r<b)$ とすると, 2直線 $AB$ , $AC$ の傾きは等しいから,  
$`\begin{equation}
\cfrac{b}{a}=\cfrac{r}{q}.
\end{equation}`$  
$`\begin{equation}
bq = ar.
\end{equation}`$ ここで, $a$ と $b$ が共通の素因数をもたない, つまり $a$ と $b$ が互いに素であると仮定すると, $q$ は $a$ の倍数となるが, これは $0<q<a$ であることに反する.
したがって, $a$ と $b$ は共通の素因数をもつ.
以上より, 題意が示された. (証明終り)
