#include<iostream>
#include"Circle.h"
using namespace std;
int main(){			
	Circle c1(5);	
	cout << "radius: " << c1.getRadius() 
	     << " area: "  << c1.calculatearea() << endl;
	
	Circle *c2 = new Circle(2);
	c2->setRadius(10);
	cout << "c2: "   << c2->getRadius()
	     << " area: "<< c2->calculatearea() << endl;
	delete c2;	

	cout << "hello world"<< endl;
	return 0;
}

