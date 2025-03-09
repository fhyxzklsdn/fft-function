# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.30)

# 设置项目名称和版本
project(eigen VERSION 1.0)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定 vcpkg 工具链文件（替换为你的 vcpkg 路径）
set(CMAKE_TOOLCHAIN_FILE "E:/tool/test/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# 手动设置 Eigen3 的路径（替换为你的实际路径）
set(Eigen3_DIR "E:/tool/test/vcpkg/packages/eigen3_x64-windows/share/eigen3")

# 查找 Eigen3 库
find_package(Eigen3 CONFIG REQUIRED)

# 添加可执行文件
add_executable(eigen main.cpp
        eigen.h
        fft.cpp)

# 链接 Eigen3 库
target_link_libraries(eigen PRIVATE Eigen3::Eigen)