#include <iostream>
#include <exception>
#include <sstream>

using namespace std;

class DimensionMismatchException : public exception {
    string message;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        stringstream ss;
        ss<<"DimensionMismatchException-Matrices must have same dimensions ("
        <<r1<<"x"<<c1<<" vs "<<r2<<"x"<<c2<<")!";
        message = ss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class Matrix {
    T** data;
    int rows, cols;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols];
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    void input() {
        cout<<"Enter elements of "<<rows<<"x"<<cols<<" matrix:\n";
        for (int i=0;i<rows;i++)
            for (int j = 0; j < cols; ++j)
                cin>>data[i][j];
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = this->data[i][j] + other.data[i][j];

        return result;
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        A.input();
        B.input();

        Matrix<int> C = A + B;
        C.display();
    }
    catch (const DimensionMismatchException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
