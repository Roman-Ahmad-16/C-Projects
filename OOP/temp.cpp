#include <iostream>
using namespace std;
class Celsius
{

public:
    float temp;

    Celsius(float t)
    {
        temp = t;
    }

    float toFahrenheit()
    {
        return (temp * 9 / 5) + 32;
    }
};
class Fahrenheit
{

public:
    float temp;

    Fahrenheit(float t)
    {
        temp = t;
    }

    float convertToCelsius()
    {
        return (temp - 32) * 5 / 9;
    }
};

int main()
{
    Celsius c(25);
    Fahrenheit f(98.6);

    cout << "25 Celsius = " << c.toFahrenheit() << " Fahrenheit" << endl;
    cout << "98.6 Fahrenheit = " << f.convertToCelsius() << " Celsius" << endl;

    return 0;
}