#include<iostream>
#include"Circle.h"
using namespace std;
float Circle::PI = 3.14159;
Circle::Circle(){radius = 0; cout << "an object has been created" << endl;}
Circle::Circle(int a){radius = a; cout << "an object has been created" << endl;}
Circle::~Circle(){cout << "destructor has been called" << endl;}
int Circle::getRadius(){return radius;}
void Circle::setRadius(int inRadius){radius = inRadius;}
float Circle::calculatearea(){return radius * radius * PI;}
