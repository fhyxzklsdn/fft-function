#include"eigen.h"// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
using namespace FFTLibrary;
using std::cout;

int main() {
    Eigen::MatrixXd input(3, 3);
    input << 1, 2, 3,
             4, 5, 6,
             7, 8, 9;

    Eigen::MatrixXd kernel(2, 2);
    kernel << 1, 0,
              0, -1;

    // 执行卷积操作
    Eigen::MatrixXd result = conv2(input, kernel);

    // 输出结果
    std::cout << "Input:\n" << input << "\n\n";
    std::cout << "Kernel:\n" << kernel << "\n\n";
    std::cout << "Result:\n" << result << "\n";
}// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.