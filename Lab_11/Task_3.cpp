#include <iostream>
#include <exception>
using namespace std;

class InvalidTemperatureException : public exception {};

template <typename T>
T convertToFahrenheit(T celsius) {
    const double ABSOLUTE_ZERO = -273.15;
    if (celsius < ABSOLUTE_ZERO)
        throw InvalidTemperatureException();
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    try {
        cout << "Attempting to convert -300C...\n" << endl;
        double result = convertToFahrenheit(-300.0);
        cout << "Fahrenheit: " << result << "°F" << endl;
    }
    catch (const InvalidTemperatureException& e) {
        cout << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }
    return 0;
}
