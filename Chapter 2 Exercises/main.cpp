//
//  main.cpp
//  Chapter 2 Exercises
//
//  Created by Sebastian Cordoba on 27/01/2024.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
        
    /*Exercise 1*/
    
    cout << "Exercise 1:\n";
    //cout << (true || false) == (true) << "\n";
    cout << ((true && false ) || true)  << "\n";
    cout << (true && (false || true))  << "\n";
    cout << (true && false || true) << "\n";
    cout << (3*5==15 && (7*8==21 || true != false))<< "\n";
    
    /*Exercise 2*/
    
    cout << "Exercise 2:\n";
    cout << "int \t" << sizeof(int) << "\n";
    cout << "long int\t" << sizeof(long int) << "\n";
    cout << "short int\t" << sizeof(short int) << "\n";
    cout << "long long int\t" << sizeof(long long) << "\n";
    cout << "unsigned int\t" << sizeof(unsigned int) << "\n";
    cout << "unisgned short int\t" << sizeof(unsigned short int) << "\n";
    cout << "unisgned long int\t" << sizeof(unsigned long int) << "\n";
    cout << "unisgned long long\t" << sizeof(unsigned long long) << "\n";
    
    /*Exercise 3*/
    
    /*Cast char values to int values to find codes used for the 
     characters ’a’, ’z’, ’A’, ’Z’, ’0’, and ’9’.
     What codes are used for a carriage return, a new line, and a tab?
     */
    
    cout << "Exercise 3:\n";
    
    char x = 'a';
    char y = 'z';
    char z = 'A';
    char v = 'Z';
    char w = '0';
    char m = '9';
    
    int a = x;
    int b = y;
    int c = z;
    int d = v;
    int e = w;
    int f = m;
    
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << d << "\n";
    cout << e << "\n";
    cout << f << "\n";
    
    cout << "Exercise 3\n";
    cout << 'A' << '\t' << ((int)'A') << '\n';
    cout << 'Z' << '\t' << ((int)'Z') << '\n';
    cout << 'a' << '\t' << ((int)'a') << '\n';
    cout << 'z' << '\t' << ((int)'z') << '\n';
    cout << "Carriage return" << '\t' << ((int)'\r') << '\n';
    cout << "New line" << '\t' << ((int)'\n') << '\n';
    cout << "Tab" << '\t' << ((int)'\t') << '\n';
    
    
    /*Exercise 4*/
    
    /*  
        What value do you get if you subtract the unsigned int 5
        from the unsigned int 3? Try writing the numbers involved
        in binary to explain what is going on.
     */
    
    unsigned int g = 5;
    unsigned int h = 3;
    cout << "Exercise 4:\n";
    cout << h - g << "\n"; // 011-101= -10
    
    /*Exercise 5*/
    
    /* 
     
     Write a program that reads a single char of input and then
     prints out the same character in upper case. To do this, convert
     the char to an integer and use this to work out if it is a lower
     case letter or not. If it is, convert it to the code for an upper
     case letter. Then convert this back to an integer.
     
     the difference between a character's uppercase and lowercase is 32, due to the bit distance
     */
    
    char character;
    cout << "Exercise 5:\n";
    cout << "Enter a character:\n";
    cin  >>  character;
    int convChar = (int) character;
    if (convChar >= 97 && convChar <= 122){
        convChar = convChar - 32;
    }
    else {
        convChar = convChar;
    }
    char upperCase = (char)convChar;
    
    cout << upperCase << "\n";
    
    /*Exercise 6*/
    
    /*
     
     Write a program where the user enters a decimal number
     and the code prints out the nearest integer. You should
     use casting as part of your solution. Write a second
     version the easy way by using the cmath library.
     
     */
    
    /*
    3.5 and 3.4 go to 3 por ejemplo and 3.51 to 4
     */
    
    double decimal;
    int nearestInt;
    
    cout << "Enter a decimal number:\n";
    cin >> decimal;
    
    if (decimal - 0.5 >= (int)decimal){
        nearestInt = (int)decimal + 1;
    }
    else {
        nearestInt = (int)decimal;
    }
    
    cout << "The nearest integer is:\n";
    cout << nearestInt << "\n";
    
    
    //using cmath:
    
    double easyDec;
    
    cin >> easyDec;
    cout << "Nearest integer:\n";
    cout << round(easyDec) << "\n";
    
    /*Exercise 8*/
    
    int k = -1;
    unsigned int j = 0;
    if (k<j){
        cout << "k is smaller";
    }
    else {
        cout << "k is bigger";
    }
    cout << "Because we’re interpreting k to equal ";
    unsigned int castValue = (unsigned int)k;
    cout << castValue;
    cout << "\n";
    return 0;
}
