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
      DEBUG_PRINT( "norminv(" << x <<")" );
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
    // Note the #include <stdexcept> at the top of the file
    if (checkRange && (x<0 || x>1.0)) {
        throw logic_error("Parameter x is out of range for norminv. It should be between 0 and 1");
    } else {
        return norminvNoCheck(x);
    }
}
 
*/
double normcdf(double x) {
      DEBUG_PRINT( "normcdf("<<x<<")");
    double k = pow(1 + 0.2316419 * x, -1);
    double terms = hornerFunction(k, 0.319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429);
    
    double approx = 1 - 1/sqrt2PI * exp(-pow(x, 2)/2) * k * terms;
    if (x < 0) {
        return 1 - normcdf(-x);
    }
    
    return approx;
}

double euroPutBlackScholes(double vol, double ttm, double strikePrice, double spotPrice, double riskFreeRate) {
    
    double d_plus = 1 / (vol * sqrt(ttm)) * (log(spotPrice/strikePrice) + (riskFreeRate + 0.5 * pow(vol, 2)) * ttm);
    double d_minus = d_plus - vol * sqrt(ttm);
    
    double price = normcdf(-d_minus) * strikePrice * exp(-riskFreeRate * ttm) - normcdf(-d_plus) * spotPrice;
    
    return price;
}

double euroCallBlackScholes(double vol, double ttm, double strikePrice, double spotPrice, double riskFreeRate) {
    
    double price = euroPutBlackScholes(vol, ttm, strikePrice, spotPrice, riskFreeRate) - strikePrice * exp(-riskFreeRate * ttm) + spotPrice;
    
    return price;
    
}


static void testNormCdf() {
  // test bounds
  ASSERT(normcdf(0.3)>0);
  ASSERT(normcdf(0.3)<1);
  // test extreme values
  ASSERT_APPROX_EQUAL(normcdf(-1e10), 0, 0.001);
  ASSERT_APPROX_EQUAL(normcdf(1e10), 1.0, 0.001);
  // test increasing
  ASSERT(normcdf(0.3)<normcdf(0.5));
  // test symmetry
  ASSERT_APPROX_EQUAL(normcdf(0.3),
    1 - normcdf(-0.3), 0.0001);
  ASSERT_APPROX_EQUAL(normcdf(0.0), 0.5, 0.0001);
  // test inverse
  ASSERT_APPROX_EQUAL(normcdf(norminv(0.3)),
    0.3, 0.0001);
  // test well known value
  ASSERT_APPROX_EQUAL(normcdf(1.96), 0.975, 0.001);
}

static void testNormInv() {
    ASSERT_APPROX_EQUAL(norminv(0.975), 1.96, 0.01 );
}

static void testEuroPut() {
    //As spot price tends to 0, put price tends to 0
    ASSERT_APPROX_EQUAL(euroPutBlackScholes(0.1, 0.5, 100.0, 1e-7, 0.03), 0, 0.0001);
    //As spot price tends to infinity, put price tends to 0
    ASSERT_APPROX_EQUAL(euroPutBlackScholes(0.1, 0.5, 100.0, 1e7, 0.03), 0, 0.0001);
    //As ttm approaches 0, put price tends to 0
    ASSERT_APPROX_EQUAL(euroPutBlackScholes(0.1, 1e-7, 100.0, 110.0, 0.03), 0, 0.0001);
    
}

void testMatlib() {
    setDebugEnabled(true);
    TEST(testNormInv);
    setDebugEnabled(true);
    TEST(testNormCdf );
    TEST(testEuroPut);
}
