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
    Eigen::VectorXcd fft(const Eigen::VectorXcd& X,int n) {
        int inputSize = X.size();

        // 补零或截断
        Eigen::VectorXcd paddedX(n);
        if (inputSize < n) {
            paddedX.head(inputSize) = X; // 复制原始数据
            paddedX.tail(n - inputSize).setZero(); // 补零
        } else {
            paddedX = X.head(n); // 截断到 n 点
        }

        // 使用 Eigen 的 FFT 模块计算 DFT
        Eigen::FFT<double> fft;
        Eigen::VectorXcd Y(n);
        fft.fwd(Y, paddedX); // 计算正向 FFT

        return Y;
    }
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& X, int n,int dim) {
        using namespace Eigen;
        int rows = X.rows();
        int cols = X.cols();
        MatrixXcd Y;
        switch (dim) {
            case 1:
                Y.resize(n, cols);
            for (int j = 0; j < cols; ++j) {
                // 将当前列转换为复数向量
                VectorXcd colData(rows);
                for (int i = 0; i < rows; ++i) {
                    colData[i] = X(i, j);
                }

                // 如果 n > rows，补零
                if (n > rows) {
                    colData.conservativeResize(n);
                    colData.tail(n - rows).setZero();
                }

                // 执行 FFT
                VectorXcd fftResult;
                FFT<double> fft;
                fft.fwd(fftResult, colData);

                // 将结果存储到输出矩阵
                for (int i = 0; i < n; ++i) {
                    Y(i, j) = fftResult[i];
                }

            }
            break;
            case 2:
                Y.resize(rows, n);
            for (int i = 0; i < rows; ++i) {
                // 将当前行转换为复数向量
                VectorXcd rowData(cols);
                for (int j = 0; j < cols; ++j) {
                    rowData[j] = X(i, j);
                }

                // 如果 n > cols，补零
                if (n > cols) {
                    rowData.conservativeResize(n);
                    rowData.tail(n - cols).setZero();
                }

                // 执行 FFT
                VectorXcd fftResult;
                FFT<double> fft;
                fft.fwd(fftResult, rowData);

                // 将结果存储到输出矩阵
                for (int j = 0; j < n; ++j) {
                    Y(i, j) = fftResult[j];
                }
            }
            break;
            default:
                 std::cout<<"dim must be 1 or 2";
            break;
        }
        return Y;
    }
    Eigen::VectorXcd ifft(const Eigen::VectorXcd& input) {
        Eigen::VectorXcd result(input.size());

        // 创建 FFT 对象
        Eigen::FFT<double> fft;

        // 计算逆傅里叶变换（IFFT）
        fft.inv(result, input);

        // 打印结果
        std::cout << "IFFT result:\n" << result << std::endl;

        return result;
    }
    Eigen::MatrixXcd ifft(const Eigen::MatrixXcd& input) {
        Eigen::MatrixXcd result(input.rows(), input.cols());

        // 创建 FFT 对象
        Eigen::FFT<double> fft;

        // 对每一列进行 IFFT
        for (int i = 0; i < input.cols(); ++i) {
            Eigen::VectorXcd col = input.col(i);  // 提取第 i 列
            Eigen::VectorXcd col_result;
            fft.inv(col_result, col); // 对第 i 列进行 IFFT
            result.col(i) = col_result; // 将结果存储到输出矩阵的第 i 列
        }

        // 打印结果
        std::cout << "IFFT result (column-wise):\n" << result << std::endl;

        return result;
    }
    Eigen::VectorXcd ifft(const Eigen::VectorXcd& X,int n) {
        int original_size = X.size();
        Eigen::VectorXcd padded_Y;

        if (n > original_size) {
            // 如果 n 大于 Y 的长度，补零
            padded_Y.resize(n);
            padded_Y.head(original_size) = X;
            padded_Y.tail(n - original_size).setZero();
        } else if (n < original_size) {
            // 如果 n 小于 Y 的长度，截断
            padded_Y = X.head(n);
        } else {
            // 如果 n 等于 Y 的长度，直接使用 Y
            padded_Y = X;
        }

        // 创建 FFT 对象
        Eigen::FFT<double> fft;

        // 计算 n 点逆傅里叶变换
        Eigen::VectorXcd result;
        fft.inv(result, padded_Y);

        return result;
    }
    Eigen::MatrixXd conv2(const Eigen::MatrixXd& input, const Eigen::MatrixXd& kernel) {
        int inputRows = input.rows();
        int inputCols = input.cols();
        int kernelRows = kernel.rows();
        int kernelCols = kernel.cols();

        int outputRows = inputRows + kernelRows - 1;
        int outputCols = inputCols + kernelCols - 1;

        Eigen::MatrixXd output = Eigen::MatrixXd::Zero(outputRows, outputCols);

        for (int i = 0; i < outputRows; ++i) {
            for (int j = 0; j < outputCols; ++j) {
                double sum = 0.0;
                for (int m = 0; m < kernelRows; ++m) {
                    for (int n = 0; n < kernelCols; ++n) {
                        int inputRow = i - m;
                        int inputCol = j - n;
                        if (inputRow >= 0 && inputRow < inputRows && inputCol >= 0 && inputCol < inputCols) {
                            sum += input(inputRow, inputCol) * kernel(m, n);
                        }
                    }
                }
                output(i, j) = sum;
            }
        }

        return output;
    }
}
// Created by 熊思远 on 2025/3/9.

