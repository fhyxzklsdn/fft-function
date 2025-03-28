#ifndef EIGEN_H
#define EIGEN_H
#include<Eigen/Dense>
#include<unsupported/Eigen/FFT>
#include <unsupported/Eigen/CXX11/Tensor>
#include<iostream>
namespace FFTLibrary {

    Eigen::VectorXcd fft(const Eigen::VectorXcd& input);
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& input);
    Eigen::VectorXcd fft(const Eigen::VectorXcd& X,int n);
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& X, int n,int dim);
    Eigen::VectorXcd ifft(const Eigen::VectorXcd& input);
    Eigen::MatrixXcd ifft(const Eigen::MatrixXcd& input);
    Eigen::VectorXcd ifft(const Eigen::VectorXcd& X,int n);
    Eigen::MatrixXcd ifft(const Eigen::MatrixXcd& X, int n,int dim);
    Eigen::MatrixXd conv2(const Eigen::MatrixXd& input, const Eigen::MatrixXd& kernel);
}
#endif //EIGEN_H
