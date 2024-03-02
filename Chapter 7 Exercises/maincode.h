//
//  main_code.h
//  chapter_7_exercises
//
//  Created by Sebastian Cordoba on 01/02/2024.
//

#pragma once
#include "stdafx.h"
using namespace std;

void passByQuadratic(double a, double b, double c, double& x1, double& x2);

void testQuadForm();

vector<double> vectorQuadratic(double a, double b, double c);

double min(const vector<double>& data);
double max(const vector<double>& data);

vector<double> randuniform(int n);

vector<double> randn(int n);

vector<double> BoxMuller(int n);

vector<double> stockHighPrices(const string& directory);

double prctile(const vector<double>& v, double p);

void hist(const string& file, const vector<double>& values, int n);


void testAll();
