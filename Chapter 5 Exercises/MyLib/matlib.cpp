//
//  matlib.cpp
//  MyLib
//
//  Created by Sebastian Cordoba on 31/01/2024.
//

#include "matlib.h"
#include "stdafx.h"

static const double sqrt2PI = sqrt(2 * 3.141592653589793);

static const double a0 = 2.50662823884;
static const double a1 = -18.61500062529;
static const double a2 = 41.39119773534;
static const double a3 = -25.44106049637;
static const double b1 = -8.47351093090;
static const double b2 = 23.08336743743;
static const double b3 = -21.06224101826;
static const double b4 = 3.13082909833;
static const double c0 = 0.3374754822726147;
static const double c1 = 0.9761690190917186;
static const double c2 = 0.1607979714918209;
static const double c3 = 0.0276438810333863;
static const double c4 = 0.0038405729373609;
static const double c5 = 0.0003951896511919;
static const double c6 = 0.0000321767881768;
static const double c7 = 0.0000002888167364;
static const double c8 = 0.0000003960315187;

static inline double hornerFunction(double x, double a, double b) {
    return a + x * b;
}

static inline double hornerFunction(double x, double a, double b, double c) {
    return a + x * hornerFunction(x, b, c);
}

static inline double hornerFunction(double x, double a, double b, double c, double d) {
    return a + x * hornerFunction(x, b, c, d);
}

static inline double hornerFunction(double x, double a, double b, double c, double d, double e) {
    return a + x * hornerFunction(x, b, c, d, e);
}

static inline double hornerFunction(double x, double a, double b, double c, double d, double e, double f) {
    return a + x * hornerFunction(x, b, c, d, e, f);
}

static inline double hornerFunction(double x, double a, double b, double c, double d, double e, double f, double g) {
    return a + x * hornerFunction(x, b, c, d, e, f, g);
}

static inline double hornerFunction(double x, double a, double b, double c, double d, double e, double f, double g, double h) {
    return a + x * hornerFunction(x, b, c, d, e, f, g, h);
}

static inline double hornerFunction(double x, double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    return a + x * hornerFunction(x, b, c, d, e, f, g, h, i);
}

double norminv(double x) {
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

/*

double norminv( double x, bool checkRange=1) {
    if (checkRange && (x<0 || x>1.0)) {
        throw logic_error("Parameter x is out of range for norminv. It should be between 0 and 1");
    } else {
        return norminvNoCheck(x);
    }
}
 
*/

double normcdf(double x) {
    
    double k = pow(1 + 0.2316419 * x, -1);
    double terms = hornerFunction(k, 0.319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429);
    
    double approx = 1 - 1/sqrt2PI * exp(-pow(x, 2)/2) * k * terms;
    if (x < 0) {
        return 1 - normcdf(-x);
    }
    
    return approx;
}
