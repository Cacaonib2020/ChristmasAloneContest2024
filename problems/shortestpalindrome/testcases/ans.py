import os
import time

# 入力ディレクトリと出力ディレクトリの指定
input_dir = "./in"
output_dir = "./oput"

# 出力ディレクトリの作成（存在しない場合に作成）
os.makedirs(output_dir, exist_ok=True)

# 入力ディレクトリ内のすべてのファイルを取得
input_files = sorted(os.listdir(input_dir))

# 各ファイルについて処理を実行
for filename in input_files:
    input_path = os.path.join(input_dir, filename)
    output_path = os.path.join(output_dir, filename)

    # 実行開始時間を記録
    start_time = time.time()

    # ans.exe を実行して、結果をファイルに出力
    command = f"python sample.py < {input_path} > {output_path}"
    os.system(command)

    # 実行時間を計測
    elapsed_time = time.time() - start_time

    # 実行結果を表示
    print(f"{input_path} {elapsed_time:.3f}sec")
