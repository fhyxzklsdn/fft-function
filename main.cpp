#include"eigen.h"// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
using namespace FFTLibrary;
using std::cout;

int main() {
    Eigen::MatrixXcd X(4, 2);  // 4 行 2 列的复数矩阵
    X << 1, 5,
         2, 6,
         3, 7,
         4, 8;  // 输入信号矩阵，每列是一个信号

    int n = 8;  // FFT 计算点数
    Eigen::MatrixXcd Y = fft(X, n);

    std::cout << "FFT result:\n" << Y << std::endl;
    return 0;
}// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.