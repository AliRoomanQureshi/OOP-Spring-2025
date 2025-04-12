#include <iostream>
using namespace std;

class Matrix2x2;

class MatrixHelper {
public:
    static void updateElement(Matrix2x2& matrix, int row, int col, int value);
};

class Matrix2x2 {
private:
    int elements[2][2];

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) {
        elements[0][0] = a;
        elements[0][1] = b;
        elements[1][0] = c;
        elements[1][1] = d;
    }

    Matrix2x2 operator+(const Matrix2x2& other) {
        return Matrix2x2(
            elements[0][0] + other.elements[0][0],
            elements[0][1] + other.elements[0][1],
            elements[1][0] + other.elements[1][0],
            elements[1][1] + other.elements[1][1]
        );
    }

    Matrix2x2 operator-(const Matrix2x2& other) {
        return Matrix2x2(
            elements[0][0] - other.elements[0][0],
            elements[0][1] - other.elements[0][1],
            elements[1][0] - other.elements[1][0],
            elements[1][1] - other.elements[1][1]
        );
    }

    Matrix2x2 operator*(const Matrix2x2& other) {
        return Matrix2x2(
            elements[0][0] * other.elements[0][0] + elements[0][1] * other.elements[1][0],
            elements[0][0] * other.elements[0][1] + elements[0][1] * other.elements[1][1],
            elements[1][0] * other.elements[0][0] + elements[1][1] * other.elements[1][0],
            elements[1][0] * other.elements[0][1] + elements[1][1] * other.elements[1][1]
        );
    }
    friend int determinant(const Matrix2x2& matrix);

    friend class MatrixHelper;

    friend ostream& operator<<(ostream& os, const Matrix2x2& matrix) {
        os<<matrix.elements[0][0]<<" "<<matrix.elements[0][1]<<endl;
        os<<matrix.elements[1][0]<<" "<<matrix.elements[1][1]<<endl;
        return os;
    }
};

int determinant(const Matrix2x2& matrix) {
    return matrix.elements[0][0] * matrix.elements[1][1] - matrix.elements[0][1] * matrix.elements[1][0];
}

void MatrixHelper::updateElement(Matrix2x2& matrix, int row, int col, int value) {
    if (row >= 0 && row < 2 && col >= 0 && col < 2)
        matrix.elements[row][col] = value;
    else
        cout<<"Invalid index!"<<endl;
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout<<"Matrix m1:\n"<<m1;
    cout<<"Matrix m2:\n"<<m2;

    Matrix2x2 sum = m1 + m2;
    Matrix2x2 diff = m1 - m2;
    Matrix2x2 product = m1 * m2;

    cout<<"Sum of m1 and m2:\n"<<sum;
    cout<<"Difference of m1 and m2:\n"<<diff;
    cout<<"Product of m1 and m2:\n"<<product;

    cout<<"Determinant of m1: "<<determinant(m1)<<endl;

    MatrixHelper::updateElement(m1, 0, 1, 10);
    cout<<"Matrix m1 after updating element (0,1) to 10:\n"<<m1;

    return 0;
}
