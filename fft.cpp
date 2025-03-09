#include"eigen.h"
namespace FFTLibrary {
    Eigen::VectorXcd fft(const Eigen::VectorXcd& input) {
        Eigen::FFT<double> fft;
        Eigen::VectorXcd output;
        fft.fwd(output, input); // 计算正向 FFT
        return output;
    }
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& input) {
        int rows = input.rows();
        int cols = input.cols();

        // 创建输出矩阵（与输入矩阵大小相同）
        Eigen::MatrixXcd output(rows, cols);

        // 创建 FFT 对象
        Eigen::FFT<double> fft;

        // 对每一列进行傅里叶变换
        for (int col = 0; col < cols; ++col) {
            Eigen::VectorXcd column = input.col(col); // 获取当前列
            Eigen::VectorXcd fftColumn;              // 存储当前列的 FFT 结果
            fft.fwd(fftColumn, column);              // 执行 FFT
            output.col(col) = fftColumn;             // 将结果存储到输出矩阵中
        }

        return output;
    }
    Eigen::VectorXcd fft(const Eigen::VectorXcd& X, int n) {
        Eigen::FFT<double> fft;
        Eigen::VectorXcd X_padded(n);

        int original_size = X.size();

        // 处理长度问题
        if (original_size < n) {
            // 复制原始数据并填充零
            X_padded.setZero();
            X_padded.head(original_size) = X;
        } else {
            // 截断数据
            X_padded = X.head(n);
        }

        Eigen::VectorXcd result(n);
        fft.fwd(result, X_padded);  // 计算 FFT
        return result;
    }
}
// Created by 熊思远 on 2025/3/9.

