#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <filesystem>

std::string generate_random_string(int length) {
    std::string result;
    for (int i = 0; i < length; ++i) {
        char random_char = 'a' + std::rand() % 26; // 英小文字をランダムに生成
        result += random_char;
    }
    return result;
}

int main() {
    std::srand(std::time(0)); // 乱数のシードを現在時刻で初期化

    const int TEST_CASES = 22; // 入力ケースの数
    const std::string OUTPUT_DIR = "./in";

    // 出力ディレクトリの作成
    std::filesystem::create_directory(OUTPUT_DIR);

    for (int i = 1; i < TEST_CASES; ++i) {
        // ランダムな文字列の長さを生成 (1 <= N <= 100)
        int N = std::rand() % 100 + 1;

        // ランダムな文字列を生成
        std::string S = generate_random_string(N);

        // ファイル名の生成
        std::ostringstream filename;
        filename << OUTPUT_DIR << "/testcase-" << std::setw(2) << std::setfill('0') << i << ".txt";

        // ファイルに書き込む
        std::ofstream outfile(filename.str());
        if (outfile.is_open()) {
            outfile << N << "\n" << S << "\n";
            outfile.close();
        } else {
            std::cerr << "Failed to open file: " << filename.str() << "\n";
        }
    }

    std::cout << "Test cases generated in " << OUTPUT_DIR << "/\n";
    return 0;
}
