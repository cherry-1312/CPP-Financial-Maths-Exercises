//
//  main_code.cpp
//  chapter_7_exercises
//
//  Created by Sebastian Cordoba on 01/02/2024.
//

#include "maincode.h"
#include "stdafx.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "charts.h"

using namespace std;

static const double PI = 3.141592653589793;

static vector<double> helperVector(int n) {
    
    vector<double> testV;
    srand((int)time(NULL));
    
    for (int i=0; i<n; i++) {
        testV.push_back(cos(rand()));
    }
    return testV;
}

///////////////////////////////////////////////
//
//   EXERCISES
//
///////////////////////////////////////////////

/*
 Exercise 1:
*/

void passByQuadratic(double a, double b, double c, double& x1, double& x2) {
    
    const double& discriminator = b * b - 4 * a * c;
    const double& delta = sqrt(discriminator);
    
    if (discriminator > 0) {
        cout << "Number of roots is 2\n";
        x1 =(-b + delta)/(2 * a);
        x2 = (-b - delta)/(2 * a);
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }
    
    if (discriminator == 0) {
        cout << "Repeated root\n";
        x1 = x2 = -b / (2 * a);
        if (x1 != 0.0) {
            cout << "x1 = x2 = " << x1 << "\n";
        } else {
            cout << "x1 = x2 = 0\n";
        }
        
    }
    
    if (discriminator < 0) {
        cout << "There are no roots over the reals\n";
    }
}


vector<double> vectorQuadratic(double a, double b, double c) {
    
    const double& discriminator = b * b - 4 * a * c;
    const double& delta = sqrt(discriminator);
    
    vector<double> solutions;
    
    if (discriminator > 0) {
        cout << "Number of roots is 2\n";
        solutions.push_back((-b + delta)/(2 * a));
        solutions.push_back((-b - delta)/(2 * a));
        cout << "x1 = " << solutions[0] << "\n";
        cout << "x2 = " << solutions[1] << "\n";
    }
    
    if (discriminator == 0) {
        cout << "Repeated root\n";
        solutions.push_back(-b / (2 * a));
        if (solutions[0] != 0) {
            cout << "x1 = x2 = " << solutions[0] << "\n";
        } else {
            cout << "x1 = x2 = 0\n";
        }
    }
    
    if (discriminator < 0) {
        cout << "There are no roots over the reals\n";
    }
    
    return solutions;
}

/*

Exercise 2:
 
*/

double mean(const vector<double>& data) {
    
    int n = (int)data.size();
    double total = 0.0;
    
    for (int i=0; i<n; i++) {
        total += data[i];
    }
    return total / n;
}



/*

Exercise 3:
 
*/



double standardDeviation(const vector<double>& data) {
    
    int n = (int)data.size();
    double mu = mean(data);
    double total = 0.0;
    
    for (int i=0; i<n; i++) {
        total += pow(data[i] - mu, 2);
        
    }
    return sqrt(total / (n - 1));
}


/*
 
 Exercise 4:
 
*/

double min(const vector<double>& data) {
    
    int n = (int)data.size();
    double minimum = data[0];
    
    for (int i=0; i<n; i++) {
        if (data[i]<data[0]) {
            minimum = data[i];
        }
    }
    return minimum;
}

double max(const vector<double>& data) {
    
    int n = (int)data.size();
    double maximum = data[0];
    
    for (int i=0; i<n; i++) {
        if (data[i]>data[0]) {
            maximum = data[i];
        }
    }
    return maximum;
}

/*
 
 Exercise 5:
 
*/

vector<double> randuniform1(int n) {
    
    vector<double> randu(n, 0.0);
    
    
    for (int i=0; i<n; i++) {
        srand((int)time(NULL));
        randu[i] = rand();
    }
    
    for (int i=0; i<n; i++) {
        randu[i] = randu[i]/RAND_MAX;
    }
    return randu;
}

//Wasn't getting exercise 5 to work with the code above
//so resorted to using <random> library which seemed to
//have solved the issue.

vector<double> randuniform(int n) {
    vector<double> randu(n, 0.0);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 0; i < n; i++) {
        randu[i] = dis(gen);
    }

    return randu;
}

/*
 
 Exercise 6:
 
 Applicaion of the CLT.
 
*/

static vector<double> setMeanToZero(const vector<double>& data) {
    double mu = mean(data);
    vector<double> modified = data;
    
    for (int i=0; i<(int)modified.size(); i++) {
        modified[i] -= mu;
    }
    return modified;
}

static vector<double> setSTDtoOne(const vector<double>& data) {
    double sigma = standardDeviation(data);
    vector<double> modified = data;
    
    for (int i=0; i<(int)modified.size(); i++) {
        modified[i] /= sigma;
    }
    return modified;
}


static double sumOfRandU(const vector<double>& data) {
    
    double total = 0.0;
    int n = (int)data.size();
    
    for (int i=0; i<n; i++) {
        total += data[i];
    }
    return total/n;
}


vector<double> randn(int n) {
    vector<double> normalDist(n);
    
    for (int i=0; i<n; ++i) {
        vector<double> v = randuniform(n);
        normalDist[i] = sumOfRandU(v);
    }
    normalDist = setMeanToZero(normalDist);
    normalDist = setSTDtoOne(normalDist);
    return normalDist;
}

/*
 
 Exercise 7:
 
*/

vector<double> BoxMuller(int n) {
    
    vector<double> u1 = randuniform(n);
    vector<double> u2 = randuniform(n);
    vector<double> n1(n);
    
    for (int i=0; i<n; ++i) {
        n1[i] = sqrt(-2 * log(u1[i])) * cos(2 * PI * u1[i]);
    }
    return n1;
}

/*
 
 Exercise 8-11 are written in charts.cpp
 
*/

//Below is a helper function for exercise 8
//which reads Apple's stock data from a JSON
//and inserts the high prices into a vector

vector<double> stockHighPrices(const string& directory) {
    
    ifstream ifs(directory);
    rapidjson::IStreamWrapper isw(ifs);
    rapidjson::Document doc;
    doc.ParseStream(isw);
    
    vector<double> highPrices;
    
    if (doc.IsArray()) {
        for (rapidjson::SizeType i = 0; i < doc.Size(); i++) {
            const rapidjson::Value& entry = doc[i];
            if (entry.IsArray() && entry.Size() >= 3) {
                const rapidjson::Value& highPrice = entry[2];
                if (highPrice.IsNumber()) {
                    highPrices.push_back(highPrice.GetDouble());
                }
            }
        }
    }
    return highPrices;
}

/*
 
 Exercise 9:
 
 */

double prctile(const vector<double>& v, double p) {
    
    vector<double> sorted = v;
    
    sort(sorted.begin(), sorted.end());
    
    double position = sorted.size() * (p / 100);
    
    if (position != floor(position)) {
        
        double posFloor = floor(position);
        double posCeil = ceil(position);
        double lowerValue = sorted[(int)posFloor];
        double upperValue = sorted[(int)posCeil];
        
        return lowerValue + (upperValue - lowerValue) * (position - posFloor);
    } else {
        return sorted[(int)position];
    }
}

/*
 
 Exercise 10:
 
*/

void hist(const string& file, const vector<double>& values, int n) {
    
    vector<double> boundaries(n + 1);
    vector<double> amounts(n, 0);
    vector<double> midpoints(n);
    
    double minVal = *min_element(values.begin(), values.end());
    double maxVal = *max_element(values.begin(), values.end());
    
    double binWidth = (maxVal - minVal) / n;
    
    for (int i = 0; i <= n; i++) {
        boundaries[i] = minVal + i * binWidth;
    }
    
    for (double entry : values) {
        for (int i = 0; i < n; i++) {
            if (entry >= boundaries[i] && entry < boundaries[i + 1]) {
                amounts[i]++;
                break;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        midpoints[i] = (boundaries[i] + boundaries[i + 1]) / 2;
    }
    
    columnChart(file, midpoints, amounts);
    
}

///////////////////////////////////////////////
//
//   TESTS
//
///////////////////////////////////////////////

static void testMinMax() {
    
    vector<double> vector = helperVector(10);
    
    ASSERT(min(vector)<max(vector));
}

static void testMean() {
    
    vector<double> vector = helperVector(10);
    
    //for (int i=0; i<(int)vector.size(); i++) {
    //    cout << vector[i] << "\n";
    //}
    
    //cout << mean(vector) << "\n";
    
    ASSERT(min(vector)<mean(vector)<max(vector));
}

static void testSetMeanToZero() {
    vector<double> v = helperVector(30);
    vector<double> newVector((int)v.size());
    
    newVector = setMeanToZero(v);
    
    ASSERT(mean(newVector)==0.0);
}

static void testSetSTDtoOne() {
    vector<double> v = helperVector(30);
    vector<double> newVector((int)v.size());
    
    newVector = setSTDtoOne(v);
    
    ASSERT(standardDeviation(newVector)==1.0);
}

static void testRandUniform() {
    
    vector<double> random = randuniform(200);
    double total = 0.0;
    
    for (int i=0; i<(int)random.size(); i++) {
        //cout << random[i] << "\n";
        total += random[i];
    }
    
    total = total / (int)random.size();
    
    ASSERT_APPROX_EQUAL(total, 0.5, 0.01);
}


static void testRandn() {
    
    const vector<double>& tester = randn(3000);
    
    ASSERT_APPROX_EQUAL(mean(tester), 0.0, 0.0001);
    ASSERT_APPROX_EQUAL(standardDeviation(tester), 1.0, 0.0001);
}

static void testBoxMuller() {
    const vector<double>& tester = BoxMuller(3000);

    ASSERT_APPROX_EQUAL(mean(tester), 0.0, 0.0001);
    ASSERT_APPROX_EQUAL(standardDeviation(tester), 1.0, 0.0001);
}


void testAll() {
    TEST(testMinMax);
    TEST(testMean);
    TEST(testRandUniform);
    TEST(testSetMeanToZero);
    TEST(testSetSTDtoOne);
    TEST(testRandn);
    TEST(testBoxMuller);
}
