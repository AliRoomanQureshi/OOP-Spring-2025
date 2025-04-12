#include <iostream>
using namespace std;

class Vector2D {
private:
    float x, y;

public:
    Vector2D(float xVal = 0, float yVal = 0) {
        x = xVal;
        y = yVal;
    }

    Vector2D operator+(const Vector2D &v) const {
        return Vector2D(x + v.x, y + v.y);
    }

    Vector2D operator-(const Vector2D &v) const {
        return Vector2D(x - v.x, y - v.y);
    }

    Vector2D operator*(float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    friend float dotProduct(const Vector2D &v1, const Vector2D &v2);
    friend ostream& operator<<(ostream &out, const Vector2D &v);
};
float dotProduct(const Vector2D &v1, const Vector2D &v2) {
    return (v1.x * v2.x + v1.y * v2.y);
}

ostream& operator<<(ostream &out, const Vector2D &v) {
    out<<"("<<v.x<<", "<<v.y<<")";
    return out;
}

int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    Vector2D sum = v1 + v2;
    Vector2D diff = v1 - v2;
    Vector2D scaled = v1 * 2;

    float dot = dotProduct(v1, v2);

    cout<<"v1 = "<<v1<<endl;
    cout<<"v2 = "<<v2<<endl;
    cout<<"v1 + v2 = "<<sum<<endl;
    cout<<"v1 - v2 = "<<diff<<endl;
    cout<<"v1 * 2 = "<<scaled<<endl;
    cout<<"dotProduct(v1, v2) = "<<dot<<endl;

    return 0;
}
