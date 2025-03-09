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
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& X, int n);
}
#endif //EIGEN_H
