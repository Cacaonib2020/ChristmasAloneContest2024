#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>

// ランダムな文字列を生成
std::string generate_random_string(int length) {
    std::string result;
    for (int i = 0; i < length; ++i) {
        char random_char = 'a' + std::rand() % 26; // 英小文字をランダムに生成
        result += random_char;
    }
    return result;
}

// 回文に並べ替え可能な文字列を生成
std::string generate_palindrome(int length) {
    std::string half;
    for (int i = 0; i < length / 2; ++i) {
        char random_char = 'a' + std::rand() % 26; // 英小文字をランダムに生成
        half += random_char;
    }

    std::string palindrome = half;
    if (length % 2 == 1) {
        palindrome += 'a' + std::rand() % 26; // 奇数長の場合、真ん中の文字を追加
    }
    std::reverse(half.begin(), half.end());
    palindrome += half;

    // ランダムに並び替えた状態で返す
    std::random_shuffle(palindrome.begin(), palindrome.end());
    return palindrome;
}

int main() {
    std::srand(std::time(0)); // 乱数のシードを現在時刻で初期化

    const int TEST_CASES = 35; // 入力ケースの数
    const std::string OUTPUT_DIR = "./in";

    // 出力ディレクトリの作成
    std::filesystem::create_directory(OUTPUT_DIR);

    for (int i = 0; i < TEST_CASES; ++i) {
        // ランダムな文字列の長さを生成 (1 <= N <= 100)
        int N = std::rand() % 100 + 1;

        // 50%の確率でランダムな文字列または回文に並べ替え可能な文字列を生成
        std::string S;
        if (std::rand() % 2 == 0) {
            S = generate_random_string(N); // ランダムな文字列
        } else {
            S = generate_palindrome(N); // 回文に並べ替え可能な文字列
        }

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
