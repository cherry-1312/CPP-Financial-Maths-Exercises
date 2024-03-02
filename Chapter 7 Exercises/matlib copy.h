//
//  matlib.h
//  MyLib
//
//  Created by Sebastian Cordoba on 31/01/2024.
//

#pragma once //prevents same file being included twice
#include "stdafx.h"

const double PI = 3.14159265358979;

double normcdf(double x);

double norminv(double x);

double euroPutBlackScholes(double vol, double ttm, double strikePrice, double spotPrice, double riskFreeRate);

double euroCallBlackScholes(double vol, double ttm, double strikePrice, double spotPrice, double riskFreeRate);

void testMatlib();

