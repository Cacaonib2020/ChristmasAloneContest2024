# Generated by CacaoNiB with ChatGPT

# 入力の読み込み
N = int(input())
S = input()

# 結果の計算
# 入力された文字列 S から始まる最短の回文を作成
for i in range(N):
    # 現在の S に対し、逆順の文字列を追加して回文を試作
    candidate = S + S[:i][::-1]
    if candidate == candidate[::-1]:  # 回文か確認
        print(candidate)
        break
