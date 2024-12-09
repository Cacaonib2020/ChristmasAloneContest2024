#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <filesystem>

int main() {
    std::srand(std::time(0)); // 乱数のシードを現在時刻で初期化

    const int TEST_CASES = 10; // 入力ケースの数
    const std::string OUTPUT_DIR = "./in";

    // 出力ディレクトリの作成
    std::filesystem::create_directory(OUTPUT_DIR);

    for (int i = 1; i <= TEST_CASES; ++i) {
        int R = std::rand() % 100 + 1; // 1 <= R <= 100
        int Y = std::rand() % 100 + 1; // 1 <= Y <= 100
        int W = std::rand() % 100 + 1; // 1 <= W <= 100

        // ファイル名の生成
        std::ostringstream filename;
        filename << OUTPUT_DIR << "/testcase-" << std::setw(2) << std::setfill('0') << i << ".txt";

        // ファイル出力
        std::ofstream outfile(filename.str());
        if (outfile.is_open()) {
            outfile << R << "\n" << Y << "\n" << W << "\n";
            outfile.close();
        } else {
            std::cerr << "Failed to open file: " << filename.str() << "\n";
        }
    }

    std::cout << "Test cases generated in " << OUTPUT_DIR << "/\n";
    return 0;
}