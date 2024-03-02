//
//  main.cpp
//  Chapter_4_Exercises
//
//  Created by Sebastian Cordoba on 30/01/2024.
//

#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

const double a0 = 2.50662823884;
const double a1 = -18.61500062529;
const double a2 = 41.39119773534;
const double a3 = -25.44106049637;
const double b1 = -8.47351093090;
const double b2 = 23.08336743743;
const double b3 = -21.06224101826;
const double b4 = 3.13082909833;
const double c0 = 0.3374754822726147;
const double c1 = 0.9761690190917186;
const double c2 = 0.1607979714918209;
const double c3 = 0.0276438810333863;
const double c4 = 0.0038405729373609;
const double c5 = 0.0003951896511919;
const double c6 = 0.0000321767881768;
const double c7 = 0.0000002888167364;
const double c8 = 0.0000003960315187;

double hornerFunction(double x, double a, double b) {
    return a + x * b;
}

double hornerFunction(double x, double a, double b, double c) {
    return a + x * hornerFunction(x, b, c);
}

double hornerFunction(double x, double a, double b, double c, double d) {
    return a + x * hornerFunction(x, b, c, d);
}

double hornerFunction(double x, double a, double b, double c, double d, double e) {
    return a + x * hornerFunction(x, b, c, d, e);
}

double hornerFunction(double x, double a, double b, double c, double d, double e, double f) {
    return a + x * hornerFunction(x, b, c, d, e, f);
}

double hornerFunction(double x, double a, double b, double c, double d, double e, double f, double g) {
    return a + x * hornerFunction(x, b, c, d, e, f, g);
}

double hornerFunction(double x, double a, double b, double c, double d, double e, double f, double g, double h) {
    return a + x * hornerFunction(x, b, c, d, e, f, g, h);
}

double hornerFunction(double x, double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    return a + x * hornerFunction(x, b, c, d, e, f, g, h, i);
}

/*
 Exercise 1: Implement n! using for, while and do while.
*/

int whileFactorial(int n) {
    int b = 1;
    while (n >= 1) {
        b *= n--;
    }
    return b;
}

int forFactorial(int n) {
    int b = 1;
    for (int i = 1; i <= n; i++) {
        b *= i;
    }
    return b;
}

int doWhileFactorial(int n) {
    int b = 1;
    do {
        b *= n--;
    } while (n >= 1);
    return b;
}

/*
 Exercise 2 and 3: Rectangle rule approximation.
*/

double rectangleSin(double a, double b, int n) {
    double h = (b - a)/n;
    double approximation = 0.0;
    for (int i = 0; i <= n - 1; i++) {
        double x = a + h * (i + 0.5);
        approximation += sin(x)/n;
    }
    return approximation;
}

double rectangleNormCDF(double x, int n) {
    double h = 1.0/n;
    double approximation = 0.0;
    for (int i = 0; i < n; i++) {
        double m = h * (i + 0.5);
        double s = 1 / m;
        approximation += pow(m, -2) * exp(-0.5 * pow((x + 1 - s), 2));
    }
    return approximation / n;
}

/*
 Exercise 4:
*/

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int prev = 0;
    int current = 1;
    
    for (int i = 2; i <= n; i++) {
        int next = current + prev;
        prev = current;
        current = next;
    }
    return current;
}

/*
 Exercise 5 and 6:
*/

double norminvNoCheck(double x) {
    double y = x - 0.5;
    if (-0.42 < y && y < 0.42) {
        double r = y * y;
        return y * (hornerFunction(r, a0, a1, a2, a3) / hornerFunction(r, 1.0, b1, b2, b3, b4));
    }
    else {
        double r;
        if (y <= 0.0) {
            r = x;
        }
        else {
            r = 1.0 - x;
        }
        double s = log(-log(r));
        if (x > 0.5) {
            return hornerFunction(s, c0, c1, c2, c3, c4, c5, c6, c7, c8);
        }
        else {
            return -hornerFunction(s, c0, c1, c2, c3, c4, c5, c6, c7, c8);
        }
        
    }
    
}

double norminv( double x, bool checkRange=1) {
    if (checkRange && (x<0 || x>1.0)) {
        throw logic_error("Parameter x is out of range for norminv. It should be between 0 and 1");
    } else {
        return norminvNoCheck(x);
    }
}

/*
 Exercise 7
*/

void abc() {
    for (int i = 0; i < 10; i++){
        cout << i << "\n";
    }
}

int main() {
    
    cout << whileFactorial(4) << "\n";
    int result = forFactorial(4);
    cout << result << "\n";
    int result_2 = doWhileFactorial(4);
    cout << result_2 << "\n";
    cout << rectangleSin(0.0, 1.0, 100) << "\n";
    cout << rectangleNormCDF(1.96, 1000) << "\n";
    cout << fibonacci(30) << "\n";
    try {
        double result = norminv(1.1);
        cout << result << "\n";
    } catch (const std::logic_error& e) {
        cerr << e.what() << "\n";
    }
    abc();
    return 0;
}
