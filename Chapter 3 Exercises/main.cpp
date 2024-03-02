//
//  main.cpp
//  Chapter_3_exercises
//
//  Created by Sebastian Cordoba on 28/01/2024.
//

#include <iostream>
#include <cmath>

using namespace std;

int sumOfInts(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n + sumOfInts(n - 1);
    }
}

void exercise2(int a, int b) {
    if (a > b) {
        return;
    }
    else {
        cout << a << "\n";
        exercise2(a + 1, b);
    }
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

const double sqrt2PI = sqrt(2 * 3.141592653589793);
double normcdf(double x) {
    
    double k = pow(1 + 0.2316419 * x, -1);
    double approx = 1 - 1/sqrt2PI * exp(-pow(x, 2)/2) * k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));
    
    if (x < 0) {
        return 1 - normcdf(-x);
    }
    
    return approx;
}


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


double redefinedNormCDF(double x) {
    
    double k = pow(1 + 0.2316419 * x, -1);
    double terms = hornerFunction(k, 0.319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429);
    
    double approx = 1 - 1/sqrt2PI * exp(-pow(x, 2)/2) * k * terms;
    if (x < 0) {
        return 1 - normcdf(-x);
    }
    
    return approx;
}

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

double norminv(double x) {
    double y = x - 0.5;
    if (-0.42 < y < 0.42) {
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

double blackScholesCallPrice(double strikePrice, double ttM, double spotPrice, double vol, double riskFreeRate) {
    
    double d1 = 1/(vol * sqrt(ttM)) * (log(spotPrice/strikePrice) + (riskFreeRate + (vol * vol * 0.5) * ttM));
    double d2 = d1 - vol * sqrt(ttM);
    
    return redefinedNormCDF(d1) * spotPrice - redefinedNormCDF(d2) * strikePrice * exp(-riskFreeRate * ttM);
}

int main() {
    
    cout << sumOfInts(5) << "\n";
    exercise2(2, 7);
    cout << "\n";
    cout << factorial(4) << "\n";
    cout << fibonacci(5) << "\n";
    cout << normcdf(0.3) << "\n";
    cout << redefinedNormCDF(0.3) << "\n";
    cout << blackScholesCallPrice(100.0, 0.5, 110, 0.1, 0.03) << "\n";

    return 0;
}
