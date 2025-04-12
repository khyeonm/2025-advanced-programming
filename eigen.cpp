// conda install conda-forge::eigen으로 설치

#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main() {
    // 3x2 행렬 A 정의
    Eigen::Matrix<double, 3, 2> A;
    A << 1, 2,
         3, 4,
         5, 6;

    // 2x3 행렬 B 정의
    Eigen::Matrix<double, 2, 3> B;
    B << 7,  8,  9,
         10, 11, 12;

    // 행렬곱 C = A * B (3x3 행렬)
    Eigen::Matrix<double, 3, 3> C = A * B;

    // 결과 출력
    cout << "Matrix A (3x2):\n" << A << "\n\n";
    cout << "Matrix B (2x3):\n" << B << "\n\n";
    cout << "Matrix C = A * B (3x3):\n" << C << endl;

    return 0;
}

// 실행 코드
// g++ -I$CONDA_PREFIX/include/eigen3 -O3 eigen.cpp -o eigen